#include <globaldefs.h>
ARM
#pragma optimization_level 4
struct HandleOwner;
extern "C" {void _ZN8Object3D4DrawEb(void*,bool);void Object3D_DrawEffectHandle(HandleOwner*);void Object_SumTwoCountsAcrossActiveLinkedNodes(unsigned char*,unsigned short*,unsigned short*);}
// Original: arm9/ov015 @ 0x0218EE38; symbol: func_ov015_0218ee38; size: 0xB8.
extern "C" void Graphics_DrawHandleOrObjectAndCollectCounts(void* owner){
unsigned zero=0;char* p=(char*)owner;
*(unsigned short*)(p+0x34)=*(unsigned short*)(p+0x36)=0;
if(*(int*)(*(char**)(p+0x28)+12)){
*(volatile unsigned*)0x04000444=0;
Object3D_DrawEffectHandle(*(HandleOwner**)(p+0x28));
*(volatile unsigned*)0x04000448=1;
unsigned char* object=*(unsigned char**)(*(char**)(p+0x28)+4);
if(!object){*(unsigned short*)(p+0x34)=0;*(unsigned short*)(p+0x36)=0;return;}
Object_SumTwoCountsAcrossActiveLinkedNodes(object,(unsigned short*)(p+0x34),(unsigned short*)(p+0x36));
}else{
*(volatile unsigned*)0x04000444=0;
_ZN8Object3D4DrawEb(*(void**)(p+0x24),false);
*(volatile unsigned*)0x04000448=1;
*(unsigned short*)(p+0x34)=*(unsigned short*)(*(char**)(*(char**)(*(char**)(p+0x24)+8)+0x54)+0x28);
*(unsigned short*)(p+0x36)=*(unsigned short*)(*(char**)(*(char**)(*(char**)(p+0x24)+8)+0x54)+0x2a);
}
}
