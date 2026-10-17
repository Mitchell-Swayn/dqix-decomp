#include <globaldefs.h>
ARM
#pragma optimize_for_size off
#include <System/Memory.h>
#include <System/Interrupts.h>
struct Event{unsigned short type,status,code,id;unsigned a,b;unsigned short c,d;unsigned char payload[6];unsigned short size;unsigned userdata;unsigned short x,y;unsigned char rest[32];};
extern "C" void System_ReadHardwareMacAddress(void*);extern "C" int WirelessCommand_ReadInitializedStatus(),WirelessCommand_ReadSharedWord14CLowHalfwordAtomically(),ReadOptionalSharedHalfwordStatusUnderIRQGuard();extern "C" unsigned char* ReadGlobalOperationContextPointerAt4();
// Original: arm9/main @ 0x020D4770; symbol: func_020d4770; size: 0xD8.
extern "C" int BuildEventAndDispatchRequestWithCallback(int id,void(*callback)(Event*),unsigned userdata){Event event;if(callback){VectorizedMemset(&event,0,68);event.type=0x82;event.status=0;event.code=25;event.id=id;event.a=0;event.b=0;event.c=0;event.size=0xffff;event.userdata=userdata;event.d=0;System_ReadHardwareMacAddress(event.payload);}int irq=DisableIRQInterrupts();int error=WirelessCommand_ReadInitializedStatus();if(error){SetIRQInterruptState(irq);return error;}unsigned char* state=ReadGlobalOperationContextPointerAt4()+id*4;*(void(**)(Event*))(state+0xcc)=callback;*(unsigned*)(state+0x10c)=userdata;if(callback){event.y=WirelessCommand_ReadSharedWord14CLowHalfwordAtomically();event.x=ReadOptionalSharedHalfwordStatusUnderIRQGuard();callback(&event);}SetIRQInterruptState(irq);return 0;}
