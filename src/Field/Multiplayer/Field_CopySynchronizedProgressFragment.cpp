#include <globaldefs.h>
#include <std_library_functions.h>
ARM
extern "C" void* GameState_GetSerializedProgressState();
extern "C" void Script_SelectProgressCategoryForZone(unsigned char*,int);
// Original: arm9/ov017 @ 0x021CDCCC; symbol: func_ov017_021cdccc; size: 0x64.
// Copies at most 14 bytes at the requested offset, clipped at 253 bytes, then
// selects the global record category with ID 0xC3B5 when that boundary is reached.
extern "C" void Field_CopySynchronizedProgressFragment(void* unused,unsigned offset,const void* source)
{
 unsigned char* record=(unsigned char*)GameState_GetSerializedProgressState();
 unsigned end=offset+14;
 int count=14;
 int finalize=0;
 if(end>253){count=253-offset;finalize=1;}
 else if(end==253)finalize=1;
 if(count<0)return;
 memcpy(record+offset,source,count);
 if(finalize)Script_SelectProgressCategoryForZone((unsigned char*)GameState_GetSerializedProgressState(),0xc3b5);
}
