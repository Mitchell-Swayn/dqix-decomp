#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
#include <std_library_functions.h>
extern "C" void GameState_ClearSaveErrorExitRequest(int);
extern "C" int SaveData_ReadCardSaveBytes(int,void*,unsigned,int);
extern "C" int SaveData_WriteBackupBytes(int,const void*,unsigned,int);
extern "C" int System_TestExternalStatusNonzero();
extern "C" void SaveData_FinishBackupTransfer();
extern "C" unsigned FileCache_ComputeCRC32(const unsigned char*,unsigned);
extern "C" int SaveData_ReadAndValidateNameChecksumPacket(unsigned*,int);
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant6[];
extern "C" char SaveData_AdvanceValidatedBankReplication_TextSave011[];
struct Replication { unsigned char unknown,stage;unsigned short padding;unsigned char* bank; };
// Original: arm9/main @ 0x020AB7A8; symbol: SaveData_AdvanceValidatedBankReplication; size: 0x218.
// Validate a staged save bank before copying it to the opposite backup slot.
extern "C" ARM int SaveData_AdvanceValidatedBankReplication(unsigned char* object,int alternate) {
Replication* self=(Replication*)object;
unsigned char firstCheck,secondCheck;unsigned packet[5];
if(self->stage==0) {
GameState_ClearSaveErrorExitRequest((int)GameState::GetInstance());
if(!SaveData_ReadCardSaveBytes(0,&firstCheck,1,0))return 1;
BackgroundLoader::FreeAllocationsGlobal();self->bank=(unsigned char*)Main_UnknownRoleZeroInitializedStorage_Variant6+0x2901c;
if(!SaveData_ReadCardSaveBytes(alternate?0x8010:0x10,self->bank,0x6fe4,1))return 1;
self->stage=1;
} else if(self->stage==1) {
if(!System_TestExternalStatusNonzero())return 0;
SaveData_FinishBackupTransfer();if(!SaveData_ReadCardSaveBytes(0,&secondCheck,1,0))return 2;
unsigned char* data=self->bank;
if(*(unsigned*)data!=FileCache_ComputeCRC32(data+4,16))return 3;
if(!data[5])return 3;
if(!strcmp((char*)data+8,SaveData_AdvanceValidatedBankReplication_TextSave011))return 3;
data=self->bank;if(*(unsigned*)(data+0x14)!=FileCache_ComputeCRC32(data+0x18,0x5c))return 3;
data=self->bank;if(*(unsigned*)(data+0x74)!=FileCache_ComputeCRC32(data+0x78,0x6f5c))return 3;
SaveData_WriteBackupBytes(alternate?0x10:0x8010,self->bank,0x6fe4,1);self->stage=2;return 4;
} else if(self->stage==2) {
if(!System_TestExternalStatusNonzero())return 4;
SaveData_FinishBackupTransfer();
if(alternate&&SaveData_ReadAndValidateNameChecksumPacket(packet,1)) {
((unsigned char*)packet)[4]=0;packet[0]=FileCache_ComputeCRC32((unsigned char*)packet+4,16);
SaveData_WriteBackupBytes(0x10,packet,20,0);
}
self->stage=3;return 5;
} else return 5;
return 0;
}
