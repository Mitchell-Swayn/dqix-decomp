# ARM7 startup boundary inventory

This is a control-flow and data-reference inventory of the startup bytes only. It
uses the verified USA input ROM (`c7c3014c237900c8281289b8bc76a781969b6278`),
`config/usa/arm7/baseline.json`, and `config/usa/arm7/source_units.json`. The raw
listing is reproducible with `tools/disassemble_arm7.py 0x02380000 0x0238021c
--mode arm`; a temporary branch/effective-address audit used Capstone on the
same payload. Runtime addresses below are end-exclusive. This does not establish
the code/data denominator for the rest of ARM7.

| Runtime range | Payload range | Bytes | Classification | Evidence |
| --- | --- | ---: | --- | --- |
| `[0x02380000, 0x023800e4)` | `[0x000, 0x0e4)` | 228 | ARM instructions | Header entry is `0x02380000`; control flow ends at `bx r1` at `0x023800e0`. Calls helpers at `0x02380118` and `0x0238018c`. |
| `[0x023800e4, 0x02380118)` | `[0x0e4, 0x118)` | 52 | Literal pool | Thirteen PC-relative `ldr` instructions in the entry routine reference these thirteen aligned words, including the tail target loaded at `0x02380114`. |
| `[0x02380118, 0x02380184)` and `[0x02380188, 0x0238018c)` | `[0x118, 0x184)` and `[0x188, 0x18c)` | 112 | ARM instructions | Called at `0x023800a0`; internal branches implement descriptor copying and BSS clearing; returns with `bx lr` at `0x02380188`. The unconditional branch at `0x02380180` skips its embedded literal. |
| `[0x02380184, 0x02380188)` | `[0x184, 0x188)` | 4 | Literal pool | PC-relative `ldr` at `0x02380118` references this word, which points to the parameter block at `0x02380204`. |
| `[0x0238018c, 0x023801fc)` | `[0x18c, 0x1fc)` | 112 | ARM instructions | Called at `0x023800c8`; conditional loops and exits remain within the range; returns with `bx lr` at `0x023801f8`. |
| `[0x023801fc, 0x02380204)` | `[0x1fc, 0x204)` | 8 | Literal pool | PC-relative loads at `0x02380190` and `0x023801f0` reference these two words. |
| `[0x02380204, 0x0238021c)` | `[0x204, 0x21c)` | 24 | Initialized parameters | Six aligned words consumed by the entry/copy helper: descriptor-table start/end, copy source, empty startup BSS start/end, and zero-fill value. Values are validated against the two autoload descriptors by `tools/arm7_build.py`. |

The startup partition sums to 540 initialized bytes: 452 instruction bytes, 64
literal-pool bytes, and 24 initialized parameter bytes. Its header BSS size is
zero. The parameter words are `(0x023a8fac, 0x023a8fc4, 0x0238021c,
0x0238021c, 0x0238021c, 0)`. The autoloads' runtime BSS ranges are separate
and recorded in
`config/usa/arm7/source_units.json`; they are not payload bytes and are not
included in this startup sum. The three instruction-bearing routines are
confirmed for this bounded range, but their original source-language origin has
not been established. They are not reviewed assembly exceptions or C source
coverage. No complete function count is inferred for either autoload or for the
ARM7 payload as a whole.

This inventory does not classify the rest of startup-adjacent/autoload bytes,
assign source ownership, or discover indirect targets. Direct branches and
PC-relative data references suffice for these three routines, but a whole-module
inventory still needs broader disassembly, function-boundary validation, and
separate initialized-data/BSS analysis.
