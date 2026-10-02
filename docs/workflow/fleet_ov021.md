# ov021 worker batch

Batch: `fleet_ov021_20261003_0145`, started 2026-10-02 15:43:23 UTC.
Baseline revision: `0ade2646fe7e27eb53d084a9e857334d18b3b47f`.
No previous ov021 source, workflow notes, or matching attempts were present.

## Accepted family

| Source | Original range (end exclusive) | Functions | Instruction bytes | Literal bytes |
| --- | --- | ---: | ---: | ---: |
| SceneLifecycle.cpp | 0218b5a0–0218b5fc | 2 | 88 | 4 |
| SceneFrame.cpp | 0218baf8–0218bbc4 | 2 | 196 | 8 |

The lifecycle initializes the shared brightness prefix and scene allocator,
then destroys that allocator and frees its backing allocation through the main
allocator. The frame pair advances the scene, latches an exit request, processes
sound, enables three DISP3DCNT features, submits rendering, flushes OAM cache
ranges, and requests a geometry buffer swap. Unknown dependencies keep their
original address names; these descriptions do not establish the overlay's
gameplay identity.

The main dispatcher at 02001184 allocates 0xbc bytes, initializes the context,
calls 0218b5fc, destroys it, and frees the context. Overlay21Context models that
allocation with the 0x2c brightness prefix, actual SafeAllocator at 0x2c, scene
pointer at 0x40, texture-state subobject at 0x44, object pointer at 0xb4, and exit
flag at 0xb8. The texture subobject's two ten-word image-state arrays, two
palette-state records, allocation keys and sizes follow 0207de48/0207df50.
Compile-time checks establish 0x2c, 0x70 and 0xbc sizes. No shared header edits.

InitializeBrightnessState's existing GameResources interface is called through
a documented cast: its disassembly accesses only the common 0x00–0x28 prefix.
This overlay's later layout differs from GameResources, so the context does not
pretend to contain a full GameResources object.

## Attempts and validation

- Initial candidate comparison: both lifecycle functions exact, both frame
  functions exact (one source variant per function).
- First full acceptance failed ov021 because MWLD discarded the lifecycle unit:
  main's ambiguous overlay calls resolve to ov015/ov016 symbol names. The linked
  frame addresses consequently moved backward by 0x5c. No instruction changes
  were needed.
- Added `#pragma force_active on/reset` around the two lifecycle entrypoints.
  The second lifecycle comparison remained exact; full symbol addresses returned
  to their original values. This is retention metadata, not assembly or a code
  substitute.
- Three candidate-building comparison calls total, plus one read-only frame
  recheck. No unproductive instruction variants or exhausted prior caps.
- Final `.venv/Scripts/ninja.exe -j2 rom check report sha1` exited 0. All module
  and symbol checks passed, ARM7 baseline passed, and ROM SHA-1 equals
  `c7c3014c237900c8281289b8bc76a781969b6278`. Original input SHA-1 separately
  checked against the same value. Input/output isolation guards passed.
- `git diff --check` passed. No gameplay smoke test was performed in this batch.

Verbose original disassembly, acceptance logs, and final factory_evidence
packages are under ignored `build/factory/fleet_ov021/`. Candidate snapshots,
objdiff output, diagnoses and attempt counts are under `build/matching/`.
The batch start/finish records under `build/workflow/fleet_ov021_20261003_0145/`
provide measured elapsed wall time and revision/coverage snapshots. Tokens were
not measured.

## Coverage and remaining work

ARM9 report delta: +4 matched functions, +296 matched code bytes (284
instructions plus 12 literals), +0 initialized data bytes, +0 BSS bytes, and
no assembly added. Before/after: 1651/1655 functions, 218816/219112 code bytes,
66724/66724 data bytes. Denominators remain 14790 functions, 2959478 code bytes,
1602476 data bytes. ARM7 coverage unchanged. These are local worker gains,
pending integrator acceptance.

The 0x4fc-byte entry loop at 0218b5fc–0218baf8 remains original fallback,
including its 80-byte literal pool. The 16-byte rodata array at 0218bbc4 and
four-byte ctor entry remain fallback; no data coverage is claimed. External
scene/camera/sound/OAM internals remain unresolved, as do most entry-loop
dependencies. The module has no BSS payload in its current map. ov021 is not
complete. No queue edit, integration or merge was performed.
