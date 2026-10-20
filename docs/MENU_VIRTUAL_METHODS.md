# Shared menu record virtual methods

The shared ov023 menu records and the ov004 quest-message-panel record use corresponding
virtual slots. The table addresses and ordered function relocations establish
slot membership; concrete implementations establish supported operations.
An empty body alone establishes only that the operation is ignored.

| Slots | Contract evidence |
|---|---|
| `0x04`, `0x08` | Secondary rendering and draw passes; model and zone render records supply implementations. |
| `0x0C`, `0x10`, `0x14` | Layer screen-buffer clear, destination cache clean and background-load refresh. |
| `0x24`–`0x48` | X confirmation enable, X/Y state routes, confirm route and confirm callback. |
| `0x4C`–`0x80` | Selection/page change, Select, Up, Down, Y and X callbacks, in setter/query pairs. |
| `0x84`–`0xA0` | Right, Left, L and R callbacks, in setter/query pairs. Grid implementations store the corresponding callback identifiers. |
| `0xA4`, `0xA8` | Touch-press callback setter and query. |
| `0xAC` | Combined touch press, held and release callback setter. |
| `0xB0`, `0xB4` | Touch-repeat callback setter and query. |
| `0xB8` | Selection eligibility or containment query. |
| `0xC8`, `0xCC` | Auxiliary vector setter and getter; text records use the vector for the cursor offset. |
| `0xD8`, `0xDC` | Display-mode/style setter and query; the concrete meaning depends on record kind. |
| `0xE0`, `0xE4` | Numeric value setter and query. |
| `0xE8` | Zone-state query. |
| `0xEC` | Linked data or script execution context query. |
| `0xF0`, `0xF4` | Positive and negative temporary draw offsets. Sprite drawing consumes and resets their flags. |
| `0xF8` | Record activity/containment query used during group dispatch; concrete predicates differ by record kind. |

The sprite-cell update routine at `arm9/ov023:021faed0` consumes touch callback
identifiers at object offsets `0x3C`, `0x3E`, `0x40` and `0x42`. Its press/held/
release branches and repeat countdown distinguish these fields. The three-argument
setter at `arm9/ov023:021fb23c` fills the first three fields; the separate setter
at `arm9/ov023:021fb24c` fills the repeat field.

## Script adapters

The ov011 script adapters locate records through the same display-record
registry and invoke the shared virtual interface. `MenuScript_SetRecord*`
functions expose confirmation, selection/page changes, X/Y routes, directional
callbacks and touch callbacks. The paired adapters set Up/Down, Right/Left and
L/R callbacks in that order. `MenuScript_SetGridSelectCallback` and
`MenuScript_SetGridYCallback` explicitly require record kind 7; the selection-grid
initializer establishes that discriminator.

The direct menu script setters configure grid cancel state/callback and wrapping,
and sprite-cell touch rectangles, palette and priority overrides.
`MenuScript_SetGridCancelCallbackReturningZero` writes the callback but always
returns zero; the ordinary cancel-callback setter returns one after writing.
Both preserve the original behavior.

The touch triple adapter invokes slot `0xAC` with press, held and release
identifiers. These adapters preserve their existing return behavior: some fail
when the record is absent, while paired/triple setters return one even when no
record is found. Naming the interface does not change these contracts.

## Unresolved contracts

Slots `0xBC` and `0xC0` currently have only constant-zero implementations in the
recovered table set. Their purpose remains unproven. Slot `0xC4` updates a bounded
layer entry, but the common interface meaning is unresolved. Slots `0xD0` and
`0xD4` have special flag-query and flag-update implementations; their shared
menu interface contract requires further caller analysis. The corresponding
empty/default methods retain explicit uncertainty and their slot qualifiers.

The method evidence is retained per module/address in
`config/usa/function_names.json`. Original source paths and their current locations
are recorded in `config/usa/source_layout.json`.

`Menu_CreateQuestMessagePanelDescriptor` (`arm9/ov011:02187e20`) installs
virtual table `0x021705f8` on the allocated record. Its initializer at
`arm9/ov004:02167820` sets record kind `0x15`, creates a private `0x2800`-byte
arena and initializes the embedded `QuestMessagePanel` at offset `0x34`.
The update at `arm9/ov004:021678d8` invokes the embedded panel's indicator update;
resource teardown at `arm9/ov004:021678bc` destroys panel resources and its owning
allocator. These construction and lifecycle links establish the descriptive
`QuestMessagePanelRecord` owner used by its virtual defaults. The name describes
the recovered role rather than claiming an original source class name.
These naming changes preserve bodies, signatures, original identity comments and
compilation-unit boundaries. Assembly reference listings remain unreconstructed.
