#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" int sprintf(char*,const char*,...);
extern "C" char* strstr(const char*,const char*);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState20GetGameObjectByIndexEi(void*,int);
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" void _ZN16BackgroundLoader19GetLoadedFileByNameEPKcPPvPj(void*,const char*,void**,unsigned*);
extern "C" void _ZN8Object3D26LoadType0AnimationFromFileEiPKcP13SafeAllocator(void*,int,const char*,void*);
extern "C" void _ZN8Object3D34LoadType0AnimationFromFileInMemoryEiP13SafeAllocatorPKvj(void*,int,void*,const void*,unsigned);
extern "C" int Script_ResolveEventObjectIndex(int);
extern "C" int Script_ReadParameterAsInteger(void*);
extern "C" int Script_ReadParameterString(void*);
// Original data: arm9/ov001 @ 0x21658b8; symbol: data_ov001_021658b8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" void* EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage;
extern "C" char Script_LoadEventTextTable_PathDataS[],Script_LoadType0AnimationsForObjects_TextNsbca[],Script_LoadType0AnimationsForObjects_TextNsbma[],Script_LoadType0AnimationsForObjects_TextNsbtp[],Script_LoadType0AnimationsForObjects_TextNsbta[];
struct Param { char bytes[8]; };
// Original: arm9/ov001 @ 0x0215F060; symbol: func_ov001_0215f060; size: 0x150.
extern "C" int Script_LoadType0AnimationsForObjects(Param* params,int count) {
 int name=Script_ReadParameterString(params++);
 void* state=_ZN9GameState11GetInstanceEv();
 void* allocator=EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage;
 char path[32];
 sprintf(path,Script_LoadEventTextTable_PathDataS,name);
 int type=-1;
 if(strstr(path,Script_LoadType0AnimationsForObjects_TextNsbca)) type=0;
 else if(strstr(path,Script_LoadType0AnimationsForObjects_TextNsbma)) type=1;
 else if(strstr(path,Script_LoadType0AnimationsForObjects_TextNsbtp)) type=2;
 else if(strstr(path,Script_LoadType0AnimationsForObjects_TextNsbta)) type=3;
 if(type<0) return 0;
 void* file; unsigned size;
 _ZN16BackgroundLoader19GetLoadedFileByNameEPKcPPvPj(_ZN16BackgroundLoader11GetInstanceEv(),path,&file,&size);
 for(int i=1;i<count;i++) {
 int index=Script_ReadParameterAsInteger(params++);
 void* obj=_ZN9GameState20GetGameObjectByIndexEi(state,Script_ResolveEventObjectIndex(index));
 if(obj) {
 if(file) _ZN8Object3D34LoadType0AnimationFromFileInMemoryEiP13SafeAllocatorPKvj(obj,type,allocator,file,size);
 else _ZN8Object3D26LoadType0AnimationFromFileEiPKcP13SafeAllocator(obj,type,path,allocator);
 }
 }
 return 1;
}
