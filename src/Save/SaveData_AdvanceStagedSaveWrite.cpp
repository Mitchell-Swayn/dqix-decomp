#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Resource/GameResources.h>
#include <Resource/Brightness.h>
#include <Filesystem/BackgroundLoader.h>
struct Flags;
extern "C" GameResources* GameResources_GetInstance();
extern "C" int SaveData_ReadCardSaveBytes(int,void*,unsigned,int);
extern "C" int SaveData_WriteBackupBytes(int,const void*,unsigned,int);
extern "C" void GameState_RequestSaveErrorExit(Flags*);
extern "C" void* SystemState_GetGlobalFlags();
extern "C" void SystemState_SetFlags(unsigned*,unsigned);
extern "C" void SystemState_ClearFlags(unsigned*,unsigned);
extern "C" void GameResources_SetPrimaryFlags(unsigned*,unsigned);
extern "C" void GameResources_ClearPrimaryFlags(unsigned*,unsigned);
extern "C" int System_TestExternalStatusNonzero();
extern "C" void SaveData_FinishBackupTransfer();
extern "C" int SaveData_SerializeGameState(void*,void*,int,int);
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant6[];
extern "C" unsigned char* SaveDataAdvanceStagedSaveWrite_UnknownRoleZeroInitializedStorage;
struct SaveWriteState { unsigned char stage,padding[3];unsigned char* data; };
// Original: arm9/main @ 0x020AAD1C; symbol: SaveData_AdvanceStagedSaveWrite; size: 0x268.
// Advance the asynchronous save transaction while managing its shared workspace and flags.
extern "C" ARM int SaveData_AdvanceStagedSaveWrite(void* object,void* argument,int option,int alternate) {
SaveWriteState* self=(SaveWriteState*)object;
unsigned char check;
if(self->stage==0) {
GameState* game=GameState::GetInstance();game->unknownByte_5cc8_=1;
GameResources* resources=GameResources_GetInstance();
if(!SaveData_ReadCardSaveBytes(0,&check,1,0)){SetBrightness(resources,-16,10);GameState_RequestSaveErrorExit((Flags*)game);self->stage=4;return 1;}
BackgroundLoader::FreeAllocationsGlobal();SystemState_SetFlags((unsigned*)SystemState_GetGlobalFlags(),0x2000000);GameResources_SetPrimaryFlags(&resources->brightnessFlags_0,0x10);
self->data=(unsigned char*)Main_UnknownRoleZeroInitializedStorage_Variant6+0x2901c;
if(!SaveData_ReadCardSaveBytes(0x8000,self->data,0x6fe4,1)){SystemState_ClearFlags((unsigned*)SystemState_GetGlobalFlags(),0x2000000);GameResources_ClearPrimaryFlags(&resources->brightnessFlags_0,0x10);self->stage=4;return 1;}
self->stage=1;
} else if(self->stage==1) {
if(!System_TestExternalStatusNonzero())return 0;
SaveData_FinishBackupTransfer();SaveDataAdvanceStagedSaveWrite_UnknownRoleZeroInitializedStorage=self->data;
if(!SaveData_SerializeGameState(self,argument,option,alternate)){SystemState_ClearFlags((unsigned*)SystemState_GetGlobalFlags(),0x2000000);GameResources_ClearPrimaryFlags(&GameResources_GetInstance()->brightnessFlags_0,0x10);self->stage=4;return 1;}
SaveDataAdvanceStagedSaveWrite_UnknownRoleZeroInitializedStorage=0;
SaveData_WriteBackupBytes(alternate?0x8010:0x10,self->data+0x10,0x6fe4,1);self->stage=2;
} else if(self->stage==2) {
if(!System_TestExternalStatusNonzero())return 0;
SaveData_FinishBackupTransfer();
if(alternate){SystemState_ClearFlags((unsigned*)SystemState_GetGlobalFlags(),0x2000000);GameResources_ClearPrimaryFlags(&GameResources_GetInstance()->brightnessFlags_0,0x10);self->stage=4;return 1;}
SaveData_WriteBackupBytes(0x8010,self->data+0x10,0x6fe4,1);self->stage=3;
} else if(self->stage==3) {
if(!System_TestExternalStatusNonzero())return 0;
SaveData_FinishBackupTransfer();SystemState_ClearFlags((unsigned*)SystemState_GetGlobalFlags(),0x2000000);GameResources_ClearPrimaryFlags(&GameResources_GetInstance()->brightnessFlags_0,0x10);self->stage=4;return 1;
}
return 0;
}
