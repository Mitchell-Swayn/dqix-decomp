#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
extern "C" void MenuRecord_ResetHeader(void*);extern "C" void Graphics_InitializeCanvasTransferState(void*);extern "C" void Graphics_SetTextBackgroundScreenSize(void*,unsigned);extern "C" void Graphics_SetBackgroundColorMode(void*,unsigned);extern "C" int Graphics_InvokeTwoIndexTransferCallback(void*,void*,void*);extern "C" char* Menu_FindSessionArenaById(void*,unsigned);extern "C" void Graphics_AllocateAndClearConfiguredBuffer(void*,void*);extern "C" void MenuLayerRecord_AttachNamedPayloadFromOwnerTask(void*,void*);struct Flags{char pad[0x44];unsigned char low:4;unsigned char high:4;};
// Original: arm9/ov023 @ 0x021F745C; symbol: Graphics_InitializeTypeTwoRecordAndAllocateCanvas; size: 0xF4.
extern "C" int MenuLayerRecord_InitializeAndAllocateScreenBuffer(char* self,void* owner,int a,int b,void* p,void* q,unsigned low,unsigned high,unsigned mode){MenuRecord_ResetHeader(self);H(self,4)=2;P(self,32)=(char*)owner;H(self,6)=a;H(self,8)=b;H(self,10)=0;P(self,36)=(char*)p;P(self,16)=(char*)q;W(self,72)=0;Graphics_InitializeCanvasTransferState(self+40);Graphics_SetTextBackgroundScreenSize(self+40,0);((Flags*)self)->low=(unsigned char)low;((Flags*)self)->high=(unsigned char)high;Graphics_SetBackgroundColorMode(self+40,mode);Graphics_InvokeTwoIndexTransferCallback(self+40,0,0);char* node=Menu_FindSessionArenaById(owner,U(self,8));if(!node)return 0;Graphics_AllocateAndClearConfiguredBuffer(self+40,node+4);MenuLayerRecord_AttachNamedPayloadFromOwnerTask(self,owner);H(self,80)=0;H(self,82)=0;return 1;}
