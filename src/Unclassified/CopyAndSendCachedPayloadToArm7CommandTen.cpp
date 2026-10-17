#include "globaldefs.h"
#pragma optimize_for_size off
ARM
extern "C" void* WirelessCommand_TryReceiveHighBitMarkedPacket(); extern "C" void MI_CpuCopy8(const void*,void*,unsigned); extern "C" void _Z15CleanCacheRangePKvj(const void*,unsigned); extern "C" int _Z17SendCommandToArm7iib(int,int,bool); extern "C" void OS_SendMessage(void*,void*,int); extern "C" unsigned char data_021142e8;
// Original: arm9/main @ 0x020D4168; symbol: func_020d4168; size: 0x70.
extern "C" int CopyAndSendCachedPayloadToArm7CommandTen(const void*src,unsigned size){void*p=WirelessCommand_TryReceiveHighBitMarkedPacket();if(!p)return 8;MI_CpuCopy8(src,p,size);_Z15CleanCacheRangePKvj(p,size);int result=_Z17SendCommandToArm7iib(10,(int)p,false);OS_SendMessage(&data_021142e8,p,1);return result<0?8:2;}
