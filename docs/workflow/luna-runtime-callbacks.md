# Runtime exception callback follow-up

Review based on `122dbf2` for the callback/cleanup path around `0x0200ef8c`.

The initialized pair at `data_020ef070` remains backed by relocations to
`func_0200efa0` and `func_0200efac`. The currently matched
`func_0200efb8` loads and invokes the first entry with no arguments. The second
entry has no observed consumer in this path, so its role remains unknown.
`func_0200efa0` has a relocation at `0x0200efa8` to `func_02001578` (the
existing exit/abort path), but this alone does not establish the callback's
whole behavior or a stable semantic name for either table field.

The adjacent `func_0200ef8c` calls `func_0200efb8` at `0x0200ef8c` and
`func_0200ed8c` at `0x0200ef94`, according to the relocation map. Its 20-byte
target object reports a frame-pointer-based argument setup and saved-register
epilogue. Two straightforward C candidates were compared and rejected: a
record parameter followed by both calls scored 16.67%; a no-argument wrapper
passing a local `RuntimeExceptionRecord` scored 28.57%. Neither is retained.
The local-record hypothesis does not explain the target frame setup and is not
claimed as semantics. No callback implementation was reconstructed or forced
into the link.

Existing destructor list registration/traversal is already typed in
`RuntimeState.h`, `RuntimeGlobalObjectRegistration.cpp`, and
`RuntimeDestructors.cpp`: the node's `next`, destructor callback, object, and
head-pointer update are corroborated by matched source. This inspection found
no adjacent untyped destructor helper with enough evidence to add safely.

No code/data coverage delta is claimed. The two candidate object comparisons
are archived under ignored `build/matching/`. Full module/symbol checks,
ARM7 verification, and ROM SHA-1 acceptance passed unchanged at
`c7c3014c237900c8281289b8bc76a781969b6278`. The batch window was 47.5 seconds;
token usage was not measured. Start/finish snapshots are in
`docs/workflow/evidence/luna-runtime-callbacks-{start,finish}.json`.
