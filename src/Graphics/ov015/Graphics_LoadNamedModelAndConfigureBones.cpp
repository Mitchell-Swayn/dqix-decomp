#include <globaldefs.h>
ARM
extern "C" int sprintf(char*,const char*,...);
extern "C" void __clear(void*,unsigned);
extern "C" void _ZN13SafeAllocator5ResetEv(void*);
extern "C" void SnapshotBlockAndVolatileWordPair(char*);
extern "C" void Graphics_RestoreTextureImageAndPaletteVRAMState(void*);
extern "C" void _ZN16BackgroundLoader13AddLockGlobalEv();
extern "C" void _ZN16BackgroundLoader16RemoveLockGlobalEv();
extern "C" void* _Z18LoadFileIntoMemoryPKcPvPj(const char*,void*,unsigned*);
extern "C" void ClearEightBytes(unsigned*);
extern "C" void _ZN8Object3D18LoadFromCHRArchiveEP21ObjectArchiveLoadInfo(void*,void*);
extern "C" int _ZN7Model3D12GetBoneIndexEPKc(void*,const char*);
extern "C" void* _Z17GetModel3DContextP7Model3D(void*);
extern "C" void Graphics_CaptureSelectedPositionMatrices(void*);
extern "C" void _Z38SetModelRenderContextRenderCommandHookP18ModelRenderContextPFvP20RenderCommandHandlerEiii(void*,void(*)(void*),int,int,int);
extern "C" void _ZN8Object3D8SetScaleEPK8Vector3i(void*,const void*);
extern "C" bool _ZN8Object3D21MaybeSetBCFGAnimationEii(void*,int,int);
extern "C" void Object_InvokeSaveTextureImageVRAMState(char*);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_FindOffset3B0ObjectWithFlag2(void*);
extern "C" void Object_SetStateTwoAndClearWord218(int);
extern "C" void WriteWordAtOffset218(int,int);
extern "C" char data_ov015_02194078[],data_ov015_02194052[],data_0211e33c[],data_ov015_0219415c[],data_ov015_02194160[],data_ov015_02194167[];
extern "C" unsigned char data_ov015_02193fe0[];
struct Vector {int x,y,z;};
extern "C" Vector data_ov015_02193d20;
struct LoadInfo {int first;const void* data;int size;void* allocator;int flags,unknown[3];};
struct Entry {unsigned id;const char* name;};
// Original: arm9/ov015 @ 0x0218E2A4; symbol: func_ov015_0218e2a4; size: 0x1F4.
extern "C" int Graphics_LoadNamedModelAndConfigureBones(unsigned char* self,const Entry* entry) {
 if(!entry->name) return 0;
 char path[32]={0};
 _ZN13SafeAllocator5ResetEv(*(void**)(self+8));
 int success=1;
 char* snapshot=**(char***)(self+4);
 SnapshotBlockAndVolatileWordPair(snapshot);
 Graphics_RestoreTextureImageAndPaletteVRAMState(snapshot);
 if(self[0x1c]==5) sprintf(path,data_ov015_02194078,entry->name);
 else sprintf(path,data_ov015_02194052,entry->name);
 _ZN16BackgroundLoader13AddLockGlobalEv();
 unsigned size=0;
 if(!_Z18LoadFileIntoMemoryPKcPvPj(path,data_0211e33c,&size)) success=0;
 else {
  LoadInfo info;
  ClearEightBytes((unsigned*)&info);
  void* allocator=*(void**)(self+8);
  info.allocator=allocator;
  info.data=data_0211e33c;
  info.size=size;
  info.flags=1;
  _ZN8Object3D18LoadFromCHRArchiveEP21ObjectArchiveLoadInfo(*(void**)(self+0x24),&info);
  void* model=*(void**)(*(unsigned char**)(self+0x24)+8);
  data_ov015_02193fe0[1]=_ZN7Model3D12GetBoneIndexEPKc(model,data_ov015_0219415c);
  data_ov015_02193fe0[2]=_ZN7Model3D12GetBoneIndexEPKc(model,data_ov015_02194160);
  data_ov015_02193fe0[0]=_ZN7Model3D12GetBoneIndexEPKc(model,data_ov015_02194167);
  void* context=_Z17GetModel3DContextP7Model3D(model);
  _Z38SetModelRenderContextRenderCommandHookP18ModelRenderContextPFvP20RenderCommandHandlerEiii(context,Graphics_CaptureSelectedPositionMatrices,0,6,3);
  *(unsigned*)context|=4;
  Vector scale=data_ov015_02193d20;
  _ZN8Object3D8SetScaleEPK8Vector3i(*(void**)(self+0x24),&scale);
  _ZN8Object3D21MaybeSetBCFGAnimationEii(*(void**)(self+0x24),0,*(int*)(self+0x44));
 }
 _ZN16BackgroundLoader16RemoveLockGlobalEv();
 Object_InvokeSaveTextureImageVRAMState(snapshot);
 if(!success) return 0;
 void* game=_ZN9GameState11GetInstanceEv();
 if(!game) return 0;
 void* object=GameState_FindOffset3B0ObjectWithFlag2(game);
 if(!object) return 0;
 Object_SetStateTwoAndClearWord218((int)object);
 WriteWordAtOffset218((int)object,0);
 *(unsigned*)(self+0xc)=entry->id;
 return 1;
}
