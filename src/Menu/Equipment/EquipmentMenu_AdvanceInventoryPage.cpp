#include <globaldefs.h>
ARM
#pragma opt_common_subs off
extern "C" int SoundSfx_StartCurrentSequenceArchiveEntry(...);
extern "C" void* memset(void*,int,unsigned);extern "C" void* memcpy(void*,const void*,unsigned);
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage[];
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov005 @ 0x021585FC; symbol: AdvanceWrappedSelectionAndSavePreviousIndices; size: 0xc8.
extern "C" int EquipmentMenu_AdvanceInventoryPage(char* self,int direction){
unsigned max=(unsigned char)(B(self+B(self,0x3dbc),0x3df4)-1);int old=*(signed char*)(self+0x3dbd);int selected=(signed char)(old+direction);if(selected<0)selected=(signed char)max;if(selected>(int)max)selected=0;int changed=1;if(selected==old)changed=0;if(changed){SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);if(direction<0)W(self,0x3dcc)|=0x20000;else W(self,0x3dcc)|=0x40000;B(self,0x3dbe)=B(self,0x3dbc);B(self,0x3dbf)=*(signed char*)(self+0x3dbd);B(self,0x3dbd)=selected;W(self,0x3dcc)|=0x40;B(self,0x3daa)=0;}return changed;
}
