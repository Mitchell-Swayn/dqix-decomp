#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" unsigned _ZNK9GameState12GetTickCountEv(void*);
// Original: arm9/ov023 @ 0x021ECE9C; symbol: AdvanceFlaggedPanelHorizontalSlide; size: 0xDC.
extern "C" void Menu_AdvanceQueuedPanelHorizontalSlide(char* self){if(!(U(self,0x438)&0x80))return;unsigned state=B(self,0x433);if(state==0){H(self,0x448)=-36;B(self,0x43c)=0;B(self,0x433)++;}if(state!=1)return;U(self,0x438)|=1;B(self,0x43c)+=_ZNK9GameState12GetTickCountEv(_ZN9GameState11GetInstanceEv());H(self,0x448)=(int)(292.0f*((float)(unsigned)B(self,0x43c)/60.0f))-36;if(H(self,0x448)>256){U(self,0x438)&=~0x80;H(self,0x448)=-36;B(self,0x43c)=0;U(self,0x438)|=2;B(self,0x433)=0;}}
