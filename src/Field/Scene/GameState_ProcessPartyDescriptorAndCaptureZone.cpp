#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned int TextContext_GetSharedInstance(void*);
extern "C" void TextMarkup_ExpandAndWrapText(void* p,int unused,void* a,void* b,int c,int d,unsigned flags);
extern "C" void *PartyProgress_GetInstance();
extern "C" void PartyProgress_CaptureRecoveryZoneOnce(char* p);
extern "C" void* Script_ReadGlobalExecutionValue();
extern "C" void Text_EnqueueThreeEntryMessage(void*,void*,int,int,int,int);
extern "C" void GameState_BuildTwelveByteDescriptorForPartyMember(void* out,int index);
extern "C" void* Text_LookupStandardString(unsigned key);
// Original: arm9/ov017 @ 0x021C2EA4; symbol: func_ov017_021c2ea4; size: 0x98.
extern "C" void GameState_ProcessPartyDescriptorAndCaptureZone(char *self) {
    char scratch[128];
    char descriptor[12];
    void **context = (void **)TextContext_GetSharedInstance(_ZN9GameState11GetInstanceEv());
    GameState_BuildTwelveByteDescriptorForPartyMember(descriptor,*(unsigned char *)(self + 0x95));
    *context = descriptor;
    TextMarkup_ExpandAndWrapText(context,12,Text_LookupStandardString(0x31),scratch,227,0,1);
    Text_EnqueueThreeEntryMessage(Script_ReadGlobalExecutionValue(),scratch,0,0,1,1);
    PartyProgress_CaptureRecoveryZoneOnce((char *)PartyProgress_GetInstance());
    *(unsigned char *)(self + 0x8c) = 3;
}
