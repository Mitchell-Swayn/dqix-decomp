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

## Continuation: requested quantities and pending selections

Batch `fleet_ov006_20261003t_continuation`, baseline
`37f19f2096caeef41b03995285b62ace3b1eb228`. Previous handoff, local attempt
ledger, original ov006 symbols/delink map, and queue ownership were inspected.
These five functions had no earlier variants or deferred caps. No queue,
other-module, compiler, environment, or original comparison input was changed.

Verified ranges (end exclusive):

| Range | Observed behavior | Instruction bytes | Source variants |
| --- | --- | ---: | ---: |
| 02159094–02159108 | Restore the last occupied pending slot and clear it | 116 | 1 |
| 02159108–0215919c | Subtract matching ID quantities and record the first empty pending slot | 148 | 1 |
| 02159320–021593b0 | Increase requested quantity, cap to selected quantity and mark change | 144 | 1 |
| 021593b0–0215943c | Decrease requested quantity, replace zero with one and mark change | 140 | 1 |
| 02159564–021595b4 | Update active entry control, refresh changed entry and normalize input result | 80 | 1 |

Original assembly establishes three parallel arrays in the controller:
unsigned 16-bit categories at 0x372, signed 16-bit IDs at 0x378, and unsigned
byte quantities at 0x38c. Initialization at 02157a60 clears categories and
quantities and sets all three IDs to -1. Restore traverses slots 2 through 0,
calls the existing table insertion helper with the category narrowed to a byte,
then clears only the first occupied slot it finds. Subtraction traverses the
entire category array without breaking after an ID match, then records the
first slot whose ID is nonpositive. It preserves the original unsigned byte
subtraction behavior and does not change category counts.

The caller at 0215c040 passes category 0x38a, selected ID 0x370 and requested
quantity 0x38b to subtraction. Input handling at 02159834 confirms the increase
and decrease helpers and direction flags at 0x430/0x431. Both helpers cap the
extracted available quantity at nine before adjusting the requested byte.
The local four-byte `SelectedItem` record preserves extractor outputs and
their stack layout. The menu pointer at 0x14 remains an explicitly incomplete
external type: 02080fa8 writes a looked-up integer value, and 020813ec returns
an integer status. Their implementation and complete menu layout remain fallback.
The active-control pointer at 0x44 and previous-control value at 0x35e are
established by 02159564 and its original updater at 0215f3d8. Descriptive names
are reconstruction names; address-derived function symbols remain unchanged.

All five functions matched their first source hypothesis, in three candidate
object comparisons. Two additional compatibility comparisons confirmed the
previous six functions still match after the local header extension: five
comparison invocations total. No failed source hypothesis or additional variant
was discarded. `factory_diff.py` reports no differences for the pending pair.
No new storage is emitted for the partial controller layout or pending arrays.

Full `ninja -j2 rom check report sha1` passed, including all configured ARM9
modules, symbols, ARM7 preservation and ROM SHA-1
`c7c3014c237900c8281289b8bc76a781969b6278`. The independent original input SHA-1
also passed. `git diff --check` passed. No gameplay test was run.

`work_batch.py` measured 245.882185 seconds (4m05.88s) through acceptance,
before handoff documentation and commit. ARM9 delta: +5 matched functions,
+628 instruction/code bytes; +0 literal, initialized-data, BSS and assembly
bytes. All denominators and ARM7 counters are unchanged. ARM9 report totals:
1,662 matched functions, 219,904 matched code bytes, 66,724 matched data bytes.
Token usage is unknown. These are worktree results, not integrated main gains.

Local evidence:

- `build/workflow/fleet_ov006_20261003t_continuation/{start,finish}.json`
- `build/factory/ov006-cont-acceptance.log`
- `build/factory/ov006-{quantity,update,pending}-exact.json`
- `build/factory/ov006-pending-v1-diagnosis.json`
- Quantity: `build/matching/20261002T155502-8322dbbb1a4f4a24a0aaf7d4713500e2/`
- Entry update: `build/matching/20261002T155502-4e86149852c140bdbeaa2d45fb8f6915/`
- Pending slots: `build/matching/20261002T155611-e36b9cafe1c746319a7fcc8a119e5e60/`
- Prior compatibility: `build/matching/20261002T155700-76801cf88f1d476aa31c8f3bf3266519/`
  and `build/matching/20261002T155700-09f426618e9f45f0a8ad1750126985df/`
- Original disassembly: `build/factory/ov006-dis/ov006_4.s` and `main_81.s`

Remaining required dependencies include insertion at 02158fd8 and its static
capacity table, allocation/population, entry setup at 0215943c, input handling
at 021595b4, display/update routines at 0215f3d8/0215f4dc/0215f740, menu layout,
controller subobjects, and original overlay data/BSS. They retain fallback;
this batch makes no module-completion or runtime-validation claim.
