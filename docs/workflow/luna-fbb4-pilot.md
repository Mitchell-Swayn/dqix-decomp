# Luna GameState chunk-copy helper

The whole-task clock began at `2026-10-02T10:42:17Z`, before branching from
current main `84c272e6de5c6a30f312c43e4b5fa263e3e85c6a` and reconfiguring the
clean worker. Validated completion and the coverage snapshot were recorded at
`2026-10-02T10:51:36.752795Z`, 559.75 seconds after start. The separate
`tools/work_batch.py` interval was 419.712 seconds. Prior batch commit
`809e1f3` remains preserved in its existing branch and is already in the main
source tree.

Fresh original disassembly confirmed `func_0200fbb4` spans 328 bytes and returns
the destination pointer. Its observed 112-byte layout is kept neutral: a u16 at
0x00; bytes 0x02..0x0a; signed byte 0x0b; bytes 0x0c..0x0e; an untouched gap at
0x0f; a 12-byte aligned aggregate at 0x10; signed halfwords at 0x1c and 0x1e;
four 32-bit words at 0x20..0x2f; a 48-byte aligned aggregate at 0x30..0x5f;
bytes 0x60..0x69; signed halfwords at 0x6a and 0x6c; byte 0x6e; and an
untouched gap at 0x6f. No gameplay or save-data meaning is assigned to this
layout.

The source uses a local layout type and ordinary C++ aggregate assignment.
MWCC's implicit memberwise copy body matches the target when temporarily mapped
for investigation, but without inlining it appears as a second, differently
named operator symbol and is not an acceptable match. The final source retains
`#pragma always_inline on`; this embeds that same compiler-generated memberwise
copy inside the required C-linkage function. No assembly, config-level symbol
remapping, binary substitution, or credit from the temporary analysis mapping is
used.

| Candidate | Result |
| ---: | --- |
| 1 | Whole-layout assignment emitted a separate mangled copy-operator symbol. No function match. |
| 2 | `auto_inline` pragma kept the extra symbol. |
| 3 | `inline_depth(1)` kept the extra symbol. |
| 4 | `always_inline` with the preceding pragmas produced a single 100% symbol. |
| 5 | Removing the unnecessary pragmas and keeping only `always_inline` remained 100%. |

The final object matches all 328 code bytes (82 ARM instructions), with no
literal/data/BSS bytes. The report delta is +328 matched code bytes and one
function; denominators are unchanged. Full guarded `ninja rom check report sha1`
passed ARM9 main, ITCM, DTCM, all 35 overlays, symbol checks, the ARM7 source
build and preservation baseline, and USA ROM SHA-1
`c7c3014c237900c8281289b8bc76a781969b6278`. No gameplay validation was run.

Verbose builds, per-candidate comparisons, and the temporary analysis mapping
are stored under ignored `build/`; the final object comparison has one symbol at
100%. Token usage was not measured.
