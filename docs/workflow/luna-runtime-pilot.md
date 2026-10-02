# Luna GameState accessor pilot

The whole-task clock began at `2026-10-02T10:16:59Z`, before worktree setup.
Validated completion and the coverage snapshot were recorded at
`2026-10-02T10:27:15.720041Z`, for 616.72 seconds including setup and incident
handling. Note preparation and commit followed. The worker used branch
`work/luna-runtime` from `74b991750dc748377fe424548ad16626a4a772fb`.

The requested small string and locale helpers were already source-owned in the
starting branch: StringSearch (4/4), StringCopy (2/2), StringCompareAligned
(1/1), RuntimeLocaleTimeText (4/4), RuntimeLocaleTime (1/1), and
RuntimeCharacterConversion (2/2) all compared at 100%. With integrator approval,
the pilot moved to four adjacent GameState accessors whose types and fields are
established by `GameState`: the resource pointer at offset 0 and an otherwise
unnamed byte at offset 4. The byte's semantics remain unknown.

`GameStateResourceAccessors.cpp` reconstructs `func_0200fb84` (resource-pointer
setter), `func_0200fb8c` (resource-pointer getter), `func_0200fb94` (byte setter),
and `func_0200fb9c` (byte getter). They add 32 instruction bytes, four functions,
no literal/data/BSS bytes, and no symbol or denominator changes. One candidate
per function matched its original object on the first build; all four symbols
report 100% objdiff. Main's current symbols and delink map retain these exact
ranges as fallback; they do not overlap the integrated `GameStateObjects.cpp`
range.

The full `ninja rom check report` run passed ARM9 main, ITCM, DTCM, all 35
overlays, symbol checks, and the ARM7 build/preservation baseline. This older
configure script writes an unfinalized ROM and cannot run its raw `sha1` target
successfully. The guarded finalizer read the rebuilt ROM and untouched extracted
baseline, wrote to a separate output, verified secure-area identity, and passed
the target USA ROM SHA-1 `c7c3014c237900c8281289b8bc76a781969b6278`.

One setup mistake is recorded explicitly: the first private ROM setup used a
hardlink for the output, which aliased the root output and worker input paths.
Root checked file identities: the separate vectors output was not in that link
group, so the initial worker report of a vectors-output alias was unconfirmed.
The original extracted USA baseline was never changed. Work stopped after the
raw hash failure; the integrator verified the hashes and independently restored
the aliased output copies as separate files. No vectors source files were
changed. Subsequent setup and acceptance used the verified extracted baseline
and the private worker output only.

Logs and attempt details are under ignored `build/`: `setup.log`,
`luna-runtime-acceptance.log`, `luna-runtime-finalize.log`, and the single
`build/matching/` attempt record. The initial setup, incident response,
reconstruction, checks, and documentation are included in the whole-task clock.
The `tools/work_batch.py` snapshots record the post-setup coverage interval
separately: 394.46 seconds, +32 matched code bytes and +4 functions, with all
denominators unchanged. Token usage was not measured. Gameplay validation was
not performed.
