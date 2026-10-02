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

## Continuation: model-group allocator lifecycle

Batch `fleet_ov023_20261003_cont_lifecycle`, based on worker commit
`f88728248e783c750fac6b32b811009194e4fd70`; measured reconstruction/initial acceptance
interval **235.447501 seconds**. Prior source and experiment evidence were
preserved. No inherited failed variants or caps cover these three functions.
One source variant per function matched; no unresolved candidate was accepted.

New source `src/Factory/ov023/ModelGroupLifecycle.cpp` owns instruction/literal
range `[0x021e4e8c, 0x021e4fd8)` and constant data range
`[0x021fd6d4, 0x021fd6fc)`. Original symbols remain unchanged.

| Function suffix | Instructions | Literals | Established operation |
| --- | ---: | ---: | --- |
| 021e4e8c | 140 | 0 | Initialize ten Object3Ds and allocator pointers, twelve task IDs and tail flags |
| 021e4f18 | 76 | 0 | Cancel group tasks, initialize Object3Ds, destroy all eleven allocators |
| 021e4f64 | 112 | 4 | Allocate backing buffers and create ten model allocators plus a 4096-byte auxiliary allocator |

Measured gain: **3 functions, 332 report code bytes** (328 instruction bytes
and 4 literal-pool bytes), **40 initialized read-only data bytes**, zero BSS,
alignment or assembly bytes. All ARM9 denominators and ARM7 counters are
unchanged. Nonselected functions and data retain original fallback.

The full ten-entry unsigned size table is source-defined, including the
non-round sizes 0x23e8 and 0x1b58. This removes the selected allocation routine's
original table dependency. Caller `021e33b4` allocates independent 0xc20-byte
groups and calls initialization, allocator setup and texture-context setup;
`021fc518` repeats this lifecycle for two embedded groups at stride 0xc20.
Teardown callers `021e2f38` and `021fc6cc` were inspected in the original
disassembly. The teardown deliberately calls `Object3D::Initialize`, as the
original code does, before destroying the allocators.

`ModelGroup.h` is local to ov023 and shares the established real Object3D and
SafeAllocator arrays between the two source units. Additional assertions check
the allocator, auxiliary allocator, loading flag and tail-pointer offsets.
The c12 flag is observed gating pending loads in `021e5020`; c14 gates later
updates. Uses of c18 in `021e5020`, `021e540c` and `021e5974` establish a pointer,
but its exact pointee remains unresolved. No cross-module headers changed.
The 794-bf4 region still requires recovery of its ten 0x70-byte texture-context
subobjects before reconstructing the next setup/loading family; no raw-offset
accesses into that region were added by this batch.

The first map experiment incorrectly used two `.text` entries in one delink
unit; dsd rejected that configuration. Its stale-target unpaired comparison at
`20261002T155157-40f321d6ef9144ebbcdf36f52c03891f` is diagnostic only, with no
acceptance credit. Splitting the earlier range into its own source unit retained
the same first source variant and yielded four of four exact symbols. The prior
unit also retained ten of ten exact symbols after the shared-layout move. Final
no-build validation again yielded four of four exact symbols. Thus four tool
comparisons were recorded, of which three are valid matching/regression checks;
there were no failed source variants to carry into the next batch. After the
measured snapshot, two further candidate comparisons checked removal of trailing
blank lines from the new files: four of four lifecycle symbols and ten of ten
prior symbols remained exact. Total comparisons: six, five valid and one
rejected-map diagnostic; still one source variant per new function.

Acceptance: `ninja -j2 rom check report sha1` exited successfully, with full
module and symbol checks, ARM7 baseline verification, input/output isolation
guards and exact USA SHA-1 `c7c3014c237900c8281289b8bc76a781969b6278`.
The original input SHA-1 was rechecked independently. The full acceptance rerun
after whitespace cleanup also passed. `git diff --cached --check` passed.
No gameplay/runtime tests; token usage unmeasured. No merge or queue edits.

Ignored local evidence:

- `build/workflow/fleet_ov023_20261003_cont_lifecycle/{start,finish}.json`
- `build/factory/fleet_ov023_dis/ov023_4.s` (original disassembly and callers)
- `build/factory/fleet_ov023_cont_lifecycle_evidence.json`
- `build/factory/fleet_ov023_cont_lifecycle_final_evidence.json`
- `build/factory/fleet_ov023_cont_lifecycle_postcleanup_evidence.json`
- `build/factory/fleet_ov023_cont_lifecycle_diff.json` (zero mismatches)
- `build/factory/fleet_ov023_cont_acceptance.log`
- `build/factory/fleet_ov023_cont_final_acceptance.log`
- `build/matching/20261002T155234-fde9c1ecceee45c68436ee7a59d71475/`
- `build/matching/20261002T155254-ef24ef908c774f8eb4057ecec7e4d8d2/`
- `build/matching/20261002T155351-be2ee6d61f524ecba1d7731795f2c912/`
- `build/matching/20261002T155616-5724d6448c694b32be9d4266121004e2/`
- `build/matching/20261002T155616-bc716b57715f404c8621e4ce0cadfdeb/`

Remaining required work: texture-context layout/setup and its two backing
tables, model loading/drawing, unselected group methods/data, exact flag and
Object3D field meanings. This batch does not complete ov023. Snapshots precede
the source commit and are worker-local evidence, not integrated-main coverage.
The measured interval excludes the later documentation/whitespace cleanup and
its final validation rerun.
