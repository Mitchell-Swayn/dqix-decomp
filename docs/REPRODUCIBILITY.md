# Reproducing and verifying the USA build

The starting source revision `94cc9c872266f0a6d15d3fb037fba24b8d3696d6`
was rebuilt on 2026-10-02 (Australia/Sydney) from a Git source archive, a fresh
ROM extraction, and fresh compiler objects. All ARM9 main, ITCM, DTCM, 35 overlay,
and symbol checks passed. This does not establish complete decompilation or
runtime correctness. The ARM7 payload is still supplied by the extracted ROM.

Evidence is in [the manifest](verification/baseline-clean-build.json) and
[the full build log](verification/baseline-clean-build.log). The manifest records
the source revision, input SHA-1, SHA-256 of each matching compiler executable
and DLL, dsd, objdiff, Ninja, Python version, commands, and coverage counters.
No ROM, BIOS, or extracted proprietary data is included in these records.

## Inputs and tools

- USA ROM: `extract/baserom_dqix_usa.nds`, SHA-1
  `c7c3014c237900c8281289b8bc76a781969b6278`.
- For final whole-ROM acceptance, a user-supplied DS ARM7 BIOS:
  `arm7_bios.bin`, SHA-1 `24f67bdea115a2c847c8813a262502ee1607b7df`.
- Python 3.11 or newer and Ninja. This workspace uses `.venv/Scripts/python.exe`
  and `.venv/Scripts/ninja.exe`.
- Matching Metrowerks ARM compiler/linker `2.0/sp2p2` in
  `tools/mwccarm/2.0/sp2p2`, dsd 0.10.2, objdiff 2.7.1. The recorded Windows tool
  hashes can be enforced with `--tool-lock` below. Upstream's compiler download
  URL is mutable, so a version directory alone is not a content pin.
- Linux additionally needs the configured Wine/Wibo runner; this clean-build
  procedure has been exercised on Windows only.

GCC generates decomp.me contexts in the default Ninja workflow; it is not the
matching compiler and is unnecessary for the explicit targets below.

## Fresh build without disturbing the workspace

From the repository root in PowerShell:

```powershell
.\.venv\Scripts\python.exe tools/verify_clean_build.py --revision HEAD --tool-lock docs/verification/baseline-clean-build.json
```

The script resolves a committed revision, verifies the input hashes and tool
hashes, and creates a new directory under `build/verification/`. It archives that
revision, copies only the required external inputs/tools, reconfigures, extracts
the ROM from scratch, and runs `ninja rom check report`. Existing extraction,
objects, generated reports and working-tree edits are not used. The temporary
directory and logs are retained for investigation; the script deletes nothing.
Commit intended source changes before selecting a revision to verify.

After providing the BIOS, require final SHA-1 acceptance with:

```powershell
.\.venv\Scripts\python.exe tools/verify_clean_build.py --revision HEAD --tool-lock docs/verification/baseline-clean-build.json --require-sha1
```

That option fails early if BIOS is absent. With BIOS present the script always
runs `ninja sha1` after the module checks. A missing BIOS produces the explicit
status `module_baseline_passed_final_sha1_blocked`, never whole-ROM acceptance.
The recorded baseline output SHA-1 without BIOS is
`c86d3ee5c7434e9be811ed512f1ef0549acaedc7`, which differs from the target.

For day-to-day incremental checks, `build-usa.cmd` is a local convenience helper,
or activate the environment and run:

```text
python tools/configure.py usa
ninja rom check report
```

This revision has no `ninja min` target. Source map changes require reconfiguration.

## Runtime verification

No emulator or hardware gameplay tests have been performed in this verification
record. Boot, new game, field navigation, battles, menus, save/load, grotto
generation, scripted events, multiplayer, and late-game paths remain untested.
Module equality and a future whole-ROM hash result must be reported separately
from observations of gameplay.
