# ARM7 autoload 0 entry boundary inventory

The startup tail at `0x023800d8` loads its branch target from literal word
`0x02380110`; the verified word is `0x037f8000`. It then loads LR from
`0x02380114` (`0xffff0000`) and executes `bx r1` at `0x023800e0`. The target is
word-aligned, so this transfer enters ARM mode at the first byte of autoload 0
(`wram`). The input ROM SHA-1 is
`c7c3014c237900c8281289b8bc76a781969b6278`; the recorded ARM7 payload SHA-1 is
`a662d5c6a78e990244299926cf6862ce910a475d`.

| Runtime range | Payload range | Bytes | Classification | Boundary evidence |
| --- | --- | ---: | --- | --- |
| `[0x037f8000, 0x037f8478)` | `[0x21c, 0x694)` | 1,144 | ARM instructions | Startup `bx` target. A control-flow walk from the first instruction decodes and reaches all 286 words; conditional branches contribute both paths, calls contribute their fallthrough, and the final unconditional branch at `0x037f8474` loops to `0x037f8450`. No fallthrough reaches the following pool. |
| `[0x037f8478, 0x037f84a0)` | `[0x694, 0x6bc)` | 40 | Literal pool | Ten aligned words are targets of PC-relative `ldr` instructions in the entry loop. |
| `[0x037f84a0, 0x037f84a8)` | `[0x6bc, 0x6c4)` | 8 | ARM call veneer | Called from the entry loop; `ldr ip, [pc]` then `bx ip`. |
| `[0x037f84a8, 0x037f84ac)` | `[0x6c4, 0x6c8)` | 4 | Literal pool | The veneer loads `0x03803ef1`, which selects Thumb mode at `0x03803ef0`. Target function boundary and ownership are not inventoried here. |
| `[0x037f84ac, 0x037f84b4)` | `[0x6c8, 0x6d0)` | 8 | ARM call veneer | Called by the loop at `0x037f8450`; `ldr ip, [pc]` then `bx ip`. |
| `[0x037f84b4, 0x037f84b8)` | `[0x6d0, 0x6d4)` | 4 | Literal pool | The veneer loads `0x03803ebf`, which selects Thumb mode at `0x03803ebe`. Target function boundary and ownership are not inventoried here. |

This bounded `wram` entry scope contains 1,160 instruction bytes and 48 literal
bytes. It has no standalone initialized-data range. The six ranges partition
payload `[0x21c, 0x6d4)` exactly, ending where the existing `BootFlags` source unit
begins. Its runtime BSS is outside this initialized payload scope. The main loop
and two veneers are confirmed code ranges, not C source coverage or reviewed
assembly exceptions; the original language/source of the loop and veneers is
unknown. These byte-class totals describe inventory only and must never be added
to source-coverage counters. A later source reconstruction may overlap the same
bytes without making the underlying partition invalid.

`config/usa/arm7/inventory_ranges.json` records this partition alongside the
previously established startup partition. Run
`python -m unittest discover -s tools -p test_arm7_inventory_ranges.py` to check
that the confirmed scopes reconcile, stay inside their configured payload
regions, keep scopes disjoint, and match their recorded classification byte
totals. Source reconstruction overlap is allowed and does not affect these
partition checks. These totals are never additive to source-coverage counters;
the checks constrain only recorded scopes. The rest of autoload
0, autoload 1, and ARM7-wide code/data/function denominators remain unknown.
