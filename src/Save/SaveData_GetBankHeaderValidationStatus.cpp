#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" {extern unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];int Input_TestKeyMask(unsigned short*,unsigned short);int SaveData_ReadCardSaveBytes(unsigned,void*,unsigned,unsigned);unsigned FileCache_ComputeCRC32(void*,unsigned);}
// Original: arm9/main @ 0x020AB9C0; symbol: func_main_020ab9c0; size: 0x9c.
// Reads20-byte save packet, validates payload CRC and reports flag states.
extern "C" int SaveData_GetBankHeaderValidationStatus(int alternate){unsigned address=alternate?0x8010:0x10;unsigned packet[5];if(Input_TestKeyMask(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x2000))return 2;if(!SaveData_ReadCardSaveBytes(address,packet,20,0))return 1;if(packet[0]!=FileCache_ComputeCRC32((char*)packet+4,16))return 2;if(!((unsigned char*)packet)[5])return 3;return ((unsigned char*)packet)[4]==1?4:0;}
