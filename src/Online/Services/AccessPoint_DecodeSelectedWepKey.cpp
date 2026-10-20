#include <globaldefs.h>
ARM
extern "C" int MI_CpuCopy8(...);
extern "C" int System_DecodeAndApplyInputRecord(...);
extern "C" int System_DecodeAndApplyInputRecord(...);
extern "C" int AccessPoint_DeriveWepKeyFromLegacySsid(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov031 @ 0x022140E8; symbol: DecodeSelectedNetworkIdentity.
extern "C" int AccessPoint_DecodeSelectedWepKey(char*input,unsigned kind,char*output){
switch(kind){case 2:input+=256;case 1:input+=256;case 0:struct Flags{unsigned char kind:2;unsigned char rest:6;};B(output,0)=((Flags*)(input+230))->kind;MI_CpuCopy8(input+128,output+2,16);break;case 5:input+=256;case 4:input+=256;case 3:B(output,0)=1;MI_CpuCopy8(input+209,output+2,5);break;case 6:{B(output,0)=2;char*entry=input+0x47c+B(input,0xd13)*192;AccessPoint_DeriveWepKeyFromLegacySsid(entry,output+2);break;}case 7:{B(output,0)=2;char*entry=input+0x47c+B(input,0xd13)*192;System_DecodeAndApplyInputRecord(entry,output+2);break;}case 8:case 9:break;}return B(output,0)!=0;
}
