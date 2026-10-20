#include <globaldefs.h>
ARM
extern "C" int OS_GetOwnerInfo(...);
extern "C" int DisableInterruptsAndHaltForever(...);
extern "C" int MI_CpuCopy8(...);
extern "C" int Graphics_InitializeSubDisplayStateAndRecordGrid(...);
extern "C" int MB_Init(...);
extern "C" int MB_SetParentCommParam(...);
extern "C" int Multiboot_SetParentState(...);extern "C" void Multiboot_HandleParentCommunicationEvent();
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);
// Original data: arm9/ov031 @ 0x2290d14; symbol: data_ov031_02290d14.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char* MultibootGetParentState_UnknownRoleZeroInitializedStorage;

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov031 @ 0x022386D4; symbol: InitializeHardwarePacketAndRegisterParentCallback.
extern "C" void Multiboot_InitializeParentAndInstallEventCallback(int first,int second){
char configuration[84];OS_GetOwnerInfo(configuration);struct Packet{unsigned char flags,count;unsigned short values[10];};Packet packet;packet.flags=(packet.flags&~15)|(B(configuration,1)&15);unsigned count=H(configuration,26);packet.count=count;MI_CpuCopy8(configuration+4,packet.values,count*2);packet.flags&=~240;struct Header{unsigned short words[7];};Header header={0,0,0,0,0,0,0};*(Header*)MultibootGetParentState_UnknownRoleZeroInitializedStorage=header;P(MultibootGetParentState_UnknownRoleZeroInitializedStorage+0x1b000,320)=MultibootGetParentState_UnknownRoleZeroInitializedStorage+0x10040;if(MB_Init(P(MultibootGetParentState_UnknownRoleZeroInitializedStorage+0x1b000,320),&packet,first,second,2))DisableInterruptsAndHaltForever();MB_SetParentCommParam(256,1);Graphics_InitializeSubDisplayStateAndRecordGrid(Multiboot_HandleParentCommunicationEvent);Multiboot_SetParentState(1);
}
