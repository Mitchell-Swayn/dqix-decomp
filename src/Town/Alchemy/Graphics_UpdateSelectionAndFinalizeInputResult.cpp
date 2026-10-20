#include <globaldefs.h>
ARM
extern "C" int Input_IsKeyMaskNewlyPressed(unsigned short* p,unsigned int mask);
extern "C" void SoundSfx_StartCurrentSequenceArchiveEntry(char* p,int a,void* b);
extern "C" void TextCanvas_ResetDisplayPartByKey(unsigned char *p,int value);
extern "C" void KeyRepeater_Reset(unsigned char* p);
extern "C" void Window_HideAndResetOptionSelection(void **p);
extern "C" int KrakPot_HandleSelectionConfirmInput(void*);
extern "C" int KrakPot_HandleSelectionCancelInput(void*);
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov006 @ 0x02159E50; symbol: func_ov006_02159e50; size: 0xBC.
extern "C" int Graphics_UpdateSelectionAndFinalizeInputResult(unsigned char *self) {
    int result = 0;
    self[0x42c] = 0;
    *(void**)(self + 0x44) = self + 0x36c;
    if (KrakPot_HandleSelectionConfirmInput(self) || Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x200)) {
        SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
        result = -1;
        if (*(short*)(self + 0x36c) == 34) result = 1;
    } else if (KrakPot_HandleSelectionCancelInput(self)) result = -1;
    if (result) {
        TextCanvas_ResetDisplayPartByKey(*(unsigned char**)(self + 0x14), *(short*)(self + 0x36e));
        KeyRepeater_Reset(self + 0x9c);
        *(void**)(self + 0x44) = 0;
    }
    if (*(void***)(self + 0x18) && result) Window_HideAndResetOptionSelection(*(void***)(self + 0x18));
    return result;
}
