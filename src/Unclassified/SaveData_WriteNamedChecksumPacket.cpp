#include "globaldefs.h"
#pragma optimize_for_size on
ARM
struct Packet{unsigned checksum;unsigned reserved;char name[12];};extern "C" int func_02075910(int,void*,int,int);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" unsigned FileCache_ComputeCRC32(const void*,unsigned);extern "C" void func_02075acc(unsigned,const void*,unsigned,int);extern "C" char data_020f1bf0[];
// Original: arm9/main @ 0x020ABA5C; symbol: func_020aba5c; size: 0x8C.
extern "C" int SaveData_WriteNamedChecksumPacket(int mode){unsigned state;Packet packet;if(!func_02075910(0,&state,1,0))return 0;memset(&packet,0,20);strcpy(packet.name,data_020f1bf0);packet.checksum=FileCache_ComputeCRC32((unsigned char*)&packet+4,16);func_02075acc(mode?0x8010:0x10,&packet,20,0);return 1;}
