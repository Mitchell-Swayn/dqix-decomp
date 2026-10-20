#include <globaldefs.h>
ARM
extern "C" void MIi_CpuClear16(int,void*,unsigned);
extern "C" void MIi_CpuClearFast(int,void*,unsigned);
extern "C" void MIi_CpuCopy16(const void*,volatile void*,int);
extern "C" int MBi_ReadIconInfo(const char*,unsigned char*,int);
extern "C" unsigned MBi_CountUtf16Units(const unsigned short*);
struct GameInfoInput { unsigned unused; const unsigned short *name; const void *description; const char *icon,*palette; unsigned id; unsigned char count; };
// Original: arm9/ov027 @ 0x021DAB84; symbol: func_ov027_021dab84; size: 0xF0.
// Builds the multiboot game information record and substitutes an empty icon on read failure.
extern "C" void MBi_MakeGameInfo(unsigned char *out,GameInfoInput *in,const void *user)
{
    MIi_CpuClear16(0,out,0x4c0);
    out[0x4b2]=0;
    int failed=!MBi_ReadIconInfo(in->icon,out,1);
    failed|=!MBi_ReadIconInfo(in->palette,out,0);
    if(failed) { out[0x4b2]=1; MIi_CpuClearFast(0,out,0x220); }
    *(unsigned*)(out+0x4b8)=in->id;
    if(user)MIi_CpuCopy16(user,out+0x220,22);
    out[0x236]=in->count;
    MIi_CpuCopy16(in->name,out+0x238,(unsigned short)(MBi_CountUtf16Units(in->name)*2));
    MIi_CpuCopy16(in->description,out+0x298,192);
    out[0x358]=1;
    *(unsigned short*)(out+0x35a)=1;
    *(unsigned short*)(out+0x4b0)=1;
}
