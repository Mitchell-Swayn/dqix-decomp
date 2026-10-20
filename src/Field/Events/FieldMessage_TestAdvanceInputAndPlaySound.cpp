#include <globaldefs.h>
#pragma force_active on
ARM
extern "C" unsigned TextContext_GetSharedInstance();
extern "C" int Input_IsKeyMaskNewlyPressed(unsigned short*,unsigned);
extern "C" void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);
// Original data: arm9/main @ 0x02114E30; symbol: data_02114e30.
// Mutable key transition state, owned by the main executable.
extern "C" unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x02114E54; symbol: data_02114e54.
// Mutable input state whose byte+0x54 also advances the message.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant4[];
// Original data: arm9/main @ 0x02108760; symbol: data_02108760.
// Shared sound-effect object passed to the existing sequence-archive helper.
extern "C" char Main_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov017 @ 0x021AA080; symbol: func_ov017_021aa080; size: 0xEC.
// Tests message-ready state and advance keys/touch, then plays the standard confirmation sound.
extern "C" int FieldMessage_TestAdvanceInputAndPlaySound()
{
    int state=*(int*)(TextContext_GetSharedInstance()+0x9a0);
    int advance=0;
    if(state==3 || state==0) {
        if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,1) ||
           Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x200) ||
           Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x100) ||
           Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x40) ||
           Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x80) ||
           Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x20) ||
           Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x10)) advance=1;
        if(Main_UnknownRoleZeroInitializedStorage_Variant4[0x54]) advance=1;
    }
    if(!advance) return 0;
    SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
    return 1;
}
