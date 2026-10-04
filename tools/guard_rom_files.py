"""Reject aliased ROM outputs before invoking a writer."""
import argparse
from pathlib import Path
import subprocess
import sys


def check_paths(inputs, outputs):
    for index, output in enumerate(outputs):
        if output.is_symlink():
            raise ValueError(f"ROM output must not be a symbolic link: {output}")
        if output.exists() and output.stat().st_nlink > 1:
            raise ValueError(f"ROM output has multiple hard links: {output}")
        for other in [*inputs, *outputs[:index]]:
            if output.resolve() == other.resolve() or (
                output.exists() and other.exists() and output.samefile(other)
            ):
                raise ValueError(f"ROM output aliases another ROM path: {output} / {other}")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--input", type=Path, action="append", default=[])
    parser.add_argument("--output", type=Path, action="append", required=True)
    parser.add_argument("command", nargs=argparse.REMAINDER)
    args = parser.parse_args()
    try:
        check_paths(args.input, args.output)
        command = args.command
        if command[:1] == ["--"]:
            command = command[1:]
        return subprocess.call(command) if command else 0
    except (OSError, ValueError) as error:
        print(f"ROM file isolation FAIL: {error}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    sys.exit(main())
