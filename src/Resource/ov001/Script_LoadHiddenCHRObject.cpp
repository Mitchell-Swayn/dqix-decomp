#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" int ReadScriptParameterAsInteger(void*);
extern "C" int ConvertNegativeIndexToBiasedMagnitude(int);
extern "C" int sprintf(char*,const char*,...);
extern "C" void _ZN16BackgroundLoader19GetLoadedFileByNameEPKcPPvPj(void*,const char*,void**,unsigned*);
extern "C" void _ZN16BackgroundLoader13AddLockGlobalEv();
extern "C" void _ZN16BackgroundLoader16RemoveLockGlobalEv();
extern "C" unsigned LoadFileToGlobalScratchAndReturnLength(const char*,void**);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" void _ZN8Object3D10InitializeEv(void*);
extern "C" void _ZN8Object3D18LoadFromCHRArchiveEP21ObjectArchiveLoadInfo(void*,void*);
extern "C" void NSBXX_Model_SetPolygonID(void*,unsigned);
extern "C" bool _ZN8Object3D21MaybeSetBCFGAnimationEii(void*,int,int);
extern "C" void _ZN8Object3D10MakeHiddenEv(void*);
extern "C" void GameState_SetIndexedObjectAndSlot(void*,int,void*);
extern "C" unsigned data_ov001_021658b8[];
extern "C" char data_ov001_02165775[];
struct LoadInfo { unsigned unknown; void* file; unsigned len; unsigned allocator; int flag; unsigned more[3]; };
// Original: arm9/ov001 @ 0x0215CE4C; symbol: func_ov001_0215ce4c; size: 0x14C.
extern "C" int Script_LoadHiddenCHRObject(char* params,int count) {
 void* gs; unsigned alloc; int lock; char* object; int index; void* loader;
 gs=_ZN9GameState11GetInstanceEv();
 loader=_ZN16BackgroundLoader11GetInstanceEv();
 index=ConvertNegativeIndexToBiasedMagnitude(ReadScriptParameterAsInteger(params));
 int a=0;
 if(count>=2) a=ReadScriptParameterAsInteger(params+8);
 alloc=data_ov001_021658b8[a];
 char path[80];
 sprintf(path,data_ov001_02165775);
 void* file; unsigned len;
 lock=0;
 _ZN16BackgroundLoader19GetLoadedFileByNameEPKcPPvPj(loader,path,&file,&len);
 if(!file) {
  _ZN16BackgroundLoader13AddLockGlobalEv();
  lock=1;
  if(!LoadFileToGlobalScratchAndReturnLength(path,&file)) {
   _ZN16BackgroundLoader16RemoveLockGlobalEv(); return 0;
  }
 }
 object=_ZN13SafeAllocator8AllocateEj(alloc,0xac);
 _ZN8Object3D10InitializeEv(object);
 LoadInfo info;
 info.allocator=alloc;info.file=file;info.len=len;info.flag=1;
 _ZN8Object3D18LoadFromCHRArchiveEP21ObjectArchiveLoadInfo(object,&info);
 if(lock) _ZN16BackgroundLoader16RemoveLockGlobalEv();
 NSBXX_Model_SetPolygonID(*(void**)(*(char**)(object+8)+0x54),0x3d);
 *(int*)(object+0x44)=0;
 *(int*)(object+0x48)=-0xa000;
 *(int*)(object+0x4c)=0x1000;
 _ZN8Object3D21MaybeSetBCFGAnimationEii(object,0,0);
 _ZN8Object3D10MakeHiddenEv(object);
 GameState_SetIndexedObjectAndSlot(gs,index,object);
 return 1;
}
