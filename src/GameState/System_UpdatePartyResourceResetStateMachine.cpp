#include <globaldefs.h>
ARM
extern "C" char* _ZN9GameState11GetInstanceEv();
extern "C" void GameState_ClearByteSlots(void*);
extern "C" void* GameState_ReadPResources(void*);
extern "C" char* GameState_GetObjectWithFlag100(void*,int);
extern "C" int GameState_ReadProtagonistObjectIndex(void*);
extern "C" unsigned char* GameState_GetIndexList(void*);
extern "C" void GameState_ClearByteFlagsExceptBitFourAtOffset63DC(unsigned char*);
extern "C" void Object_ResetByte63DCToBit0(char*);
extern "C" void* ReadGlobalValueAt020FB3F0();
extern "C" unsigned short _ZNK8Object3D10GetField06Ev(void*);
extern "C" char* ReadWordFieldAtOffset1C();
extern "C" void ClearAndStageSharedGraphicsBuffers(char*);
extern "C" void ResetGlobalOwnerAndEmbeddedSelectionState(void*);
extern "C" unsigned ReadWordFieldAtOffset954(void*);
extern "C" void BackgroundLoader_RemoveObjectTaskAndResetLoadFields(void*);
extern "C" bool Object_TestElement380Exceeds0(signed char*);
extern "C" void* Object_GetGlobalDisplayManager();
extern "C" void Util_RemoveFirstRecordAndClearUnusedSlots(void*);
extern "C" void Resource_CreateInitializedQueueEntry(void*,int,int,int);
extern "C" void Unclassified_QueueRecordWithByteArguments(unsigned char,unsigned char);
extern "C" void Network_QueueTypeAdRecord(short,short,signed char);
// Original: arm9/main @ 0x02093428; symbol: func_02093428; size: 0x288.
extern "C" void System_UpdatePartyResourceResetStateMachine(unsigned char* self) {
 char* state=_ZN9GameState11GetInstanceEv();
 char* owner=ReadWordFieldAtOffset1C();
 ReadGlobalValueAt020FB3F0();
 unsigned char protagonist=GameState_ReadProtagonistObjectIndex(state);
 if(self[0x35]==0) {
 unsigned char* list=GameState_GetIndexList(state);
 unsigned count=list[0xf7c];
 for(unsigned char i=0;i<count;i++) {
 char* obj=GameState_GetObjectWithFlag100(state,*(list+i+0xf78));
 if(obj && Object_TestElement380Exceeds0((signed char*)obj)) BackgroundLoader_RemoveObjectTaskAndResetLoadFields(obj);
 }
 *(short*)(self+0x30)=10;self[0x35]++;
 } else if(self[0x35]==1) {
 if(!*(unsigned char*)(state+0x7f74)) {self[0x35]=3;return;}
 if(*(int*)(owner+0x9a0)) return;
 unsigned value=ReadWordFieldAtOffset954(owner);
 if(value==0) {self[0x35]++;return;}
 if(value==1) {
 *(short*)(self+0x30)=3;self[0x35]=4;
 Unclassified_QueueRecordWithByteArguments(protagonist,3);
 int index=GameState_ReadProtagonistObjectIndex(state);
 Network_QueueTypeAdRecord(10000,-1,(signed char)index);
 }
 } else if(self[0x35]==2) {
 if(!*(unsigned char*)(state+0x7f74)) {*(short*)(self+0x30)=11;self[0x35]=4;return;}
 Unclassified_QueueRecordWithByteArguments(protagonist,2);
 int flag=0;
 char* obj=GameState_GetObjectWithFlag100(state,0);
 if(obj && (*(unsigned char*)(obj+0xbe)==2 || _ZNK8Object3D10GetField06Ev(obj)==0x170c)) {
 unsigned id=*(unsigned short*)(obj+0x1b2);
 if(id) {
 if(id>=1 && id<=0x7fff) flag=1;
 else if(id>=0x8005 && id<=0x83ed) flag=1;
 }
 }
 Resource_CreateInitializedQueueEntry(GameState_ReadPResources(state),1,flag,0);
 GameState_ClearByteFlagsExceptBitFourAtOffset63DC((unsigned char*)state);
 if(*(unsigned char*)(state+0x7f75)) Object_ResetByte63DCToBit0(state);
 Util_RemoveFirstRecordAndClearUnusedSlots(Object_GetGlobalDisplayManager());
 self[0x34]=4;self[0x35]=0;
 } else if(self[0x35]==3) {
 ResetGlobalOwnerAndEmbeddedSelectionState(owner);
 ClearAndStageSharedGraphicsBuffers(owner);
 Util_RemoveFirstRecordAndClearUnusedSlots(Object_GetGlobalDisplayManager());
 self[0x34]=4;self[0x35]=0;
 GameState_ClearByteSlots(state);
 } else if(self[0x35]==4) {
 if(!*(int*)(owner+0x998)) self[0x35]=3;
 }
}
