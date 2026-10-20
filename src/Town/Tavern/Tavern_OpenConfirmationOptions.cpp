#include <globaldefs.h>
ARM
extern "C" {
    void TextCanvas_CreateAndConfigureDisplayPart(void*,int);
    void KeyRepeater_Reset(void*);
    void SoundSfx_StartCurrentSequenceArchiveEntry(void*,int,int);
    void TextCanvas_HideDisplayPart(void*,int);
    void Window_CreateOptionLayoutAndResetSelection(void*,int);
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern char Main_UnknownRoleZeroInitializedStorage[];
}
// Original: arm9/ov003 @ 0x021612C0; symbol: func_ov003_021612c0; size: 0x84.
// Field purposes remain uncertain; operation and call sequence follow original instructions.
extern "C" void Tavern_OpenConfirmationOptions(char* p) {
    *(short*)(p+0x488)=9;
    *(short*)(p+0x474)=*(short*)(p+0x49c)=44;
    *(short*)(*(char**)(p+0x324)+0x36)=*(short*)(p+0x49c);
    TextCanvas_CreateAndConfigureDisplayPart(*(void**)(p+0x324),*(short*)(p+0x488));
    KeyRepeater_Reset(p+0x308);
    *(int*)(p+0x470)=0;
    SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,5,0);
    if(*(void**)(p+0x390)) {
        TextCanvas_HideDisplayPart(*(void**)(p+0x324),*(short*)(p+0x488));
        Window_CreateOptionLayoutAndResetSelection(*(void**)(p+0x390),-1);
    }
}
