#include <globaldefs.h>
ARM
extern "C" void Bgm_RequestTemporarySequence(int self,unsigned short value);
extern "C" bool Bgm_IsTemporarySequencePendingOrPlaying(char* p);
// Original data: arm9/main @ 0x2109bf4; symbol: data_02109bf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant2[];
// Original: arm9/ov005 @ 0x0215CB4C; symbol: func_ov005_0215cb4c; size: 0x88.
extern "C" int EquipmentMenu_PollTemporaryMusic(unsigned char* p) {
if(!(*(unsigned int*)(p+0x3dcc)&0x10000))return 0;
unsigned char state=p[0x3df3];
if(state==0){Bgm_RequestTemporarySequence((int)Main_UnknownRoleZeroInitializedStorage_Variant2,0x3d);++p[0x3df3];}
if(state==1){
if(Bgm_IsTemporarySequencePendingOrPlaying(Main_UnknownRoleZeroInitializedStorage_Variant2))return 1;
*(unsigned int*)(p+0x3dcc)&=~0x10000;
p[0x3df3]=0;
return 0;
}
return 1;
}
