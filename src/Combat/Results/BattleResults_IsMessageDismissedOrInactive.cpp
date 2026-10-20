#include <globaldefs.h>
static inline bool IsInactiveState(char* state) { return *(int*)(state+0x998)==0; }
extern "C" {
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2114e54; symbol: data_02114e54.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 112 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned char KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[],Main_UnknownRoleZeroInitializedStorage_Variant4[],Main_UnknownRoleZeroInitializedStorage[];
int Input_IsKeyMaskNewlyPressed(void*,int);
char* TextContext_GetSharedInstance();
void SoundSfx_StartCurrentSequenceArchiveEntry(void*,int,int);
}

// Original: arm9/ov023 @ 0x021F4FC8; symbol: func_ov023_021f4fc8; size: 0x134.
// Field roles remain unclassified; offsets describe the observed layout.
extern "C" ARM bool BattleResults_IsMessageDismissedOrInactive(void)
{
    char* state=TextContext_GetSharedInstance();
    int result=0;
    int mode=*(int*)(state+0x9a0);
    if(mode==3 || mode==0)
    {
        if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,1)||Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,2)||Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x200)||Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x100)||Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x400)||Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x40)||Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x80)||Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x20)||Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x10)) result=1;
        if(Main_UnknownRoleZeroInitializedStorage_Variant4[0x54]) result=1;
    }
    if(result)
    {
        SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
        return true;
    }
    return (int)IsInactiveState(state) != 0;
}
