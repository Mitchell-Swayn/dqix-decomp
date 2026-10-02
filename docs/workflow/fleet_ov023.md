# ov023 model-group reconstruction

Batch: `fleet_ov023_20261003_0148`; measured reconstruction/acceptance interval
315.986028 seconds. One code variant per function; two object comparisons
(initial compile and final no-build validation). No inherited attempt records
or caps were found for this module in this worktree. Token usage is unmeasured.

Accepted source: `src/Factory/ov023/ModelGroup.cpp`, end-exclusive instruction
range `0x021e6088–0x021e61f4`. All ten symbols match 100%:

| Function suffix | Bytes | Established operation |
| --- | ---: | --- |
| 021e6088 | 60 | Copy rotation to model slots 0, 6, 1, 5 |
| 021e60c4 | 28 | Copy three rotation components to Object3D |
| 021e60e0 | 92 | Set those four slots to a Y-only rotation |
| 021e613c | 20 | Return an Object3D rotation by value |
| 021e6150 | 8 | Store the byte at group offset c11 |
| 021e6158 | 20 | Invalidate one model slot's signed field at offset 2 |
| 021e616c | 40 | Invalidate all ten slots |
| 021e6194 | 4 | Preserve existing empty lifecycle hook |
| 021e6198 | 8 | Store the zone-state pointer at c0c |
| 021e61a0 | 84 | Remove nonnegative loader task IDs, reset all twelve to -1 |

Coverage delta: +10 functions, +364 instruction/code bytes; +0 literal pool,
initialized data, BSS, alignment, or assembly bytes. All coverage denominators
are unchanged. The original target object contains only a 364-byte `.text`
payload and ELF metadata; this range has no literal pools. Nonselected functions
and program data retain original fallback. No module-completion claim.

The initializer `021e4e8c` constructs ten contiguous Object3D instances at stride
ac, ten SafeAllocator instances at stride 14 starting at 6b8, an auxiliary
allocator at 780, and twelve task IDs at bf4. Allocation in `021e33b4` uses c20
bytes; `021fc518` independently embeds two groups at the same stride. Existing
shared Object3D fields and layout are used directly. Compile-time assertions
check object size, rotation offset, group size, task array, state pointer and
flag offsets. No shared headers changed.

Caller `021e447c` reads a rotation from one group and applies it to another,
then invalidates selected model slots; `021e4f18` calls the loader-task cleanup.
Call sites and original disassembly are preserved in the evidence below.
The evidence helper's caller list is empty because relocation maps use
`module:overlay(23)` while its symbol lookup uses directory `ov023`; callers
were checked directly against relocation maps and dsd disassembly.

Remaining dependencies: initializer/destructor/loading/drawing functions,
associated constant tables, exact meaning of Object3D `unknown_2_`, c11 flag,
and the unmodeled group region 794–bf4 and trailing fields. These are still
required reconstruction work. The unknown arrays describe unrecovered dynamic
object fields and do not supply binary code or static data. The rotation getter
uses the compiler's hidden return pointer; the setter copies components explicitly
because Vector3i has an existing out-of-line assignment operator.

Validation: `ninja -j2 rom check report sha1` passed all module/symbol checks,
ARM7 baseline verification, ROM input/output isolation guards, and final SHA-1
`c7c3014c237900c8281289b8bc76a781969b6278`. The independent original input's SHA-1
was also rechecked. No gameplay/runtime tests were run for this batch.

Local ignored evidence:

- `build/workflow/fleet_ov023_20261003_0148/{start,finish}.json`
- `build/factory/fleet_ov023_dis/ov023_4.s`
- `build/factory/fleet_ov023_modelgroup_evidence.json`
- `build/factory/fleet_ov023_modelgroup_diff.json` (zero mismatched symbols)
- `build/factory/fleet_ov023_acceptance.log`
- `build/matching/20261002T154621-51a639a2f670489eb585edf2e7f2d298/`
- `build/matching/20261002T154800-5f741c345ae04ea8ab999d1c5d181c5b/`

Batch snapshots were taken before the source commit; their dirty-tree flag and
baseline revision must not be interpreted as an integrated-main measurement.
