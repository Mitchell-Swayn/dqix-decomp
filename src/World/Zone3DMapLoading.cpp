#include "World/Zone3D.h"
#include "World/Zone3DPaths.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/NarcHandle.h"
#include "Filesystem/FileAccessor.h"
#include "Filesystem/LowNitroHandle.h"
#include "Filesystem/FileIO.h"
#include "Resource/GameResources.h"
#include "Graphics/NSBXX/NSBXX.h"
#include "World/ZonePredicates.h"

#if defined(jpn)
#define GameState_GetFieldAddress468 func_020112f4
#define func_02013750 func_02013518
#define ReadWordFieldAtOffset150 func_02054fe4
#define func_0207a5b8 func_0207b3f0
#define func_0207b9cc func_0207c804
#define SnapshotBlockAndVolatileWordPair func_0207ecd0
#define ReadGlobalAt02108F0C func_0208b2a8
#define func_02094d00 func_02096950
#define Object_FindRecordByKeyInCountedArray func_0209b684
#define func_020de848 func_020e01c4


#endif

extern "C"
{
    void* GameState_GetFieldAddress468(GameState*);

    void* ReadWordFieldAtOffset150(void*);
    void Script_InitializeAndExecuteOwnerContextCode(const char*, SafeAllocator*, const void*, unsigned int);

    // Texture functions
    void* SnapshotBlockAndVolatileWordPair(void*);
    void Graphics_RestoreTextureImageAndPaletteVRAMState(void*);
    void Object_InvokeSaveTextureImageVRAMState(void*);

    void* ReadGlobalAt02108F0C();
    void func_02094d00(void*);
    Zone3D_StructPtr_8* Object_FindRecordByKeyInCountedArray(void*, unsigned short id);

    void DisableInterruptsAndHaltForever(); // abort() or similar
    void func_020de848(void*);

    void func_02013750(Zone3D*, bool);

}


// Original: arm9/main @ 0x02013FB4; symbol: _ZN6Zone3D15ProcessMaplist9Ev; size: 0x88.
bool Zone3D::ProcessMaplist9()
{
    if (mapListLoadHandle_ < 0)
        return true;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (loader->GetTaskStatus(mapListLoadHandle_) == 0)
        return false;
    
    void* script;
    unsigned int length;
    loader->GetLoadedFileByID(mapListLoadHandle_, &script, &length);
    LoadZoneInfoFromMapListScript(currentZoneID_, &mapListInfo_, script, length);
    loader->RemoveTask(mapListLoadHandle_);
    mapListLoadHandle_ = -1;
    LoadMapAMBL();
    return true;
}

// Original: arm9/main @ 0x0201403C; symbol: _ZN6Zone3D11LoadMapAMBLEv; size: 0xCC.
void Zone3D::LoadMapAMBL()
{
    BackgroundLoader* loader = BackgroundLoader::GetInstance();

    char filenameBuffer[20];

    if (IsMainGrottoFloorZone(currentZoneID_))
    {
        int environ = grotto_.GetActiveGrottoEnviron();
        if (environ == 0)
            environ = 1;
        if (environ > 5)
            environ = 5;
        sprintf(filenameBuffer, gZone3DPaths.grottoFloorAMBL, gZone3DPaths.mapRoot, environ);
    }
    else if (IsGrottoBossFloorZone(currentZoneID_))
    {
        int environ = grotto_.GetActiveGrottoEnviron();
        sprintf(filenameBuffer, gZone3DPaths.grottoEntranceAMBL, gZone3DPaths.mapRoot, environ);
    }
    else
    {
        sprintf(filenameBuffer, gZone3DPaths.zoneAMBL, gZone3DPaths.mapRoot, pUnknownStruct_8_->mapShortName_);
    }
    mapAMBLLoadHandle_ = loader->QueueLoadFile(filenameBuffer, NULL);
}

// Original: arm9/main @ 0x02014108; symbol: _ZN6Zone3D13UnpackMapAMBLEv; size: 0x288.
bool Zone3D::UnpackMapAMBL()
{
    if (mapAMBLLoadHandle_ < 0)
        return true;

    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (loader->GetTaskStatus(mapAMBLLoadHandle_) == 0)
        return false;

    // If we get here, the loading finished but was not successful
    if (loader->GetDetailedTaskStatus(mapAMBLLoadHandle_) != BackgroundLoader::TaskStatus_Complete)
    {
        loader->RemoveTask(mapAMBLLoadHandle_);
        mapAMBLLoadHandle_ = -1;
        return true;
    }
    
    void* amblData;
    unsigned int amblFilesize;
    
    loader->GetLoadedFileByID(mapAMBLLoadHandle_, &amblData, &amblFilesize);

    for (int pass = 0; pass < 2; pass++)
    {
        NarcHandle narc;
        if (narc.Initialize(gZone3DPaths.archiveMount, (const unsigned char*)amblData))
        {
            NitroVM vm;
            unsigned int fileID = 0;
            NitroVM_Initialize(&vm);
            while (PrepareReadFileInNARCByID(&vm, &narc, fileID))
            {
                char innerFilePath[80];
                NitroVM_WriteOutFilePath(&vm, innerFilePath, 80);
                
                const char* extension = strrchr(innerFilePath, '.');
                if (extension == NULL)
                {
                    NitroVM_FinishRead(&vm);
                    fileID++;
                    continue;
                }
                unsigned int innerFilesize = vm.fileInfo.endOffset - vm.fileInfo.startOffset;
                NitroVM_FinishRead(&vm);
                const void* innerFilePtr = narc.GetFileByIndex(fileID);
                if (pass == 0)
                {
                    // nsbtx file (we can have multiple of these)
                    if (strcmp(gZone3DPaths.textureExtension, extension) == 0)
                        ProcessNSBTXFile(innerFilePtr, innerFilesize, innerFilePath);
                }
                else if (pass == 1)
                {
                    // bmbl file
                    if (strcmp(gZone3DPaths.mapBinaryExtension, extension) == 0)
                        ProcessBMBLFile(innerFilePtr, innerFilesize);
                    // dat file
                    else if (strcmp(gZone3DPaths.dataExtension, extension) == 0)
                    {
                        SafeAllocator* alloc = pAllocator_68_;
                        unsigned int decompressedSize;
                        const void* decompressed = DecompressLZ77FileIntoScratchSpace(*alloc, innerFilePtr, decompressedSize);
                        // this call is responsible for setting the top-screen map
                        Script_InitializeAndExecuteOwnerContextCode(mapListInfo_.maybeModelName, alloc, decompressed, decompressedSize);
                    }
                    // bpos file. From testing these seem to be a grotto thing
                    else if (strcmp(gZone3DPaths.positionExtension, extension) == 0)
                        ProcessBPOSFile(innerFilePtr, innerFilesize);
                }
                fileID++;
            }
            narc.Destroy();
        }
        if (pass == 0)
        {
            unsigned int allocSize = pAllocator_4c_->GetMaxPossibleAllocation();
            void* memory = pAllocator_4c_->Allocate(allocSize);
            if (memory == NULL)
                DisableInterruptsAndHaltForever();
            internalAllocator_.ResetAllocatorPointer();
            internalAllocator_.CreateTypeA(memory, allocSize);
            pAllocator_68_ = &internalAllocator_;
            internalAllocator_.Reset();
        }
    }
    loader->RemoveTask(mapAMBLLoadHandle_);
    mapAMBLLoadHandle_ = -1;
    QueueLoadATS_AMBL();
    return true;
}

// Original: arm9/main @ 0x02014390; symbol: _ZN6Zone3D15ProcessBMBLFileEPKvj; size: 0x48.
bool Zone3D::ProcessBMBLFile(const void* filedata, unsigned int /*filesize*/)
{
    SafeAllocator* allocator = pAllocator_68_;
    unsigned int decompressedLength;
    void* decompressed = DecompressLZ77FileIntoScratchSpace(*allocator, filedata, decompressedLength);
    Zone3D_StructPtr_8* ptr8 = pUnknownStruct_8_;

    bFeatures_.Reset();
    // run another script with opcode table at 0x020ef388
    bFeatures_.LoadFromScript(allocator, decompressed, decompressedLength);
    pUnknownStruct_8_ = ptr8; // why?
    return true;
}

// Original: arm9/main @ 0x020143D8; symbol: _ZN6Zone3D15ProcessBPOSFileEPKvj; size: 0x3C.
bool Zone3D::ProcessBPOSFile(const void* filedata, unsigned int /*filesize*/)
{
    SafeAllocator* allocator = pAllocator_68_;
    unsigned int decompressedLength;
    void* decompressed = DecompressLZ77FileIntoScratchSpace(*allocator, filedata, decompressedLength);
    Zone3D_StructPtr_8* ptr8 = pUnknownStruct_8_;

    bFeatures_.LoadFromScript(allocator, decompressed, decompressedLength);
    pUnknownStruct_8_ = ptr8; // why?
    return true;
}

// Original: arm9/main @ 0x02014414; symbol: _ZN6Zone3D15ProcessBATSFileEPKvj; size: 0x48.
bool Zone3D::ProcessBATSFile(const void* filedata, unsigned int /*filesize*/)
{
    SafeAllocator* allocator = pAllocator_68_;
    unsigned int decompressedLength;
    void* decompressed = DecompressLZ77FileIntoScratchSpace(*allocator, filedata, decompressedLength);
    lighting_.Initialize();
    lighting_.LoadFromScript(decompressed, decompressedLength, allocator);
    return true;
}

// Original: arm9/main @ 0x0201445C; symbol: _ZN6Zone3D16ProcessNSBTXFileEPKvjPKc; size: 0x14C.
bool Zone3D::ProcessNSBTXFile(const void* filedata, unsigned int filesize, const char* filename)
{
    SafeAllocator* allocator = pAllocator_68_;
    void* graphicsPtr = unknown_ptr_50_;

    Model3DListNode* modelNode = (Model3DListNode*)allocator->Allocate(sizeof(Model3DListNode));
    if (modelNode != NULL)
    {
        modelNode->model_.Clear();
        modelNode->filename_ = NULL;
        modelNode->pNext_ = NULL;
        char* newFilenameBuffer = (char*)allocator->Allocate(strlen(filename) + 1);
        modelNode->filename_ = newFilenameBuffer;
        if (newFilenameBuffer != NULL)
        {
            strcpy(newFilenameBuffer, filename);
            modelNode->pNext_ = firstModel_418_;
            firstModel_418_ = modelNode;
            unsigned int decompressedLength;
            void* decompressed = DecompressLZ77FileIntoScratchSpace(*allocator, filedata, decompressedLength);
            if (decompressed != NULL)
            {
                Graphics_RestoreTextureImageAndPaletteVRAMState(graphicsPtr);
                modelNode->model_.SetRawFile(decompressed, decompressedLength);
                modelNode->model_.ClearRawFileCache();
                modelNode->model_.ProcessRawFile(Model3D::TextureStagingMode_Immediate);
                Object_InvokeSaveTextureImageVRAMState(graphicsPtr);
                NSBXXTex* texture = modelNode->model_.GetTEX0();
                if (texture != NULL)
                {
                    textureImageMemory_ += NSBXX_Tex_GetBlock1Length(texture);
                    texturePaletteMemory_ += NSBXX_Tex_GetBlock4Length(texture);
                }
                bool success = false;
                if (texture != 0)
                {
                    // bit weird, but I guess block 1 starts right after the metadata ends
                    unsigned int textureMetadataLength = texture->block1Offset_;
                    NSBXXTex* copyOfpVar5 = (NSBXXTex*)allocator->Allocate(textureMetadataLength);
                    if (copyOfpVar5 != NULL)
                    {
                        memcpy(copyOfpVar5, texture, textureMetadataLength);
                        modelNode->model_.SetTEX0(copyOfpVar5);
                        success = true;
                    }
                }
                if (!success)
                    modelNode->model_.Clear();
            }
        }
    }
    return true;
}

// Original: arm9/main @ 0x020145A8; symbol: _ZN6Zone3D11LoadMapAMDJEv; size: 0x154.
void Zone3D::LoadMapAMDJ()
{
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    char filenameBuffer[20];
    if (IsMainGrottoFloorZone(currentZoneID_))
    {
        int environ = grotto_.GetActiveGrottoEnviron();
        if (environ == 0)
            environ = 1;
        if (environ > 5)
            environ = 5;
        sprintf(filenameBuffer, gZone3DPaths.grottoFloorAMDJ, gZone3DPaths.mapRoot, environ);
    }
    else if (IsGrottoBossFloorZone(currentZoneID_))
    {
        int environ = grotto_.GetActiveGrottoEnviron();
        sprintf(filenameBuffer, gZone3DPaths.grottoEntranceAMDJ, gZone3DPaths.mapRoot, environ);
    }
    else
    {
        if (currentZoneID_ == 10000 || currentZoneID_ == 10100)
        {
            if (unknown_42c_ == 0)
            {
                sprintf(filenameBuffer, gZone3DPaths.zoneObjectsVariantB, gZone3DPaths.mapRoot, pUnknownStruct_8_->mapShortName_);
                unknown_42c_++;
            }
            else if (unknown_42c_ == 1)
            {
                sprintf(filenameBuffer, gZone3DPaths.zoneObjectsVariantA, gZone3DPaths.mapRoot, pUnknownStruct_8_->mapShortName_);
                unknown_42c_++;
            }
        }
        else
        {
            sprintf(filenameBuffer, gZone3DPaths.zoneObjects, gZone3DPaths.mapRoot, pUnknownStruct_8_->mapShortName_);
        }
    }
    mapAMDJLoadHandle_ = loader->QueueLoadFile(filenameBuffer, NULL);
}

// Original: arm9/main @ 0x020146FC; symbol: _ZN6Zone3D13UnpackMapAMDJEv; size: 0x204.
bool Zone3D::UnpackMapAMDJ()
{
    if (mapAMDJLoadHandle_ < 0)
        return true;

    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (loader->GetTaskStatus(mapAMDJLoadHandle_) == 0)
        return false;

    // If we get here, loading finished but was not successful
    if (loader->GetDetailedTaskStatus(mapAMDJLoadHandle_) != BackgroundLoader::TaskStatus_Complete)
    {
        loader->RemoveTask(mapAMDJLoadHandle_);
        mapAMDJLoadHandle_ = -1;
        return true;
    }

    void* amdjData;
    unsigned int amdjFilesize;
    loader->GetLoadedFileByID(mapAMDJLoadHandle_, &amdjData, &amdjFilesize);
    NarcHandle narc;
    if (narc.Initialize(gZone3DPaths.archiveMount, (unsigned char*)amdjData))
    {
        NitroVM vm;
        unsigned int fileID = 0;
        NitroVM_Initialize(&vm);
        while (PrepareReadFileInNARCByID(&vm, &narc, fileID))
        {
            char innerFilePath[80];
            NitroVM_WriteOutFilePath(&vm, innerFilePath, 80);
            
            const char* extension = strrchr(innerFilePath, '.');
            if (extension == NULL)
            {
                NitroVM_FinishRead(&vm);
                fileID++;
                continue;
            }
            unsigned int innerFilesize = vm.fileInfo.endOffset - vm.fileInfo.startOffset;
            NitroVM_FinishRead(&vm);
            const void* innerFilePtr = narc.GetFileByIndex(fileID);
            if (strcmp(gZone3DPaths.objectsExtension, extension) == 0)
            {
                int numIterations = bFeatures_.arraySize64_;
                for (int i = 0; i < numIterations; i++)
                {
                    ZoneFeatures::Opcode64Entry* bstr = bFeatures_.GetOpcode64Entry(i);
                    if (strstr(innerFilePath, bstr->string_10))
                        ProcessBMDJFile(innerFilePtr, innerFilesize, bstr);
                }
            }
            fileID++;
        }
        for (Zone3D_BMDJStruct* item = firstBMDJStruct_41c_; item != NULL; item = item->pNext_)
        {
            BuildBMDJObjects(item);
            if (unknown_42c_ == 2) 
                break;
        }
        narc.Destroy();
    }
    loader->RemoveTask(mapAMDJLoadHandle_);
    mapAMDJLoadHandle_ = -1;
    if (unknown_42c_ == 1)
    {
        LoadMapAMDJ();
        return false;
    }

    if (mapListInfo_.buffer2[0] != '\0')
        atmosphericEffects_.LoadArchive(mapListInfo_.buffer2);
    return true;
}

// Original: arm9/main @ 0x02014900; symbol: _ZN6Zone3D15ProcessBMDJFileEPKvjPN12ZoneFeatures13Opcode64EntryE; size: 0x8C.
bool Zone3D::ProcessBMDJFile(const void* filedata, unsigned int filesize, ZoneFeatures::Opcode64Entry* misc)
{
    SafeAllocator* allocator = pAllocator_68_;
    Zone3D_BMDJStruct* newStruct = (Zone3D_BMDJStruct*)allocator->Allocate(sizeof(Zone3D_BMDJStruct));
    if (newStruct == NULL)
        return false;

    ResetBMDJGroup(newStruct);
    newStruct->unknown_0_ = misc->unk_0;
    newStruct->vec_48_ = misc->vector_4.vec;
    unsigned int decompressedLength;
    void* decompressed = DecompressLZ77FileIntoScratchSpace(*allocator, filedata, decompressedLength);
    if (decompressed == NULL)
        return false;

    newStruct->scriptData_.Load(allocator, decompressed, decompressedLength);
    newStruct->pNext_ = firstBMDJStruct_41c_;
    firstBMDJStruct_41c_ = newStruct;
    return true;
}

// Original: arm9/main @ 0x0201498C; symbol: _ZN6Zone3D25ProcessAtmosphericEffectsEv; size: 0x98.
bool Zone3D::ProcessAtmosphericEffects()
{
    if (!atmosphericEffects_.IsArchiveLoaded())
        return false;
    atmosphericEffects_.ProcessArchive(&atmosphericEffects_, pAllocator_68_, unknown_ptr_50_);
    for (AtmosphericEffect* effect = atmosphericEffects_.GetFirstEffect();
        effect != NULL; effect = effect->pNext_)
    {
        if (effect->object_.pModel_ == NULL)
            continue;
        NSBXXTex* tex0 = effect->object_.pModel_->GetTEX0();
        if (tex0 == NULL)
            continue;
        textureImageMemory_ += NSBXX_Tex_GetBlock1Length(tex0);
        texturePaletteMemory_ += NSBXX_Tex_GetBlock4Length(tex0);
    }
    return true;
}

