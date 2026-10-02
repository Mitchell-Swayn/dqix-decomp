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
