#include <globaldefs.h>
ARM
struct GameState;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned ReadWordFieldAtOffset1C();
extern "C" void* GameState_GetIndexList(GameState*);
extern "C" void ClearOwnerBuffersAndResetSignedByteSentinels(signed char*);
extern "C" void SetOneOfSixteenWordFieldsAtOffset8B0(unsigned*,int,unsigned);
extern "C" void WriteBoundedIndexedByteAt902(char*,int,int);
extern "C" void Object_WriteBoundedSixteenByteArrayElementAtOffset8F1(char*,int,int);
extern "C" void* LookupGlobalResourceByKey(unsigned);
extern "C" void ProcessSixStagesUsingSharedWordScratchBuffer(void*,int,void*,void*,int,int,unsigned);
// Original: arm9/ov003 @ 0x0215DE6C; symbol: func_ov003_0215de6c; size: 0xB0.
extern "C" void Graphics_InitializeFormattedStateValue(char* self,void* output) {
GameState* state=(GameState*)_ZN9GameState11GetInstanceEv();
char* context=(char*)ReadWordFieldAtOffset1C();
char* list=(char*)GameState_GetIndexList(state);
unsigned value=*(unsigned*)(list+0xf6c);
if(*(unsigned char*)(self+0x3bb)==2) value-=*(unsigned*)(self+0x3cc);
ClearOwnerBuffersAndResetSignedByteSentinels((signed char*)context);
SetOneOfSixteenWordFieldsAtOffset8B0((unsigned*)context,0,value);
WriteBoundedIndexedByteAt902(context,0,7);
Object_WriteBoundedSixteenByteArrayElementAtOffset8F1(context,0,1);
void* resource=LookupGlobalResourceByKey(1009);
ProcessSixStagesUsingSharedWordScratchBuffer(context,8,resource,output,256,0,0);
}
