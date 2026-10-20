struct WindowCanvasOwner;
struct WindowCanvasRecord;
struct Owner;
struct Record;
#include <globaldefs.h>
#include <GameState/GameState.h>
#include <std_library_functions.h>
ARM

typedef unsigned int undefined4;

extern "C" unsigned int TextContext_GetSharedInstance();
extern "C" GameObject* GameState_GetObjectWithFlag100(GameState* state, int index);
extern "C" ARM undefined4 GameObject_GetLinkedIndexedState(int param_1);
extern "C" unsigned int GameState_GetIndexedWordIfValid(void* table, int index);
extern "C" void Text_InitializeAndPopulateBoundedOutputBuffer(int size, char* out);
extern "C" void TextMarkup_ExpandAndWrapText(void* p, int unused, void* a, void* b, int c, int d, unsigned flags);
extern "C" WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner* self, unsigned id);
extern "C" int Window_ReplaceCanvasTextById(Owner* self, unsigned id, void* data, unsigned arg, unsigned char flag);
extern "C" int Window_PushTextCanvas(...);

// Original: arm9/ov000 @ 0x0217964C; symbol: func_ov000_0217964c; size: 0x150.
// Builds wrapped description text for the selected carried-item record and either
// replaces ready canvas 0x24 or pushes a new canvas using that record's coordinates.
extern "C" void BattleMenu_UpdateCarriedItemDescriptionWindow(char* self, char* record) {
    if (!record)
        return;

    char* scratch = *(char**)(TextContext_GetSharedInstance() + 0x5c);
    memset(scratch, 0, 0x960);

    int object = (int)GameState_GetObjectWithFlag100(GameState::GetInstance(), *(int*)(record + 0x4c));
    if (!object)
        return;
    GameObject_GetLinkedIndexedState(object);

    unsigned int entry = GameState_GetIndexedWordIfValid(record, *(signed char*)(record + 0x22));
    if (!entry)
        return;
    if (*(signed short*)(entry + 0x18) <= 0)
        return;
    Text_InitializeAndPopulateBoundedOutputBuffer(*(signed short*)(entry + 0x18), scratch);

    char wrap[0x800];
    TextMarkup_ExpandAndWrapText((void*)TextContext_GetSharedInstance(), 0xa, scratch, wrap, 0x72, 0, 0);

    char* text = wrap;
    char* panel = self + 0x188;
    if (Window_FindActiveCanvasById((WindowCanvasOwner*)panel, 0x24)) {
        Window_ReplaceCanvasTextById((Owner*)panel, 0x24, text, 1, 0);
        return;
    }

    int x = *(int*)(record + 0x44);
    int y = *(int*)(record + 0x48);
    *(short*)(panel + 0xa0) = 0x10;
    *(short*)(panel + 0xa2) = 8;
    *(short*)(panel + 0xa4) = (short)((x >> 3) + 0x10);
    *(short*)(panel + 0xa6) = (short)(y >> 3);
    *(short*)(panel + 0xa8) = 7;
    *(short*)(panel + 0xaa) = 5;
    *(short*)(panel + 0xac) = 0xa;
    *(short*)(panel + 0xae) = 0xe;
    *(unsigned char*)(panel + 0xb1) = 0x24;
    Window_PushTextCanvas(panel, text, 0, 0, 0, 1, 0, 0);
}
