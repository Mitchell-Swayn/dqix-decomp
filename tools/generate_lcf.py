"""Generate dsd's LCF, then add declared absolute linker values.

Pinned dsd 0.10.2 has no absolute-symbol configuration. These values represent
link-time SDK settings, not storage or executable ranges, and add no bytes.
"""
import argparse
import json
import re
import subprocess
from pathlib import Path


def apply_absolute_symbols(lcf_path: Path, symbols_path: Path) -> None:
    if not symbols_path.exists():
        return
    symbols = json.loads(symbols_path.read_text(encoding="utf-8"))
    if not isinstance(symbols, dict):
        raise ValueError("Absolute linker symbols must be a JSON object")
    definitions = []
    for name, value in symbols.items():
        if not re.fullmatch(r"[A-Za-z_][A-Za-z0-9_]*", name):
            raise ValueError(f"Invalid linker symbol name: {name!r}")
        if not isinstance(value, str) or not re.fullmatch(r"0x[0-9a-fA-F]{1,8}", value):
            raise ValueError(f"Expected a 32-bit hexadecimal value for {name}")
        definitions.append(f"    {name} = {value};")
    text = lcf_path.read_text(encoding="utf-8")
    marker = "SECTIONS {"
    if text.count(marker) != 1:
        raise ValueError("Expected exactly one SECTIONS block in generated LCF")
    for name in symbols:
        if re.search(r"\b" + re.escape(name) + r"\s*=", text):
            raise ValueError(f"Linker symbol already defined: {name}")
    lcf_path.write_text(text.replace(marker, marker + "\n" + "\n".join(definitions), 1),
                        encoding="utf-8")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--dsd", type=Path, required=True)
    parser.add_argument("--config-path", type=Path, required=True)
    parser.add_argument("--lcf-path", type=Path, required=True)
    args = parser.parse_args()
    subprocess.run([str(args.dsd.resolve()), "lcf", "--config-path", str(args.config_path)], check=True)
    apply_absolute_symbols(args.lcf_path, args.config_path.parent / "linker_symbols.json")


if __name__ == "__main__":
    main()
