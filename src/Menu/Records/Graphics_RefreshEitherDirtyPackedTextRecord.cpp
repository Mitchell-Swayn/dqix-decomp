#include <globaldefs.h>
ARM
extern "C" int Window_ReplaceCanvasTextById(...);
extern "C" void memset(...);
extern "C" void Text_AppendSelectedPackedRecord(...);
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov008 @ 0x021873AC; symbol: Graphics_RefreshEitherDirtyPackedTextRecord; size: 0xd0.
// Refreshes either packed text record when its dirty flag800/1000 is set, then clears that flag.
extern "C" void Graphics_RefreshEitherDirtyPackedTextRecord(char* self,int index){if(index==0){if(!(U(self,0xb18)&0x800))return;memset(P(self,0xb8),0,2400);Text_AppendSelectedPackedRecord(self,P(self,0xb8),index,0);Window_ReplaceCanvasTextById(self+0x130,1,P(self,0xb8),1,0);U(self,0xb18)&=~0x800;}else if(index==1){if(!(U(self,0xb18)&0x1000))return;memset(P(self,0xb8),0,2400);Text_AppendSelectedPackedRecord(self,P(self,0xb8),index,0);Window_ReplaceCanvasTextById(self+0x130,2,P(self,0xb8),1,0);U(self,0xb18)&=~0x1000;}}
