# Cartridge ARM7 reconstruction

The cartridge ARM7 program is a required executable component, distinct from the
console ARM7 BIOS. The independent source build currently reconstructs **68 C
functions: 6,660 instruction bytes plus 496 bytes of literal pools**. Six necessary
CPU-status routines (120 bytes) are separately reviewed assembly exceptions;
864 bytes of standalone diagnostic data and 316 bytes of BSS now have source
definitions. The other 159,736 payload bytes
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
| Reconstructed C instructions / compiler literal pools | 6,660 / 496 bytes |
| Reconstructed initialized standalone data / reviewed assembly ranges | 864 / 120 bytes |
| Reconstructed BSS / total autoload BSS | 316 / 22,744 bytes |
| Binary fallback | 159,736 bytes |
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
`[0x037fd89c, 0x037fdc50)` (payload `[0x5ab8, 0x5e6c)`), with 896 C
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
source-owned; thread block/unblock and the signed-division runtime helper remain
explicit binary dependencies. Queue instances are caller-owned, so no BSS is
credited by this unit.

`src/Mutex.c` reconstructs six recursive-mutex and owner-list routines at
`[0x037fcca0, 0x037fce1c)` (payload `[0x4ebc, 0x5038)`), with 372 C
instruction bytes and 8 literal bytes. Ownership, recursive reference counts,
blocking and wakeups follow the native thread fields at offsets 0x68/0x6c/0x70.
The thread structure is deliberately partial, and the external scheduler block
at `0x03808fd0` remains unowned BSS. Blocking, wakeup and mutex-list pop helpers
remain binary dependencies; no data bytes are credited by this unit.

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
