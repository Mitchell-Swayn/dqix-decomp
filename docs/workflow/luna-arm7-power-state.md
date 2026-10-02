# Luna ARM7 power-state initializer

Started at 2026-10-02 12:24:21 UTC in fresh worker worktree
`work/arm7-touch-followup`, based on integrated revision `4571ec4`. The
independent USA ROM copy verified as SHA-1
`c7c3014c237900c8281289b8bc76a781969b6278`.

Added `ARM7_InitializePowerState` at runtime `0x03805ad0`, payload offset
56556, size 60 (52 instruction bytes and 8 literal bytes). It sets the first
word of the established `ARM7_PowerState` layout to one, clears its operation
word, and zeros the 16 halfwords beginning four bytes into that state. The
struct declaration mirrors the existing `PowerTask.c` layout. A scan found no
direct ARM7 `BL` caller; any indirect caller remains unverified.

Three source variants were needed: the first two failed the expected size or
loop condition; the signed do-while form matched all 60 bytes. Later edits
aligned the state declaration with `PowerTask.c` and clarified the accepted
touch routine's shared MMIO base offsets; a full rebuild confirmed both exact
units. In `TouchControllerStatus.c`, GPIO base `0x04000136` plus byte offsets
`0x8a` and `0x8c` yields SPI control/data at `0x040001c0` and `0x040001c2`.
Named offset macros preserve the same compiled bytes and the disassembly's
single base register.

Delta: +52 instruction bytes, +8 literal bytes, +0 initialized data, +0 BSS,
+1 function, and -60 binary-fallback bytes. The touch-status source edit has no
coverage delta. Complete ARM7 payload and source-symbol checks passed with
`payload_sha1=a662d5c6a78e990244299926cf6862ce910a475d`. Tests passed:
`test_arm7_build.py` (11), `test_arm7_dependencies.py` (10 passed, one skipped),
and `test_disassemble_arm7.py` (15). Full integrated-ROM acceptance remains
with the integrator.
