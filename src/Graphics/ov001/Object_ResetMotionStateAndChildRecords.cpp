#include <globaldefs.h>
ARM
extern "C" void* memset(void*,int,unsigned);
extern "C" char* strcpy(char*,const char*);
extern "C" void Ov001_InitializeExtendedSessionRecord(void*);
extern "C" char data_ov001_02164d10[];
// Original: arm9/ov001 @ 0x021588E4; symbol: func_ov001_021588e4; size: 0x1D4.
extern "C" void Object_ResetMotionStateAndChildRecords(char* p) {
 *(int*)(p+0x30)=0;
 *(int*)(p+0x34)=0;
 *(int*)(p+0x38)=0;
 *(int*)(p+0x3c)=0;
 *(int*)(p+0x40)=0;
 *(int*)(p+0x44)=0;
 *(int*)(p+0x48)=0;
 memset(p+0x4c,0,12);
 memset(p+0x58,0,12);
 *(int*)(p+0x6c)=0;
 *(int*)(p+0x68)=0;
 *(int*)(p+0x64)=0;
 *(int*)(p+0x70)=0;
 *(int*)(p+0x74)=-1;
 *(int*)(p+0x78)=0;
 memset(p+0x7c,0,12);
 strcpy(p+0x94,data_ov001_02164d10);
 *(int*)(p+0x88)=*(int*)(p+0x8c)=*(int*)(p+0x90)=0;
 memset(p+0xb4,0,12);
 memset(p+0xc0,0,12);
 *(int*)(p+0xcc)=*(int*)(p+0xd4)=*(int*)(p+0xd8)=0;
 memset(p+0xdc,0,12);
 memset(p+0xe8,0,12);
 memset(p+0xf4,0,12);
 memset(p+0x100,0,12);
 *(int*)(p+0x10c)=0;
 memset(p+0x110,0,12);
 memset(p+0x11c,0,12);
 memset(p+0x128,0,12);
 *(int*)(p+0x134)=0;
 *(int*)(p+0xa24)=0;
 memset(p+0x138,0,12);
 memset(p+0x144,0,12);
 memset(p+0x150,0,12);
 *(int*)(p+0x8)=0;
 *(int*)(p+0xc)=0;
 *(int*)(p+0x10)=0;
 *(int*)(p+0x14)=0;
 *(int*)(p+0x18)=0;
 *(int*)(p+0x1c)=0;
 *(int*)(p+0x20)=0;
 *(int*)(p+0x24)=0;
 *(int*)(p+0x28)=0;
 *(int*)(p+0x2c)=0;
 *(int*)(p+0xa20)=0;
 if(!*(void**)p)return;
 if(*(int*)(p+4)<=0)return;
 for(int i=0;i<*(int*)(p+4);i++)Ov001_InitializeExtendedSessionRecord(*(char**)p+i*0x4c);
}
