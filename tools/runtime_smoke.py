#!/usr/bin/env python3
"""Minimal libretro software-renderer runner for reproducible local smoke evidence.

Supply a separately installed DeSmuME libretro core. Captures are observations,
not assertions that gameplay passed; inspect images and record findings separately.
All saves, screenshots and states remain under the specified output directory.
"""

import argparse
import ctypes as C
import hashlib
import json
from pathlib import Path
import shutil
import struct
import sys
import time
import zlib


class Variable(C.Structure):
    _fields_ = [("key", C.c_char_p), ("value", C.c_char_p)]


class Game(C.Structure):
    _fields_ = [("path", C.c_char_p), ("data", C.c_void_p), ("size", C.c_size_t), ("meta", C.c_char_p)]


class SystemInfo(C.Structure):
    _fields_ = [("name", C.c_char_p), ("version", C.c_char_p), ("extensions", C.c_char_p),
                ("need_fullpath", C.c_bool), ("block_extract", C.c_bool)]


ENV = C.CFUNCTYPE(C.c_bool, C.c_uint, C.c_void_p)
VIDEO = C.CFUNCTYPE(None, C.c_void_p, C.c_uint, C.c_uint, C.c_size_t)
AUDIO = C.CFUNCTYPE(None, C.c_int16, C.c_int16)
BATCH = C.CFUNCTYPE(C.c_size_t, C.POINTER(C.c_int16), C.c_size_t)
POLL = C.CFUNCTYPE(None)
INPUT = C.CFUNCTYPE(C.c_int16, C.c_uint, C.c_uint, C.c_uint, C.c_uint)
LOG = C.CFUNCTYPE(None, C.c_int, C.c_char_p)
BUTTONS = {"b": 0, "y": 1, "select": 2, "start": 3, "up": 4, "down": 5,
           "left": 6, "right": 7, "a": 8, "x": 9, "l": 10, "r": 11}


def sha256(path):
    with path.open("rb") as stream:
        return hashlib.file_digest(stream, "sha256").hexdigest()


def png(path, pixels, width, height, pitch, pixel_format):
    rows = bytearray()
    for y in range(height):
        rows.append(0)
        row = pixels[y * pitch:(y + 1) * pitch]
        if pixel_format == 1:
            for x in range(width):
                b, g, r = row[x * 4:x * 4 + 3]
                rows.extend((r, g, b))
        else:
            for (value,) in struct.iter_unpack("<H", row[:width * 2]):
                if pixel_format == 2:
                    r, g, b = value >> 11, (value >> 5) & 63, value & 31
                    rows.extend(((r << 3) | (r >> 2), (g << 2) | (g >> 4), (b << 3) | (b >> 2)))
                else:
                    r, g, b = (value >> 10) & 31, (value >> 5) & 31, value & 31
                    rows.extend(((r << 3) | (r >> 2), (g << 3) | (g >> 2), (b << 3) | (b >> 2)))
    def chunk(kind, data):
        return struct.pack(">I", len(data)) + kind + data + struct.pack(">I", zlib.crc32(kind + data))
    path.write_bytes(b"\x89PNG\r\n\x1a\n" + chunk(b"IHDR", struct.pack(">2I5B", width, height, 8, 2, 0, 0, 0))
                     + chunk(b"IDAT", zlib.compress(rows)) + chunk(b"IEND", b""))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--core", required=True, type=Path)
    parser.add_argument("--rom", type=Path, default=Path("dqix_usa.nds"))
    parser.add_argument("--output", required=True, type=Path)
    parser.add_argument("--frames", type=int, default=1200)
    parser.add_argument("--capture-every", type=int, default=300)
    parser.add_argument("--inputs", type=Path, help='JSON list: {"start":0,"end":10,"buttons":["a"]}')
    parser.add_argument("--load-state", type=Path)
    parser.add_argument("--load-save", type=Path, help="Cartridge .dsv save, loaded by a fresh emulator process")
    args = parser.parse_args()
    if sys.platform != "win32" or C.sizeof(C.c_void_p) != 8:
        parser.error("This minimal frontend currently supports Windows x64 only")
    if args.frames <= 0 or args.capture_every <= 0:
        parser.error("Frame counts must be positive")
    args.output.mkdir(parents=True, exist_ok=True)
    output = args.output.resolve()
    system = output / "system"
    system.mkdir(exist_ok=True)
    directory_bytes = str(system).encode()
    save_bytes = str(output).encode()
    events = json.loads(args.inputs.read_text()) if args.inputs else []
    for event in events:
        if not 0 <= event["start"] < event["end"]:
            parser.error("Input events must have nonnegative start < end")
        if any(name not in BUTTONS for name in event.get("buttons", [])):
            parser.error("Unknown joypad button")
        if "touch" in event and not (len(event["touch"]) == 2 and
                0 <= event["touch"][0] < 256 and 0 <= event["touch"][1] < 384):
            parser.error("Touch coordinates must be within the 256x384 dual-screen image")
    save_path = output / (args.rom.stem + ".dsv")
    if args.load_save:
        if args.load_save.resolve() != save_path.resolve():
            shutil.copy2(args.load_save, save_path)
    initial_save_hash = sha256(save_path) if save_path.is_file() else None
    variables = {}
    overrides = {b"desmume_internal_resolution": b"256x192", b"desmume_num_cores": b"1",
                 b"desmume_pointer_mouse": b"enabled", b"desmume_pointer_type": b"touch",
                 b"desmume_opengl_mode": b"disabled", b"desmume_load_to_memory": b"enabled"}
    frame = 0
    pixel_format = 0
    latest = None

    @LOG
    def log(level, format_string):
        # On the tested Windows x64 ABI extra varargs may be ignored. Do not
        # interpret the format string without its arguments.
        pass

    @ENV
    def environment(command, data):
        nonlocal pixel_format
        command &= 0xffff
        if command == 3:  # GET_CAN_DUPE
            C.cast(data, C.POINTER(C.c_bool))[0] = True
        elif command in (9, 31):  # system/save directory
            C.cast(data, C.POINTER(C.c_char_p))[0] = directory_bytes if command == 9 else save_bytes
        elif command == 10:
            value = C.cast(data, C.POINTER(C.c_int))[0]
            if value not in (0, 1, 2):
                return False
            pixel_format = value
        elif command == 15:
            variable = C.cast(data, C.POINTER(Variable)).contents
            variable.value = overrides.get(variable.key, variables.get(variable.key))
            return variable.value is not None
        elif command == 16:
            entries = C.cast(data, C.POINTER(Variable))
            index = 0
            while entries[index].key:
                key, description = entries[index].key, entries[index].value
                variables[key] = description.split(b"; ", 1)[1].split(b"|", 1)[0]
                index += 1
        elif command == 17:
            C.cast(data, C.POINTER(C.c_bool))[0] = False
        elif command in (39, 52):  # language, core option version (legacy variables)
            C.cast(data, C.POINTER(C.c_uint))[0] = 0
        elif command == 27:  # GET_LOG_INTERFACE; core calls this unconditionally
            C.cast(data, C.POINTER(C.c_void_p))[0] = C.cast(log, C.c_void_p)
        elif command in (11, 18, 35):  # input descriptors, no-game support, controller info
            pass
        else:
            return False
        return True

    @VIDEO
    def video(data, width, height, pitch):
        nonlocal latest
        if data and (frame % args.capture_every == 0 or frame == args.frames - 1):
            latest = (C.string_at(data, pitch * height), width, height, pitch, pixel_format)

    @AUDIO
    def audio(left, right):
        pass

    @BATCH
    def batch(data, frames):
        return frames

    @POLL
    def poll():
        pass

    @INPUT
    def input_state(port, device, index, button):
        if port != 0:
            return 0
        active = [event for event in events if event["start"] <= frame < event["end"]]
        if device == 6:
            touch = next((event["touch"] for event in active if "touch" in event), None)
            if touch is None:
                return 0
            if button == 2:
                return 1
            if button in (0, 1):
                return int(touch[button] / (256 if button == 0 else 384) * 65536 - 32768)
            return 0
        if device != 1:
            return 0
        return int(any(event["start"] <= frame < event["end"] and
                       button in [BUTTONS[name] for name in event.get("buttons", [])] for event in active))

    core = C.CDLL(str(args.core.resolve()))
    for name, callback, signature in (("environment", environment, ENV), ("video_refresh", video, VIDEO),
                                     ("audio_sample", audio, AUDIO), ("audio_sample_batch", batch, BATCH),
                                     ("input_poll", poll, POLL), ("input_state", input_state, INPUT)):
        function = getattr(core, "retro_set_" + name)
        function.argtypes = [signature]
        function(callback)
    core.retro_load_game.argtypes = [C.POINTER(Game)]
    core.retro_load_game.restype = C.c_bool
    core.retro_get_system_info.argtypes = [C.POINTER(SystemInfo)]
    core.retro_serialize_size.restype = C.c_size_t
    core.retro_serialize.argtypes = [C.c_void_p, C.c_size_t]
    core.retro_serialize.restype = C.c_bool
    core.retro_unserialize.argtypes = [C.c_void_p, C.c_size_t]
    core.retro_unserialize.restype = C.c_bool
    core.retro_init()
    info = SystemInfo()
    core.retro_get_system_info(C.byref(info))
    path_bytes = str(args.rom.resolve()).encode()
    rom_bytes = None if info.need_fullpath else C.create_string_buffer(args.rom.read_bytes())
    game = Game(path_bytes, C.cast(rom_bytes, C.c_void_p) if rom_bytes else None,
                args.rom.stat().st_size if rom_bytes else 0, None)
    if not core.retro_load_game(C.byref(game)):
        raise RuntimeError("Core rejected ROM")
    if args.load_state:
        state = C.create_string_buffer(args.load_state.read_bytes())
        if not core.retro_unserialize(state, len(state) - 1):
            raise RuntimeError("Core rejected saved state")
    manifest = {"core": info.name.decode(), "version": info.version.decode(),
                "core_sha256": sha256(args.core), "rom_sha256": sha256(args.rom),
                "rom_sha1": hashlib.sha1(args.rom.read_bytes()).hexdigest(),
                "frames_requested": args.frames, "input_events": events,
                "loaded_state": str(args.load_state) if args.load_state else None,
                "loaded_state_sha256": sha256(args.load_state) if args.load_state else None,
                "initial_cartridge_save_sha256": initial_save_hash,
                "captures": [], "automatic_gameplay_assertions": False}
    started = time.monotonic()
    for frame in range(args.frames):
        latest = None
        core.retro_run()
        if latest is not None:
            capture = output / f"frame-{frame:06}.png"
            png(capture, *latest)
            manifest["captures"].append({"frame": frame, "file": capture.name, "sha256": sha256(capture)})
            print(f"Frame {frame}: {capture.name}", flush=True)
    size = core.retro_serialize_size()
    if size:
        state = C.create_string_buffer(size)
        if core.retro_serialize(state, size):
            (output / "end.state").write_bytes(state.raw)
    manifest["elapsed_seconds"] = time.monotonic() - started
    manifest["frames_executed"] = args.frames
    manifest["variables"] = {key.decode(): overrides.get(key, value).decode() for key, value in variables.items()}
    core.retro_unload_game()
    core.retro_deinit()
    manifest["final_cartridge_save_sha256"] = sha256(save_path) if save_path.is_file() else None
    (output / "manifest.json").write_text(json.dumps(manifest, indent=2) + "\n")


if __name__ == "__main__":
    main()
