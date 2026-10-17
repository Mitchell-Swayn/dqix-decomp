#include <globaldefs.h>
ARM
extern "C" void* Memory_AllocateZeroedBlock(unsigned,unsigned);
extern "C" void* InitializeSteppedOverlayValues(int,void*,int);
extern "C" void* System_InitializeGlobalQueue();
extern "C" void func_ov031_0223d918(void*,void*);
extern "C" void func_ov031_0223d908(void*,void*);
extern "C" unsigned char* data_ov031_02290d64;
// Original: arm9/ov031 @ 0x0223DABC; symbol: func_ov031_0223dabc; size: 0xC0.
extern "C" void Resource_AllocateAndInitializeTwoStateBlocks(){
 data_ov031_02290d64=(unsigned char*)Memory_AllocateZeroedBlock(0x340,4);
 for(int i=0;i<2;i++){
 int offset=i*0x1a0;
 *(void**)(data_ov031_02290d64+offset+0x19c)=InitializeSteppedOverlayValues(32,data_ov031_02290d64+offset,12);
 *(void**)(data_ov031_02290d64+offset+0x198)=System_InitializeGlobalQueue();
 *(unsigned short*)(data_ov031_02290d64+offset+0x188)=0x300;
 *(unsigned short*)(data_ov031_02290d64+offset+0x194)=0x400;
 func_ov031_0223d918(*(void**)(data_ov031_02290d64+offset+0x198),data_ov031_02290d64+offset+0x180);
 func_ov031_0223d908(*(void**)(data_ov031_02290d64+offset+0x198),data_ov031_02290d64+offset+0x18c);
 }
}
