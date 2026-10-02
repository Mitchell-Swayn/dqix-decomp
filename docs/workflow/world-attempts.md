# World matching attempts

## 2026-10-02: collision-instance collection at 020181fc

Deferred after nine source variants (including failed compiler edits). The
closest compiled candidate matched 87.69231%: instruction sequence and size
matched, but the second pass used r6 for the output index and r5 for the input
index; the target uses the reverse. The first pass, allocation and pool matched.
No range was marked complete or credited for this draft.

The routine counts resources of kind 1, allocates an instance-pointer array at
Zone3D+824, then fills it. Main grotto floors instead set the count at +82c to
0x101 and return. Existing semantics and the missing allocation-failure check
were preserved. Local draft: build/matching/Zone3DCollisionInstances.cpp (untracked).

Tried shared versus separate loop/count variables, moving declarations,
initializing the second loop index before its count, reusing the first pass's
index as the output index, and splitting the output postincrement. Best form
used a second `for (int i = 0, count = ...; i < count; ++i)` and postincrement.
Next experiment: inspect allocator/register-lifetime effects of saving the
allocation result to a temporary before assigning the member; compare an
original neighboring two-pass collector before trying further variants.

The state-recording routine at 02017c58 matched after three variants: keep the
group ID as int and declare the count outside the group loop. The adjacent
request setters and the flag-4 mutator matched on the first compiled form.
The receiving state store and flag 4's gameplay meaning remain unresolved.

## Zone record table boundaries

The record-index tables at 020e6dc0, 020e6dc2 and 020e6ddc remain explicit data
fallback dependencies. Separately reconstructing only their 8 used bytes split
off unreferenced neighboring constants; the linker's dead stripping removed
those constants and shifted the remaining image. Their source extraction was
therefore deferred, with no data credit. Next step: establish ownership and
layout for the complete 020e6dc0..020e6df0 constant group before splitting it.
The four record/index functions themselves match and do not require this split.

## Zone3D constructor at 0201c014

Deferred after nine source variants, including one unsupported always_inline
attribute compile failure. The best constructor matched 73.58491% with exact
array lifetime helpers but ActiveGrottoClass's nested FloorMap constructor
remaining out of line. Raising inline depth/size thresholds, bottom-up modes,
an explicit member initializer, and moving the definition outside the class did
not change that call. A manual floor-map reset in the inline grotto constructor
expanded, but folded the base address instead of preserving target r5 and was
70.90909%. No constructor range is credited. Draft: build/matching/Zone3DConstructor.cpp.
Next: inspect a proven MWCC nested-constructor inline pattern or compiler ABI
settings before another variant. Its matching destructor and embedded resets
are independently reconstructable. Shared constructor hooks used only by the
deferred experiment were removed; observed destructor hooks remain.
