#include <globaldefs.h>
ARM
#pragma optimization_level 4
#pragma optimize_for_size off
#include <System/Mutex.h>
extern "C" void Resource_UpdateSelectedRecordModesFromEnableState(int,unsigned short,unsigned);
extern "C" int System_DispatchNestedResourceByByte9();
// Original: arm9/ov031 @ 0x0220586C; symbol: func_ov031_0220586c; size: 0x84.
// Configures the endpoint under its receive mutex and records success or failure flags.
extern "C" int Network_ExecuteSocketEndpointSetup(void* request)
{
 unsigned char* command=(unsigned char*)request;
 unsigned char* socket=*(unsigned char**)(command+4);
 unsigned char* state=*(unsigned char**)(socket+0x64);
 int result=0;
 LockMutex((Mutex*)(state+0xe0));
 Resource_UpdateSelectedRecordModesFromEnableState(*(unsigned short*)(command+0x10),*(unsigned short*)(command+0x12),*(unsigned*)(command+0x14));
 *(int*)(state+0xf8)=0;
 int mode=*(signed char*)(command+0xc);
 if(mode==0||mode==4)result=System_DispatchNestedResourceByByte9();
 UnlockMutex((Mutex*)(state+0xe0));
 if(result){*(volatile short*)(socket+0x70)|=0x40;return -76;}
 *(volatile short*)(socket+0x70)|=4;
 return 0;
}
