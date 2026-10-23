#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
#include <Filesystem/BackgroundLoader.h>
#include <Filesystem/NarcHandle.h>
#include <Filesystem/FileIO.h>
#include <World/Object3D.h>
ARM
extern "C" {
void* TextContext_GetSharedInstance();
void TextWindow_LoadFrameArchiveParts(void*,SafeAllocator*,const void*);
void TextureVRAM_SnapshotAllocationBounds(void*);
void Graphics_RestoreTextureImageAndPaletteVRAMState(void*);
void Object_InvokeSaveTextureImageVRAMState(void*);
int sprintf(char*,const char*,...);
void* memcpy(void*,const void*,unsigned);
// Original data: arm9/ov017 @ 0x021D7504, 0x021D7510, 0x021D751B,
// 0x021D7577, 0x021D7584, 0x021D758D and 0x021D75A2: file and archive member names.
extern const char Field_LoadChestPickupAndInteractionVisuals_PathDataBinS[];
extern const char Field_LoadChestPickupAndInteractionVisuals_TextIconNsarc[];
extern const char Field_LoadChestPickupAndInteractionVisuals_TextARC[];
extern const char Field_LoadWindowCoffinShadowAndAnimationResources_TextKanokeNsbmd[];
extern const char Field_LoadWindowCoffinShadowAndAnimationResources_TextKageChr[];
extern const char Field_LoadWindowCoffinShadowAndAnimationResources_PathDataAniObjDefPac[];
extern const char Field_LoadWindowCoffinShadowAndAnimationResources_PathDataAniBgDefBncl[];
}
#pragma force_active on
// Original: arm9/ov017 @ 0x0219BA0C; symbol: func_ov017_0219ba0c; size: 0x244.
// Loads window frames, coffin and shadow models, and object/background animation resources under the loader lock.
extern "C" void Field_LoadWindowCoffinShadowAndAnimationResources(char* self,int framesOnly) {
    void* text=TextContext_GetSharedInstance();
    BackgroundLoader::GetInstance();
    SafeAllocator* allocator=(SafeAllocator*)(self+0xb0);
    void* texture=self+0x56c;
    BackgroundLoader::AddLockGlobal();
    allocator->Reset();
    TextureVRAM_SnapshotAllocationBounds(texture);
    Graphics_RestoreTextureImageAndPaletteVRAMState(texture);
    char filename[80];
    sprintf(filename,Field_LoadChestPickupAndInteractionVisuals_PathDataBinS,Field_LoadChestPickupAndInteractionVisuals_TextIconNsarc);
    const void* file;unsigned length;
    unsigned archiveLength;
    if(!LoadFileIntoMemory(filename,Main_UnknownRoleZeroInitializedStorage_Variant6,&archiveLength)) {BackgroundLoader::RemoveLockGlobal();return;}
    NarcHandle archive;
    if(!archive.Initialize(Field_LoadChestPickupAndInteractionVisuals_TextARC,Main_UnknownRoleZeroInitializedStorage_Variant6)) {BackgroundLoader::RemoveLockGlobal();return;}
    TextWindow_LoadFrameArchiveParts(text,allocator,Main_UnknownRoleZeroInitializedStorage_Variant6);
    if(framesOnly) {archive.Destroy();Object_InvokeSaveTextureImageVRAMState(texture);BackgroundLoader::RemoveLockGlobal();return;}
    archive.Destroy();
    (*(Model3D**)(self+0x36c8))->Clear();
    if(GetFileInNarc(Main_UnknownRoleZeroInitializedStorage_Variant6,Field_LoadWindowCoffinShadowAndAnimationResources_TextKanokeNsbmd,&file,&length,0))
        (*(Model3D**)(self+0x36c8))->CopyAndProcessRawFile(&allocator->allocUnion,file,length,(Model3D::TextureStagingMode)0);
    (*(Object3D**)(self+0x36cc))->Initialize();
    if(GetFileInNarc(Main_UnknownRoleZeroInitializedStorage_Variant6,Field_LoadWindowCoffinShadowAndAnimationResources_TextKageChr,&file,&length,0)) {
        ObjectArchiveLoadInfo info;
        info.fileData=file;info.unk_8=length;info.allocator=allocator;info.unk_10=1;
        (*(Object3D**)(self+0x36cc))->LoadFromCHRArchive(&info);
    }
    Object_InvokeSaveTextureImageVRAMState(texture);
    unsigned size;
    if(!LoadFileIntoMemory(Field_LoadWindowCoffinShadowAndAnimationResources_PathDataAniObjDefPac,Main_UnknownRoleZeroInitializedStorage_Variant6,&size)) {BackgroundLoader::RemoveLockGlobal();return;}
    void* objectAnimations=allocator->Allocate(size);
    if(!objectAnimations) {BackgroundLoader::RemoveLockGlobal();return;}
    memcpy(objectAnimations,Main_UnknownRoleZeroInitializedStorage_Variant6,size);
    *(void**)(self+0x30)=objectAnimations;*(unsigned*)(self+0x34)=size;
    if(!LoadFileIntoMemory(Field_LoadWindowCoffinShadowAndAnimationResources_PathDataAniBgDefBncl,Main_UnknownRoleZeroInitializedStorage_Variant6,&size)) {BackgroundLoader::RemoveLockGlobal();return;}
    void* backgroundAnimations=allocator->Allocate(size);
    if(!backgroundAnimations) {BackgroundLoader::RemoveLockGlobal();return;}
    memcpy(backgroundAnimations,Main_UnknownRoleZeroInitializedStorage_Variant6,size);
    *(void**)(self+0x2c)=backgroundAnimations;
    BackgroundLoader::RemoveLockGlobal();
}
#pragma force_active off
