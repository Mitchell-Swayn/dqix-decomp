#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x211e33c; symbol: data_0211e33c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 7889 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant3[],WindowFrame_LoadArchivePartsWithReusableAllocator_PathDataBinIconNsarc[],Main_UnknownRoleZeroInitializedStorage_Variant6[],WindowFrame_LoadArchivePartsWithReusableAllocator_TextARC[];extern "C" void* AllocatorUnion_AllocateFourByteAligned(void*,unsigned);extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);extern "C" void _ZN13SafeAllocator5ResetEv(void*);extern "C" void _ZN16BackgroundLoader13AddLockGlobalEv();extern "C" void _ZN16BackgroundLoader16RemoveLockGlobalEv();extern "C" void* _Z18LoadFileIntoMemoryPKcPvPj(const char*,void*,unsigned*);extern "C" int _ZN10NarcHandle10InitializeEPKcPKh(void*,const char*,const void*);extern "C" void _ZN10NarcHandle7DestroyEv(void*);extern "C" void LoadEightNamedArchiveRenderParts(void*,void*,void*);
// Original: arm9/main @ 0x0202F24C; symbol: func_0202f24c; size: 0xC4.
extern "C" void WindowFrame_LoadArchivePartsWithReusableAllocator(char* p){unsigned size;char narc[104];if(!*(void**)(p+1092)){*(void**)(p+1092)=AllocatorUnion_AllocateFourByteAligned(Main_UnknownRoleZeroInitializedStorage_Variant3,20);_ZN13SafeAllocator21ResetAllocatorPointerEv(*(void**)(p+1092));void* memory=AllocatorUnion_AllocateFourByteAligned(Main_UnknownRoleZeroInitializedStorage_Variant3,3848);_ZN13SafeAllocator11CreateTypeAEPvj(*(void**)(p+1092),memory,3848);_ZN13SafeAllocator5ResetEv(*(void**)(p+1092));}else _ZN13SafeAllocator5ResetEv(*(void**)(p+1092));_ZN16BackgroundLoader13AddLockGlobalEv();void* file=_Z18LoadFileIntoMemoryPKcPvPj(WindowFrame_LoadArchivePartsWithReusableAllocator_PathDataBinIconNsarc,Main_UnknownRoleZeroInitializedStorage_Variant6,&size);if(file&&_ZN10NarcHandle10InitializeEPKcPKh(narc,WindowFrame_LoadArchivePartsWithReusableAllocator_TextARC,file)){LoadEightNamedArchiveRenderParts(p,*(void**)(p+1092),file);_ZN10NarcHandle7DestroyEv(narc);}_ZN16BackgroundLoader16RemoveLockGlobalEv();}
