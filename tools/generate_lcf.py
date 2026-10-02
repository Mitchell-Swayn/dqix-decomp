"""Generate dsd's LCF, then add declared absolute values and symbol aliases.

Pinned dsd 0.10.2 has no absolute-symbol configuration. Absolute values represent
link-time SDK settings. Interior aliases identify an element of a source-owned
array and add no storage. MWLD evaluates aliases in order and gives them the
current output section, so each alias follows its owning input object section.
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
    aliases = []
    for name, value in symbols.items():
        if not re.fullmatch(r"[A-Za-z_][A-Za-z0-9_]*", name):
            raise ValueError(f"Invalid linker symbol name: {name!r}")
        if isinstance(value, str) and re.fullmatch(r"0x[0-9a-fA-F]{1,8}", value):
            definitions.append(f"    {name} = {value};")
        elif isinstance(value, dict) and set(value) == {"base", "offset", "object", "section"}:
            patterns = {"base": r"[A-Za-z_][A-Za-z0-9_]*",
                        "offset": r"0x[0-9a-fA-F]{1,8}",
                        "object": r"[A-Za-z_][A-Za-z0-9_]*\.o",
                        "section": r"\.[A-Za-z_][A-Za-z0-9_]*"}
            if any(not isinstance(value[key], str) or not re.fullmatch(pattern, value[key])
                   for key, pattern in patterns.items()) or value["base"] == name:
                raise ValueError(f"Invalid interior linker alias: {name}")
            aliases.append((name, value))
        else:
            raise ValueError(f"Expected a 32-bit hexadecimal value or interior alias for {name}")
    text = lcf_path.read_text(encoding="utf-8")
    marker = "SECTIONS {"
    if text.count(marker) != 1:
        raise ValueError("Expected exactly one SECTIONS block in generated LCF")
    for name in symbols:
        if re.search(r"\b" + re.escape(name) + r"\s*=", text):
            raise ValueError(f"Linker symbol already defined: {name}")
    if aliases:
        # The compiler objects can be built concurrently with this LCF. Check
        # configured module symbols here; the linker and dsd then check the
        # actual object definition and alias module/address during acceptance.
        configured_path = symbols_path.parent / "symbols.txt"
        configured = {line.split()[0] for line in configured_path.read_text().splitlines()
                      if line.strip() and not line.lstrip().startswith("#")}
        for name, alias in aliases:
            if alias["base"] not in configured or name not in configured:
                raise ValueError(f"Interior alias or base missing from module symbols: {name}")
    for name, alias in aliases:
        owner = re.compile(r"(?m)^([ \t]+)" + re.escape(alias["object"])
                           + r"\(" + re.escape(alias["section"]) + r"\)[ \t]*$")
        if len(list(owner.finditer(text))) != 1:
            raise ValueError(f"Expected one owning input section for linker alias: {name}")
        text = owner.sub(lambda match: match.group(0) + "\n" + match.group(1)
                         + f"{name} = {alias['base']} + {alias['offset']};", text)
    if definitions:
        text = text.replace(marker, marker + "\n" + "\n".join(definitions), 1)
    lcf_path.write_text(text, encoding="utf-8")


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
