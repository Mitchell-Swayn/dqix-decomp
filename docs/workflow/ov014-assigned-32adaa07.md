# ov014 assigned preview functions

Reconstructed only the six assigned functions in `02184700–02184f10`.
None was already covered at starting revision
`03358014be54535df2a389ed2d28ba83d552465b`.
The packet's `ov014_5` label was absent from this checkout's generated inventory;
the functions were initially in `ov014_7`. The exact source range now owns its
own target object. Other fallback functions and program data remain required work.

`ModelPreview.cpp` describes the partial preview state, selection and transform
record layouts. Names describe observed behavior, rather than established original
names. The member-function dispatch table and initialization guard remain external
program-data dependencies. No definitions or coverage for those data were added.
The third adjustment byte aliases the animation-switch flag, as in the original
draw-loop addressing. Both views occupy the same union storage.

All six functions compare at 100% in `build/preview-review-diff.json` against
newly delinked exact-range original objects. `ninja -j2 rom check report sha1`
passes for the final source; verbose evidence is in
`build/preview-acceptance-final.log`. ROM SHA-1:
`c7c3014c237900c8281289b8bc76a781969b6278`.
No gameplay tests were performed. No assembly or binary substitutes were added.

## Cumulative unproductive source variants

Prior attempts were empty. Read commands, identical recompilations, target-range
regeneration and relocation-only differences between differently scoped objects
are excluded. The first candidate's unsupported layout assertion caused a compiler
failure for all four functions then present and counts once for each.

| Function | Unproductive variants | Evidence and successful hypothesis |
| --- | ---: | --- |
| `func_ov014_02184700` | 1 | Initial register order and local member-pointer copy differed. Declaration order, two explicitly ordered vector temporaries, byte flag update and direct table dispatch match. |
| `func_ov014_02184a64` | 2 | Local sprite pointer retained through draw caused multiply-add; direct repeated stores reloaded the base. A local pointer for stores, recomputed draw argument and zero initialization before the selection expression match. |
| `func_ov014_02184c08` | 1 | Unsupported assertion only; first compiled transform source matches. |
| `func_ov014_02184d08` | 1 | Unsupported assertion only; first compiled cancellation source matches. |
| `func_ov014_02184dcc` | 9 | Assertion, combined increment/mask, callee return declaration, promoted signed modulo, unsigned modulo, local byte increment/mask, explicitly unsigned local modulo, full-width bitfield and wider index temporary. Separate byte assignment followed by masking matches on variant ten. |
| `func_ov014_02184e3c` | 1 | Unsupported assertion only; first compiled cycling source matches after exact-range relocation comparison. |

Final readability/layout review retained 100% matching. Batch snapshots and elapsed
time are under `build/workflow/ov014_assigned_32adaa07/`; tokens are unmeasured.
No function reached ten unproductive variants. No dependency request is needed.
