# Matched vector arithmetic

`src/System/VectorMath.cpp` reconstructs five existing C-linkage interfaces in
USA ARM9 range `[0x020c2d90, 0x020c2f18)`: addition, subtraction, inner product,
cross product and length. The 392-byte range matches exactly, including the
compiler-generated eight-byte hardware-register literal pool in the length
function. Objdiff counts the whole range as code and reports five matched
functions. There are no standalone program-data definitions or assembly wrappers.
Existing symbol names and prototypes already described these operations, so no
symbol renaming was needed.

Inputs use the existing signed 20.12 fixed-point vector representation. The dot
product accumulates full-width products before rounding; the cross product rounds
each component after subtraction. All cross-product inputs are captured before
stores, preserving aliasing when output equals either input. Its local declaration
order is deliberately retained because changing it changes Metrowerks register
allocation. Length uses the 64-bit hardware square-root operand mode, retaining an
extra precision bit before rounding back to the existing fixed-point scale. It
does not add locking or overflow handling absent from the original instructions.

Existing callers support these meanings: `Object3D.cpp` adds position vectors,
`ExtendedVectorMath.cpp` subtracts source/target positions, `AnimationProcessing.cpp`
reconstructs rotation basis vectors with cross products, and `Model3D.cpp` and
`RenderCommands.cpp` use lengths for radius/scaling calculations. These operations
appear in the SDK region; their exact original source spelling is not asserted.
`Vector3fix_Normalize` remains binary fallback.

The follow-up `Vector3fix_Distance` implementation in `VectorDistance.cpp` owns
`[0x020c3030, 0x020c30ac)`, another 124 matching bytes including an eight-byte
compiler literal pool. It computes signed component differences, sums their
full-width squares and uses the same hardware square-root rounding as length.
The small inline square helper and captured x difference preserve register
allocation without adding instructions or assembly. Total reconstructed coverage
across these source units is six functions and 516 objdiff code bytes. The intervening
normalization range remains explicitly outside the source mapping.

`FixedPointMath.cpp` reconstructs the adjacent nine hardware arithmetic helpers
at `[0x020c2bf4, 0x020c2d90)`, adding 412 matching objdiff code bytes (including
52 bytes of compiler literal pools). These implement fixed-point quotient and
square-root setup/result conversion, reciprocal setup, full divider-result read,
and integer quotient/remainder. The asynchronous helpers preserve the original
register modes, operand widths and polling. Fixed-point results add their original
rounding constants before shifting; negative/zero square-root input returns zero.
Division error handling and interrupt synchronization are not added.

The full divider-result accessor uses a non-volatile result read after polling the
volatile busy flag, reproducing the original single register-pair load. Other
result accessors retain the observed separate loads. The MMIO addresses are
compiler-generated literal pools, not copied binary fallbacks or global data.
`Object3D`, `AtmosphericEffect`, and `ExtendedVectorMath` callers use fixed-point
division for animation timing, effect scaling and vector/angle operations.

The hardware-helper milestone passed `ninja rom check` and `ninja report` in the
same isolated worktree. All nine functions match after linking, including calls
between newly reconstructed helpers; the entire ARM9 module/symbol verification
also passed. Across the three source units this work now covers 15 functions and
928 matching report bytes, without reducing any denominator.

Validation in the isolated `work/vectors` worktree used the pinned compiler and
ran `ninja rom check`, then `ninja report`. ARM9 main, both autoloads, all 35
overlays, symbol checks and the independent ARM7 checks passed. Each compiled
function was also compared directly with its original instruction/literal bytes.
The report's total code/data/function denominators remained unchanged. This is
matching evidence, not a new runtime gameplay test. The worktree's base predates
the separate ROM header finalization change; final whole-ROM verification belongs
to integration with that change.

The matrix follow-up reconstructs four existing interfaces in separate source
units: 3x3 scale `[0x020c11a4, 0x020c1264)`, 4x3 scale
`[0x020c1948, 0x020c197c)`, 3x3 vector transform
`[0x020c17c4, 0x020c1840)`, and 4x3 vector transform
`[0x020c2034, 0x020c20d4)`. Together these add four functions and 528 matched
code bytes, with no data or assembly definitions. Scale multiplies each basis
row by its corresponding factor; the 4x3 variant preserves translation.
Transforms accumulate full-width products and shift by 12 without rounding.
The 4x3 variant then adds translation. Input components are captured before
output stores, preserving in-place vector transforms; declaration order retains
the compiler's original register allocation. Intermediate output stores in the
4x3 transform also follow the original ordering.

`RenderConfig.cpp` uses in-place matrix scaling, while `GeometryFifo.cpp` uses
the 4x3 transform to obtain a view-space vector. Existing names and types needed
no changes. `ninja rom check` and the separate report both passed; each new unit
reports 100% matching code/functions, including the scale-to-scale call after
linking. The total denominators remain 2,959,478 code bytes, 1,602,476 data bytes,
and 14,790 functions. These seven math source units now cover 19 functions and
1,456 matched code bytes. Normalization remains outside the source mappings.

`Matrix4Translation.cpp` adds the adjacent 172-byte function at
`[0x020c189c, 0x020c1948)`. For distinct source/destination matrices it invokes
the existing 36-byte rotation-copy helper; that helper remains binary fallback
and receives no source credit here. Translation applies the supplied offset
through the rotation basis, truncates each full-width sum, and adds the existing
translation. The source preserves the in-place case and store order. Whole-module
checks and the linked report pass at 100% for this function. Across these eight
math units the total is now 20 functions and 1,628 matched code bytes, still with
no added standalone data definitions or denominator changes.
