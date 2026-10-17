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
extern "C" bool _ZN8Object3D21MaybeSetBCFGAnimationEii(void*,int,int);
extern "C" unsigned LoadFileToGlobalScratchAndReturnLength(const char*,void**);
extern "C" int ConvertNegativeIndexToBiasedMagnitude(int);
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView*);
extern "C" unsigned OV017_ReadWordField04(void*);
extern "C" int sprintf(char*,const char*,...);
extern "C" unsigned data_ov001_021658b8[];
extern "C" char data_ov001_02165745[];
// Original: arm9/ov001 @ 0x0215BB3C; symbol: func_ov001_0215bb3c; size: 0x184.
extern "C" int Resource_ScriptLoadObjectArchive(char* args,int count) {
 char path[80]; ObjectArchiveLoadInfo info; void* file; unsigned length;
 void* state=_ZN9GameState11GetInstanceEv();
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 unsigned allocator; int package; int id; int index;
 id=OV017_ReadWordField04(args);
 IntegerParameterView* indexParam=(IntegerParameterView*)(args+8);
 args+=16;
 index=ConvertNegativeIndexToBiasedMagnitude(ReadScriptParameterAsInteger(indexParam));
 int allocatorIndex=0;
 if(count>=3) { allocatorIndex=ReadScriptParameterAsInteger((IntegerParameterView*)args); args+=8; }
 allocator=data_ov001_021658b8[allocatorIndex];
 package=3;
 if(count>=4) package=ReadScriptParameterAsInteger((IntegerParameterView*)args);
 char* object=(char*)_ZN9GameState20GetGameObjectByIndexEi(state,index);
 if(!object) return 0;
 sprintf(path,data_ov001_02165745,id);
 int locked=0;
 _ZN16BackgroundLoader19GetLoadedFileByNameEPKcPPvPj(loader,path,&file,&length);
 if(!file) {
  _ZN16BackgroundLoader13AddLockGlobalEv(); locked=1;
  if(!LoadFileToGlobalScratchAndReturnLength(path,&file)) { _ZN16BackgroundLoader16RemoveLockGlobalEv(); return 0; }
 }
 struct Flags { unsigned mode:1; };
 unsigned mode=0;
 if(*(Flags**)(object+0xc)) mode=(*(Flags**)(object+0xc))->mode;
 info.allocator=allocator; info.fileData=file; info.length=length; info.flag=1; info.packageID=package;
 if(mode==0) _ZN8Object3D18LoadFromCHRArchiveEP21ObjectArchiveLoadInfo(object,&info);
 else if(mode==1) _ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(object,&info,0);
 if(locked) _ZN16BackgroundLoader16RemoveLockGlobalEv();
 _ZN8Object3D21MaybeSetBCFGAnimationEii(object,0,0);
 return 1;
}
