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

## Deferred task queue

The existing `g_vramStagingTaskQueue[0x100]` declaration describes 256 sixteen-byte
tasks at `0x01ffe270..0x01fff270`. An isolated source definition matches this
4,096-byte BSS range at 100%, but extracting it separates the following original
label `data_01fff270`. That unreferenced 16-byte range disappears during linking,
causing the required symbol check to fail. Its purpose and allocation extent
remain unresolved.

The task queue and trailing label retain original fallback ownership. No tail
padding, source object or retention reference was invented. The matching queue
draft remains under ignored `build/VRAMStagingTaskQueue-deferred.cpp`. The
observed missing-symbol result is recorded in
`build/sol61-staging-queue-trial.json`; original/candidate queue comparison
evidence remains under `build/matching/`. The successful final checks are in
`build/sol61-graphics-state-acceptance.log`.
