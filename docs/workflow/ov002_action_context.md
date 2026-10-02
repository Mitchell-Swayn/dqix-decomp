# ov002 action-context callback

Assigned function only: `func_ov002_02153ea4`, 380 instruction bytes,
`0x02153ea4..0x02154020`, based on revision
`039055bbde7fd706535beafb996dc6148b2b6589`.

The packet calls its inventory unit `ov002_4`; the starting checkout's
objdiff configuration and generated disassembly instead put this function in
`ov002_6`. The host must reconcile that identity. Only the named function was
split into source; no other fallback functions or data were reconstructed.

The callback takes dispatcher, context, item record, and bank-selection arguments.
It checks the context and item-record pointers, but does not inspect the record.
Context +2 is a signed owner byte, +3 an unsigned member count, and +4 four
signed member indices. Four six-byte result records start at +8 and +0x20.
Each record has status at +0, a short value at +2, and an unavailable flag at +4.
The callback initializes all four records of the selected bank, evaluates the
supplied members, and returns whether a qualifying result was recorded.
Gameplay names and the dispatcher/record layouts remain hypotheses.

Read-only analysis of `func_ov002_021536ec` shows 12-byte dispatch entries:
a signed-short key at +0, callback component at +4, and adjustment component
at +8. It tests bit zero of the latter to choose direct versus virtual
member-call resolution and shifts it right arithmetically for this adjustment.
This is evidence for a member-function-pointer pair, not an ordinary single
function-pointer table declaration. The first table passes fourth argument 0;
the second passes 1. Starting relocation-map load records at 0x0216ccd0,
0x0216cd00, and 0x0216cd60 point to the assigned callback. They correspond to
keys 5, 7, and 0x2b in the generated original disassembly. Host validation of
inventory and dispatch relocations is still required; no data credit is claimed.

Attempts: prior count 0; cumulative conservative count 5: four object comparison
calls and one failed header compilation. Variant one reached 92.63%, with only
the result accumulator and bank-pointer registers exchanged. Declaring the
accumulator before the pointer produced 100% on variant two. Adding layout checks
initially lacked the project's offsetof definition; including
std_library_functions.h fixed compilation. One comparison after that failed build
used the previous object and supplies no final-source validation; it is retained
in the count. The last comparison uses the freshly compiled final source and
matches 100%. Initial tool-path setup failure is not a source variant.

Verbose original disassembly and candidates are in ignored build/action_dis and
build/matching. Full acceptance log: build/action_acceptance_final.log.
Batch measurement: build/workflow/ov002_action_callback. No runtime tests or
measured token usage. No queue, tools, build-harness source, input, or other
worktree edits.

Acceptance passed: ninja -j2 rom check report sha1, including all configured
modules, symbol checks, ARM7 preservation, and exact ROM SHA-1
c7c3014c237900c8281289b8bc76a781969b6278. work_batch.py measured 406.291506
seconds, +1 matched function, +380 matched code bytes, +0 data bytes, unchanged
denominators, and zero ARM7/literal/data/BSS/assembly gains. Source commit:
d50f939. This is local worker validation; host integration remains separate.
