#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
struct Vector3i{int x,y,z;};
// Original data: arm9/ov003 @ 0x217fb8c; symbol: data_ov003_0217fb8c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0a0100000a0100000a010000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
struct LoadInfo{int kind;void* archive;unsigned size;void* allocator;int owned;int extra[3];};extern "C" {void* _ZN16BackgroundLoader11GetInstanceEv();void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*,int,void**,unsigned*);unsigned char* GameResources_GetInstance();void TextureVRAM_SnapshotAllocationBounds(char*);void Graphics_RestoreTextureImageAndPaletteVRAMState(void*);int _Z26FindFilesInNarcBySubstringPKvPKcPS0_Pjj(const void*,const char*,const void**,unsigned*,unsigned);void* _Z36DecompressLZ77FileIntoAllocatedSpaceR13SafeAllocatorPKvRj(void*,const void*,unsigned*);bool _ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(void*,LoadInfo*,void*);void Object_InvokeSaveTextureImageVRAMState(char*);void _ZN8Object3D8SetScaleEPK8Vector3i(void*,const Vector3i*);void _ZN8Object3D18SetAnimationByNameEPKci(void*,const char*,int);extern char Town_LoadPreviewModel_TextCchr[],Town_LoadPreviewModel_TextStand[];extern Vector3i TownLoadPreviewModel_UnknownRoleInitializedBytes;}
// Original: arm9/ov003 @0x0217c974; symbol:Graphics_LoadCompressedModelAndRestoreTextureState; size:0x110.
// Loads compressed model from background archive while saving/restoring texture VRAM state, then sets scale and animation.
extern "C" void Town_LoadPreviewModel(unsigned char* self){LoadInfo info;void* archive;unsigned archiveSize;unsigned fileSize;const void* file;unsigned unpackedSize;_ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(_ZN16BackgroundLoader11GetInstanceEv(),W(self,0x130),&archive,&archiveSize);unsigned char* resources=GameResources_GetInstance();TextureVRAM_SnapshotAllocationBounds((char*)resources+0x2cc);Graphics_RestoreTextureImageAndPaletteVRAMState(resources+0x2cc);if(!_Z26FindFilesInNarcBySubstringPKvPKcPS0_Pjj(archive,Town_LoadPreviewModel_TextCchr,&file,&fileSize,1))return;void* unpacked=_Z36DecompressLZ77FileIntoAllocatedSpaceR13SafeAllocatorPKvRj(self+4,file,&unpackedSize);if(!unpacked)return;info.kind=0;info.archive=unpacked;info.extra[0]=0;info.extra[1]=0;info.extra[2]=0;info.allocator=self+4;info.size=unpackedSize;info.owned=1;_ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(self+0x80,&info,0);Object_InvokeSaveTextureImageVRAMState((char*)resources+0x2cc);Vector3i scale=TownLoadPreviewModel_UnknownRoleInitializedBytes;W(self,0xc4)=0;W(self,0xc8)=0xfae;W(self,0xcc)=0;_ZN8Object3D8SetScaleEPK8Vector3i(self+0x80,&scale);_ZN8Object3D18SetAnimationByNameEPKci(self+0x80,Town_LoadPreviewModel_TextStand,0);}
