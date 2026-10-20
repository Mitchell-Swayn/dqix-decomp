#!/usr/bin/env python3
"""Export DQIX item SPR frames to PNG; requires Pillow.

Layout follows Graphics_LoadRResourceFramesPaletteAndGroups.cpp:
frame count/format; frame dimensions and image count; image offsets and encoded
texture dimensions, followed by packed pixels; then RGB555 palette entries.
The animation/group tail is retained in the original file, not interpreted here.
"""
import argparse
import base64
import hashlib
import json
from pathlib import Path
import struct

ROOT = Path(__file__).resolve().parents[1]


def decode_frames(data):
    offset = 0

    def take(size):
        nonlocal offset
        if size < 0 or offset + size > len(data):
            raise ValueError('Truncated SPR image or palette')
        result = data[offset:offset + size]
        offset += size
        return result

    frame_count, pixel_format = struct.unpack('<HH', take(4))
    if not 1 <= frame_count <= 512 or pixel_format not in (3, 4):
        raise ValueError('Unsupported frame count or pixel format (expected indexed 4/8 bpp)')
    frames = []
    for _ in range(frame_count):
        width, height, count = struct.unpack('<HHI', take(8))
        if not 1 <= width <= 1024 or not 1 <= height <= 1024 or count > 4096:
            raise ValueError('Invalid frame dimensions or image count')
        indices = bytearray(width * height)
        for _ in range(count):
            x, y, width_code, height_code = struct.unpack('<HHHH', take(8))
            if width_code > 7 or height_code > 7:
                raise ValueError('Invalid texture dimension code')
            image_width, image_height = 8 << width_code, 8 << height_code
            if x + image_width > width or y + image_height > height:
                raise ValueError('Image rectangle exceeds its frame')
            packed = take(image_width * image_height // (2 if pixel_format == 3 else 1))
            for py in range(image_height):
                for px in range(image_width):
                    index = py * image_width + px
                    value = packed[index // 2] >> (4 * (index & 1)) & 15 if pixel_format == 3 else packed[index]
                    indices[(y + py) * width + x + px] = value
        frames.append((width, height, indices))
    palette_count, = struct.unpack('<I', take(4))
    if not 1 <= palette_count <= 256:
        raise ValueError('Invalid palette length')
    palette = []
    for _ in range(palette_count):
        color, = struct.unpack('<H', take(2))
        channels = [(color >> shift) & 31 for shift in (0, 5, 10)]
        palette.append(tuple((value << 3) | (value >> 2) for value in channels))
    decoded = []
    for width, height, indices in frames:
        pixels = bytearray()
        for index in indices:
            if index >= palette_count:
                raise ValueError('Pixel references missing palette entry')
            pixels.extend((*palette[index], 0 if index == 0 else 255))
        decoded.append((width, height, bytes(pixels)))
    return decoded


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--input-dir', type=Path, default=ROOT / 'extract/usa/files/data/ani')
    parser.add_argument('--output-dir', type=Path, default=ROOT / 'build/assets/item-sprites')
    args = parser.parse_args()
    from PIL import Image, ImageDraw
    inputs = sorted(args.input_dir.glob('d_*.spr'))
    if not inputs:
        parser.error('No d_*.spr files found')
    args.output_dir.mkdir(parents=True, exist_ok=True)
    records, previews = [], []
    for source in inputs:
        payload = source.read_bytes()
        frames = decode_frames(payload)
        names = []
        for index, (width, height, rgba) in enumerate(frames):
            name = source.stem + (f'_frame{index:03}' if len(frames) > 1 else '') + '.png'
            output = args.output_dir / name
            image = Image.frombytes('RGBA', (width, height), rgba)
            image.save(output)
            names.append(name)
            if index == 0:
                previews.append((source.stem, image))
        records.append(dict(source=str(source.resolve()), source_sha256=hashlib.sha256(payload).hexdigest(), png_files=names))
    columns, cell_width, cell_height = 16, 92, 100
    sheet = Image.new('RGB', (columns * cell_width, ((len(previews) + columns - 1) // columns) * cell_height), '#e4e6eb')
    draw = ImageDraw.Draw(sheet)
    for index, (name, image) in enumerate(previews):
        x, y = index % columns * cell_width, index // columns * cell_height
        scaled = image.resize((image.width * 3, image.height * 3), Image.Resampling.NEAREST)
        sheet.paste(scaled, (x + 10, y + 4), scaled)
        draw.text((x + 12, y + 80), name, fill='#17202a')
    sheet.save(args.output_dir / 'contact-sheet.png')
    (args.output_dir / 'manifest.json').write_text(json.dumps(dict(format='PNG RGBA; palette index 0 transparent; RGB555 expanded to RGB888', files=records), indent=2) + '\n')
    items = [dict(name=Path(record['png_files'][0]).stem,
                  src='data:image/png;base64,' + base64.b64encode((args.output_dir / record['png_files'][0]).read_bytes()).decode())
             for record in records]
    template = Path(__file__).with_name('item_sprite_gallery.html').read_text()
    (args.output_dir / 'index.html').write_text(template.replace('__ITEMS__', json.dumps(items, separators=(',', ':'))))
    print(f'Exported {len(records)} item resources ({sum(len(r["png_files"]) for r in records)} PNG frames) to {args.output_dir}')


if __name__ == '__main__':
    main()
