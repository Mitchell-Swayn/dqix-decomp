#include <globaldefs.h>
ARM
extern "C" int sprintf(char*,const char*,...);
extern "C" void __clear(void*,unsigned);
extern "C" void _ZN13SafeAllocator5ResetEv(void*);
extern "C" void TextureVRAM_SnapshotAllocationBounds(char*);
extern "C" void Graphics_RestoreTextureImageAndPaletteVRAMState(void*);
extern "C" void _ZN16BackgroundLoader13AddLockGlobalEv();
extern "C" void _ZN16BackgroundLoader16RemoveLockGlobalEv();
extern "C" void* _Z18LoadFileIntoMemoryPKcPvPj(const char*,void*,unsigned*);
extern "C" void Object3D_ResetArchiveLoadInfo(unsigned*);
extern "C" void _ZN8Object3D18LoadFromCHRArchiveEP21ObjectArchiveLoadInfo(void*,void*);
extern "C" int _ZN7Model3D12GetBoneIndexEPKc(void*,const char*);
extern "C" void* _Z17GetModel3DContextP7Model3D(void*);
extern "C" void Graphics_CaptureSelectedPositionMatrices(void*);
extern "C" void _Z38SetModelRenderContextRenderCommandHookP18ModelRenderContextPFvP20RenderCommandHandlerEiii(void*,void(*)(void*),int,int,int);
extern "C" void _ZN8Object3D8SetScaleEPK8Vector3i(void*,const void*);
extern "C" bool _ZN8Object3D23SetBCFGAnimationByIndexEii(void*,int,int);
extern "C" void Object_InvokeSaveTextureImageVRAMState(char*);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetManualControlCamera(void*);
extern "C" void Camera_InitializeManualControlState(int);
extern "C" void Camera_SetManualControlMode(int,int);
// Original data: arm9/main @ 0x211e33c; symbol: data_0211e33c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 7889 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Graphics_LoadAnimationArchiveById_PathDataEventLv5SChr[],Graphics_LoadNamedModelAndConfigureBones_PathDataCharaSChr[],Main_UnknownRoleZeroInitializedStorage_Variant6[],Graphics_LoadNamedModelAndConfigureBones_TextEye[],Graphics_LoadNamedModelAndConfigureBones_TextLookat[],Graphics_LoadNamedModelAndConfigureBones_TextPos[];
// Original data: arm9/ov015 @ 0x2193fe0; symbol: data_ov015_02193fe0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffffff00.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov015.md.
extern "C" unsigned char GraphicsCaptureSelectedPositionMatrices_UnknownRoleInitializedBytes[];
struct Vector {int x,y,z;};
// Original data: arm9/ov015 @ 0x2193d20; symbol: data_ov015_02193d20.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0a0100000a0100000a010000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov015.md.
extern "C" Vector GraphicsLoadNamedModelAndConfigureBones_UnknownRoleInitializedBytes;
struct LoadInfo {int first;const void* data;int size;void* allocator;int flags,unknown[3];};
struct Entry {unsigned id;const char* name;};
// Original: arm9/ov015 @ 0x0218E2A4; symbol: func_ov015_0218e2a4; size: 0x1F4.
extern "C" int Graphics_LoadNamedModelAndConfigureBones(unsigned char* self,const Entry* entry) {
 if(!entry->name) return 0;
 char path[32]={0};
 _ZN13SafeAllocator5ResetEv(*(void**)(self+8));
 int success=1;
 char* snapshot=**(char***)(self+4);
 TextureVRAM_SnapshotAllocationBounds(snapshot);
 Graphics_RestoreTextureImageAndPaletteVRAMState(snapshot);
 if(self[0x1c]==5) sprintf(path,Graphics_LoadAnimationArchiveById_PathDataEventLv5SChr,entry->name);
 else sprintf(path,Graphics_LoadNamedModelAndConfigureBones_PathDataCharaSChr,entry->name);
 _ZN16BackgroundLoader13AddLockGlobalEv();
 unsigned size=0;
 if(!_Z18LoadFileIntoMemoryPKcPvPj(path,Main_UnknownRoleZeroInitializedStorage_Variant6,&size)) success=0;
 else {
  LoadInfo info;
  Object3D_ResetArchiveLoadInfo((unsigned*)&info);
  void* allocator=*(void**)(self+8);
  info.allocator=allocator;
  info.data=Main_UnknownRoleZeroInitializedStorage_Variant6;
  info.size=size;
  info.flags=1;
  _ZN8Object3D18LoadFromCHRArchiveEP21ObjectArchiveLoadInfo(*(void**)(self+0x24),&info);
  void* model=*(void**)(*(unsigned char**)(self+0x24)+8);
  GraphicsCaptureSelectedPositionMatrices_UnknownRoleInitializedBytes[1]=_ZN7Model3D12GetBoneIndexEPKc(model,Graphics_LoadNamedModelAndConfigureBones_TextEye);
  GraphicsCaptureSelectedPositionMatrices_UnknownRoleInitializedBytes[2]=_ZN7Model3D12GetBoneIndexEPKc(model,Graphics_LoadNamedModelAndConfigureBones_TextLookat);
  GraphicsCaptureSelectedPositionMatrices_UnknownRoleInitializedBytes[0]=_ZN7Model3D12GetBoneIndexEPKc(model,Graphics_LoadNamedModelAndConfigureBones_TextPos);
  void* context=_Z17GetModel3DContextP7Model3D(model);
  _Z38SetModelRenderContextRenderCommandHookP18ModelRenderContextPFvP20RenderCommandHandlerEiii(context,Graphics_CaptureSelectedPositionMatrices,0,6,3);
  *(unsigned*)context|=4;
  Vector scale=GraphicsLoadNamedModelAndConfigureBones_UnknownRoleInitializedBytes;
  _ZN8Object3D8SetScaleEPK8Vector3i(*(void**)(self+0x24),&scale);
  _ZN8Object3D23SetBCFGAnimationByIndexEii(*(void**)(self+0x24),0,*(int*)(self+0x44));
 }
 _ZN16BackgroundLoader16RemoveLockGlobalEv();
 Object_InvokeSaveTextureImageVRAMState(snapshot);
 if(!success) return 0;
 void* game=_ZN9GameState11GetInstanceEv();
 if(!game) return 0;
 void* object=GameState_GetManualControlCamera(game);
 if(!object) return 0;
 Camera_InitializeManualControlState((int)object);
 Camera_SetManualControlMode((int)object,0);
 *(unsigned*)(self+0xc)=entry->id;
 return 1;
}
