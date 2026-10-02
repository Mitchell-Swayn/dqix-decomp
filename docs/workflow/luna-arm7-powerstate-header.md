# Luna ARM7 shared power-state layout

Started at 2026-10-02 12:34:41 UTC in fresh worker worktree
`work/arm7-powerstate-header`, based on integrated revision `47b73ef`. The
independent USA ROM copy verified as SHA-1
`c7c3014c237900c8281289b8bc76a781969b6278`.

Added `PowerState.h` and changed both `PowerStateInit.c` and `PowerTask.c` to
use one 40-byte declaration: a 32-bit initialized word at offset 0, sixteen
16-bit slots at offset 4, and the operation word at offset `0x24`. The slots
are ordinary RAM fields, so the shared declaration uses no `volatile`
qualifiers. Compiling with ordinary fields and with only the slot array
volatile both preserved the original unit bytes; the nonvolatile layout was
kept because no asynchronous/MMIO access is established for this state.

The initializer and task units both remain byte exact. The full ARM7 payload
SHA-1 is unchanged at `a662d5c6a78e990244299926cf6862ce910a475d`; code, literals,
initialized data, BSS, functions, and fallback deltas are all zero. Tests
passed: `test_arm7_build.py` (11), `test_arm7_dependencies.py` (10 passed, one
skipped), and `test_disassemble_arm7.py` (15). MWCC dependency files for both
units include the new header. Full integrated-ROM acceptance remains with the
integrator.
