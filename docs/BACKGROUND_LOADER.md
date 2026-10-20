# Background file loader subsystem

`Filesystem/BackgroundLoader` owns the BackgroundLoader task queue and its two overlay implementations. The address-qualified inventory in `config/usa/background_loader_symbols.json` covers45 matched functions:35 in the main class unit, five in overlay33 and five in overlay34. Forty established/API or ABI names are retained; five behavior names replace vague or address-only spellings.

## Ownership and organization

The three implementation units live intact under `src/Filesystem/BackgroundLoader/`, with `ov033` and `ov034` retaining module identity. The public BackgroundLoader headers keep their established include paths. Overlay34 local contract headers move with their implementation, preserving relative include resolution and the exact duplicated field declarations. No source units are merged.

The class owns a24-entry task queue, an ExtendedNitroVM reader, a ProcessorContext and scratch storage. Its task records contain paths, ID, packed type/status, allocator/data pointers and a scratch block descriptor. The worker entry repeatedly calls virtual `Process`; overlay-specific dispatch supplies the implementations.

## Queue and storage behavior

File tasks support plain files, GP1 data and named inner files in GP2 archives. Overlay tasks delegate loading/cleanup to System/Overlay. IDs wrap modulo1024. Fence entries block later work until preceding tasks are removed. Queue-full and invalid path-length cases retain their existing halt behavior.

Processing releases the resource mutex around reads/decompression and reconciles the copied task by ID afterward. If a task was removed while work was in flight, the processor releases its allocations. Scratch file blocks grow from the left; GP2 metadata uses the right arena. Archive CRC lets successive tasks reuse a readable archive. Scratch accounting records the rightmost block endpoint and a historical high-water sum.

The two overlay implementations share the queue contract but remain separate. Overlay34 has additional entropy-sampled allocation behavior; this refactor preserves it and does not infer a protection penalty or unify the processors. Overlay34 instance helpers are explicit C shims with dispatch-pointer stores; the original C++ type is not claimed.

## Clarified names

| Previous method/helper | Current name | Contract |
|---|---|---|
| `MaybeWaitIdle` | `PauseQueueAndWaitForInFlightWork` | First releases completed buffers/requeues nonfence tasks, then adds a processing lock and waits until flags78C.3 and GP2operationInFlight are clear under resource mutex. |
| `MaybeReset` | `ResetQueuedTasksAndScratchUsage` | Releases task scratch blocks, zeroes queued task records, resets queue length, left scratch boundary and processlocks; external buffers are not freed here. |
| `MaybeFreeAllocations` | `ReleaseCompletedBuffersAndRequeueTasks` | Frees scratch and external buffers for completed tasks, resets nonfence tasks to unallocated, aborts current reader and updates processing flags. |
| `func_ov034_022a29b8` | `BackgroundLoader_InitializeStaticDispatchInstance` | Installs base dispatch, initializes/resets BackgroundLoader state and installs concrete process dispatch. Explicit C shim; no inferred original C++ class spelling. |
| `func_ov034_022a29e4` | `BackgroundLoader_ResetStaticInstanceToBaseDispatch` | Restores base dispatch then initializes/resets BackgroundLoader state; flags parameter and nominal ABI are retained. Does not claim deallocation. |

`PauseQueueAndWaitForInFlightWork` may leave a processing lock to be removed by its caller. `ResetQueuedTasksAndScratchUsage` resets queued scratch allocations but does not claim to free external allocations. `ReleaseCompletedBuffersAndRequeueTasks` preserves fence entries, aborts reader work and requeues the other task statuses. These differences matter to callers.

## Routine inventory

| Identity | Symbol |
|---|---|
| arm9/main:0202f700 | `_ZN16BackgroundLoader4Task14ZeroInitializeEv` |
| arm9/main:0202f744 | `_Z30BackgroundLoaderThreadFunctionP16BackgroundLoader` |
| arm9/main:0202f760 | `_ZN16BackgroundLoader4Task15GetFullFilenameEPc` |
| arm9/main:0202f798 | `_ZN16BackgroundLoader11GetInstanceEv` |
| arm9/main:0202f7a8 | `_ZN16BackgroundLoader21FreeAllocationsGlobalEv` |
| arm9/main:0202f7c8 | `_ZN16BackgroundLoader13AddLockGlobalEv` |
| arm9/main:0202f7e8 | `_ZN16BackgroundLoader16RemoveLockGlobalEv` |
| arm9/main:0202f808 | `_ZN16BackgroundLoader17InitializeOrResetEv` |
| arm9/main:0202f894 | `_ZN16BackgroundLoader8PopulateEPvji` |
| arm9/main:0202f920 | `_ZN16BackgroundLoader32PauseQueueAndWaitForInFlightWorkEv` |
| arm9/main:0202f984 | `_ZN16BackgroundLoader7AddLockEv` |
| arm9/main:0202f9b4 | `_ZN16BackgroundLoader10RemoveLockEv` |
| arm9/main:0202fa00 | `_ZN16BackgroundLoader14RemoveAllLocksEv` |
| arm9/main:0202fa38 | `_ZN16BackgroundLoader13QueueFileTaskEPKciS1_P13SafeAllocator` |
| arm9/main:0202fc38 | `_ZN16BackgroundLoader16QueueOverlayTaskEjb` |
| arm9/main:0202fcfc | `_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator` |
| arm9/main:0202fd14 | `_ZN16BackgroundLoader12QueueLoadGP1EPKcP13SafeAllocator` |
| arm9/main:0202fd2c | `_ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator` |
| arm9/main:0202fd44 | `_ZN16BackgroundLoader16QueueLoadOverlayEj` |
| arm9/main:0202fd54 | `_ZN16BackgroundLoader8AddFenceEv` |
| arm9/main:0202fdd0 | `_ZN16BackgroundLoader13GetTaskStatusEi` |
| arm9/main:0202fe58 | `_ZN16BackgroundLoader8GetFlag0Ev` |
| arm9/main:0202fe68 | `_ZN16BackgroundLoader21GetDetailedTaskStatusEi` |
| arm9/main:0202fec8 | `_ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj` |
| arm9/main:0202ff34 | `_ZN16BackgroundLoader19GetLoadedFileByNameEPKcPPvPj` |
| arm9/main:0202ffd8 | `_ZN16BackgroundLoader22GetLoadedFileInArchiveEPKcS1_PPvPj` |
| arm9/main:02030090 | `_ZN16BackgroundLoader31ResetQueuedTasksAndScratchUsageEv` |
| arm9/main:02030110 | `_ZN16BackgroundLoader38ReleaseCompletedBuffersAndRequeueTasksEv` |
| arm9/main:020301c8 | `_ZN16BackgroundLoader10RemoveTaskEi` |
| arm9/main:02030310 | `_ZN16BackgroundLoader4TaskaSERKS0_` |
| arm9/main:02030390 | `_ZN16BackgroundLoader17GetNumQueuedTasksEv` |
| arm9/main:02030398 | `_ZN16BackgroundLoader15GetTaskFilenameEiPc` |
| arm9/main:02030400 | `_ZN16BackgroundLoader22AllocateInScratchSpaceEPNS_4Task22ScratchSpaceAllocationEj` |
| arm9/main:02030584 | `_ZN16BackgroundLoader16FreeScratchSpaceEPNS_4Task22ScratchSpaceAllocationE` |
| arm9/main:020305c8 | `_ZN16BackgroundLoader15RefreshCountersEv` |
| arm9/ov033:022a29b8 | `__sinit_Ov33BackgroundLoader.cpp` |
| arm9/ov033:022a2180 | `_Z28PopulateOv33BackgroundLoaderPvji` |
| arm9/ov033:022a21a8 | `_ZN20Ov33BackgroundLoader7ProcessEv` |
| arm9/ov033:022a296c | `_ZN20Ov33BackgroundLoaderC1Ev` |
| arm9/ov033:022a2998 | `_ZN20Ov33BackgroundLoaderD1Ev` |
| arm9/ov034:022a2a04 | `__sinit_ov034_022a2a04` |
| arm9/ov034:022a2180 | `Filesystem_PopulateStaticOverlayBackgroundLoader` |
| arm9/ov034:022a21a8 | `Filesystem_ProcessOverlayBackgroundLoaderTasks` |
| arm9/ov034:022a29b8 | `BackgroundLoader_InitializeStaticDispatchInstance` |
| arm9/ov034:022a29e4 | `BackgroundLoader_ResetStaticInstanceToBaseDispatch` |

## Subsystem boundary

SDK/filesystem reading, archive decompression, allocators, scheduling and mutexes are dependencies. Gameplay/resource objects using the queue do not belong to this subsystem solely because they call it. Existing wrapper prefixes are evidence to investigate, not ownership proof. Flag0 is retained as a raw processing-state flag because the processor writes it on several different paths; it is not renamed to IsIdle or IsQueueEmpty.

The refactor changes names and source placement only. Field layouts, signatures, control flow, strings, constants, dispatch data and initialization ABI symbols are preserved.
