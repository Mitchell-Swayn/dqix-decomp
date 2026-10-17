#include <globaldefs.h>
extern "C" int func_ov011_02184c30(void*);
extern "C" void* func_ov017_021b2164();
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*,unsigned);
extern "C" unsigned OV023_ReadHalfwordField04(void*);
extern "C" void* GameResources_GetInstance();
extern "C" void func_ov011_021849e0(void*,unsigned);
extern "C" void func_ov023_021f9c58(void*,unsigned);
extern "C" void func_ov023_021f9c60(void*,unsigned);
extern "C" void func_ov023_021fb274(void*,int);
extern "C" void func_ov023_021fb284(void*,int);
extern "C" void WriteByteAtOffset60(void*,unsigned);
extern "C" void func_ov023_021f8944(void*,void*,unsigned,unsigned);
extern "C" void _Z13SetBrightnessP13GameResourcesii(void*,int,int);
extern "C" void _Z17SetMainBrightnessP13GameResourcesii(void*,int,int);
extern "C" void _Z16SetSubBrightnessP13GameResourcesii(void*,int,int);
extern "C" void* FindTreeNodeForwarder(void*,unsigned);
extern "C" unsigned func_ov011_021844f4(void*,unsigned,unsigned);
extern "C" unsigned func_ov011_021844a4(void*,unsigned,unsigned);
extern "C" void func_ov023_021f6844(void*,unsigned);
extern "C" void _ZN13SafeAllocator5ResetEv(void*);
extern "C" void* _ZN13SafeAllocator8AllocateEj(void*,unsigned);
extern "C" void Graphics_RestoreTextureImageAndPaletteVRAMState(void*);
extern "C" void Object_InvokeSaveTextureImageVRAMState(void*);
// Original: arm9/ov011 @ 0x02187DA8; symbol: func_ov011_02187da8; size: 0x60.
extern "C" unsigned func_ov011_02187da8(void* self) { unsigned id=func_ov011_02184c30(self); unsigned value=func_ov011_02184c30((char*)self+8); void* item=func_ov023_021f6880(func_ov011_021849c8(func_ov017_021b2164()),id); if(!item) return 0; if(OV023_ReadHalfwordField04(item)!=1) return 0; func_ov023_021fb284(item,(signed char)value); return 1; }
