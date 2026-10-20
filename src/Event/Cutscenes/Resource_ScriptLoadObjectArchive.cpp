#include <globaldefs.h>
ARM
#pragma opt_common_subs off
struct IntegerParameterView;
struct ObjectArchiveLoadInfo { int unknown; const void* fileData; unsigned length; unsigned allocator; int flag,a,b,packageID; };
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState20GetGameObjectByIndexEi(void*,int);
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" void _ZN16BackgroundLoader13AddLockGlobalEv();
extern "C" void _ZN16BackgroundLoader16RemoveLockGlobalEv();
extern "C" int _ZN16BackgroundLoader19GetLoadedFileByNameEPKcPPvPj(void*,const char*,void**,unsigned*);
extern "C" void _ZN8Object3D18LoadFromCHRArchiveEP21ObjectArchiveLoadInfo(void*,ObjectArchiveLoadInfo*);
extern "C" void _ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(void*,ObjectArchiveLoadInfo*,void*);
extern "C" bool _ZN8Object3D23SetBCFGAnimationByIndexEii(void*,int,int);
extern "C" unsigned Event_LoadFileIntoSharedScratch(const char*,void**);
extern "C" int Script_ResolveEventObjectIndex(int);
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView*);
extern "C" unsigned Script_ReadParameterString(void*);
extern "C" int sprintf(char*,const char*,...);
// Original data: arm9/ov001 @ 0x21658b8; symbol: data_ov001_021658b8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage[];
extern "C" char Script_LoadEventTextTable_PathDataS[];
// Original: arm9/ov001 @ 0x0215BB3C; symbol: func_ov001_0215bb3c; size: 0x184.
extern "C" int Resource_ScriptLoadObjectArchive(char* args,int count) {
 char path[80]; ObjectArchiveLoadInfo info; void* file; unsigned length;
 void* state=_ZN9GameState11GetInstanceEv();
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 unsigned allocator; int package; int id; int index;
 id=Script_ReadParameterString(args);
 IntegerParameterView* indexParam=(IntegerParameterView*)(args+8);
 args+=16;
 index=Script_ResolveEventObjectIndex(Script_ReadParameterAsInteger(indexParam));
 int allocatorIndex=0;
 if(count>=3) { allocatorIndex=Script_ReadParameterAsInteger((IntegerParameterView*)args); args+=8; }
 allocator=EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage[allocatorIndex];
 package=3;
 if(count>=4) package=Script_ReadParameterAsInteger((IntegerParameterView*)args);
 char* object=(char*)_ZN9GameState20GetGameObjectByIndexEi(state,index);
 if(!object) return 0;
 sprintf(path,Script_LoadEventTextTable_PathDataS,id);
 int locked=0;
 _ZN16BackgroundLoader19GetLoadedFileByNameEPKcPPvPj(loader,path,&file,&length);
 if(!file) {
  _ZN16BackgroundLoader13AddLockGlobalEv(); locked=1;
  if(!Event_LoadFileIntoSharedScratch(path,&file)) { _ZN16BackgroundLoader16RemoveLockGlobalEv(); return 0; }
 }
 struct Flags { unsigned mode:1; };
 unsigned mode=0;
 if(*(Flags**)(object+0xc)) mode=(*(Flags**)(object+0xc))->mode;
 info.allocator=allocator; info.fileData=file; info.length=length; info.flag=1; info.packageID=package;
 if(mode==0) _ZN8Object3D18LoadFromCHRArchiveEP21ObjectArchiveLoadInfo(object,&info);
 else if(mode==1) _ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(object,&info,0);
 if(locked) _ZN16BackgroundLoader16RemoveLockGlobalEv();
 _ZN8Object3D23SetBCFGAnimationByIndexEii(object,0,0);
 return 1;
}
