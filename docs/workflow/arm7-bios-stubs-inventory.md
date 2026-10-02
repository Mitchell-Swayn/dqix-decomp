# ARM7 Thumb BIOS-call stub inventory

Two ARM veneers in the startup loop load odd function pointers and use `bx` to
enter Thumb mode. The pointers resolve to exact four-byte routines in the WRAM
autoload:

| Thumb range | Payload range | Instructions | Incoming veneer | Role visible in cartridge bytes |
| --- | --- | --- | --- | --- |
| `[0x03803ebe, 0x03803ec2)` | `[0xc0da, 0xc0de)` | `svc #6; bx lr` | `[0x037f84ac, 0x037f84b4)` loads `0x03803ebf` | Calls BIOS SVC 6 and returns. |
| `[0x03803ef0, 0x03803ef4)` | `[0xc10c, 0xc110)` | `svc #14; bx lr` | `[0x037f84a0, 0x037f84a8)` loads `0x03803ef1` | Calls BIOS SVC 14 and returns. |

The SVC instructions and their return boundaries are directly decoded from the
verified ARM7 payload. The first veneer has three `bl` callers in the entry
loop (`0x037f80b4`, `0x037f80e0`, `0x037f8180`); the second has one
(`0x037f8450`). Each entry ends at its own `bx lr`; neighboring code begins with another SVC
stub. The bytes contain no literal pools or
standalone data. This inventory does not expand to the surrounding stub sequence.

These are cartridge-resident wrappers that invoke supervisor calls handled by
the external ARM7 BIOS. The BIOS implementations are not part of the cartridge
payload. The wrapper form is visible, but no original symbol or object map proves
that these bytes came from a particular SDK; SDK ownership and the SVC API names
remain unresolved. They are not script interpreters. The two four-byte ranges
are instruction inventory only, not C source coverage or reviewed assembly
exceptions. Their bytes are included in the inventory sidecar and must never be
added to source-coverage counters.

`tools/audit_arm7_bios_stubs.py` reproduces the reference walk from the verified
ROM: it checks the ARM veneers, their PC-relative literal values, direct call
sites from the startup loop, Thumb mode targets, and the exact `svc; bx lr`
sequences. Run it with the original USA ROM at `extract/baserom_dqix_usa.nds`, or
run `python -m unittest discover -s tools -p test_audit_arm7_bios_stubs.py` for
unit checks and an integration check when the ROM is present. Its output explicitly
credits zero source coverage. The broader ARM7 code/data/function denominator
remains unknown.
