# Luna ARM7 power IPC receive attempt

Started at 2026-10-02 12:51:32 UTC in fresh worker worktree
`work/arm7-power-events`, based on integrated revision `6c28cf4`. The
independent USA ROM copy verified as SHA-1
`c7c3014c237900c8281289b8bc76a781969b6278`.

The candidate at runtime `0x03805b0c` is called by `ARM7_SpiIpcCallback` for
channel 8 with the IPC message word. This call is explicit at `0x03804f4c`;
the callback declaration and channel dispatch establish the one-word ABI. Its
state accesses align with `PowerState.h`: message bit 25 clears sixteen
halfword slots, bits 16..19 select a slot for the low halfword, and bit 24
enables dispatch based on the high byte in slot 0. Commands `0x60` send IPC
word `0x0300e000`; `0x61` and `0x62` enqueue a type-3 SPI task with two
arguments and report success through `ARM7_SendPowerReply`. The enqueue
signature is independently used by `PowerLedUpdate.c`.

Ten candidate source variants were compiled. The closest was size-correct at
320 bytes (304 instruction, 16 literal), but seven instruction words still
differed: the compiler chose r0 as the power-state base where the target uses
r1, with dependent operands in r0/r1 swapped for slot reads. All other bytes,
including the retry tests and command literals, matched. No source or manifest
coverage is retained for this function. A useful next experiment needs new
evidence for the original temporary/register lifetime pattern; further ad hoc
register-allocation changes are deferred.

The existing ARM7 baseline remains unchanged. No coverage delta is claimed.
