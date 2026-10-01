# Runtime observations, 2026-10-02

The rebuilt USA ROM was exercised with a local DeSmuME libretro frontend.
This is a limited gameplay smoke test, separate from code/module matching.
It is not complete game acceptance.

## Environment and evidence

- Windows x64, Python 3.11.15; `tools/runtime_smoke.py` provides software video,
  scripted joypad/touch inputs, cartridge save directories and local screenshots.
- Core: DeSmuME `git 95b4d79`, from the official
  [libretro Windows x64 build directory](https://buildbot.libretro.com/nightly/windows/x86_64/latest/).
  DLL SHA-256: `0fe7664ffdc626bca548dc03f7d1907569474175ff13e131de1cf3aaf555f399`.
  The nightly URL is mutable; verify this hash to reproduce this environment.
- Interpreter CPU, software rasterizer, native 256x192 screen resolution,
  top/bottom display, no external BIOS, built-in firmware, no Wi-Fi emulation.
  Audio samples were discarded, so sound correctness was not evaluated.
- Exact rebuilt ROM SHA-1: `c7c3014c237900c8281289b8bc76a781969b6278`;
  SHA-256: `a5bbe96f69256d973c145d92e69bb8813b6f07edf28abfd9d69b9c2c75599b32`.
  Earlier exploratory runs used the identical program payload with the historical
  four-byte header-checksum difference. The archived opening and reload records
  below use the exact-hash ROM.
- [Opening manifest](verification/runtime/opening.json),
  [field/menu manifest](verification/runtime/field-menu.json),
  [fresh cartridge reload manifest](verification/runtime/quick-reload.json).
  These record input timing, core/ROM hashes, capture hashes and configuration.
  They contain metadata, not game binaries, saves or screenshot payloads.

Screenshots, emulator states and generated cartridge saves remain locally under
`build/runtime/`; they are deliberately excluded from source commits. Images
were visually inspected, not merely inferred from a process exit code.

## Observed results

| Scenario | Observation | Local evidence |
|---|---|---|
| Boot/title | Title art and new-adventure menu displayed | `menu/frame-000599.png` |
| New game | Character model and customization menu rendered; defaults and name `1` accepted | `newgame/frame-000599.png`, `character/frame-000399.png` |
| Opening script | Dialogue/cutscenes progressed into the first battle and Observatory | `exact-rom/frame-016000.png`, `exact-rom/frame-021999.png` |
| Battle | Enemy turn, Aquila's attack and damage text rendered; party progressed beyond battle | `opening/frame-007199.png`, `exact-rom/frame-014000.png` |
| Field movement | Up input moved the character up the Observatory stairs; map/player position changed | `field-menu/frame-000060.png` |
| Menus | X opened the field menu; Misc. options and Quick Save confirmation displayed | `field-menu/frame-000359.png`, `misc/frame-000239.png`, `quicksave/frame-000239.png` |
| Quick Save/reload | Game wrote a quick log; a fresh emulator process detected it, loaded it, and restored the same Observatory location | `reload/frame-001799.png`, `reload-confirmed/frame-003599.png` |

The fresh reload used only the generated cartridge `.dsv` file, **no emulator
state**. The earlier exploratory menu stages did use emulator states to avoid
replaying the opening. Cartridge save SHA-256 after Quick Save was
`27489c308ffe9563afeaee6a64590476dc16fa5eecc364cc5dac8ae87328116e`.
Quick Save is not a substitute for testing ordinary church saves, multiple save
cycles, error recovery or later story progression.

## Reproduction

Supply the separately installed matching libretro DLL, build the exact ROM, and
use an empty output directory for a fresh session:

```powershell
.\.venv\Scripts\python.exe tools/runtime_smoke.py --core build/runtime-tools/desmume_libretro.dll --output build/runtime/replay-opening --inputs docs/verification/runtime/opening-inputs.json --frames 22000 --capture-every 2000
```

For an existing generated Quick Save, start a fresh emulator process:

```powershell
.\.venv\Scripts\python.exe tools/runtime_smoke.py --core build/runtime-tools/desmume_libretro.dll --output build/runtime/replay-reload --load-save build/runtime/saved/dqix_usa.dsv --inputs docs/verification/runtime/reload-inputs.json --frames 3600 --capture-every 1200
```

The save is not distributed; create it through the in-game Misc. > Quick Save
menu. Input files use half-open frame intervals. Joypad names are `a`, `b`, `x`,
`y`, `start`, `select`, directions, `l`, `r`. A `touch: [x, y]` event uses the
combined 256x384 display coordinates. The runner records observations and does
not automatically label screenshots as gameplay passes.

## Remaining acceptance tests

Ordinary saves, additional battles/abilities/status effects, inventories and
equipment, grotto generation, representative later scripted events, multiplayer,
communication and late-game paths remain untested. No physical DS hardware test
was performed. No claim is made that early-game success covers those paths.

## Progress images

On Windows, after a successful `ninja rom check report sha1`, run
`powershell -NoProfile -File tools/progress_image.ps1`. The generated
`build/progress/latest.png` reads the ARM9 and ARM7 reports and hashes the rebuilt
ROM. Its bars describe matching coverage, including pre-existing ARM9 assembly;
they are separate from gameplay evidence and are not an estimate of effort.
The command uses Windows System.Drawing without additional Python packages.
