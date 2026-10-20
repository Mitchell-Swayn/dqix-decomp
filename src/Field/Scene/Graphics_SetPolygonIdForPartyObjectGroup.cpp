#include <globaldefs.h>
ARM
#include <std_library_functions.h>
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
struct CountPrice{unsigned count:7,price:25;};
struct FlagBits{unsigned char a:1,b:1,index:6;};
struct Nibbles{unsigned char low:4,high:4;};
struct SixFlags{unsigned char index:6,a:1,b:1;};
extern "C" unsigned Graphics_SetNestedModelPolygonIDIfAvailable(...);
extern "C" unsigned _ZN9GameState11GetInstanceEv(...);
extern "C" unsigned _ZN9GameState20GetGameObjectByIndexEi(...);
// Original data: arm9/ov017 @ 0x21d618e; symbol: data_ov017_021d618e.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000000000000000000000000000ffff.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" unsigned char GraphicsSetPolygonIdForPartyObjectGroup_UnknownRoleInitializedBytes[];
// Original: arm9/ov017 @ 0x0219230c; symbol: Graphics_SetPolygonIdForPartyObjectGroup.
extern "C" void Graphics_SetPolygonIdForPartyObjectGroup(void* unused,int index,unsigned polygon){int valid=index>=0&&index<=3;if(!valid)return;void* game=(void*)_ZN9GameState11GetInstanceEv();struct Eight{short v[8];};Eight indices=*(Eight*)GraphicsSetPolygonIdForPartyObjectGroup_UnknownRoleInitializedBytes;int base=index*12;indices.v[0]=index;indices.v[1]=base+19;indices.v[2]=base+20;indices.v[3]=base+21;indices.v[4]=base+27;indices.v[5]=base+28;indices.v[6]=base+29;for(int i=0;indices.v[i]>-1;i++){void* object=(void*)_ZN9GameState20GetGameObjectByIndexEi(game,indices.v[i]);if(object)Graphics_SetNestedModelPolygonIDIfAvailable(object,polygon);}}
