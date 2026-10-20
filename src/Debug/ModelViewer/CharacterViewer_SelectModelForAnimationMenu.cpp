#include <globaldefs.h>
ARM
extern "C" void CharacterViewer_PushMenuHistory(...);
extern "C" void CharacterViewer_RebuildMenu(...);
extern "C" void UpdateCachedAnimationEntry(...);
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov015 @ 0x02191BA0; symbol: Graphics_SelectLinkedAnimationRecordAndResetMode; size: 0xd0.
// Selects a linked animation record by index and resets mode/animation fields according to record byte1C.
extern "C" void CharacterViewer_SelectModelForAnimationMenu(char* self,int index){char* node=P(self,0x2c);if(!node)return;for(int i=0;i<index;++i)node=P(node,4);if(!node)return;P(self,0x30)=P(node,0);switch(B(P(node,0),0x1c)){case 0:case 1:CharacterViewer_PushMenuHistory(self,W(self,0x1a4));W(self,0x1a4)=34;CharacterViewer_RebuildMenu(self,0);break;case 2:CharacterViewer_PushMenuHistory(self,W(self,0x1a4));W(self,0x1a4)=33;CharacterViewer_RebuildMenu(self,0);break;default:W(self,0x194)=1;CharacterViewer_RebuildMenu(self,0);H(P(self,0x30),0x38)=0;UpdateCachedAnimationEntry(P(self,0x30));break;}}
