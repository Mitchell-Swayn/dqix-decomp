#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
struct AssetHeader { char unknown[0x3c]; void* data; void* records; char unknown44[8]; unsigned short count; char unknown4e[2]; unsigned char flag; };
struct LoadingOwner { char unknown[0x2d0]; int task; SafeAllocator* allocator; AssetHeader* asset; char* records; void* data; unsigned short count; unsigned char unknown2e6, phase; };
extern "C" char BackgroundLoader_AdvanceThreePhaseArchiveAssetLoad_PathDataAniObjTmGp2[], BackgroundLoader_AdvanceThreePhaseArchiveAssetLoad_MarkupObjTmLGPac[];
extern "C" void Graphics_InitializeSpriteResourceBuffers(AssetHeader*);
extern "C" void Graphics_InitializeSpriteTransformDefaults(void*);
extern "C" void SpriteAnimation_ResetTrackList(void*);
extern "C" int ResourceFile_CountActiveStrideRecords(void*);
extern "C" void* ResourceFile_GetPayloadByIndex(void*,int,unsigned*,unsigned*);
extern "C" void Graphics_DispatchDataByResourceMagic(AssetHeader*,void*,unsigned,SafeAllocator*);
// Original: arm9/main @ 0x02043368; symbol: func_02043368; size: 0x234.
extern "C" void BackgroundLoader_AdvanceThreePhaseArchiveAssetLoad(LoadingOwner* owner)
{
    struct Locals { unsigned count, size; void* file; unsigned kind; } local;
    if (!owner->allocator) return;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (owner->phase == 0) {
        if (!owner->asset) {
            unsigned char* grotto = (unsigned char*)GameState::GetInstance()->GetGrottoStruct();
            if (!grotto || !grotto[0] || grotto[2]) {
                owner->task = loader->QueueLoadFileInGP2(BackgroundLoader_AdvanceThreePhaseArchiveAssetLoad_PathDataAniObjTmGp2, BackgroundLoader_AdvanceThreePhaseArchiveAssetLoad_MarkupObjTmLGPac, 0);
                ++owner->phase;
            }
        }
    } else if (owner->phase == 1) {
        if (loader->GetTaskStatus(owner->task)) {
            owner->allocator->Reset();
            owner->asset = (AssetHeader*)owner->allocator->Allocate(0x54);
            owner->records = (char*)owner->allocator->Allocate(0xf0);
            owner->data = owner->allocator->Allocate(8);
            if (owner->asset && owner->records && owner->data) {
                Graphics_InitializeSpriteResourceBuffers(owner->asset);
                for (unsigned short i = 0; i < 6; ++i) Graphics_InitializeSpriteTransformDefaults(owner->records + i * 40);
                SpriteAnimation_ResetTrackList(owner->data);
                owner->asset->flag = 0;
                AssetHeader* asset = owner->asset;
                asset->records = owner->records;
                asset->count = 6;
                owner->asset->data = owner->data;
                owner->count = 0;
                loader->GetLoadedFileByID(owner->task, &local.file, &local.size);
                int count = ResourceFile_CountActiveStrideRecords(local.file);
                for (int i = 0; i < count; ++i) {
                    void* record = ResourceFile_GetPayloadByIndex(local.file, i, &local.kind, &local.count);
                    Graphics_DispatchDataByResourceMagic(owner->asset, record, local.count, owner->allocator);
                }
            }
            loader->RemoveTask(owner->task);
            owner->task = -1;
            ++owner->phase;
        }
    } else if (owner->phase == 2) {
        if (!owner->asset || !owner->data) {
            owner->asset = 0;
            owner->records = 0;
            owner->data = 0;
            owner->count = 0;
            owner->task = -1;
            owner->phase = 0;
        }
    }
}
