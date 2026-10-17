#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned* GameResources_GetInstance();
extern "C" char* Object_GetGlobalConnectionState();
extern "C" char* GetRecordAtResolvedIndexWithStride116(char*,int);
extern "C" void* ReadGlobalAt02100044();
extern "C" unsigned Object_TestIndexedByte100EFlagByKey(char*,int);
extern "C" unsigned Object_ReadElement4();
extern "C" unsigned* GetGlobalStatePointer();
extern "C" void RecordFlags_ClearWordMask(unsigned*,unsigned);
extern "C" void* Object_GetGlobalDisplayManager();
extern "C" void Object_ResetDisplayManagerAndActivate(void*);
extern "C" int InsertRecordByDescendingClassification(unsigned char*,short,int,signed char);
extern "C" int ReadIndexedSignedField1038(char*);
extern "C" int TestResolvedBitInResolvedFlags(unsigned,int);
extern "C" int Object_TestNewlySetHalfwordMask(unsigned short*,unsigned);
extern "C" void SetWordMaskBits_Main0203B4A0(unsigned*,unsigned);
extern "C" unsigned WaitForStateThreeThenProcessOwnerWithTimeout(void*);
extern "C" void ClearIndirectBytePairAt441C(char*);
extern "C" void GameState_ResetPartyMemberHalfwords(void*);
extern "C" void* FillThirtyTwoByteBitsetWithFF(unsigned char*);
extern "C" void Flags_ClearWordMask(unsigned*,unsigned);
extern "C" unsigned short data_02114e30[];
struct RecordBits {unsigned short first:1,rest:15;};
// Original: arm9/ov017 @ 0x021AF2F8; symbol: func_ov017_021af2f8; size: 0x1F4.
extern "C" unsigned Network_UpdateDisconnectSelectionState(char* self) {
 _ZN9GameState11GetInstanceEv();
 unsigned* resources=GameResources_GetInstance();
 char* conn=Object_GetGlobalConnectionState();
 GetRecordAtResolvedIndexWithStride116(conn,0);
 void* bits=ReadGlobalAt02100044();
 if(Object_TestIndexedByte100EFlagByKey(conn,0)||Object_ReadElement4()==8) {
  RecordFlags_ClearWordMask(GetGlobalStatePointer(),0x8020);
  void* display=Object_GetGlobalDisplayManager();
  Object_ResetDisplayManagerAndActivate(display);
  InsertRecordByDescendingClassification((unsigned char*)display,4,-1,0);
  return 3;
 }
 int available=0;
 if(ReadIndexedSignedField1038(conn)==0)available=1;
 else {
  for(int i=0;i<4;i++) {
   if(i==ReadIndexedSignedField1038(conn))continue;
   if(!TestResolvedBitInResolvedFlags((unsigned)conn,i))continue;
   char* record=GetRecordAtResolvedIndexWithStride116(conn,i);
   if(record && !((RecordBits*)(record+2))->first) {available=1;break;}
  }
  if(*(signed char*)(self+0x10)!=ReadIndexedSignedField1038(conn))self[0xf]=0;
 }
 int mode=*(signed char*)(self+0xf);
 if(mode==-1||available) {
  if(Object_TestNewlySetHalfwordMask(data_02114e30,2)) {
   self[0xf]=-1;
   SetWordMaskBits_Main0203B4A0(resources,2);
   WaitForStateThreeThenProcessOwnerWithTimeout(conn);
   ClearIndirectBytePairAt441C((char*)resources);
   GameState_ResetPartyMemberHalfwords(resources);
   FillThirtyTwoByteBitsetWithFF((unsigned char*)bits);
   Flags_ClearWordMask(resources,0x40);
   self[1]=1;
  }
 } else if(mode==1) {
  if(!*(int*)(conn+0xfc0))self[1]=1;
 } else {
  SetWordMaskBits_Main0203B4A0(resources,2);
  WaitForStateThreeThenProcessOwnerWithTimeout(conn);
  ClearIndirectBytePairAt441C((char*)resources);
  GameState_ResetPartyMemberHalfwords(resources);
  FillThirtyTwoByteBitsetWithFF((unsigned char*)bits);
  Flags_ClearWordMask(resources,0x40);
  self[1]=1;
 }
 return *(unsigned char*)(self+8);
}
