# Assigned ov003 menu-selection functions

Baseline: `03358014be54535df2a389ed2d28ba83d552465b`. None of the six assigned
functions was already covered. The packet's fallback identity `ov003_5` is stale:
the baseline objdiff inventory and original disassembly put these functions in
`ov003_8`. Ownership follows the exact assigned names and addresses.

`src/Factory/ov003/MenuSelection.cpp` owns only `.text
[0x02154fd0, 0x02155618)`, containing the six assigned functions. No other fallback
functions, initialized data, BSS, or assembly are reconstructed. The range has
1,608 reported code bytes: 1,584 ARM instruction bytes and 24 literal bytes.
Partial structure declarations describe existing objects; they allocate no
replacement storage. Field meanings are inferred, not recovered original names.
In particular, the party-object extension at +0x150 and its details' +0x950 text
index remain partial views independent of the existing shorter GameObject view.

| Function | Bytes | Inferred behavior | Cumulative unproductive variants |
| --- | ---: | --- | ---: |
| func_ov003_02154fd0 | 76 | Draw active menu and touch menu | 0 |
| func_ov003_0215501c | 192 | Position touch cursor from selected menu entry | 1 |
| func_ov003_021550dc | 300 | Read confirmation and update touch selection | 0 |
| func_ov003_02155208 | 176 | Read cancellation from buttons or touch menu | 0 |
| func_ov003_021552b8 | 712 | Display party-specific message and advance message state | 2 |
| func_ov003_02155580 | 152 | Initialize page, selection and touch mode | 1 |

Prior attempts were empty. Three distinct source candidates were compiled.
Unchanged exact functions in later compilations are not additional variants.
The first candidate matched three functions. Reversing independent coordinate
adjustments recovered cursor register allocation; chaining the two assignments
of selection 6 recovered initialization scheduling. The message function's
inline conversion and then an int intermediate both differed in narrowing
register allocation. A short intermediate recovered those instructions.
The remaining two reported message differences were defined-versus-undefined
references to functions outside the assigned range; the regenerated dedicated
target object resolved these, without reconstructing the callees or altering
comparison inputs. All six dedicated target symbols then compared at 100%.
No function reached the ten-variant cap; no dependency task is requested.

Verification: `ninja -j2 rom check report sha1` passed the configured ARM9 module
and symbol checks, ARM7 verification/packaging, and ROM SHA-1
`c7c3014c237900c8281289b8bc76a781969b6278`. The original input SHA-1 was independently
verified. Runtime tests were not performed. `git diff --check` passed.

`work_batch.py` measured 322.175943 seconds through the finish snapshot, before
the documentation/source commit. Worker report deltas: functions +6, code +1608,
data +0. ARM7 counters and every coverage denominator were unchanged. Token usage
was not measured. Queue state was not edited.

Verbose evidence is under ignored `build/`: `assigned-dis/`,
`menu-v1.json`, `menu-v2.json`, `menu-v3.json`, `menu-exact.json`,
`menu-compile.log`, `menu-configure.log`, `menu-build.log`,
`menu-acceptance.log`, and `workflow/ov003_assigned_5/{start,finish}.json`.
Referenced external callees and program-owned data retain their existing source
or fallback status; this result does not claim completion of ov003.
