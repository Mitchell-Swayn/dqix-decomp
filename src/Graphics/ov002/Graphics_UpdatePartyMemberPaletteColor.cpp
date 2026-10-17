#include <globaldefs.h>
ARM
#pragma optimization_level 4
struct GameState;struct Object3D;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetIndexList(GameState*);
extern "C" Object3D* _ZN9GameState21GetPartyMemberByIndexEi(GameState*,int);
extern "C" unsigned char* ReadWordFieldAtOffset150(void*);
extern "C" void _Z25CleanInvalidateCacheRangePKvj(const void*,unsigned);
extern "C" void LoadToMainObjStandardPalette(const void*,unsigned,unsigned);
// Original: arm9/ov002 @ 0x02161A8C; symbol: func_ov002_02161a8c; size: 0xBC.
extern "C" void Graphics_UpdatePartyMemberPaletteColor() {
unsigned short white=0x7fff;
unsigned short dark=0x2108;
unsigned short* color;
GameState* state=(GameState*)_ZN9GameState11GetInstanceEv();
char* list=(char*)GameState_GetIndexList(state);
unsigned char count=*(unsigned char*)(list+0xf7c);
for(unsigned char i=0;i<count;++i) {
int index=*(list+i+0xf78);
color=&white;
Object3D* object=_ZN9GameState21GetPartyMemberByIndexEi(state,index);
if(!object) continue;
unsigned char* data=ReadWordFieldAtOffset150(object);
if(!data) continue;
if(data[0x56a]==1 || data[0x56a]==15) color=&dark;
index=(index+9)<<4;
_Z25CleanInvalidateCacheRangePKvj(color,2);
unsigned offset=index+13;
LoadToMainObjStandardPalette(color,offset<<1,2);
}
}
