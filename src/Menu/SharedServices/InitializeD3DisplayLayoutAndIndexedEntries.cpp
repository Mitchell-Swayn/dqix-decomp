#include <globaldefs.h>
#include <GameState/GameState.h>
extern "C" unsigned TextContext_GetSharedInstance();
extern "C" void SoundSfx_StartCurrentSequenceArchiveEntry(char*, int, void*);
extern "C" void GameState_WriteUnknownF70(GameState*, unsigned char);
extern "C" void SaveData_ResetTransferProgress(unsigned char*);
extern "C" void Menu_AllocateAndAppendTextLabelWidget(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned char);
extern "C" void Menu_BindExistingWidgetToSelectionGridCell(void*, int, int, int);
extern "C" void* TitleMenu_ConfigureTextCanvasAndAdvanceCharacterOffset(void*, int, int, int);
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov004 @ 0x2171034; symbol: data_ov004_02171034.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" unsigned char InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov004 @ 0x0216D004; symbol: func_ov004_0216d004; size: 0x184.
// Initializes the D3 display layout and its paired indexed entries.
extern "C" int InitializeD3DisplayLayoutAndIndexedEntries(void* self) {
    unsigned char* display = (unsigned char*)TextContext_GetSharedInstance();
    display[0x1000 + 0x9ca] = 0;
    SoundSfx_StartCurrentSequenceArchiveEntry((char*)Main_UnknownRoleZeroInitializedStorage, 5, 0);
    GameState_WriteUnknownF70(GameState::GetInstance(), 0);
    SaveData_ResetTransferProgress(*(unsigned char**)(InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage + 0x10));
    InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage[2] = 1;
    if (InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage[3] == 4) {
        Menu_AllocateAndAppendTextLabelWidget((unsigned)self, 0x38, 2, 0xd3, 0x3d, 0xc, 6, 0xc, 1);
        Menu_AllocateAndAppendTextLabelWidget((unsigned)self, 0x39, 2, 0xd3, 0x3e, 0xc, 0x14, 0xc, 1);
    } else {
        Menu_AllocateAndAppendTextLabelWidget((unsigned)self, 0x38, 2, 0xd3, 0x23, 0xa, 6, 0xa, 1);
        Menu_AllocateAndAppendTextLabelWidget((unsigned)self, 0x39, 2, 0xd3, 0x35, 0xa, 0x14, 0xa, 1);
    }
    for (int i = 0; i < 2; ++i)
        Menu_BindExistingWidgetToSelectionGridCell(self, 0x12d, i + 0x38, i);
    TitleMenu_ConfigureTextCanvasAndAdvanceCharacterOffset(self, 0xd3, 0x60, 0);
    return 0;
}
