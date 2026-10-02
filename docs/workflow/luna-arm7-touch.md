# Luna ARM7 touch-status pilot

Started at 2026-10-02 12:08:07 UTC on `work/arm7-touch-batch`, based on
`1fd54b4`. Pre-existing untracked `.d` files were preserved. The independent
USA ROM copy has SHA-1 `c7c3014c237900c8281289b8bc76a781969b6278`.

Added `ARM7_ReadTouchControllerStatus` at runtime `0x038055b8`, size 244,
payload offset 55252, mapped through the ARM7 manifest. It uses established
GPIO-mode and touch-clock helpers and reproduces the SPI status and GPIO-bit
branches. Its external halfword status symbol follows the disassembled `ldrh`;
the higher-level meaning remains uncertain.

Candidate comparison took two compile variants. The first had three address,
write-target, or branch-polarity mismatches. The corrected source matched the
complete 244-byte unit. Delta: +220 instruction bytes, +24 literal bytes,
+0 initialized data, +0 BSS, +1 function, and -244 binary-fallback bytes.

The adjacent routine at `0x03805550` reads `[sp]` immediately after allocating
four bytes and has no proven initialization or caller contract, so it remains
deferred. The next touch sampler at `0x038056d0` spans about 476 bytes and
depends on broader state/layout behavior. Neither range received source
coverage.

`arm7_build.py` passed complete payload and source-symbol checks with
`payload_sha1=a662d5c6a78e990244299926cf6862ce910a475d`. Tests passed:
`test_arm7_build.py` (11), `test_arm7_dependencies.py` (10 passed, one skipped),
and `test_disassemble_arm7.py` (15). Full integrated-ROM acceptance remains
with the integrator.
