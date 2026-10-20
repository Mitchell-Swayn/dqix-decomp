#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
extern "C" {void _Z25InitializeBrightnessStateP13GameResources(void*);void* memset(void*,int,unsigned);void DebugMenu_Initialize(void*);void CharacterViewer_ResetVramReservationSlot(void*);}
// Original: arm9/ov015 @0x02193294; symbol:Graphics_InitializeBrightnessAndThreeEntryBanks; size:0x118.
// Initializes brightness state, invalid sentinels, owner buffers and three four-entry banks.
extern "C" void CharacterViewer_InitializeState(unsigned char* self){_Z25InitializeBrightnessStateP13GameResources(self);W(self,0x2c)=0;W(self,0x30)=0;W(self,0x34)=0;((signed char*)self)[0x38]=-1;W(self,0x194)=-1;W(self,0x198)=-1;self[0x19c]=1;self[0x19d]=1;self[0x19e]=1;self[0x19f]=1;self[0x1a0]=0;self[0x1a1]=0;W(self,0x1a4)=-1;memset(self+0x1a8,-1,128);W(self,0x228)=0;W(self,0x22c)=0;W(self,0x230)=0;W(self,0x234)=0;W(self,0x238)=0;W(self,0x23c)=0;W(self,0x240)=0;W(self,0x244)=0;W(self,0x248)=0;W(self,0x24c)=0;W(self,0x250)=0;W(self,0x254)=0;W(self,0x258)=0;W(self,0x25c)=0;W(self,0x260)=0;W(self,0x264)=0;memset(self+0x268,0,82);W(self,0x348)=0;W(self,0x34c)=0;W(self,0x2bc)=30;W(self,0x2c0)=0;W(self,0x84)=0;DebugMenu_Initialize(self+0x2c4);W(self,0x304)=1;W(self,0x344)=0;self[0x350]=0;unsigned char* second;unsigned char* first;first=self+0xc4;second=self+0xe4;unsigned char* third=self+0x104;for(int i=0;i<4;++i){CharacterViewer_ResetVramReservationSlot(first+i*8);CharacterViewer_ResetVramReservationSlot(second+i*8);CharacterViewer_ResetVramReservationSlot(third+i*8);}}
