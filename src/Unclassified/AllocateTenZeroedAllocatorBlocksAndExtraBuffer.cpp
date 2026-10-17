#include <globaldefs.h>
ARM
#include <Memory/SafeAllocator.h>
#include <System/Memory.h>
extern "C" {extern unsigned int data_020e7c40[];void InitializeElevenContextBoundedResourceRegions(void*,int);
// Original: arm9/main @ 0x020542B4; symbol: func_020542b4; size: 0x138.
void AllocateTenZeroedAllocatorBlocksAndExtraBuffer(unsigned char* p,SafeAllocator* alloc,int value){alloc->Reset();for(int i=0;i<10;i++){unsigned int size=data_020e7c40[i];void* data=alloc->Allocate(size);VectorizedMemset(data,0,size);((SafeAllocator*)(p+4+i*0x14))->CreateTypeA(data,size);}InitializeElevenContextBoundedResourceRegions(p,value);void* data=alloc->Allocate(0x2000);VectorizedMemset(data,0,0x2000);((SafeAllocator*)(p+0x52c))->CreateTypeA(data,0x2000);data=alloc->Allocate(0x5400);VectorizedMemset(data,0,0x5400);((SafeAllocator*)(p+0x540))->CreateTypeA(data,0x5400);data=alloc->Allocate(0x1000);VectorizedMemset(data,0,0x1000);((SafeAllocator*)(p+0x554))->CreateTypeA(data,0x1000);data=alloc->Allocate(0xc00);VectorizedMemset(data,0,0xc00);((SafeAllocator*)(p+0x5d8))->CreateTypeA(data,0xc00);}}
