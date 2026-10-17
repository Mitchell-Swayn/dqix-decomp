#include <globaldefs.h>
ARM
extern "C" void InitializeVRAM();
extern "C" int _Z19GenerateLockOwnerIDv();
extern "C" void DisableInterruptsAndHaltForever();
extern "C" void _Z20DMAMemsetSynchronousijjj(int, unsigned int,unsigned int,unsigned int);
extern "C" void MIi_CpuClear32(int,void*,unsigned int);
extern "C" unsigned short data_02111220[];
extern "C" int data_020f226c[];
#define R16(a) (*(volatile unsigned short*)(a))
#define R32(a) (*(volatile unsigned int*)(a))
// Original: arm9/main @ 0x020C36F0; symbol: GX_Init; size: 0x14C.
extern "C" void GX_Init() {
 R16(0x4000304) |=0x8000;
 R16(0x4000304) = (unsigned short)((R16(0x4000304)&~0x20e)|0x20e);
 R16(0x4000304) = (unsigned short)(R16(0x4000304)|1);
 InitializeVRAM();
 while(*(volatile unsigned short*)(data_02111220+1)==0) {
  int id=_Z19GenerateLockOwnerIDv();
  if(id==-3) DisableInterruptsAndHaltForever();
  *(volatile unsigned short*)(data_02111220+1)=(unsigned short)id;
 }
 R16(0x4000004)=0;
 R32(0x4000000)=0;
 if(data_020f226c[1]!=-1) {
  _Z20DMAMemsetSynchronousijjj(data_020f226c[1],0x4000008,0,0x60);
  R16(0x400006c)=0;
  _Z20DMAMemsetSynchronousijjj(data_020f226c[1],0x4001000,0,0x70);
 } else {
  MIi_CpuClear32(0,(void*)0x4000008,0x60);
  R16(0x400006c)=0;
  MIi_CpuClear32(0,(void*)0x4001000,0x70);
 }
 R16(0x4000020)=0x100;
 R16(0x4000026)=0x100;
 R16(0x4000030)=0x100;
 R16(0x4000036)=0x100;
 R16(0x4001020)=0x100;
 R16(0x4001026)=0x100;
 R16(0x4001030)=0x100;
 R16(0x4001036)=0x100;
}
