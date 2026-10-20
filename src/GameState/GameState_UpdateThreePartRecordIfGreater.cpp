#include <globaldefs.h>
ARM
extern "C" {
unsigned char* GameState_GetSerializedProgressState();
void* Network_GetConnectionManager();
char* GameResources_GetInstance();
void Script_GetCategoryProgressTriple(unsigned char*,unsigned char,unsigned char*,unsigned char*,unsigned char*);
void Script_ClearCategoryProgressFlags(char*,int);
void Script_ClearCategorySecondaryProgressFlags(char*,int);
void Script_ResetMessageUsageCounters(unsigned char*);
void Script_SetCategoryProgressTriple(unsigned char*,unsigned char,unsigned char,unsigned char,unsigned char);
int Network_IsSessionActive(void*);
bool Network_IsParentOrOffline(unsigned*);
void Network_QueueConnectionValueRecord(int,unsigned char,int,unsigned short);
void GameState_CopySelectedRecordInitialThreeBytes(unsigned char*);
}
// Original: arm9/main @ 0x020703C8; symbol: func_020703c8; size: 0x134.
extern "C" void GameState_UpdateThreePartRecordIfGreater(int index,int first,int second,int third) {
 unsigned char* state=GameState_GetSerializedProgressState();
 void* connection=Network_GetConnectionManager();
 unsigned char* buffers=*(unsigned char**)(GameResources_GetInstance()+0x44c4);
 unsigned char a,b,c;
 Script_GetCategoryProgressTriple(state,index,&a,&b,&c);
 if(a*10000 + b*100 + c < first*10000 + second*100 + third) {
  if(a!=first) {
   Script_ClearCategoryProgressFlags((char*)state,index);
   Script_ResetMessageUsageCounters(buffers);
  } else if(b!=second) {
   Script_ClearCategorySecondaryProgressFlags((char*)state,index);
   Script_ResetMessageUsageCounters(buffers);
  }
  Script_SetCategoryProgressTriple(state,index,(unsigned char)first,(unsigned char)second,(unsigned char)third);
  if(Network_IsSessionActive(connection) && Network_IsParentOrOffline((unsigned*)connection))
   Network_QueueConnectionValueRecord(2,(unsigned char)index,0,(unsigned short)((first<<10)|(second<<5)|third));
  GameState_CopySelectedRecordInitialThreeBytes(state);
 }
}
