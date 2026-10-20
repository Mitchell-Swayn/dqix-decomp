#include <globaldefs.h>
ARM
struct Threshold { float value; unsigned pad; };
// Original data: arm9/ov024 @ 0x21fe970; symbol: data_ov024_021fe970.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 6666663f.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
// Original data: arm9/ov024 @ 0x21fe974; symbol: data_ov024_021fe974.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 5a000000cdcc4c3f5a0000003333333f400000009a99193f200000000000003f10000000cdcccc3e080000009a99993e04000000cdcc4c3e02000000cdcccc3d ...; full span in module reference.
// Observed span: 68 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" { unsigned _fdiv(unsigned,unsigned); int _fflt(int); unsigned _ffltu(unsigned); void* _ZN9GameState11GetInstanceEv(); unsigned char* GameState_GetObjectWithFlag100(void*,int); extern Threshold GameStateMapObjectValueRatioToByte_UnknownRoleInitializedBytes[]; extern unsigned char GameStateMapObjectValueRatioToByte_UnknownRoleInitializedBytes_Variant2[]; }
// Original: arm9/ov024 @ 0x021EB344; symbol: func_ov024_021eb344; size: 0x9C.
extern "C" int GameState_MapObjectValueRatioToByte(void* unused,int id,int value) {
 unsigned char* object=GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(),id);
 if(!object) return 0;
 if(value<=0) return 0;
 id=*(volatile unsigned short*)(*(unsigned char**)(object+0x138)+4);
 float ratio=(float)value/(float)(unsigned)id;
 for(int i=0;i<9;++i) if(ratio>=GameStateMapObjectValueRatioToByte_UnknownRoleInitializedBytes[i].value) return GameStateMapObjectValueRatioToByte_UnknownRoleInitializedBytes_Variant2[i*8];
 return 0;
}
