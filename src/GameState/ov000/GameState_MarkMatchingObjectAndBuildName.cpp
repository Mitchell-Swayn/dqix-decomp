#include <globaldefs.h>
ARM
struct GameState;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned char* GameState_FindIndexedObjectWithFlag400(GameState*,unsigned);
extern "C" void Object_BuildNameWithTypeSuffix(char*);
// Original: arm9/ov000 @ 0x02161274; symbol: func_ov000_02161274; size: 0x8C.
extern "C" void GameState_MarkMatchingObjectAndBuildName(unsigned char* self) {
if(!self || !*(void**)(self+0x144)) return;
short key=*(short*)(*(char**)(self+0x144)+8);
GameState* state=(GameState*)_ZN9GameState11GetInstanceEv();
for(int i=0;i<8;++i) {
unsigned char* p=GameState_FindIndexedObjectWithFlag400(state,i+0xc0);
if(p && p!=self && *(void**)(p+0x144)) {
if(*(short*)(*(char**)(p+0x144)+8)==key && !(*(unsigned char**)(p+0x138))[0x25] && !p[0x18d]) {
(*(unsigned char**)(p+0x138))[0x25]=1;
p[0x18d]=1;
Object_BuildNameWithTypeSuffix((char*)p);
return;
}
}
}
}
