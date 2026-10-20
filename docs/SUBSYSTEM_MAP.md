# Feature-based subsystem structure

`docs/subsystem-map-usa.json` groups the 14,771 inventoried ARM9 functions into
81 game-feature and shared-service groups. Feature ownership is the primary
hierarchy. Modules and loaded addresses remain location metadata; an overlay is
not a subsystem. ARM7 remains outside this inventory.

## Ownership and source layout

Bestiary, character creation, equipment, quests, titles, treasure-map menus,
mini-medal rewards, status/profile screens and shared menu infrastructure have
separate owners. Town facilities separate tavern recruitment, resting, vocation
changes, church services, banking, shopping, alchemy and canvassed guests.
Battle-menu command selection, party panels, targeting and palette helpers share
`src/Combat/BattleMenu/`, including helpers previously grouped with turns, scene
and action presentation. Music, sound effects and sound resources are explicit
engine features.

Reviewed behavior scopes identify features across module boundaries. Character
creation spans `ov009`, `ov021` and shared `ov023` code. The quest-message-panel
framework spans main ARM9, `ov004` and `ov011`. Generic helpers whose precise
feature ownership is unresolved stay in named shared-service groups; they are
not assigned a gameplay purpose based on a caller alone. Existing reviewed broad
boundaries supply the fallback for these shared services.

Each feature records binary ranges, source-directory policy, module metadata and
representative function anchors. The ranges index function locations and do not
define the feature hierarchy. No module-prefixed chunk identifiers remain.

Feature-owned source units use `src/<category>/<feature>/`, for example:

- `src/Menu/Bestiary/`
- `src/Menu/CharacterCreation/`
- `src/Menu/Quests/`
- `src/Town/Bank/`
- `src/Online/Settings/`
- `src/GameState/Statistics/` for main ARM9 statistics helpers.

Module identity is retained in symbol/delink maps and original-location comments.
Established engine/core class
units retain their existing directories unless a feature-specific owner is
proven. Whole compilation units that implement multiple features retain their
class-oriented source file; the map can classify their functions separately.
Compilation units are not split for directory organization. Relative sibling
header dependencies retain their existing paths.

Dedicated runtime support, initialized data and unreconstructed assembly retain
their existing policies. Assembly-reference filenames and original identity
comments remain unchanged; listings live under processor directories without
overlay folders. A source-path move earns no decompilation credit.

## Feature groups

Counts include named, uncertain and unreconstructed functions. They are an
inventory, not a completion percentage.

### Engine

| Feature | Functions | Source directory |
|---|---:|---|
| Runtime and startup (`SYSTEM-RUNTIME`) | 332 | Established class/service directories |
| Platform services and hardware (`SYSTEM-PLATFORM`) | 313 | Established class/service directories |
| Display and VRAM (`GRAPHICS-DISPLAY`) | 204 | Established class/service directories |
| Files, archives and background loading (`FILESYSTEM-ARCHIVES`) | 391 | Established class/service directories |
| Resource management (`RESOURCE-MANAGEMENT`) | 470 | Established class/service directories |
| Models, animation and 3D rendering (`GRAPHICS-3D`) | 379 | Established class/service directories |
| Sprites, tilemaps and fonts (`GRAPHICS-2D`) | 213 | Established class/service directories |
| Messages and text formatting (`TEXT-MESSAGES`) | 352 | Established class/service directories |
| Windows and selection widgets (`UI-WIDGETS`) | 355 | Established class/service directories |
| Save data and card backup (`SAVE-DATA`) | 122 | Established class/service directories |
| Local wireless transport (`NETWORK-LOCAL`) | 222 | Established class/service directories |
| Boot screens (`BOOT-SCREENS`) | 18 | `src/System/Boot/` |
| Startup and support services (`STARTUP-SUPPORT`) | 22 | `src/System/Startup/` |
| Read-error screens (`ERROR-SCREENS`) | 5 | `src/System/ErrorScreens/` |
| Music playback (`SOUND-MUSIC`) | 30 | `src/Sound/Music/` |
| Sound effects (`SOUND-EFFECTS`) | 18 | `src/Sound/Effects/` |
| Sound resources (`SOUND-RESOURCES`) | 12 | `src/Sound/Resources/` |

### Game core

| Feature | Functions | Source directory |
|---|---:|---|
| Actors and object lifecycle (`ACTORS`) | 847 | Established class/service directories |
| Camera and motion tracks (`CAMERA`) | 136 | Established class/service directories |
| World, zones and placement (`WORLD`) | 710 | Established class/service directories |
| Script VM and commands (`SCRIPT-VM`) | 541 | Established class/service directories |
| Party and persistent game state (`GAME-STATE`) | 395 | Established class/service directories |
| Grotto generation and treasure maps (`GROTTO-GENERATION`) | 107 | Established class/service directories |
| Statistics and records (`STATISTICS`) | 63 | `src/GameState/Statistics/` |
| Inventory and item ownership (`INVENTORY`) | 34 | `src/GameState/Inventory/` |

### Battle

| Feature | Functions | Source directory |
|---|---:|---|
| Battle turns and status effects (`BATTLE-TURNS`) | 321 | `src/Combat/Turns/` |
| Battle scene and participants (`BATTLE-SCENE`) | 132 | `src/Combat/Scene/` |
| Battle presentation commands (`BATTLE-COMMANDS`) | 148 | `src/Combat/Commands/` |
| Battle menus and command selection (`BATTLE-MENUS`) | 226 | `src/Combat/BattleMenu/` |
| Damage, healing and effects (`BATTLE-FORMULAS`) | 270 | `src/Combat/Formulas/` |
| Enemy decisions and targeting (`BATTLE-AI`) | 303 | `src/Combat/AI/` |
| Skill and spell presentation (`BATTLE-PRESENTATION`) | 303 | `src/Combat/Presentation/` |
| Special effect scenes (`BATTLE-SPECIAL-EFFECTS`) | 24 | `src/Combat/SpecialEffects/` |
| Battle results and growth (`BATTLE-RESULTS`) | 44 | `src/Combat/Results/` |

### Field

| Feature | Functions | Source directory |
|---|---:|---|
| Field scene and encounters (`FIELD-SCENE`) | 387 | `src/Field/Scene/` |
| Field events and triggers (`FIELD-EVENTS`) | 332 | `src/Field/Events/` |
| Multiplayer party synchronization (`FIELD-MULTIPLAYER`) | 302 | `src/Field/Multiplayer/` |
| Field screens and transitions (`FIELD-SCREENS`) | 173 | `src/Field/Screens/` |
| Pitfall placement (`PITFALLS`) | 3 | `src/Field/Pitfalls/` |

### Event

| Feature | Functions | Source directory |
|---|---:|---|
| Cutscene scenes and resources (`CUTSCENE-SCENE`) | 297 | `src/Event/Cutscenes/` |
| Cutscene motion and commands (`CUTSCENE-MOTION`) | 212 | `src/Event/Motion/` |
| Staff roll (`CREDITS`) | 34 | `src/Event/Credits/` |
| Movie playback (`MOVIES`) | 85 | `src/Event/Movies/` |

### Town

| Feature | Functions | Source directory |
|---|---:|---|
| Shared facility services (`TOWN-SERVICES`) | 260 | `src/Town/SharedServices/` |
| Alchemy and Krak Pot (`ALCHEMY`) | 132 | `src/Town/Alchemy/` |
| Mini-medal rewards (`MINI-MEDALS`) | 29 | `src/Town/MiniMedals/` |
| Tavern and party recruitment (`TAVERN`) | 42 | `src/Town/Tavern/` |
| Inn and resting (`INN`) | 40 | `src/Town/Inn/` |
| Vocation changes (`VOCATIONS`) | 32 | `src/Town/Vocations/` |
| Church services (`CHURCH`) | 29 | `src/Town/Church/` |
| Banking (`BANK`) | 26 | `src/Town/Bank/` |
| Shops (`SHOPS`) | 43 | `src/Town/Shops/` |
| Canvassed guests and tag mode (`GUESTS`) | 38 | `src/Town/Guests/` |

### Menus

| Feature | Functions | Source directory |
|---|---:|---|
| Party items, spells and skills (`PARTY-MENU`) | 213 | `src/Menu/Party/` |
| Shared menu services (`MENU-SHARED`) | 300 | `src/Menu/SharedServices/` |
| Equipment menu (`EQUIPMENT-MENU`) | 89 | `src/Menu/Equipment/` |
| Battle records and party talk (`RECORDS-MENU`) | 63 | `src/Menu/Records/` |
| Character creation (`CHARACTER-CREATION`) | 57 | `src/Menu/CharacterCreation/` |
| Tag-mode profile editor (`TAG-PROFILE`) | 71 | `src/Menu/TagProfile/` |
| Skill point allocation (`SKILL-ALLOCATION`) | 40 | `src/Menu/SkillAllocation/` |
| Bestiary (`BESTIARY`) | 71 | `src/Menu/Bestiary/` |
| Shared menu panels (`MENU-PANELS`) | 346 | `src/Menu/Panels/` |
| Menu records and widgets (`MENU-RECORDS`) | 352 | `src/Menu/RecordsFramework/` |
| Menu layouts and script adapters (`MENU-LAYOUTS`) | 167 | `src/Menu/Layouts/` |
| Quest menu (`QUESTS`) | 17 | `src/Menu/Quests/` |
| Titles and accolades (`TITLES`) | 42 | `src/Menu/Titles/` |
| Treasure-map menus (`TREASURE-MAP-MENU`) | 35 | `src/Menu/TreasureMaps/` |
| Character status and profiles (`STATUS-MENU`) | 42 | `src/Menu/Status/` |
| Story summary (`STORY-SUMMARY`) | 3 | `src/Menu/StorySummary/` |
| Quest message panels (`QUEST-MESSAGE-PANELS`) | 67 | `src/Menu/QuestMessagePanels/` |
| Item details (`ITEM-DETAILS`) | 34 | `src/Menu/ItemDetails/` |
| Character preview (`CHARACTER-PREVIEW`) | 14 | `src/Menu/CharacterPreview/` |
| Menu script bindings (`MENU-SCRIPTS`) | 24 | `src/Menu/ScriptBindings/` |

### Online

| Feature | Functions | Source directory |
|---|---:|---|
| Internet transport and sockets (`ONLINE-SOCKETS`) | 196 | `src/Online/Sockets/` |
| Authentication and download services (`ONLINE-SERVICES`) | 314 | `src/Online/Services/` |
| TLS and cryptography (`ONLINE-SECURITY`) | 241 | `src/Online/Security/` |
| Wi-Fi connection and profiles (`WIFI-CONNECTION`) | 339 | `src/Online/WifiConnection/` |
| WFC settings screens (`WFC-SETTINGS`) | 808 | `src/Online/Settings/` |
| DS Download Play (`DOWNLOAD-PLAY`) | 87 | `src/Online/DownloadPlay/` |
| Online content and transfers (`ONLINE-CONTENT`) | 78 | `src/Online/Content/` |

### Diagnostics

| Feature | Functions | Source directory |
|---|---:|---|
| Model and animation diagnostics (`MODEL-VIEWER`) | 103 | `src/Debug/ModelViewer/` |

## Tools and remaining uncertainty

```sh
python3 tools/subsystem_map.py --output build/subsystem-status.json
python3 tools/subsystem_map.py --packet BESTIARY --output build/packets/bestiary.json
python3 tools/subsystem_map.py --packet CHARACTER-CREATION --output build/packets/character-creation.json
```

The summary reconciles live symbols, `.text`/`.init` delink ownership and source
paths. Packets include current names, source locations, referenced strings and
ROM-derived unambiguous static callers/callees. Indirect calls and ambiguous
overlay references remain incomplete. `folder_for` returns the feature directory
when supplied, otherwise the feature's broad category folder.

The current inventory retains 54 mechanical-name review candidates and 2,145
functions without compiled source (1,345,504 code bytes). No address-only symbols
or inventoried compiled functions under `src/Unclassified/` remain. A separate
matched-source audit tracks explicit uncertainty and temporary labels; its queue
overlaps the mechanical-name queue. Compiler/ABI spellings remain intact.

[Menu virtual methods](MENU_VIRTUAL_METHODS.md), [statistics layout](STATISTICS_RECORD.md)
and [local wireless notices](LOCAL_WIRELESS.md) describe established contracts and
remaining uncertainty. Review new ownership evidence before refining a shared
service into a narrower feature; do not infer semantics from module identity.

Reviewed battle-menu data tables, strings and aliases are documented in
[BATTLE_MENU_DATA.md](BATTLE_MENU_DATA.md).

[DATA_SYMBOLS.md](DATA_SYMBOLS.md) indexes data names, values and semantic review debt.
