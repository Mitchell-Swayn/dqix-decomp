#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* GameResources_GetInstance();
extern "C" char* Object_GetGlobalConnectionState();
extern "C" char* ReadGlobalAt02100044();
extern "C" int ReadIndexedSignedField1038(char*);
extern "C" char* GetRecordAtResolvedIndexWithStride116(char*,int);
extern "C" int Object_TestNewlySetHalfwordMask(unsigned short*,unsigned);
extern "C" void SetWordMaskBits_Main0203B4A0(unsigned*,unsigned);
extern "C" unsigned WaitForStateThreeThenProcessOwnerWithTimeout(char*);
extern "C" void ClearIndirectBytePairAt441C(char*);
extern "C" void GameState_ResetPartyMemberHalfwords(char*);
extern "C" void* FillThirtyTwoByteBitsetWithFF(unsigned char*);
extern "C" void Flags_ClearWordMask(unsigned*,unsigned);
extern "C" unsigned Object_TestIndexedByte100EFlagByKey(char*,int);
extern "C" unsigned Object_ReadElement4();
extern "C" void* GetGlobalStatePointer();
extern "C" void RecordFlags_ClearWordMask(unsigned*,unsigned);
extern "C" unsigned char* Object_GetGlobalDisplayManager();
extern "C" void Object_ResetDisplayManagerAndActivate(void*);
extern "C" int InsertRecordByDescendingClassification(unsigned char*,short,int,signed char);
extern "C" unsigned _ZNK9GameState21GetEffectiveDeltaTimeEv(void*);
extern "C" void Object_SetSelectedBitAndRefreshState(unsigned char*,int);
extern "C" void* ClearBitsetAt1524(char*);
extern "C" void SetIndexedBitAt1524(unsigned char*,unsigned);
extern "C" void Network_QueueProtagonistNameRecord();
extern "C" unsigned short data_02114e30[];
#define CLEANUP() SetWordMaskBits_Main0203B4A0((unsigned*)resources,2);WaitForStateThreeThenProcessOwnerWithTimeout(connection);ClearIndirectBytePairAt441C(resources);GameState_ResetPartyMemberHalfwords(resources);FillThirtyTwoByteBitsetWithFF((unsigned char*)global);Flags_ClearWordMask((unsigned*)resources,0x40);*(unsigned char*)(self+1)=1
// Original: arm9/ov017 @ 0x021AF098; symbol: func_ov017_021af098; size: 0x260.
extern "C" int Network_AdvanceConnectionSelectionAndTimeout(char* self){
 void* state=_ZN9GameState11GetInstanceEv();
 char* resources=GameResources_GetInstance();
 char* connection=Object_GetGlobalConnectionState();
 char* global=ReadGlobalAt02100044();
 if(ReadIndexedSignedField1038(connection)==0){
  GetRecordAtResolvedIndexWithStride116(connection,0);
  if(Object_TestNewlySetHalfwordMask(data_02114e30,2)){
   *(signed char*)(self+15)=-1;CLEANUP();
  }else{
   if(Object_TestIndexedByte100EFlagByKey(connection,0) || Object_ReadElement4()==8){
    RecordFlags_ClearWordMask((unsigned*)GetGlobalStatePointer(),0x8020);
    unsigned char* display=Object_GetGlobalDisplayManager();Object_ResetDisplayManagerAndActivate(display);InsertRecordByDescendingClassification(display,4,-1,0);return 3;
   }
   *(unsigned short*)(self+18)+=_ZNK9GameState21GetEffectiveDeltaTimeEv(state);
   if(*(unsigned short*)(self+18)>5000){*(unsigned char*)(self+15)=0;CLEANUP();return *(unsigned char*)(self+8);}
  }
  return *(unsigned char*)(self+8);
 }
 if(ReadIndexedSignedField1038(connection)>=4){*(unsigned char*)(self+15)=0;CLEANUP();return *(unsigned char*)(self+8);}
 *(unsigned char*)(self+16)=ReadIndexedSignedField1038(connection);
 int selected=ReadIndexedSignedField1038(connection);Object_SetSelectedBitAndRefreshState((unsigned char*)connection,selected);
 Flags_ClearWordMask((unsigned*)resources,2);ClearBitsetAt1524(global);
 SetIndexedBitAt1524((unsigned char*)global,44);SetIndexedBitAt1524((unsigned char*)global,42);SetIndexedBitAt1524((unsigned char*)global,46);SetIndexedBitAt1524((unsigned char*)global,61);SetIndexedBitAt1524((unsigned char*)global,51);
 Network_QueueProtagonistNameRecord();*(unsigned short*)(self+18)=0;
 return 2;
}
