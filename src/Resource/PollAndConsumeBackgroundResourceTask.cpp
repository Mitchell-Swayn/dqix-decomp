#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
ARM
extern "C" {
void TextureVRAM_SnapshotAllocationBounds(void *);void Graphics_RestoreTextureImageAndPaletteVRAMState(void *);void Object_InvokeSaveTextureImageVRAMState(void *);
void NSBXX_Model_SetPolygonID(NSBXXInternalModel *,int);void Object3D_SetPositionComponents(Object3D *,int,int,int);
// Original: arm9/main @ 0x02046CC8; symbol: func_02046cc8; size: 0x140.
int PollAndConsumeBackgroundResourceTask(unsigned char *p) {
    if(*(void **)(p+0xe8))return 1;if(*(int *)(p+0xec)<0)return 0;
    unsigned char *cache;BackgroundLoader *loader;SafeAllocator *allocator;unsigned char *owner;
    GameState::GetInstance();owner=(unsigned char *)GameResources_GetInstance();
    allocator=*(SafeAllocator **)(p+0x38);if(!allocator)allocator=(SafeAllocator *)(p+0x24);
    loader=BackgroundLoader::GetInstance();
    int status=loader->GetTaskStatus(*(int *)(p+0xec));
    if(status){
    cache=owner+0x2cc;
    if(p[0x1d]) {
        TextureVRAM_SnapshotAllocationBounds(cache+0xc40);Graphics_RestoreTextureImageAndPaletteVRAMState(cache+0xc40);
        void *volatile file;volatile unsigned length;loader->GetLoadedFileByID(*(int *)(p+0xec),(void **)&file,(unsigned *)&length);
        if(file&&allocator->GetSignedAllocator()) {
            Object3D *object=(Object3D *)(p+0x3c);object->Initialize();ObjectArchiveLoadInfo info;
            void *loaded=file;unsigned loadedLength=length;info.unk_10=1;info.fileData=loaded;info.unk_8=loadedLength;info.allocator=allocator;
            object->LoadFromCHRArchive(&info);NSBXX_Model_SetPolygonID(object->pModel_->rawInternalModel_,61);
            Object3D_SetPositionComponents(object,0,-0xa000,0x1000);object->SetBCFGAnimationByIndex(0,0);
        }
        Object_InvokeSaveTextureImageVRAMState(cache+0xc40);
    }
    loader->RemoveTask(*(int *)(p+0xec));*(int *)(p+0xec)=-1;return 1;
    }
    return 0;
}
}
