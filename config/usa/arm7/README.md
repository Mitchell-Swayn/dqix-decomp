# Cartridge ARM7 reconstruction

The cartridge ARM7 program is a required executable component, distinct from the
console ARM7 BIOS. The independent source build currently reconstructs **240 C
functions: 20,432 instruction bytes plus 1,464 bytes of literal pools**. Six necessary
CPU-status routines (120 bytes) are separately reviewed assembly exceptions;
1,188 bytes of standalone initialized data and 3,512 bytes of BSS now have source
definitions. The other 144,672 payload bytes
remain explicit original-binary fallback. Byte equality does not imply
decompilation completion. `baseline.json` records the original zero-source
starting point; `source_units.json` describes the active source replacements.

| Property | USA value |
| --- | --- |
| CPU | ARM7TDMI |
| ROM payload | `[0x001e2400, 0x0020b3c4)` |
| Loaded payload | `[0x02380000, 0x023a8fc4)` |
| Header entry point | `0x02380000` |
| Payload size | 167,876 bytes |
| Payload SHA-1 | `a662d5c6a78e990244299926cf6862ce910a475d` |
| ARM7 overlay table size | 0 |
| Reconstructed C instructions / compiler literal pools | 20,432 / 1,464 bytes |
| Reconstructed initialized standalone data / reviewed assembly ranges | 1,188 / 120 bytes |
| Reconstructed BSS / total autoload BSS | 3,512 / 22,744 bytes |
| Binary fallback | 144,672 bytes |
| Total function count / complete code-data partition | Unknown |

These load boundaries describe the contiguous cartridge image. The startup code
copies two parts of that image to different runtime addresses (below).
`arm7_entry` is a local header-derived label, not a recovered original name or a
claim about function size. Other symbols still need analysis.

After the ARM9 build has generated `build/usa/build/rom_config.yaml`, run from the
repository root (Windows matching tools):

```bat
.venv\Scripts\python.exe tools\arm7_build.py --rom-config build/usa/build/rom_config.yaml
dsd.exe rom build --config build/usa/build/rom_config_arm7.yaml --rom build/usa/arm7/dqix_usa.nds
.venv\Scripts\python.exe tools\check_arm7.py --rom build/usa/arm7/dqix_usa.nds
.venv\Scripts\python.exe -m unittest discover -s tools -p test_check_arm7.py
.venv\Scripts\python.exe -m unittest discover -s tools -p test_arm7_build.py
```

The verifier validates the base ROM hash, extraction bytes, rebuilt payload
bytes, addresses, size, and header entry label. Its JSON report goes to
`build/usa/arm7-report.json`. This preservation report deliberately makes no
source-coverage claim. The source build's `build/usa/arm7/report.json` separately
records compiled-source checks, linked symbol checks, source hashes, compiler
hashes, flags, and fallback byte counts. Custom paths are available through
`--help` for isolated clean-build checks. Only declared source-unit symbols are
link-checked; no full original ARM7 symbol map is claimed.
Do not add this module's entire size to a *code* denominator: the internal
code/data split is not yet established. Record it as an unclassified executable
payload alongside the ARM9 report until that split is audited.

## Startup and autoload mapping

Disassembly of the entry routine establishes a call at `0x023800a0` to the copy
loop at `0x02380118`. The loop reads six parameters at `0x02380204`: table start
`0x023a8fac`, table end `0x023a8fc4`, copy source `0x0238021c`, empty startup BSS
range `[0x0238021c, 0x0238021c)`, and zero. Each 12-byte descriptor contains
destination, copy length, and subsequent BSS zero-fill length. Both descriptors
and all source/runtime mappings are validated on every source build.

| Part | Payload offsets | Runtime initialized range | Runtime BSS range |
| --- | --- | --- | --- |
| Startup and parameters | `[0, 0x21c)` | `[0x02380000, 0x0238021c)` | Empty |
| Autoload 0 (`wram`) | `[0x21c, 0x11050)` | `[0x037f8000, 0x03808e34)` | `[0x03808e34, 0x0380cda4)` |
| Autoload 1 (`mainram`) | `[0x11050, 0x28fac)` | `[0x027e0000, 0x027f7f5c)` | `[0x027f7f5c, 0x027f98c4)` |
| Copy descriptors | `[0x28fac, 0x28fc4)` | Read at original load location | None |

Names `wram` and `mainram` are descriptive labels for the destinations, not
recovered linker section names. Initialized ranges contain both code and data.
The first range crosses the WRAM boundary; the addresses above are the literal
copy-loop destinations, without assuming a particular physical memory mapping.

## Source units and pipeline

`src/BootFlags.c` reconstructs runtime range `[0x037f84b8, 0x037f84f0)` from
payload range `[0x6d4, 0x70c)`. It reads byte `0x027ffe1d` and returns `0x40` for
input `0x80`, `0x80` for input `0x40`, and zero otherwise. The call sites at
`0x037f8084` and `0x037f8150` occur in firmware-settings validation. The broader
meaning of that shared boot byte remains uncertain, so the name describes the
observed operation. The conditional 16-bit narrowing in the original code is
reproduced with an unsigned-short accumulator and return type.

`src/BitCount.c` reconstructs runtime range `[0x03803f28, 0x03803f6c)` from
payload range `[0xc144, 0xc188)`: a population count using parallel bit summation.
Its 56 instruction bytes and three 32-bit literal masks match exactly.

`src/ArenaBounds.c` reconstructs runtime range `[0x037fce88, 0x037fcfd4)` from
payload range `[0x50a4, 0x51f0)`: arena initialization, high/low getters, initial
high/low selection and the low-bound setter. These six functions access shared
HIGH boundaries at `0x027ffdc4` and LOW boundaries at `0x027ffda0`. Initial bounds
establish that direction: the main-RAM interval begins at BSS end `0x027f98c4`
and ends at `0x027ff000`. The initial accessors' earlier low/high names were
reversed; source and symbol names have been corrected without changing bytes.

Initial-boundary selection is now source, so there are no remaining binary
function dependencies in this unit. Four absolute linker symbols describe the
two BSS ends and the IRQ/system stack sizes (both `0x400` for USA). They are
link-time values, not reconstructed globals. Shared boundary storage remains
outside this source unit's data ownership. The unit owns 304 instruction bytes
and 28 literal-pool bytes. IRQ stack end `0x0380ff80` is a fixed address; retaining
stack sizes as linker symbols reproduces the original calculations and literal
order without folding the entire expression into a constant.

`src/ArenaHeap.c` reconstructs runtime range `[0x037fcfd4, 0x037fd39c)` from
payload range `[0x51f0, 0x55b8)`: list removal, sorted insertion/coalescing,
allocation, freeing, current-heap selection, arena metadata initialization and
heap creation. These seven functions own 948 instruction bytes and 20 literal
bytes. Blocks have a 0x20-byte header and 0x20-byte alignment; split remainders
smaller than 0x40 stay with the allocation. Free lists are sorted by address and
merge physically adjacent neighbors.

The nine-entry descriptor-pointer table at `[0x0380912c, 0x03809150)` now has a
36-byte source BSS definition. Its placement lies in the original WRAM autoload
zero-fill interval. Interrupt disable/restore routines at `0x037fe364` /
`0x037fe378` are now the separately reviewed CPU-status unit. Cross-unit linker
addresses remain explicit, but these three dependencies are source-owned.
The source types record a 12-byte heap descriptor and a
20-byte arena descriptor with current heap, heap count, arena start/end and
descriptor-array pointer. The corresponding ARM9 source supplied a useful
starting hypothesis; ARM7's while-loop layout and inlined list prepend were
separately matched. Locals preserve snapshot pointers across potentially aliasing
writes, matching the original loads rather than asserting unsupported aliasing.

`src/ArenaHeapCheck.c` reconstructs the heap validation routine at
`[0x037fd39c, 0x037fd6e8)` (payload `[0x55b8, 0x5904)`), with 716 C
instruction bytes and 128 literal bytes. It checks arena bounds, 32-byte block
alignment, linked-list consistency, minimum block size, free-block ordering,
and total heap accounting before returning available payload bytes or -1.
Nineteen diagnostic paths preserve the original message addresses and line
numbers. Shared message addresses use shared external symbols so the compiler
also reproduces native literal-pool sharing. The warning routine at `0x037fbdb8` remains binary-owned; diagnostic text is
now reconstructed by the separate data unit below.

`src/ArenaHeapDiagnostics.c` owns 864 initialized data bytes at
`[0x038088c0, 0x03808c20)` (payload `[0x10adc, 0x10e3c)`): thirteen unique
heap assertion format strings used by the checker's nineteen failure paths.
A typed aggregate gives each diagnostic a named char-array field; explicit
field lengths include each NUL and observed zero alignment padding. The compiler
emits one `.rodata` aggregate, preserving the native order. The source contains
readable strings, not an opaque binary array. Its single aggregate symbol is
verified and does not count as a function. Checker's external message addresses
are the corresponding member offsets inside this source-owned data range.

`src/Timing.c` reconstructs `[0x037fd6e8, 0x037fd89c)` (payload
`[0x5904, 0x5ab8)`): timer initialization flags, 64-bit timer initialization and
status, the timer-0 overflow handler, and timestamp reading. It owns 388
instruction bytes, 48 literal bytes, and BSS `[0x03809150, 0x03809164)`.
The latter holds a 4-byte initialization-flag/alignment block and the 16-byte
timer state. The counter runs at a /64 prescale and combines a software overflow
count with the 16-bit hardware timer. The reader disables IRQs and accounts for
a pending overflow before returning the combined timestamp. Interrupt-handler
registration remains an explicit binary dependency; interrupt enabling and timer
callback registration now belong to the `Interrupts` source unit. `dont_inline` preserves the original call to the flag
marker; no matching-only assembly is used.

`src/Interrupts.c` reconstructs `[0x037fb88c, 0x037fb9cc)` (payload
`[0x3aa8, 0x3be8)`): timer callback registration, interrupt-mask replacement,
master-enable disabling, specific interrupt enabling/disabling, and pending-IRQ
acknowledgement. These six functions own 288 instruction bytes and 32 literal
bytes. All register accesses use volatile C loads/stores. The 96-byte BSS range
`[0x03808e3c, 0x03808e9c)` defines eight DMA/timer response entries containing
callback, stay-enabled flag and user data. Field-base address expressions preserve
the original compiler's separate literal addresses for callback-table fields.
The original handler-registration routine at `0x037fb7f0` still consumes this
table; its separate VBlank response and initialized dispatch table remain outside
this unit's source data ownership.

`src/Alarms.c` reconstructs eight alarm scheduling functions at
`[0x037fd89c, 0x037fdc50)` (payload `[0x5ab8, 0x5e6c)`), with 8240 C
instruction bytes, 52 literal bytes and the 12-byte list state at
`[0x03809164, 0x03809170)`. It initializes and orders the doubly-linked queue,
programs timer 1, registers timeouts and periodic intervals, and cancels alarms.
All code uses ordinary C. The unsigned 64-bit division helper at `0x03807e70`,
panic routine at `0x037fbf30`, diagnostic strings at `0x03808c20` / `0x03808c2c`,
and timer-1 interrupt wrapper at `0x037fdc50` remain explicit binary dependencies.
The diagnostic line values (0x174 and 0x1a2) come from the original instructions;
no original source authorship or file contents are claimed.

`src/AlarmHandler.c` reconstructs the timer-1 expiration handler at
`[0x037fdc60, 0x037fdd54)` (payload `[0x5e7c, 0x5f70)`), with 232 C
instruction bytes and 12 literal bytes. It records the IRQ, removes an expired
head alarm, invokes its callback, requeues periodic alarms and rearms the next
alarm. Its queue state belongs to `Alarms.c`; the IRQ-fired word at `0x0380fff8`
is shared system storage, not newly owned BSS. The intervening 16-byte interrupt
entry wrapper remains binary fallback.

`src/VerticalAlarms.c` reconstructs five vertical-count alarm list functions at
`[0x037fdd54, 0x037fdea0)` (payload `[0x5f70, 0x60bc)`), with 316 C
instruction bytes and 16 literal bytes. Its 20-byte state at
`[0x03809170, 0x03809184)` holds initialization, last scanline, frame count,
and list endpoints. Sorting compares unsigned frame numbers and signed scanlines;
removal repairs both endpoints. The hardware arming routine at `0x037fdff0`
is reconstructed by the setup unit. Field `unknown32` stays descriptive rather than speculative.
The frame/last-scanline interpretation is corroborated by the wrap detector at
`0x037fe30c` (increments frame when the current scanline is below the prior one).

`src/VerticalAlarmSetup.c` reconstructs one-shot and periodic scanline-alarm
registration and DISPSTAT programming at `[0x037fdea0, 0x037fe04c)` (payload
`[0x60bc, 0x6268)`), with 388 C instruction bytes and 40 literal bytes.
It preserves native diagnostic line constants 0x189/0x1c5 and references the
binary-owned file/error strings at `0x03808c4c` / `0x03808c58`. IRQ handler
registration (`0x037fb7f0`), panic (`0x037fbf30`) and the vertical-alarm interrupt
entry (`0x037fe15c`) remain binary dependencies. DISPSTAT accesses are volatile C.
`src/VerticalFrame.c` reconstructs `[0x037fe30c, 0x037fe350)` (payload
`[0x6528, 0x656c)`): 64 instruction bytes and 4 literal bytes for IRQ-protected
VCOUNT wrap tracking. Both units reuse existing source-owned vertical-alarm state.

`src/VerticalAlarmCancel.c` reconstructs tagging, individual cancellation and
cancellation by tag at `[0x037fe04c, 0x037fe15c)` (payload
`[0x6268, 0x6378)`), with 248 C instruction bytes and 24 literal bytes.
The iterator saves its next node before cancellation; IRQ protection and the
cancelled flag preserve the native callback interaction. The tag-error string
at `0x03808c78` stays binary-owned. No additional BSS is claimed.

`src/DmaControl.c` reconstructs DMA completion waiting and channel reset at
`[0x037fe500, 0x037fe5ec)` (payload `[0x671c, 0x6808)`), with 228 C
instruction bytes and 8 literal bytes. Volatile accesses preserve the native
control-register polling, start/repeat clearing, two post-clear reads, and
channel-zero reinitialization using `0x81400001`. IRQ helpers are source-owned;
these routines add no standalone data or BSS.

`src/IPC.c` reconstructs seven FIFO routines at `[0x037fe92c, 0x037fec18)`
(payload `[0x6b48, 0x6e34)`): ARM7 initialization/handshake, handler registration
and query, command packing, raw-word sending and interrupt-driven receiving.
The public initialization wrapper is included. It owns 692 instruction bytes,
56 literal bytes and 132 BSS bytes at `[0x03809188, 0x0380920c)` for the init
flag, alignment and 32 callback pointers. Shared CPU registration masks at
`0x027fff88` / `0x027fff8c` are not newly owned data. The command's 5/1/26-bit
fields use ordinary C bitfields; every bit is assigned before the word is sent.
The receive handler drains the FIFO, dispatches channel callbacks and marks
unhandled commands for return to the other CPU. The boot-mode query
and interrupt registration remain explicit binary dependencies. The boot-mode name describes its use here,
not a claim that its wider semantics are fully recovered.

`src/CycleDelay.c` reconstructs the 24-byte wrapper at
`[0x037fe3c8, 0x037fe3e0)` (payload `[0x65e4, 0x65fc)`), with 20 C
instruction bytes and 4 literal bytes. Signed division by four and a normal C
call reproduce the native tail call to Thumb address `0x03803ea5`. The called
BIOS-facing routine remains binary fallback; this is not a BIOS reconstruction.

`src/MessageQueue.c` reconstructs initialization, send, receive and peek at
`[0x037fcadc, 0x037fcca0)` (payload `[0x4cf8, 0x4ebc)`), all 452 bytes
ordinary C instructions. The circular buffer has independent sender/receiver
wait lists, and flag bit zero selects blocking behavior. IRQ helpers are already
source-owned; thread block/unblock now belong to `ThreadWait.c`; the signed-division runtime
helper remains an explicit binary dependency. Queue instances are caller-owned, so no BSS is
credited by this unit.

`src/Mutex.c` reconstructs six recursive-mutex and owner-list routines at
`[0x037fcca0, 0x037fce1c)` (payload `[0x4ebc, 0x5038)`), with 372 C
instruction bytes and 8 literal bytes. Ownership, recursive reference counts,
blocking and wakeups follow the native thread fields at offsets 0x68/0x6c/0x70.
The thread structure is deliberately partial, and the scheduler view
at `0x03808fd0` is a subobject of the source-owned `ThreadSwitch.c` header. Blocking and wakeup helpers now belong to `ThreadWait.c`;
the mutex-list pop helper now belongs to `ThreadLists.c`; no data bytes are credited by this unit.

`src/ThreadLists.c` reconstructs five list routines at
`[0x037fc0f8, 0x037fc29c)` (payload `[0x4314, 0x44b8)`), with 412 C
instruction bytes and 8 literal bytes: priority-ordered blocked-list insertion,
blocked-list removal, mutex-list pop, and global thread-list insertion/removal.
Priority fields use unsigned comparisons. Existing-node insertion and null-list
cases preserve their original behavior. The scheduler header at `0x03808fac` is owned by `ThreadSwitch.c`; this unit
does not add duplicate data credit.

`src/ThreadWait.c` reconstructs blocking, waking all waiters, marking a thread
ready and selecting the first ready thread at `[0x037fc69c, 0x037fc7cc)`
(payload `[0x48b8, 0x49e8)`), with 2240 C instruction bytes and 8 literal bytes.
It clears blocked-list links on wakeup and preserves IRQ state. The scheduler switch routine now belongs to `ThreadSwitch.c`; list insertion
and IRQ dependencies are source-owned. No thread-context storage is counted by this unit.

`src/ThreadSwitch.c` reconstructs high-level scheduler switching at
`[0x037fc29c, 0x037fc370)` (payload `[0x44b8, 0x458c)`), with 204 C
instruction bytes and 8 literal bytes. It respects scheduler locks and IRQ mode,
selects a ready thread, runs switch callbacks and updates the active pointer.
The actual register-save/restore routines at `0x037fca58` / `0x037fca8c` remain
original binary fallback. This unit introduces no assembly and claims no source
coverage for those separate low-level routines. Its source-defined 380-byte BSS object
`[0x03808fac, 0x03809128)` contains the 52-byte scheduler header and two
0xa4-byte contexts at `0x03808fe0` / `0x03809084`. Compile-time size and member
offset assertions bind the header, context stride and aggregate extent. Unknown
header/context words remain explicitly named unknown arrays, with no invented
semantics. BSS contributes no payload bytes and no extra function/code credit.

The native scheduler initializer at `0x037fc370` binds the active-pointer cell
at root+0x1c, initialization flag at +0x20, system view at +0x24, and primary
context fields at root+0x120/124/128/12c/14c/150/154/158/15c. The thread creator at
`0x037fc460` corroborates the per-context offsets below. The protected idle
pointer in priority-changing code is `0x03808fe0`; the next independent arena
initialization flag is `0x03809128` (literal used at `0x037fce50`). Interior
scheduler/context addresses remain link-checked external dependencies where
used by other source slices, without duplicate ownership.

| Context offset | Recovered layout / evidence |
| --- | --- |
| 0x00?0x47 | Status, 15 general register slots, resume address, supervisor stack; save/restore and register-init accesses |
| 0x48?0x54 | State, global-list next, unique ID, priority; creator and list operations |
| 0x58 | Unknown word (creator clears it) |
| 0x5c?0x64 | Waiting queue and previous/next blocked links |
| 0x68?0x70 | Blocking mutex and owned-mutex list endpoints |
| 0x74?0x7c | Stack bounds and reserved-stack size |
| 0x80?0x84 | Completion wait-list endpoints |
| 0x88?0x90 | Three unknown words cleared by creator |
| 0x94?0x98 | Sleep alarm and exit callback |
| 0x9c?0xa0 | Unknown trailing words; stride fixed by adjacent embedded contexts |

`src/ThreadCreate.c` reconstructs `[0x037fc460, 0x037fc568)` (payload
`[0x467c, 0x4784)`), with 248 instruction bytes and 16 literal bytes. It assigns
an increasing ID and priority, inserts the initially blocked thread, initializes
stack bounds and two sentinel words, delegates the initial register frame, and
clears queue, mutex, sleep-alarm and callback fields. No new storage is claimed.

`src/ThreadExit.c` reconstructs four lifecycle functions at
`[0x037fc568, 0x037fc69c)` (payload `[0x4784, 0x48b8)`), with 288 instruction
bytes and 20 literal bytes. Normal return enters exit with argument zero; an
optional exit stack rebuilds the frame before dispatch. The exit callback is
cleared before calling it. Teardown releases owned mutexes, removes blocked and
global-list membership, marks the thread terminated, wakes completion waiters,
and switches away. Register-frame operations, the switch-lock increment helper and the final
termination routine remain explicit binary dependencies; list, wakeup, mutex
and scheduler calls already have source-owned implementations.

`src/ThreadPriority.c` reconstructs `[0x037fc7cc, 0x037fc874)` (payload
`[0x49e8, 0x4a90)`): 160 instruction bytes and eight literal bytes. It rejects
missing threads and the idle context, reinserts a changed priority into the
ordered global list, and invokes scheduling under IRQ protection. Its idle-thread
symbol is an address alias into existing thread-global BSS, not new storage.

`src/ThreadCallbacks.c` reconstructs `[0x037fc918, 0x037fc964)` (payload
`[0x4b34, 0x4b80)`): 68 instruction bytes and eight literal bytes for the alarm
wakeup callback and IRQ-protected switch-callback replacement. Wakeup clears both
the caller's wait slot and the thread's sleep-alarm pointer before marking ready.
The sleep wrapper itself remains binary-owned pending multiplication matching.

`src/ThreadSwitchUnlock.c` reconstructs `[0x037fc99c, 0x037fc9d4)` (payload
`[0x4bb8, 0x4bf0)`): 52 instruction bytes and four literal bytes. It decrements a
nonzero scheduler lock count under IRQ protection and returns the previous count,
or zero when already unlocked. The lock-increment routine remains binary-owned.

`src/InterruptDispatch.c` reconstructs `[0x037fb670, 0x037fb6fc)` (payload
`[0x388c, 0x3918)`): 120 instruction bytes and 20 literal bytes. It snapshots and
clears a DMA/timer response callback, invokes it with its stored user data, sets
the corresponding fired-IRQ bit at `0x0380fff8`, and conditionally disables the
hardware interrupt. Reading the continued-delivery flag after the callback
preserves changes made by callback code. The response array already has source BSS.

`src/InterruptVectors.c` reconstructs eight channel wrappers at
`[0x037fb6fc, 0x037fb77c)` (payload `[0x3918, 0x3998)`): 96 instruction bytes
and 32 literal bytes. Each routes one DMA or timer interrupt to the dispatcher.
`src/InterruptResponseIDs.c` owns the associated 16-byte constant mapping at
`[0x0380881c, 0x0380882c)` (payload `[0x10a38, 0x10a48)`): DMA IDs 8-11 and
timer-overflow IDs 3-6. These bytes count as initialized data, not instructions.

`src/VBlankDispatch.c` reconstructs `[0x037fb77c, 0x037fb7cc)` (payload
`[0x3998, 0x39e8)`): 68 instruction bytes and 12 literal bytes. It snapshots the
VBlank callback, increments the shared counter at `0x027ffc3c`, invokes the
callback without arguments, then records IRQ bit zero at `0x0380fff8`. The
12-byte VBlank response record at `[0x03808e9c, 0x03808ea8)` is now source BSS;
it immediately follows the already reconstructed eight DMA/timer responses.

`src/InterruptWaiters.c` reconstructs `[0x037fb7cc, 0x037fb7f0)` (payload
`[0x39e8, 0x3a0c)`): 28 instruction bytes and eight literal bytes. It clears
both IRQ-waiter queue endpoints and the shared VBlank count. Its eight-byte
queue at `[0x03808e34, 0x03808e3c)` is separately source-owned WRAM BSS.
`src/EmptyInterruptHandler.c` reconstructs the four-byte default return handler
at `[0x037fb66c, 0x037fb670)` (payload `[0x3888, 0x388c)`).

The cartridge-bus lock batch reconstructs nine functions in five source units:

| Unit | Runtime range | Payload range | Instructions / literals |
| --- | --- | --- | --- |
| `BusLocks.c` | `[0x037fba50, 0x037fbbe4)` | `[0x3c6c, 0x3e00)` | 388 / 16 bytes |
| `BusTryAcquire.c` | `[0x037fbbf0, 0x037fbc30)` | `[0x3e0c, 0x3e4c)` | 56 / 8 bytes |
| `BusNDS.c` | `[0x037fbc38, 0x037fbc78)` | `[0x3e54, 0x3e94)` | 40 / 24 bytes |
| `BusLockOwner.c` | `[0x037fbc80, 0x037fbc88)` | `[0x3e9c, 0x3ea4)` | 8 / 0 bytes |
| `SharedBootFlag.c` | `[0x037fcac0, 0x037fcadc)` | `[0x4cdc, 0x4cf8)` | 24 / 4 bytes |

The generic release and try-acquire routines preserve owner mismatch `-2`,
atomic claim results, callback ordering, and IRQ-only versus IRQ/FIQ masking.
GBA acquisition retries positive contention results with a wait loop; GBA
release and successful acquisition invoke their platform hooks when shared
halfword `0x027ffffa` bit 2 is clear. The bit getter's name describes the observed
test without asserting broader flag semantics. NDS wrappers use IRQ-only masking.
Shared lock records at `0x027fffe0` and `0x027fffe8` remain outside source BSS
ownership. Atomic swap, wait, platform hooks and the assembly-shaped public GBA
release trampoline remain binary dependencies; no new assembly is introduced.

`src/GPIOControl.c` and `src/GPIOControlMode.c` reconstruct two control-register
helpers at `[0x037fec18, 0x037fec50)`
(payload `[0x6e34, 0x6e6c)`): 48 instruction bytes and eight literal bytes across
two functions. The mask update reads and writes 16-bit register `0x04000134`;
the wrapper narrows its argument to 16 bits and clears mode mask `0xc000`.

`src/InputPolling.c` reconstructs initialization and the periodic callback at
`[0x037fec50, 0x037fed2c)` (payload `[0x6e6c, 0x6f48)`): 196 instruction bytes
and 24 literal bytes. Initialization requires the timer and alarm list, returns
zero if unavailable or already initialized, and schedules a 2,094-tick interval
starting at the current timestamp plus 2,094. The callback selects GPIO mode
`0x8000`, reads `0x04000136`, and publishes bits 0/1/3 shifted by ten plus bit 7
shifted to bit 15 at shared halfword `0x027fffa8`. Source BSS adds a four-byte
initialization flag and 44-byte alarm at `[0x0380920c, 0x0380923c)`, with an
explicit alarm-size check. No initialized data or assembly is added.

`src/SoundMaster.c` reconstructs eight sound-control functions at
`[0x037fed2c, 0x037fee94)` (payload `[0x6f48, 0x70b0)`): 312 instruction
bytes and 48 literal bytes. They control master-enable bit 7 at byte `0x04000501`,
stop all 16 channels and clear the two capture-control bytes at `0x04000508`,
sequence sound-power bit zero at `0x04000304`, call BIOS bias ramps with delays,
write master volume, and pack output-routing fields while retaining enable state.
The two external power-management hooks retain descriptive call-site names;
their argument `1` has no newly asserted policy semantics. Disassembly of the
Thumb BIOS-facing helpers confirms argument forwarding into r1 and SVC 8 with
r0 zero or one; those helpers remain binary-owned.

`src/SoundChannelStop.c` reconstructs `[0x037ff0b0, 0x037ff0d8)` (payload
`[0x72cc, 0x72f4)`): 40 instruction bytes and no literals. It clears channel
control bit 31 and optionally sets bit 15 according to caller flag bit zero,
preserving all other bits. Register stride is 16 bytes from `0x04000400`.
This batch owns no initialized data or BSS and introduces no assembly exception.

`src/SoundChannelConfig.c` reconstructs three setup functions at
`[0x037fee94, 0x037ff0b0)` (payload `[0x70b0, 0x72cc)`): 480 instruction
bytes and 60 literal bytes. PCM setup packs format/repeat/pan/divisor/volume,
writes period reload, loop start, length and source. PSG and noise setup retain
their distinct duty/format packing. The software requested pan and volume are
stored before any override; only channels in mask `0xfff5` use the adjustment
helper when its software control is positive. Explicit channel-byte offsets
remain live across helper calls, matching native address computation.

`src/SoundChannelParameters.c` reconstructs six functions at
`[0x037ff0d8, 0x037ff270)` (payload `[0x72f4, 0x748c)`): 368 instruction
bytes and 40 literal bytes. They set volume/divisor, period and pan, read active
and raw-control state, and apply or release the global pan override. A negative
override restores the per-channel requested values; a nonnegative override writes
one byte to all 16 channels. Requested values, override and adjustment globals
remain external storage. The adjustment helper and requested arrays are now owned by the following
sound-math batch; the broader software policy remains unasserted.

`src/SoundVolumeAdjustment.c` reconstructs `[0x037ff270, 0x037ff33c)`
(payload `[0x748c, 0x7558)`): 184 instruction bytes and 20 literal bytes. Its
setter refreshes hardware volume on channel mask `0xfff5`; its helper applies
piecewise linear correction below pan 24 and above pan 104, leaving the central
interval unchanged. The factor and two requested-value arrays now form a typed
36-byte BSS block at `[0x0380923c, 0x03809260)`. Existing external names remain
address aliases into this block; the mutable pan override remains binary data.

`src/SoundMath.c` reconstructs four functions at `[0x037ff468, 0x037ff588)`
(payload `[0x7684, 0x77a4)`): 264 instruction bytes and 24 literal bytes.
Attenuation is clamped to [-723, 0] and combined with a hardware divisor; the
volume-table wrapper calls the original Thumb BIOS-facing helper. Sine lookup
mirrors a signed-byte quarter-wave table, and the random helper advances a 32-bit
LCG with multiplier 1664525 and increment 1013904223, returning the high half.
The random seed remains mutable binary-owned data.

`src/SoundSineTable.c` owns exactly 33 constant sample bytes at
`[0x038082a8, 0x038082c9)` (payload `[0x104c4, 0x104e5)`), including both
quarter-wave endpoints. The compiler emits 33 bytes, so the following three
zero bytes remain fallback rather than being assumed alignment ownership.

`src/SoundWorkerControl.c` reconstructs four functions at
`[0x037ff588, 0x037ff674)` (payload `[0x77a4, 0x7890)`): 192 instruction
bytes and 44 literal bytes. Initialization runs once, initializes an external
platform component, creates a priority-selected thread with a 1,024-byte stack,
and marks it ready. Alarm control schedules a recurring interval of `0xaa8`
ticks beginning at now plus `0x10000`, or cancels it; notification posts message
2 without blocking. `src/SoundWorkerAlarmCallback.c` reconstructs
`[0x037ff67c, 0x037ff6c0)` (payload `[0x7898, 0x78dc)`): 56 instruction
bytes and 12 literals, posting message 1 and invoking the external diagnostic
callback if the queue is full.

The worker's contiguous 1,300-byte BSS block at `[0x03809260, 0x03809774)` is
now source-owned. Its layout follows both thread creation and the original worker
entry's queue/alarm setup, rather than assuming opaque unused storage:

| Offset | Source field / evidence |
| --- | --- |
| `0x000` | Four-byte initialization flag |
| `0x004` | Eight message-pointer slots; worker queue initialization passes count 8 |
| `0x024` | 32-byte message queue, same type as the reconstructed queue routines |
| `0x044` | 44-byte alarm, passed to alarm initialization and interval/cancel calls |
| `0x070` | 164-byte thread context, matching the proven `0xa4` context stride |
| `0x114` | 1,024-byte stack, ending at the creator's `0x03809774` stack-top argument |

Compile-time checks fix total size and context offset; each external field view
is explicitly linked to its observed address. The platform component remains binary-owned; the worker loop is now
reconstructed below. BSS adds no initialized payload or code credit.

`src/SoundPeriod.c` reconstructs period conversion and a BIOS-pitch-table
wrapper at `[0x037ff33c, 0x037ff468)` (payload `[0x7558, 0x7684)`): 292
instruction bytes and eight literals. It normalizes negative pitch into a
768-step fractional octave, multiplies the base period by a 64-bit fractional
ratio, applies the octave shift, and saturates the result to [16, 65535]. The
native overflow mask is preserved before positive shifts; the underlying Thumb
pitch-table routine remains binary-owned.

`src/SoundWorkerMain.c` reconstructs `[0x037ff6c0, 0x037ff7b4)` (payload
`[0x78dc, 0x79d0)`): 224 instruction bytes and 20 literals. It initializes the
eight-slot queue and alarm, initializes remaining sound subsystems, enables
master output with volume 127, and starts the recurring worker alarm. Its infinite
loop blocks for messages, sets a timed-update flag for message 1, invokes the
observed update sequence, and advances the sound RNG. Message 2 leaves the flag
clear. Several subsystem initialization/update callees remain explicit binary
dependencies with deliberately limited call-site names.

`src/SoundCaptureStatus.c` reconstructs `[0x037ff804, 0x037ff81c)` (payload
`[0x7a20, 0x7a38)`): 24 instruction bytes and no literals for testing capture
control bit 7. Capture configuration immediately before it remains binary-owned
pending a conditional-instruction ordering match. This batch adds no data/BSS.

`src/SoundVoice.h` shares the recovered waveform, modulation and voice layouts
across nine sound units. Size assertions enforce 12-, 10- and 84-byte records;
unknown fields retain offset-based names. Compiler-emitted dependency records
hash the shared header in every consuming unit, so future layout changes remain
part of source provenance. This consolidation adds no source-coverage credit.

`src/SoundVoiceInit.c` reconstructs `[0x037ff81c, 0x037ff878)` (payload
`[0x7a38, 0x7a94)`): 84 instruction bytes and eight literals. It sets each of
16 voice IDs, clears the active bit and five-bit pending-update field, and clears
two external channel reservation masks. The 16 records at `[0x0380979c, 0x03809cdc)` now
have a typed 1,344-byte source BSS definition with a checked `0x54` record stride.
Unidentified regions remain named by offset; no meaning is assigned to them.

`src/SoundVoiceApply.c` reconstructs `[0x037ff878, 0x037ffa64)` (payload
`[0x7a94, 0x7c80)`): 488 instruction bytes and four literals. The first pass
handles stop, setup, period, volume and pan update flags; the second pass enables
newly configured channels together and clears pending updates. This preserves
the original separation of configuration and hardware enable.

`src/SoundVoiceSetup.c` reconstructs three functions at
`[0x037ffe18, 0x037ffee4)` (payload `[0x8034, 0x8100)`): 196 instruction
bytes and eight literals. PCM setup copies the 12-byte waveform description and
source address. PSG accepts IDs 8-13 and noise accepts IDs 14-15, both using base
period 8006 before invoking the external start helper. Each returns success or
zero for an ineligible channel. The runtime waveform occupies offsets `0x38`
through `0x43`, followed by source/duty at `0x44`; callback and list fields follow.
The channel reservation masks at `0x03809774` remain external; the voice-start
helper is reconstructed below.

`src/SoundEnvelope.c` reconstructs seven functions at
`[0x037ffee4, 0x03800008)`: 284 instruction bytes and eight literal bytes.
The tick-controlled state machine advances attack, decay, sustain and release,
with setters for each parameter and helpers for release and active status.
Attenuation and attack lookup tables are typed standalone data sources below.

`src/SoundEnvelopeSetup.c` reconstructs two functions at
`[0x0380051c, 0x038005a8)`: 132 instruction bytes and eight literal bytes.
It converts fall rates, including the special 126/127 values, and starts a voice
by resetting attenuation, envelope and modulation state and setting its active
and pending-start bits. The existing 84-byte record is checked at compile time;
unidentified fields retain offset-based names.

`src/SoundModulation.c` reconstructs three functions at
`[0x03800448, 0x0380051c)`: 212 instruction bytes, with no literal pool.
Initialization sets the modulation defaults; update waits for the delay then
advances phase with eight fractional bits and wraps the integer phase at 128.
Evaluation multiplies the signed sine result by depth and range after the delay.
The first parameter byte remains unidentified. Embedded in a voice at `0x28`,
this record identifies offsets `0x2e` and `0x30` as delay counter and phase.

`src/SoundVoiceCallback.c` clears a non-null voice's callback and user data at
`[0x038001d4, 0x038001e8)` (20 instruction bytes). `src/SoundReservations.c`
reconstructs three functions at `[0x03800378, 0x03800448)` (196 instruction
bytes and 12 literal bytes): clear/get either reservation mask selected by flag
bit zero, and stop active PCM voices whose source lies in an inclusive range.
These consumers establish that the two words at `0x03809774` are channel masks,
correcting the earlier tentative list-endpoint interpretation. Their policy
names remain unknown, so fields are named `mask0` and `mask1`.

`src/SoundReserve.c` reconstructs two functions at
`[0x038001e8, 0x03800378)`: 384 instruction bytes and 16 literal bytes.
Both walk a supplied channel mask, skip mask1 reservations, invoke an existing
voice callback, stop hardware, and clear priority/callback/update/active state.
The reservation variant then ORs the supplied mask into mask0 or mask1.

`src/SoundSequenceInit.c` reconstructs `[0x038005a8, 0x0380060c)`:
92 instruction bytes and eight literal bytes. It clears the active bits of
16 sequence records (36-byte stride) and 32 track records (64-byte stride),
and assigns sequence indices. These arrays remain external BSS dependencies;
this batch makes no new BSS claim.

`src/SoundTrackRead.c` reconstructs the cached byte reader at
`[0x03800948, 0x038009a8)` (88 instruction/eight literal bytes).
`src/SoundReadCache.c` reconstructs cache fill and 24-bit little-endian reads at
`[0x03800e3c, 0x03800ea8)` (104 instruction/four literal bytes). Cache fill
aligns the requested address down to four bytes and copies four words; byte
reads refill outside the cached half-open interval and advance the track cursor.
`src/SoundSequence.h` shares the recovered sequence, track and cache layouts
with compile-time size checks. The cache's first word remains unidentified and
all three arrays/cache storage remain external; no new BSS is counted.

`src/SoundSequenceStart.c` reconstructs two functions at
`[0x038009a8, 0x038009f8)` (72 instruction/eight literal bytes), setting the
running flag directly or after the external preparation call. Preparation's
fourth argument remains unnamed by policy. `src/SoundSequenceParameters.c`
reconstructs two functions at `[0x03800d5c, 0x03800e3c)` (216 instruction/eight
literal bytes), writing byte/halfword/word parameters by offset to a sequence or
selected existing tracks. Unsupported sizes preserve the original no-write path.

`src/SoundTrackVoices.c` reconstructs seven functions at
`[0x03801088, 0x03801250)` (448 instruction/eight literal bytes): set data
cursors, release and detach track voices, look up a sequence track, stop one or
all tracks, and unlink a voice from its track callback. The sequence owns 16
track IDs at `0x08`, with 255 as the missing-track sentinel; tracks hold their
voice-list head at `0x3c`. Lookup preserves the original signed upper-bound check.
The callback's event-one branch clears voice priority and callback before unlinking;
no meaning is assigned to other event values beyond the observed unlink operation.

`src/SoundSequenceStop.c` reconstructs stop and pause at
`[0x038009f8, 0x03800acc)` (200 instruction/12 literal bytes). Stop tears down
an active sequence and clears its bit in optional shared work. Pause stores the
pause flag and releases/detaches voices for each existing track when nonzero.
`src/SoundSequenceRanges.c` reconstructs two range invalidators at
`[0x03800c74, 0x03800d5c)` (224 instruction/eight literal bytes): stop active
sequences when a track cursor or the sequence's offset-0x20 argument lies in an
inclusive interval. The argument's higher-level policy remains unidentified.

`src/SoundTrackAllocation.c` reconstructs allocation and four mute modes at
`[0x03801f5c, 0x03802020)` (192 instruction/four literal bytes). Allocation
marks the first inactive track and returns its index, or -1 when full. Mute
modes optionally release voices, with mode three additionally detaching them.
`src/SoundTrackMask.c` reconstructs two mask-based setters at
`[0x03800b98, 0x03800c74)` (212 instruction/eight literal bytes): apply mute
mode or write the halfword at offset `0x1e` and mark flag bit seven. The halfword's
policy remains unidentified; its name and associated flag retain the offset.

`src/SoundTrackInit.c` reconstructs `[0x03800fa8, 0x03801088)` (224
instruction bytes): reset track flags, cursors, parameter defaults and voice list.
Track modulation stores only the six-byte parameter prefix, now shared explicitly
with the ten-byte voice modulation record; unknown defaults retain offset names.
`src/SoundSequenceAdvance.c` reconstructs `[0x03800acc, 0x03800b98)` (196
instruction/eight literal bytes), releasing track voices, suspending the worker
alarm while advancing ticks, restarting it, and adding processed ticks to shared
work. `src/SoundSequenceVariable.c` reconstructs `[0x03801f18, 0x03801f5c)`
(64 instruction/four literal bytes), returning null without shared work, a local
sequence variable below index 16, or a global variable otherwise. Shared work has
16 records of 16 signed-halfword variables plus a tick counter; global variables
follow the known 0x260-byte prefix, with their count still unidentified.

`src/SoundSharedStatus.c` reconstructs three functions at
`[0x03802328, 0x038023fc)` (200 instruction/12 literal bytes): write a local
or global signed-halfword variable, and sample 16 channel plus two capture active
bits into optional shared work. Shared offsets `0x08` and `0x0a` now identify
those two status masks. Variable writes preserve the original unchecked access.

`src/SoundAlarms.c` reconstructs four functions at
`[0x03802428, 0x038025b0)` (376 instruction/16 literal bytes): configure,
start and stop tagged sound alarms, plus their IPC callback. Eight external
64-byte slots hold active/tag bytes, delay and interval ticks, and a 44-byte OS
alarm. Start uses a timeout for zero interval or an absolute first ring plus
interval otherwise. Stop increments the tag; callbacks send slot index and tag
on IPC command 7, retrying while the send reports failure. Slot storage and its
separate initializer remain fallback; this batch adds no BSS coverage.

`src/SoundCommandInit.c` reconstructs `[0x038025b0, 0x038025f4)`
(52 instruction/16 literal bytes), initializing an eight-entry command queue,
registering IPC handler 7, and clearing the shared-work pointer. Its 64-byte
source BSS at `[0x0380a91c, 0x0380a95c)` contains the 32-byte queue and eight
message pointers; named external aliases retain their observed addresses.
`src/SoundCommandCallback.c` reconstructs `[0x03802ca4, 0x03802cf0)`
(72 instruction/four literal bytes). Under saved/restored IRQ state it queues
messages at or above `0x02000000`, notifies the sound worker for zero, and ignores
other values. The original ignored error argument and nonblocking send are retained.

`src/SoundBankAccess.c` reconstructs the two empty ARM7 bank-access hooks
at `[0x037ff674, 0x037ff67c)` (eight ordinary C instruction bytes).
`src/SoundWaveLookup.c` reconstructs `[0x038021a0, 0x038021e0)` (64
instruction bytes): resolve an entry after the 0x3c-byte archive header, preserve
zero, add the archive base for values below `0x02000000`, and preserve absolute
addresses otherwise. Hook calls remain in order around the lookup. The entry
table is addressed as trailing storage, with no fabricated fixed array bound.

`src/SoundInstrumentStart.c` reconstructs `[0x038021e0, 0x03802328)`
(328 instruction bytes, no literals): resolve PCM archive or direct-wave data,
stage PCM/PSG/noise, set key/velocity and ADSR, and convert instrument pan around
64. Release value 255 clears the release parameter and sets the start argument to
-1. SoundBank.h checks the 10-byte parameter and 12-byte instrument layouts;
unknown link words and voice fields keep explicit names.

`src/SoundAttenuationTable.c` owns 128 signed halfwords at
`[0x038082cc, 0x038083cc)` (256 initialized data bytes), from -32768 to zero.
`src/SoundAttackTable.c` owns 19 unsigned bytes at
`[0x038084e0, 0x038084f3)` for the nonlinear attack branch. The following byte
remains fallback. These 275 bytes are data coverage, separate from function code.

`src/ResetControl.c` reconstructs four functions at
`[0x037fe3e0, 0x037fe4e8)` (236 instruction/28 literal bytes): register IPC
handler 12 once, return the received-reset flag, validate command 16, and perform
the reset sequence. Reset selects IRQ mask `0x40000`, acknowledges pending IRQs,
stops all four DMA channels and sound, sends the reset command until accepted,
and disables IME before the external boot handoff. Two halfword flags own four
BSS bytes at `[0x03809184, 0x03809188)`. Panic strings and the low-level handshake/
entry-point transfer remain explicit binary dependencies.

`src/CpuStatus.c` reconstructs `[0x037fe350, 0x037fe3c8)` (payload
`[0x656c, 0x65e4)`) using minimal MRS/MSR inline assembly to access CPSR and C
masks/returns. Ordinary C cannot express CPU-status-register access. The
coordinating agent reviewed these six bounded exceptions before implementation.
`assembly_exceptions.json` records each range, reason, instructions, evidence,
review scope and byte-verification method. Original assembly authorship remains
unknown. The **entire 120-byte routines** count as reviewed assembly, not C code;
the actual eleven inline-assembly instructions account for 44 of those bytes.
The compiler's uninitialized-variable warnings for MRS outputs are expected:
the assembly initializes those C variables, and the linked instructions are
checked exactly. No extra initialization is inserted to silence the warnings.

`arm7_build.py` compiles each declared unit with `mwccarm` targeting `arm7tdmi`,
links it at its actual runtime address with `mwldarm`, reads its linked ELF,
checks section size, addresses, symbols and bytes, then places it at its original
payload offset. It rejects overlapping units and invalid autoload mappings. All
other payload bytes are retained explicitly as fallback. The linked replacement
is used in the packaged ROM through a generated sibling ROM configuration.
Declared source functions are forced active when linking, so every function in a
multi-function unit remains present; C++ exception tables are disabled.
The compiler object is also checked before linking: initialized allocated input
sections must be `.text` for code units or `.rodata` for data-only units, and
their sizes must sum to the declared unit. Declared
`.bss` must match its owned extent exactly. Unexpected data/BSS or discarded code
fails instead of disappearing silently from source-ownership accounting.
For BSS, MWLD emits zero file bytes and a nonzero PT_LOAD memory extent; both the
linked extent and symbol addresses are checked. BSS is never inserted into the
cartridge payload or subtracted from its fallback count. It is reported as
`source_bss_bytes`, separate from initialized data and payload ownership.

This is a source-slice pipeline, not full ARM7 delinking. Add coherent source
units and their verified extents to `source_units.json`. Unit `externals` can
define linker addresses for dependencies; any dependency in unreconstructed
ranges remains fallback. Each source unit emits one `.text` image
(including compiler literal pools) or one standalone `.rodata` image, optionally
with one declared `.bss` range. Data-only units declare `data_bytes` equal to
the whole unit size, zero code/literal credit, and never add function counts.
Mixed initialized sections remain unsupported; no extra sections may be discarded. ARM7 sources live here
so the current recursive ARM9
source discovery does not compile them with ARM9 flags.

On non-Windows hosts pass `--runner ./wibo` (or an absolute Wine executable path)
to prefix both matching-tool invocations. The runner path is resolved before the
link step changes directory. The pipeline has been executed on Windows; its
Wine/Wibo invocation path still needs validation on a non-Windows host.

## Pinned dsd limitation

The pinned `dsd v0.10.2` source was inspected at commit
`561be9b11bc6e61127070d3c5e6ac9533ea825d0`:

- [init.rs](https://github.com/AetiasHax/ds-decomp/blob/561be9b11bc6e61127070d3c5e6ac9533ea825d0/cli/src/cmd/init.rs)
  initializes ARM9, its autoloads and ARM9 overlays only.
- [rom/config.rs](https://github.com/AetiasHax/ds-decomp/blob/561be9b11bc6e61127070d3c5e6ac9533ea825d0/cli/src/cmd/rom/config.rs)
  builds those ARM9 components and rewrites the original ARM7 binary path to
  remain accessible from the new ROM configuration.

The independent pipeline supplies bounded ARM7 source compilation, linking,
comparison and packaging without pretending the dsd configuration supports ARM7.
Full code/data analysis, dependency recovery and source reconstruction remain.
Keep ARM7 coverage separate from the `objdiff` ARM9 report until full compatible
analysis and denominator tracking exist.

`src/BackupTransfer.c` reconstructs four cartridge-backup SPI helpers at
`[0x03802f38, 0x038030b0)` (352 instruction/24 literal bytes). The transfer loop
sets AUXSPICNT, polls busy, dispatches byte callbacks, and clears control after
the last byte. Read, write and compare callbacks preserve volatile halfword I/O;
comparison failure limits the remaining transfer to its final byte. The proven
16-byte transfer record at `0x0380af84` remains an external BSS dependency.

`src/BackupWait.c`, `src/BackupStatus.c` and `src/BackupWriteEnable.c`
reconstruct four backup polling/command functions (324 instruction/36 literal
bytes). Polling uses an initial delay and intervals of at most five before
recording a timeout; the readiness wrapper translates the observed result codes
without inferring their broader policy. Read-status and write-enable command
bytes remain binary data dependencies. `BackupTransfer.h` shares the recovered
transfer layout and compatible callback declarations across all four units.

`src/BackupIO.c` reconstructs three backup read/write/program functions at
`[0x038031dc, 0x038033b8)` (440 instruction/36 literal bytes). Both writing
operations split data at page boundaries, issue write-enable and address commands,
then wait using their request-specific delay fields. The shared request prefix
records the result, page size, address width and observed delay values; unknown
fields remain uninterpreted and the worker storage remains external.

`src/BackupErase.c` reconstructs four comparison and erase functions at
`[0x038033b8, 0x038035dc)` (504 instruction/44 literal bytes). Comparison maps
its callback result into the request result; sector/subsector erases enforce
alignment and stop after an error, while chip erase uses its separate command
and delay pair. Known erase sizes and timing fields extend the shared request
prefix. No command bytes or shared-state storage are claimed as source data.

`src/BackupAddress.c`, `src/BackupStatusInit.c` and `src/BackupStatusWrite.c`
reconstruct three address/status helpers (372 instruction/28 literal bytes).
The address encoder preserves one-, two- and three-byte command packing under
the original supported-width precondition. Status initialization honors the
255 skip value and one-time flag; writes retry up to ten times on result 4.
The requested initial status byte at offset `0x54` extends the request prefix.

`src/CardCommand.c` and `src/CardIdentity.c` reconstruct five cartridge command/
identity functions (236 instruction/24 literal bytes): wait for ROMCTRL idle and
write the command bytes, derive transfer flags, preserve the empty hook, read the
card ID, and serialize that read through the external operation begin/complete
functions. Hardware accesses retain their byte/word widths and volatile polling.
The header pointer and worker synchronization remain explicit dependencies.

`src/CardOperationBegin.c` and `src/CardIpcCallback.c` reconstruct two worker
synchronization functions (308 instruction/4 literal bytes). Operation begin
blocks on the busy flag, then records the callback under IRQ protection. The IPC
callback accumulates request state and wakes the worker or current waiting thread.
The recovered worker prefix includes its embedded 0xa4-byte thread and wait list;
`ThreadContext.h` shares the established layout with thread creation/priority.
Worker flags are volatile. No worker BSS ownership is inferred from this prefix.

`src/CardRemovalInit.c` and `src/CardRemovalCheck.c` reconstruct four removal
initialization/detection functions (332 instruction/32 literal bytes). Detection
selects a locked card-ID comparison or hardware IRQ status and latches removal.
The shared flags, removal callback and owner allocator remain explicit external
dependencies; `CardRemoval.h` records the observed state layout without claiming BSS.
