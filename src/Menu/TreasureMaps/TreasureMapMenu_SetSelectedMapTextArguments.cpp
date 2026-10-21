#include <globaldefs.h>
#include <GameState/GameState.h>
#include <System/Memory.h>
#include <std_library_functions.h>
ARM
#pragma opt_common_subs off
#pragma opt_propagation off

struct State;
struct Buffer;

extern "C" {
int GameState_ReadProtagonistObjectIndex(GameState* state);
void* _ZN9GameState20GetUnknownGameObjectEv(void*);
unsigned int TextContext_GetSharedInstance();
void TextLayout_ResetFormattingWorkspace(signed char* object);
void TextContext_SetIndexedAuxiliaryText(unsigned char* p, int id, const char* text);
void TextContext_SetStringArgument(Buffer* p, int i, const char* s);
void* Menu_GetDisplayRecordRegistry(State* self);
void* MenuRecordList_LocateByKey(void** head, unsigned short value);
unsigned MenuRecord_GetType(void* self);
unsigned Menu_GetSelectedGridRow(void* self);
// Original data: arm9/ov004 @ 0x2171010; symbol: PopulateSelectedRecordTextPanel_UnknownRoleZeroInitializedStorage.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern char* PopulateSelectedRecordTextPanel_UnknownRoleZeroInitializedStorage;
}

// Original: arm9/ov004 @ 0x02164E40; symbol: func_ov004_02164e40; size: 0x108.
// Copies the selected type-7 map record name into a scratch buffer and sets
// text arguments from the unknown game object and that buffer.
extern "C" int TreasureMapMenu_SetSelectedMapTextArguments(void* self)
{
    char name[0x40];
    unsigned ctx = TextContext_GetSharedInstance();
    TextLayout_ResetFormattingWorkspace((signed char*)ctx);
    GameState* state = GameState::GetInstance();
    GameState_ReadProtagonistObjectIndex(state);
    char* object = (char*)_ZN9GameState20GetUnknownGameObjectEv(state);

    void* grid = MenuRecordList_LocateByKey(
        (void**)Menu_GetDisplayRecordRegistry((State*)self), 10);
    if (!grid)
        return 0;
    if (MenuRecord_GetType(grid) != 7)
        return 0;

    unsigned row = Menu_GetSelectedGridRow(grid);
    VectorizedMemset(name, 0, 0x40);

    char* table = PopulateSelectedRecordTextPanel_UnknownRoleZeroInitializedStorage;
    int offset = row * 0x1c4;
    char* kindPtr = table;
    kindPtr = kindPtr + 0xd5;
    kindPtr = kindPtr + 0xa00;
    unsigned char kind = *(unsigned char*)(kindPtr + offset);
    if (kind == 1) {
        char* src = table + 0xb20;
        src += offset;
        src += 0x63;
        strcpy(name, src);
    } else if (kind == 2) {
        char* src = table + 0xb20;
        src += offset;
        src += 0xf8;
        strcpy(name, src);
    }
    if (object)
        TextContext_SetStringArgument((Buffer*)ctx, 0, *(const char**)(object + 0x134));
    TextContext_SetIndexedAuxiliaryText((unsigned char*)ctx, 0, name);
    return 0;
}
