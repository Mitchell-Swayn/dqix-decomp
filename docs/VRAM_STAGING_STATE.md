# VRAM staging allocation state

`Graphics/itcm/VRAMStagingAllocations.cpp` defines the established
`g_vramStagingAllocations[0x80]` array at `0x01ffdf70..0x01ffe270`: 768 bytes of
ITCM BSS. Each six-byte descriptor stores a staging-buffer offset, byte size and
flags. The existing allocator examines all 128 descriptors, builds a temporary
sorted list of active spans and reuses a free descriptor. Release clears its
allocated flag. A compile-time check protects the descriptor size.

The complete array object compares at 100%. Moving its declaration into the
shared staging header leaves the existing ITCM consumer's compiled instruction
bytes and relocation entries unchanged. Full USA ROM/module/symbol/SHA-1 checks
pass. The 768-byte matched-data gain is entirely BSS; code, initialized-data and
coverage denominators are unchanged.

## Regional task sets and task queue

`VRAMStagingRegionSets.cpp` defines ten twelve-byte regional task-set records
at `0x01ffdd78..0x01ffddf0`, 120 bytes BSS. Startup at `0x020e6790` assigns each
record a task-index buffer and a capacity. The records hold that pointer,
capacity, separate regular/high-priority counts and total count. Nine original
interior labels are preserved through module-local linker aliases; their symbol
metadata describes zero-sized points within the complete 120-byte array.

`VRAMStagingTaskQueue.cpp` defines 256 sixteen-byte tasks at
`0x01ffe270..0x01fff270`, 4,096 bytes BSS. The earlier deferred trial treated
`data_01fff270` as a possible trailing object. Further evidence identifies it as
the one-past pointer used by `GetTaskByID`, `CancelAllTasksInRegion` and
`CancelOverwrittenTasks`: their original literals at `0x01ff88c0`, `0x01ff8fb4`
and `0x01ff9058` name precisely `&g_vramStagingTaskQueue[0x100]`. Its metadata now
has zero size, and its linker alias adds `0x1000` to the queue base.

The original LCF aligns `ITCM_BSS_END` to 32 bytes, supplying the final 16-byte
gap from `0x01fff270` to `0x01fff280`. Including this alignment extent in the queue
delink owner prevents the obsolete fallback endpoint definition from shadowing
the linker alias. Source allocates only the 4,096-byte array; no padding field,
extra retained object or source reference was introduced.

The regional array compares at 100%. The queue array symbol also compares at
100%, while its original `.bss` section includes 16 alignment bytes absent from
the compiler object. Consequently the measured matched-data report gains only
120 bytes for this batch: the queue receives no matched-data credit. Source BSS
definitions cover 4,216 bytes; the 16 linker-alignment bytes remain separate.
Total data/code/function denominators are unchanged. Full module/symbol/ROM
checks and the USA SHA-1 pass. Existing consumer instructions and relocations
remain unchanged.

Module-local `linker_symbols.json` files validate names against their sibling
module `symbols.txt`, then require exactly one owning input section within that
module's LCF output section. Cross-module ownership is rejected. Ninja tracks
each alias config and symbol file. Fourteen focused tests include real pinned
linker checks of alias addresses, pointer relocations and the one-past BSS
endpoint with its 16-byte alignment gap. Verbose evidence stays in ignored
`build/sol61-regional-*` files.
