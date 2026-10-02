# fleet_ov006: item selection tables

Batch `fleet_ov006_20261002t1544`, baseline
`0ade2646fe7e27eb53d084a9e857334d18b3b47f`. Independent ov006 worker;
no queue edits, shared tooling edits, other-module edits, or integration.

Verified source ranges (end exclusive):

| Range | Function | Instruction bytes | Distinct source variants |
| --- | --- | ---: | ---: |
| 0215919c–021591c4 | category ID array accessor | 40 | 1 |
| 021591c4–021591ec | category quantity array accessor | 40 | 1 |
| 021591ec–02159218 | category count accessor | 44 | 1 |
| 02159218–02159274 | scan current category for positive IDs | 92 | 1 |
| 02159274–02159320 | extract selected category, ID, quantity | 172 | 9 |
| 0215951c–02159564 | reset eight-entry paging, minimum one page | 72 | 1 |

Symbols retain their address-derived names. `ItemSelection` is a descriptive
partial controller layout, not a recovered original class name. Original
disassembly from `dsd dis` and ov006 relocation maps establish the behavior.
The allocator at 021576a0 creates two nine-pointer tables (0x24 bytes each)
and nine unsigned 16-bit counts (0x12 bytes). Each ID array is allocated at
twice its capacity and filled with -1; quantity arrays use one byte per entry.
The population/reset callers at 02158de0, 02158fd8 and 02159108 confirm signed
IDs, unsigned quantities/counts, and the table relationships. Callers
02159320/021593b0 consume the selected quantity; 0215943c and 0215f740 use
the count and IDs. Category control is offset by 0x5b, entry control by 0x64.
Negative category access yields null/zero; the original does not clamp upper
indices. Preserve the signed 16-bit conversion before testing the category.

The selected-entry extractor matched on variant 9: initialize an unsigned
16-bit index from `page * 8`, then compound-add `entryControl - 0x64`.
Variant 1 was 93.02%; variants 2–5 and 7–8 were 88.37%; variant 6 was 84.44%.
Explicit page-offset temporaries, inline narrowing, expression reversal,
separate page/row reads, row compound assignment and an explicit mask failed
to reproduce instruction order/register allocation. All drafts and observed
diffs are retained in `build/matching/`; no prior ov006 variants were found.
The other five functions matched their first source hypothesis. There were
10 object comparisons: nine selection-unit candidates and one page unit.
An initial map setup error (duplicate .text sections within one unit) was
resolved by placing the nonadjacent paging range in a separate source file.

Validation: both candidate objects have all six functions at 100%; full
`ninja -j2 rom check report sha1` passed, including every ARM9 module,
symbol checks, ARM7 preservation and ROM SHA-1
`c7c3014c237900c8281289b8bc76a781969b6278`. The independent input ROM's SHA-1
was also checked. `git diff --check` passed. No gameplay test was run.

`work_batch.py` measured 475.151261 seconds (7m55.15s). ARM9 delta:
+6 matched functions, +460 instruction/code bytes, +0 literal bytes,
+0 initialized-data bytes, +0 BSS bytes, +0 assembly bytes. All ARM9
denominators and all ARM7 counters are unchanged. ARM9 report totals became
1,657 matched functions and 219,276 matched code bytes. Token usage is unknown.
Snapshots capture the verified working tree before the final source commit.

Local evidence:

- `build/workflow/fleet_ov006_20261002t1544/{start,finish}.json`
- `build/factory/ov006-acceptance.log`
- `build/factory/ov006-selection-exact.json`, `ov006-pages-exact.json`
- `build/factory/ov006-selection-v1-diagnosis.json`
- Exact selection attempt `build/matching/20261002T154944-e5f736f139874f04985125d74b1ab0c4/`
- Exact paging attempt `build/matching/20261002T154624-ab2daaf064ea41aeb299d3d7e6d0ad29/`
- Original assembly `build/factory/ov006-dis/ov006_4.s`

Remaining required work includes allocation/population of the dynamic tables,
the controller's unreconstructed subobjects, callers, static capacities and
other overlay code/data/BSS. The opaque layout intervals preserve those
subobjects' offsets; this batch emits no controller instance or static arrays.
Original fallback remains for all other functions and data. This is a bounded
family reconstruction, not module completion. No shared header was changed.
