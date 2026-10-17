#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned int ReadWordFieldAtOffset1C(void*);
extern "C" void ProcessSixStagesUsingSharedWordScratchBuffer(void* p,int unused,void* a,void* b,int c,int d,unsigned flags);
extern "C" void *ReadGlobalAt02108F0C();
extern "C" void Object_CaptureCurrentZoneOnce(char* p);
extern "C" void* Script_ReadGlobalExecutionValue();
extern "C" void Text_EnqueueThreeEntryMessage(void*,void*,int,int,int,int);
extern "C" void GameState_BuildTwelveByteDescriptorForPartyMember(void* out,int index);
extern "C" void* LookupGlobalResourceByKey(unsigned key);
// Original: arm9/ov017 @ 0x021C2EA4; symbol: func_ov017_021c2ea4; size: 0x98.
extern "C" void GameState_ProcessPartyDescriptorAndCaptureZone(char *self) {
    char scratch[128];
    char descriptor[12];
    void **context = (void **)ReadWordFieldAtOffset1C(_ZN9GameState11GetInstanceEv());
    GameState_BuildTwelveByteDescriptorForPartyMember(descriptor,*(unsigned char *)(self + 0x95));
    *context = descriptor;
    ProcessSixStagesUsingSharedWordScratchBuffer(context,12,LookupGlobalResourceByKey(0x31),scratch,227,0,1);
    Text_EnqueueThreeEntryMessage(Script_ReadGlobalExecutionValue(),scratch,0,0,1,1);
    Object_CaptureCurrentZoneOnce((char *)ReadGlobalAt02108F0C());
    *(unsigned char *)(self + 0x8c) = 3;
}
