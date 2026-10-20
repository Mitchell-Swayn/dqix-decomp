#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original data: arm9/ov017 @ 0x21d61fc; symbol: data_ov017_021d61fc.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000ffffffff.
// Observed span: 48 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" int GraphicsStagePartyObjectTexturesAfterDisplayWait_UnknownRoleInitializedBytes[12];extern "C" void System_WaitForInterruptOneAfterShortDelay();extern "C" void* _ZN9GameState11GetInstanceEv(),*_ZN9GameState20GetGameObjectByIndexEi(void*,int),*_ZN7Model3D7GetTEX0Ev(void*);extern "C" int _Z23StageTexFilePaletteDataPV8NSBXXTexb(void*,bool),_Z21StageTexFileImageDataPV8NSBXXTexb(void*,bool);
// Original: arm9/ov017 @ 0x0218f80c; symbol: Graphics_StagePartyObjectTexturesAfterDisplayWait; size 0x120.
extern "C" void Graphics_StagePartyObjectTexturesAfterDisplayWait(int unused,int member){if(!(*(volatile unsigned short*)0x04000004&1))System_WaitForInterruptOneAfterShortDelay();void* game=_ZN9GameState11GetInstanceEv();struct List{int ids[12];};List list=*(List*)GraphicsStagePartyObjectTexturesAfterDisplayWait_UnknownRoleInitializedBytes;int offset=member*12;list.ids[0]=member;list.ids[1]=offset+19;list.ids[2]=offset+20;list.ids[3]=offset+22;list.ids[4]=offset+23;list.ids[5]=offset+24;list.ids[6]=offset+25;list.ids[7]=offset+26;list.ids[8]=offset+27;list.ids[9]=offset+28;list.ids[10]=offset+29;for(int i=0;list.ids[i]>-1;i++){void* object=_ZN9GameState20GetGameObjectByIndexEi(game,list.ids[i]);if(object&&S(object,2)>-1&&P(object,8)){void* texture=_ZN7Model3D7GetTEX0Ev(P(object,8));if(texture){_Z23StageTexFilePaletteDataPV8NSBXXTexb(texture,false);_Z21StageTexFileImageDataPV8NSBXXTexb(texture,false);}}}}
