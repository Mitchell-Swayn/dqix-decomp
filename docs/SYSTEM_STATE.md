# Recovered system data

`InterruptResponseState.cpp` owns the eight 12-byte DMA/timer callback records
at `0x0211127c..0x021112dc` and their eight 16-bit IRQ numbers at
`0x020f2274..0x020f2284`. The first four slots map DMA channels to IRQ bits 8..11;
the last four map timer channels to bits 3..6. Each record stores a callback,
the post-callback enable policy and integer callback data. Existing source and
original dispatcher/setter accesses agree on these offsets.

Interior field symbols are expressed as relocations to the array plus offsets.
The two owned symbols compare at 100%; combined module, symbol and final ROM
checks pass. This contributes 96 BSS and 16 initialized-data bytes. The existing
`InterruptHandler.cpp` was not a configured source unit at this milestone and
receives no function credit from this data reconstruction.

The eight DMA/timer entry wrappers are subsequently split into
`InterruptDispatchWrappers.cpp`, matching 128 code bytes (96 instructions and
32 compiler address literals) at `0x020c6a54..0x020c6ad4`. They pass indices 0..7
to the still-external dispatcher. All eight first forms match. Four variants
of the adjacent wait-list initializer were tried: an absolute pointer matches
instructions but not the target relocation; the relocatable field access swaps
the address/zero registers. That 24-byte initializer remains fallback.

`InterruptCallbacks.cpp` recovers the handler lookup and DMA/timer callback
setters at `0x020c6b74..0x020c6c90` (three functions, 284 report code bytes).
The existing source forms match on their first isolated compile. DMA callbacks
retain the prior IRQ enable bit, whereas timer callbacks remain enabled after
dispatch. Handler registration and the shared dispatcher still need matching.

Handler registration (`0x020c6aec..0x020c6b74`) was also isolated and tested in
five variants: original declarations, shared index scope, register hints,
size optimization, and initialized declarations. All retained the same 73.53%
register-allocation mismatch. The source and mapping were restored to fallback;
its candidate and detailed comparisons remain under ignored build outputs.

`TimerState.cpp` and `ActiveAlarmState.cpp` own the 16-byte timer overflow state
and 12-byte ordered alarm-list state at `0x02111638..0x02111654`. Their layouts
come from the existing initialization, overflow, scheduling and cancellation
accesses in `Timing.cpp`; compile-time checks enforce both sizes. The former
interior overflow-count symbol becomes the timer object's offset 8. Both data
symbols compare at 100%, and full ROM/module/symbol checks pass. The separate
alarm-initialization bitmask remains fallback.

Twelve context routines are recovered in `ContextBlocking.cpp`,
`ContextPriority.cpp`, and `ContextSleep.cpp` (480 report code bytes): sleep-alarm
cancellation, completion waiting, blocked/ready queue operations, scheduler
access, the sleep completion callback, switch callback registration, the idle
interrupt loop, and priority lookup. Their existing C++ forms match on the
first isolated compile, without the assembly matching hacks in the surrounding
unrecovered file. Full module/symbol/ROM acceptance passes.

The 168-byte sleep-registration routine itself remains fallback: its first
isolated candidate scores 61.90%, with register allocation differences. The
surrounding initialization, shutdown and priority-change routines also remain
separate work; these source slices do not establish a complete scheduler.

`ContextLifecycle.cpp` subsequently recovers six creation and termination
routines at `0x020c75b4..0x020c783c` (648 report code bytes). They initialize
context state and stack sentinels, invoke exit callbacks, release mutexes,
remove terminated contexts from queues, and wake completion waiters. All six
existing source forms match on their first isolated compile, and full
ROM/module/symbol acceptance passes. Register initialization and the remaining
scheduler primitives are still external dependencies.
