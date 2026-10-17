#include <globaldefs.h>
ARM
struct State {char pad[0x9c1];unsigned char kind;char pad2[0x222];int extent,position;volatile short phase,delay;};
extern "C" void* GetGlobalStatePointer();
extern "C" int TestWordMaskNonzero(void*,int);
extern "C" void* GameResources_GetInstance();
extern "C" int ReadSelectedFloatFieldAsInteger(void*,int);
extern "C" void CopyRepeatedBlocksAndUploadSubObjectVRAM(State*,int);
extern "C" void Graphics_ReplicateSpriteDataAndUploadSubObjectVRAM(State*,int);
// Original: arm9/main @ 0x020275E4; symbol: func_020275e4; size: 0xF8.
extern "C" void AdvanceScrollingPositionByPhaseAndKind(State* p) {
 if(TestWordMaskNonzero(GetGlobalStatePointer(),0x41))return;
 int amount=0;if(p->kind==0)amount=0x90;else if(p->kind==1)amount=0x98;
 if(!amount||amount>=p->extent)return;
 if(ReadSelectedFloatFieldAsInteger(GameResources_GetInstance(),1))return;
 switch(p->phase){case 0:++p->delay;if(p->delay>=16){p->delay=0;p->phase=1;}return;
 case 1:++p->position;if(p->extent<p->position)p->position=-amount;
 if(p->kind==0)CopyRepeatedBlocksAndUploadSubObjectVRAM(p,0);else Graphics_ReplicateSpriteDataAndUploadSubObjectVRAM(p,0);
 if(p->position==0)p->phase=2;return;default:return;}
}
