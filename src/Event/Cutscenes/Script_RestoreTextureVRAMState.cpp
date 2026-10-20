#include <globaldefs.h>
ARM
class GameState;
struct Record { char bytes[0x70]; };
struct GameResources { char pad[0x2cc]; Record records[28]; };
struct IntegerParameterView;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" GameResources* GameState_ReadPResources(GameState*);
extern "C" void TextureVRAM_SnapshotAllocationBounds(char *p);
extern "C" void Graphics_RestoreTextureImageAndPaletteVRAMState(void*);
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView* parameter);
// Original: arm9/ov001 @ 0x0215EAB0; symbol: func_ov001_0215eab0; size: 0x8C.
extern "C" int Script_RestoreTextureVRAMState(char *params, int count) {
    GameState *state = (GameState *)_ZN9GameState11GetInstanceEv();
    if (!state) return 0;
    GameResources *resources = GameState_ReadPResources(state);
    if (!resources) return 0;
    int index = Script_ReadParameterAsInteger((IntegerParameterView *)params);
    Record *record;
    if (index < 0) {
        record = resources->records;
        record = (Record *)((char *)record + 0xbd0);
    }
    else record = &resources->records[index];
    if (!record) return 0;
    int snapshot = 1;
    if (count >= 2) snapshot = Script_ReadParameterAsInteger((IntegerParameterView *)(params + 8));
    if (snapshot) TextureVRAM_SnapshotAllocationBounds((char *)record);
    Graphics_RestoreTextureImageAndPaletteVRAMState(record);
    return 1;
}
