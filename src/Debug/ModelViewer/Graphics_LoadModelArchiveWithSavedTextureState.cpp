#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original data: arm9/ov015 @ 0x2193cfc; symbol: data_ov015_02193cfc.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0a0100000a0100000a010000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov015.md.
// Original data: arm9/main @ 0x211e33c; symbol: data_0211e33c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 7889 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
namespace BCFG{struct AnimationRecord;}struct ObjectArchiveLoadInfo;extern "C" char Graphics_LoadModelArchiveWithSavedTextureState_PathDataCharaSubSChr[],Main_UnknownRoleZeroInitializedStorage_Variant6[],GraphicsLoadModelArchiveWithSavedTextureState_UnknownRoleInitializedBytes[];extern "C" void __clear(void*,unsigned),_ZN13SafeAllocator5ResetEv(void*),TextureVRAM_SnapshotAllocationBounds(char*),Graphics_RestoreTextureImageAndPaletteVRAMState(void*),Object_InvokeSaveTextureImageVRAMState(char*);extern "C" int sprintf(char*,const char*,...);extern "C" void _ZN16BackgroundLoader13AddLockGlobalEv(),_ZN16BackgroundLoader16RemoveLockGlobalEv();extern "C" void* _Z18LoadFileIntoMemoryPKcPvPj(const char*,void*,unsigned*);extern "C" void Object3D_ResetArchiveLoadInfo(unsigned*);extern "C" bool _ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(void*,ObjectArchiveLoadInfo*,int(*)(BCFG::AnimationRecord*));extern "C" void _ZN8Object3D8SetScaleEPK8Vector3i(void*,const void*);extern "C" bool _ZN8Object3D23SetBCFGAnimationByIndexEii(void*,int,int);
// Original: arm9/ov015 @ 0x0218df0c; symbol: Graphics_LoadModelArchiveWithSavedTextureState; size 0x120.
extern "C" int Graphics_LoadModelArchiveWithSavedTextureState(char* self,void* record){if(!W(record,4))return 0;char path[32];unsigned info[8];struct Vector{int x,y,z;};unsigned size;__clear(path,32);_ZN13SafeAllocator5ResetEv(P(self,8));int success=1;char* saved=P(P(self,4),0);TextureVRAM_SnapshotAllocationBounds(saved);Graphics_RestoreTextureImageAndPaletteVRAMState(saved);sprintf(path,Graphics_LoadModelArchiveWithSavedTextureState_PathDataCharaSubSChr,W(record,4));_ZN16BackgroundLoader13AddLockGlobalEv();size=0;if(!_Z18LoadFileIntoMemoryPKcPvPj(path,Main_UnknownRoleZeroInitializedStorage_Variant6,&size))success=0;else{Object3D_ResetArchiveLoadInfo(info);unsigned allocator=(unsigned)P(self,8);unsigned length=size;unsigned buffer=(unsigned)Main_UnknownRoleZeroInitializedStorage_Variant6;int flag=success;info[1]=buffer;info[2]=length;info[3]=allocator;info[4]=flag;_ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(P(self,0x24),(ObjectArchiveLoadInfo*)info,0);Vector scale=*(Vector*)GraphicsLoadModelArchiveWithSavedTextureState_UnknownRoleInitializedBytes;_ZN8Object3D8SetScaleEPK8Vector3i(P(self,0x24),&scale);_ZN8Object3D23SetBCFGAnimationByIndexEii(P(self,0x24),0,W(self,0x44));}_ZN16BackgroundLoader16RemoveLockGlobalEv();Object_InvokeSaveTextureImageVRAMState(saved);if(!success)return 0;W(self,12)=W(record,0);return 1;}
