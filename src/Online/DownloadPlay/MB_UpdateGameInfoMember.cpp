#include <globaldefs.h>
ARM
extern "C" void MIi_CpuCopy16(const void*,volatile void*,int);
// Original: arm9/ov027 @ 0x021DAD14; symbol: func_ov027_021dad14; size: 0x70.
// Copies fifteen child-user records and updates member count, bitmaps and beacon sequence.
extern "C" void MB_UpdateGameInfoMember(unsigned char *info,const void *users,unsigned members,unsigned short auxiliary)
{
    unsigned char count=1;
    MIi_CpuCopy16(users,info+0x35e,330);
    for(int i=0;i<15;i++)if(members&(2<<i))count++;
    info[0x358]=count;
    *(unsigned short*)(info+0x35a)=members|1;
    *(unsigned short*)(info+0x35c)=auxiliary;
    info[0x4b4]++;
}
