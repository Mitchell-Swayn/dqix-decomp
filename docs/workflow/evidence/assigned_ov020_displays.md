# Assigned ov020 display functions

Starting revision: `03358014be54535df2a389ed2d28ba83d552465b`.
None of the four assigned functions was already source-covered. The packet's
`ov020_4` identity was stale: current inventory placed `0218c98c` in `ov020_2`
and the other three in `ov020_3`. Only their exact text ranges were replaced.

| Function | Text bytes | Instructions | Literals | Cumulative unproductive variants |
| --- | ---: | ---: | ---: | ---: |
| func_ov020_0218c98c | 984 | 960 | 24 | 2 |
| func_ov020_0218cd98 | 500 | 480 | 20 | 6 |
| func_ov020_0218cf8c | 928 | 908 | 20 | 2 |
| func_ov020_0218d32c | 792 | 756 | 36 | 2 |

Prior attempts supplied in the packet were empty. Before consolidating the
shared controller layout, total compiled variants were respectively 3, 7, 3,
and 4. Each function then had one successful source-consolidation variant.
Successful variants are excluded from the unproductive counts above; shell
and read operations, object-only comparisons and comment rebuilds do not count.
No function reached the ten-unproductive-variant limit.

The controller's 0x20-byte descriptors occupy offsets 0x49c and 0x4bc. Engine
and layer nibbles at descriptor offset 0x1c are established by the BG register
setup and subsequent resource calls. Remaining descriptor fields are explicitly
partial. Local declaration order matters for stack slots and loader/task
registers. A local descriptor pointer gives the original sub-display bitfield
register allocation. The publisher upload descriptor, lengths and entry pointers
form one local record, preserving pointer reloads across the upload calls without
volatile storage. No assembly or binary source substitutes were added.

Hypotheses tested for cd98: direct bitfields (88.8%), nested layout and reordered
parser locals (91.2%), region pointer (92.8%), unsigned-int bitfields (92.0%),
signed-char bitfields (92.0%), region pointer declared at entry (74.4%), then
descriptor pointer (100%). For c98c/cf8c: initial loops (92.68%/92.24%), loader
and array declaration order (97.97%/97.84%), then parser scalar declaration order
(100% each). For d32c: separate locals (89.95%), void-pointer upload interface
(89.95%), volatile entry pointers (100%), then a grouped record without volatile
(100%, retained). Unused planned variants were never compiled.

Final object comparisons: TitleSubDisplay 1/1, TitleMainDisplay 1/1 and
TitleLogoDisplays 2/2 symbols at 100%. Existing title functions remain exact.
`ninja -j2 rom check report sha1` passed for the final sources, including all
module/symbol checks and ARM7 preservation. Original input and generated ROM
SHA-1 both equal `c7c3014c237900c8281289b8bc76a781969b6278`.
`git diff --check` passed. Gameplay was not tested.

Coverage delta: +4 functions and +3,204 text bytes, comprising 3,104 instruction
bytes and 100 literal bytes. Initialized data, rodata, BSS, assembly and ARM7
deltas are zero. Function, code and data denominators are unchanged. Referenced
archive names, selection tables, scratch storage and external helpers remain
external dependencies; their original fallback storage receives no source credit.
All other overlay code remains outside this assignment and required work.

Verbose disassembly, candidate variants and diffs are under ignored
`build/assigned-dis/`, `build/Title*`, and `build/matching/`. Acceptance logs are
`build/assigned-baseline.log` and `build/assigned-acceptance-final.log`.
Batch measurement is `build/workflow/assigned_ov020_subdisplay/`; its clock
starts after the first function's exploratory candidates and excludes that
initial exploration. Token usage was not measured. Queue state was not edited.
