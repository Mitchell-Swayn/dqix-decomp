#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
#include <std_library_functions.h>
#pragma opt_propagation off
ARM
struct Source;
typedef unsigned int undefined4;
extern "C" {
extern unsigned char Main_UnknownRoleZeroInitializedStorage_Variant6[];
int SaveData_ReadValidateAndOptionallyRestoreBank(void*,int,int,int);
void* SystemState_GetGlobalFlags();
void SystemState_SetFlags(unsigned*,unsigned);
void SystemState_ClearFlags(unsigned*,unsigned);
void ReloadFlaggedRecordResourcesUsingTemporaryCache(unsigned char*);
unsigned PartyRecord_GetSelectedVocation(int);
void* __clear(void*,unsigned);
void Text_MapInputBytesToVariableLengthOutputSequences(const unsigned char*,unsigned char*,unsigned);
void* GameState_GetSerializedProgressState();
int GameState_CopySourceBytesAndSelectedInitialFields(Source*,char*,int);
unsigned BitArray_ReadNonnegativeIndexMask(void*,unsigned char*,int);
bool GameState_ReadAndValidateChecksummedNinetySixByteRecord(int);
}
struct SummaryMember { unsigned char name[0x30];unsigned char vocation,level;unsigned short statistic; };
struct Summary { SummaryMember members[4];unsigned shortWord;unsigned char count,flag,statistic,other; };
// Original: arm9/main @ 0x020AB5D4; symbol: func_020ab5d4; size: 0x1D4.
extern "C" int SaveData_LoadPartySummaryAndSavedStatistics(void* bank, int unused1, int unused2, void* savedStatistics)
{
 if(!SaveData_ReadValidateAndOptionallyRestoreBank(bank,0,0,1))return 0;
 BackgroundLoader::AddLockGlobal();
 BackgroundLoader::FreeAllocationsGlobal();
 unsigned* flags=(unsigned*)SystemState_GetGlobalFlags();
 SystemState_SetFlags(flags,0x2000000);
 unsigned char* recordMetadata;
 unsigned char* save=Main_UnknownRoleZeroInitializedStorage_Variant6;
 save+=0x28000;
 unsigned char* state=(unsigned char*)GameState::GetInstance();
 unsigned char* records=save+4;
 ReloadFlaggedRecordResourcesUsingTemporaryCache(records);
 Summary summary;
 recordMetadata=records+0x1000;
 unsigned char* wordSource=records+0x2c00;
 unsigned char count=recordMetadata[0xd11];
 unsigned word=*(unsigned short*)(wordSource+0x4c);
 summary.shortWord=word;
 summary.count=count;
 for(int i=0;i<summary.count;++i){
  unsigned char* record=records+(recordMetadata[0xd0c]+i)*0x23c;
  if(record){
   SummaryMember* member=&summary.members[i];
   unsigned vocation=PartyRecord_GetSelectedVocation((int)record);
   member->vocation=vocation;
   unsigned char* vocationData=record+vocation;
   member->level=vocationData[0xf];
   member->statistic=vocationData[2];
   unsigned char name[0x30];
   __clear(name,0x30);
   Text_MapInputBytesToVariableLengthOutputSequences(record+0x140,name,1);
   memcpy(member,name,0x30);
  }
 }
 recordMetadata=save+0xac;
 char* progress=(char*)GameState_GetSerializedProgressState();
 GameState_CopySourceBytesAndSelectedInitialFields((Source*)(recordMetadata+0x2c00),progress,0);
 summary.flag=BitArray_ReadNonnegativeIndexMask(progress,(unsigned char*)progress+0x8c,0x796);
 summary.statistic=*(unsigned*)(save+0x2cac);
 summary.other=BitArray_ReadNonnegativeIndexMask(progress,(unsigned char*)progress+0x8c,0x1142)!=0;
 memcpy(state+0x7e80,&summary,0xd8);
 unsigned char* savedWord=save+0x1d8;
 savedWord+=0x3c00;
 memcpy(savedStatistics,savedWord+0x3c,4);
 if(!GameState_ReadAndValidateChecksummedNinetySixByteRecord(0)){
  BackgroundLoader::RemoveLockGlobal();SystemState_ClearFlags(flags,0x2000000);return 0;
 }
 BackgroundLoader::RemoveLockGlobal();SystemState_ClearFlags(flags,0x2000000);return 1;
}
