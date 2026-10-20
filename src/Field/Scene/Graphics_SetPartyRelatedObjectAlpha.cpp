#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
// Original data: arm9/ov017 @ 0x21d6298; symbol: data_ov017_021d6298.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000c8000000ffffffff080700105f050000.
// Observed span: 64 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
struct IDs{int values[14];};extern "C" {extern IDs GraphicsSetPartyRelatedObjectAlpha_UnknownRoleInitializedBytes;void* _ZN9GameState11GetInstanceEv();void* _ZN9GameState20GetGameObjectByIndexEi(void*,int);void _ZN8Object3D19SetAlphaScaleFactorEi(void*,int);}
// Original: arm9/ov017 @ 0x021919C8; symbol: Graphics_SetPartyRelatedObjectAlpha; size: 0xe4.
extern "C" void Graphics_SetPartyRelatedObjectAlpha(void*,int index,int alpha){IDs ids=GraphicsSetPartyRelatedObjectAlpha_UnknownRoleInitializedBytes;ids.values[0]=index;ids.values[1]=index*12+19;ids.values[2]=index*12+20;ids.values[3]=index*12+21;ids.values[4]=index*12+22;ids.values[5]=index*12+23;ids.values[6]=index*12+24;ids.values[7]=index*12+25;ids.values[8]=index*12+26;ids.values[9]=index*12+27;ids.values[10]=index*12+28;ids.values[11]=index*12+29;void* game=_ZN9GameState11GetInstanceEv();for(int i=0;ids.values[i]>-1;++i){void* object=_ZN9GameState20GetGameObjectByIndexEi(game,ids.values[i]);if(object)_ZN8Object3D19SetAlphaScaleFactorEi(object,alpha);}}
