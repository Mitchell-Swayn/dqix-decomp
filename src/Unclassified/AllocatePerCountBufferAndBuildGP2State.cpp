#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
#include <World/Zone3DEmbeddedState.h>
#include <Filesystem/BackgroundLoader.h>
#include <Filesystem/FileIO.h>
extern "C" unsigned char data_02114e20[];extern "C" const char* data_020f2a38;extern "C" const char* data_020f2a30;extern "C" void* AllocatorUnion_AllocateFourByteAligned(void*,unsigned);
struct Object{SafeAllocator allocator;ZoneState2754 state;ZoneState2754* current;};
// Original: arm9/main @ 0x0207D6DC; symbol: func_0207d6dc; size: 0xB0.
extern "C" ARM void AllocatePerCountBufferAndBuildGP2State(Object* p,const short* keys,int count){unsigned bytes=count<<8;void* buffer=AllocatorUnion_AllocateFourByteAligned(data_02114e20,bytes);p->allocator.CreateTypeA(buffer,bytes);p->allocator.Reset();p->state.Reset();BackgroundLoader::AddLockGlobal();unsigned size=0;void* file=ExtractFileFromGP2(data_020f2a38,data_020f2a30,&size);if(file)p->state.BuildForKeys(&p->allocator,file,size,keys,(unsigned short)count);BackgroundLoader::RemoveLockGlobal();p->current=&p->state;}
