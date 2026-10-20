#include <globaldefs.h>
ARM
// Original data: arm9/ov001 @ 0x21658b8; symbol: data_ov001_021658b8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" { unsigned Script_ReadParameterString(void*); void* _ZN9GameState11GetInstanceEv(); void* _ZN9GameState20GetGameObjectByIndexEi(void*,int); int sprintf(char*,const char*,...); int Script_ReadParameterAsInteger(void*); int Script_ResolveEventObjectIndex(int); void* _ZN16BackgroundLoader11GetInstanceEv(); void _ZN16BackgroundLoader19GetLoadedFileByNameEPKcPPvPj(void*,const char*,void**,unsigned*); void _ZN8Object3D39LoadType0AnimationPackageFromBCFGScriptEP13SafeAllocatorPKvj(void*,void*,const void*,unsigned); void _ZN8Object3D39LoadType0AnimationPackageFromBCFGScriptEPKcP13SafeAllocator(void*,const char*,void*); extern char Script_LoadEventTextTable_PathDataS[]; extern void* EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage; }
// Original: arm9/ov001 @ 0x0215F344; symbol: func_ov001_0215f344; size: 0xB8.
extern "C" int Graphics_LoadScriptSelectedTypeZeroAnimationPackage(unsigned char* parameters) {
 unsigned name=Script_ReadParameterString(parameters);
 void* state=_ZN9GameState11GetInstanceEv();
 if(!state) return 0;
 char path[32];
 sprintf(path,Script_LoadEventTextTable_PathDataS,name);
 int index=Script_ResolveEventObjectIndex(Script_ReadParameterAsInteger(parameters+8));
 void* object=_ZN9GameState20GetGameObjectByIndexEi(state,index);
 if(!object) return 0;
 void* allocator=EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage;
 void* code;
 unsigned size;
 _ZN16BackgroundLoader19GetLoadedFileByNameEPKcPPvPj(_ZN16BackgroundLoader11GetInstanceEv(),path,&code,&size);
 if(code) _ZN8Object3D39LoadType0AnimationPackageFromBCFGScriptEP13SafeAllocatorPKvj(object,allocator,code,size);
 else _ZN8Object3D39LoadType0AnimationPackageFromBCFGScriptEPKcP13SafeAllocator(object,path,allocator);
 return 1;
}
