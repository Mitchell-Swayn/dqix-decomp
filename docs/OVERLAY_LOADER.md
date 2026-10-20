# Overlay loader subsystem

The overlay loader owns indexed overlay loading and cleanup, the current six-slot bank and two selection stacks. `config/usa/overlay_loader_symbols.json` records its18 reviewed routine identities and address-qualified call relationships. This boundary follows shared data, complete function bodies, callers and callees; proximity alone does not establish membership.

## Loading and cleanup

`OverlayLoader_LoadOverlay` validates the overlay ID against35 entries. If the requested overlay already occupies its mapped slot, it returns success. Otherwise it runs cleanup for the old occupant, reads compressed overlay data, decompresses and invokes static initialization, then publishes the new slot ID. Resource locking and the shared busy flag serialize transitions.

`OverlayLoader_LoadOverlayWithVmRead` uses a NitroVM read and waits for completion before finalizing decompression/static initialization. It is called by the overlay33/34 backgroundloader path. Its paired cleanup entry has the same operations as the synchronous cleanup function; the suffix identifies its established calling route.

Cleanup temporarily marks the mapped slot with ID|0x40, runs registered callbacks for the overlay memory region under the resource lock, and clears the slot to0xFF. Neither cleanup entry reads overlay data. The low-level adapter020CD584 runs region cleanup and returns success; generic runtime callback-list management remains outside this subsystem.

Eight banks hold six signed byte slots each. The reset helper writes six bytes, not six words; initialization uses it for every bank. Existing `IsSceneLoaded` checks the selected bank through `SceneEntry.group` and retains its established C++ name and source unit.

## Selection stacks

Two independent selection stacks each hold up to eight indices. Each accepts indices below seven and maps them to an overlay ID before loading. Pop optionally reloads the prior top selection. Empty getters return minus one. Primary and secondary identify storage banks, not a guessed gameplay distinction.

| Storage | Primary | Secondary |
|---|---|---|
| Depth | 02109DA4[0] | 02109DA4[1] |
| Selection buffer | 02109DAE | 02109DA6 |
| Overlay mapping | 020F1962 | 020F1977 |

## Routine inventory

| Original main address | Current name | Source status |
|---|---|---|
| 0x020a1838 | `OverlayLoader_InitializeMutexSlotsAndMetadata` | preserved-existing |
| 0x020a18d4 | `OverlayLoader_ClearSixSlotEntries` | matched-source |
| 0x020a18f4 | `_Z13IsSceneLoadedj` | preserved-existing |
| 0x020a1940 | `OverlayLoader_LoadOverlay` | unreconstructed-symbol |
| 0x020a1a40 | `OverlayLoader_LoadOverlayWithVmRead` | unreconstructed-symbol |
| 0x020a1bb4 | `OverlayLoader_CleanupOverlay` | matched-source |
| 0x020a1ccc | `OverlayLoader_CleanupOverlayForVmRead` | matched-source |
| 0x020a1de4 | `OverlayLoader_ResetPrimarySelectionStack` | matched-source |
| 0x020a1df8 | `OverlayLoader_PushPrimarySelection` | matched-source |
| 0x020a1e54 | `OverlayLoader_PopPrimarySelectionAndOptionallyRestoreOverlay` | matched-source |
| 0x020a1eb0 | `OverlayLoader_GetPrimarySelectionOrMinusOne` | matched-source |
| 0x020a1edc | `OverlayLoader_ResetSecondarySelectionStack` | matched-source |
| 0x020a1ef0 | `OverlayLoader_PushSecondarySelection` | matched-source |
| 0x020a1f4c | `OverlayLoader_PopSecondarySelectionAndOptionallyRestoreOverlay` | matched-source |
| 0x020a1fa8 | `OverlayLoader_GetSecondarySelectionOrMinusOne` | matched-source |
| 0x020a1fd4 | `OverlayLoader_SetSecondarySelection` | matched-source |
| 0x020a1ffc | `OverlayLoader_InitializeSlotBankAndReturnPointer` | matched-source |
| 0x020cd584 | `OverlayLoader_RunRegionCleanupAndReturnSuccess` | matched-source |

## Source boundaries

Matched units live under `src/System/Overlay/`; the meaningful existing `src/System/SceneOverlays.cpp` API remains intact. The two unreconstructed load functions receive symbol names without reconstruction credit. Filesystem metadata/read operations, SDK locks and generic runtime cleanup keep their existing subsystem/ABI names. A caller loading an overlay does not thereby become part of the loader subsystem.

The original ABI, types, constants and bodies are preserved. Only names, provenance records and source paths change. The original overlay identity remains part of each address-qualified record.
