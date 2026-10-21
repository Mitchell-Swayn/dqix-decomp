#include <globaldefs.h>
ARM
#pragma opt_propagation off

struct State;
struct CallbackObject {
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void select(unsigned);
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void activate(unsigned);
};

extern "C" {
void Menu_AllocateAndAppendTextLabelWidget(unsigned owner, unsigned key, unsigned allocatorKey, unsigned value, unsigned a, unsigned b, unsigned c, unsigned d, unsigned char enabled);
void* TitleMenu_ConfigureTextCanvasAndAdvanceCharacterOffset(void*, int, int, int);
void GameState_UpdateIndexedNodeIfTypeSeven(State* state, int value);
void Menu_BindExistingWidgetToSelectionGridCell(void*, int, int, int);
void Menu_SelectGridEntryAndRefreshCursor(void*, int, int);
void TitleMenu_BindMappedActivationCallbacks(State* self, unsigned short key, int value, int direct);
void SoundSfx_StartCurrentSequenceArchiveEntry(char* p, int a, void* b);
void* Menu_GetDisplayRecordRegistry(State* self);
void* MenuRecordList_LocateByKey(void** head, unsigned short value);
// Original data: arm9/ov004 @ 0x2171034; symbol: InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern unsigned int InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x2108760; symbol: Main_UnknownRoleZeroInitializedStorage.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned char Main_UnknownRoleZeroInitializedStorage[];
}

// Original: arm9/ov004 @ 0x0216D358; symbol: func_ov004_0216d358; size: 0x1ac.
// Builds the quick-save confirmation labels and grid, invokes the type-0x38
// select/activate callbacks, and starts the confirmation sound.
extern "C" int TitleMenu_BuildQuickSaveConfirmation(void* self)
{
    unsigned int* storage = InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage;
    unsigned a = 0x3a;
    int saved = (int)storage[3];
    Menu_AllocateAndAppendTextLabelWidget((unsigned)self, 0x37, 2, 0xd4, a, 0xa, 0xa, 0xc, 1);
    saved = (int)TitleMenu_ConfigureTextCanvasAndAdvanceCharacterOffset(self, 0xd4, saved, 1);
    GameState_UpdateIndexedNodeIfTypeSeven((State*)self, 0x12d);
    Menu_AllocateAndAppendTextLabelWidget((unsigned)self, 0x38, 2, 0xd3, 0x3d, 0xa, 6, 0xc, 1);
    Menu_AllocateAndAppendTextLabelWidget((unsigned)self, 0x39, 2, 0xd3, 0x3e, 0xa, 0x14, 0xc, 1);
    int grid;
    int i = 0;
    grid = 0x12d;
    goto compare;
    for (;;) {
        Menu_BindExistingWidgetToSelectionGridCell(self, grid, i + 0x38, i);
        i = i + 1;
    compare:
        if (i < 2)
            continue;
        break;
    }
    Menu_SelectGridEntryAndRefreshCursor(self, 0x12d, 1);
    CallbackObject* found = (CallbackObject*)MenuRecordList_LocateByKey(
        (void**)Menu_GetDisplayRecordRegistry((State*)self), 0x38);
    if (found) {
        found->select(9);
        found->activate(9);
    }
    TitleMenu_BindMappedActivationCallbacks((State*)self, 0x39, 0x64, 0);
    TitleMenu_ConfigureTextCanvasAndAdvanceCharacterOffset(self, 0xd3, saved, 0);
    SoundSfx_StartCurrentSequenceArchiveEntry((char*)Main_UnknownRoleZeroInitializedStorage, 5, 0);
    return 0;
}
