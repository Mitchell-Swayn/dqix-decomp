#include <globaldefs.h>
ARM
extern "C" int SaveData_ReadCardSaveBytes(unsigned,void*,unsigned,unsigned);extern "C" unsigned FileCache_ComputeCRC32(void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" void SaveData_WriteBackupBytes(unsigned,void*,unsigned,unsigned);struct Payload {unsigned size;unsigned char data[80];};
// Original: arm9/main @ 0x020ABAE8; symbol: func_020abae8; size: 0x7C.
extern "C" int SaveData_ClearAuxiliaryRecordWithChecksum(int flag){Payload payload;unsigned handle;if(!SaveData_ReadCardSaveBytes(0,&handle,1,0))return 0;memset(&payload,0,84);payload.size=FileCache_ComputeCRC32((unsigned char*)&payload+4,80);SaveData_WriteBackupBytes(flag?0x8024:0x24,&payload,84,0);return 1;}
