#include <globaldefs.h>
ARM
extern "C" char* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_ReadIndexedRecordsIndex(void*,int);
extern "C" void InitializeCharacterStateArraysAndDefaults(void*);
extern "C" int SaveData_WriteNamedChecksumPacket(int);
extern "C" int SubmitZeroed84BytePayloadWithCRC(int);
extern "C" void* GameState_GetIndexList(void*);
extern "C" void InitializePairedRecordBuffersAndLists(void*);
extern "C" void VectorizedMemset(void*,int,unsigned);
struct Defaults {
 unsigned a:12,b:4,c:5,d:4,e:1,f:1,g:1,h:1,i:1,j:1,k:1;
 unsigned l:9,m:10,n:11,o:1,p:1;
 unsigned char byte;
};
// Original: arm9/main @ 0x020ABB64; symbol: func_020abb64; size: 0x144.
extern "C" int SaveData_InitializeDefaultStateAndPackets() {
 char* state=_ZN9GameState11GetInstanceEv();
 for(int i=0;i<4;i++) {
  void* character=GameState_ReadIndexedRecordsIndex(state,i);
  if(character)InitializeCharacterStateArraysAndDefaults(character);
 }
 if(!SaveData_WriteNamedChecksumPacket(0))return 0;
 if(!SaveData_WriteNamedChecksumPacket(1))return 0;
 if(!SubmitZeroed84BytePayloadWithCRC(0))return 0;
 if(!SubmitZeroed84BytePayloadWithCRC(1))return 0;
 Defaults* defaults=(Defaults*)(state+0x569c);
 defaults->a=2000;
 defaults->b=1;
 defaults->c=1;
 defaults->h=0;
 defaults->d=0;
 defaults->g=0;
 defaults->e=0;
 defaults->f=0;
 defaults->i=0;
 defaults->j=1;
 defaults->k=0;
 defaults->l=511;
 defaults->o=0;
 defaults->m=300;
 defaults->n=706;
 defaults->byte=0;
 InitializePairedRecordBuffersAndLists(GameState_GetIndexList(state));
 VectorizedMemset(state+0x6380,0,0x54);
 return 1;
}
