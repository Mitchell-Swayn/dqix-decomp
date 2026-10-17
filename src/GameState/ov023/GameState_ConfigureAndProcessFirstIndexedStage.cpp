#include <globaldefs.h>
ARM
struct GameState;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetIndexList(GameState*);
extern "C" unsigned int ReadWordFieldAtOffset1C();
extern "C" void SetOneOfSixteenWordFieldsAtOffset8B0(unsigned int*,int,unsigned int);
extern "C" void Object_WriteBoundedSixteenByteArrayElementAtOffset8F1(char*,int,int);
extern "C" void WriteBoundedIndexedByteAt902(char*,int,int);
extern "C" void ProcessSixStagesUsingSharedWordScratchBuffer(void*,int,void*,void*,int,int,unsigned);
extern "C" void* ResolveIndexedRecordAndReturnSecondWord(void*,void*);
// Original: arm9/ov023 @ 0x021E8604; symbol: func_ov023_021e8604; size: 0x88.
extern "C" void GameState_ConfigureAndProcessFirstIndexedStage(unsigned char* p){
 unsigned char* list=(unsigned char*)GameState_GetIndexList((GameState*)_ZN9GameState11GetInstanceEv());
 unsigned int* obj=(unsigned int*)ReadWordFieldAtOffset1C();
 SetOneOfSixteenWordFieldsAtOffset8B0(obj,0,*(unsigned int*)(list+0xf74));
 Object_WriteBoundedSixteenByteArrayElementAtOffset8F1((char*)obj,0,1);
 WriteBoundedIndexedByteAt902((char*)obj,0,10);
 void* record=ResolveIndexedRecordAndReturnSecondWord(p+0x4c,(void*)2);
 ProcessSixStagesUsingSharedWordScratchBuffer(obj,10,record,*(void**)(p+0x5d8),256,0,0);
}
