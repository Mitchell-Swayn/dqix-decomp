#include "World/Zone3D.h"
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
#define func_02011584 func_020112f4
#define func_02013750 func_02013518
#define func_02013490 func_02013258
#define func_02053c6c func_02054fe4
#define func_0207a5b8 func_0207b3f0
#define func_0207b9cc func_0207c804
#define func_0207df50 func_0207ecd0
#define func_0208a9b4 func_0208b2a8
#define func_02094d00 func_02096950
#define func_02099950 func_0209b684
#define func_020de848 func_020e01c4

#define data_020ef0f0 data_020ef02c
#endif

extern "C"
{
    void* func_02011584(GameState*);
    void func_02013454(void*);

    void* func_02053c6c(void*);
    void func_0205e104(const char*, SafeAllocator*, const void*, unsigned int);

    // Texture functions
    void* func_0207df50(void*);
    void func_0207df90(void*);
    void func_0207dfac(void*);

    void* func_0208a9b4();
    void func_02094d00(void*);
    Zone3D_StructPtr_8* func_02099950(void*, unsigned short id);

    void func_020c9be0(); // abort() or similar
    void func_020de848(void*);

    void func_02013490(void*);
    void func_02013750(Zone3D*, bool);

    void func_02014a24(Zone3D*, void*);
}

extern char data_020ef0f0[]; // "data/map/maplist9.bin"
extern char data_020ef106[]; // "%s/Z0%dM01.ambl"
extern char data_020ef116[]; // "data/map"
extern char data_020ef11f[]; // "%s/Z0%dM99.ambl"
extern char data_020ef12f[]; // "%s/%s.ambl"
extern char data_020ef13a[]; // "ARC"
extern char data_020ef13e[]; // ".nsbtx"
extern char data_020ef145[]; // ".bmbl"
extern char data_020ef14b[]; // ".dat"
extern char data_020ef150[]; // ".bpos"
extern char data_020ef156[]; // "%s/Z0%dM01.amdj"
extern char data_020ef166[]; // "%s/Z0%dM99.amdj"
extern char data_020ef176[]; // "%s/%sb.amdj"
extern char data_020ef182[]; // "%s/%sa.amdj"
extern char data_020ef18e[]; // "%s/%s.amdj"
extern char data_020ef199[]; // ".bmdj"
extern char data_020ef19f[]; // "Z0%dM0100"
extern char data_020ef1a9[]; // "Z0%dM0101"
extern char data_020ef1b3[]; // "Z0%dM0102"
extern char data_020ef1bd[]; // "Z0%dM0103"
extern char data_020ef1c7[]; // "%s/ats_%c.ambl"
extern char data_020ef1d6[]; // "%s.bats"
extern char data_020ef1de[]; // "ARC:/%s"
extern char data_020ef1e6[]; // "."
extern char data_020ef1e8[]; // "nsbmd"
extern char data_020ef1ee[]; // "col2"
extern char data_020ef1f3[]; // "open"
extern char data_020ef1f8[]; // "open2"
extern char data_020ef1fe[]; // "close"
extern char data_020ef204[]; // "close2"
extern char data_020ef20b[]; // "/data/ani/d_%c%03d.spr"
extern char data_020ef222[]; // "tsuboware"
extern char data_020ef22c[]; // "ARC:%s"

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
        sprintf(filenameBuffer, data_020ef106, data_020ef116, environ);
    }
    else if (IsGrottoBossFloorZone(currentZoneID_))
    {
        int environ = grotto_.GetActiveGrottoEnviron();
        sprintf(filenameBuffer, data_020ef11f, data_020ef116, environ);
    }
    else
    {
        sprintf(filenameBuffer, data_020ef12f, data_020ef116, pUnknownStruct_8_->mapShortName_);
    }
    mapAMBLLoadHandle_ = loader->QueueLoadFile(filenameBuffer, NULL);
}

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
        if (narc.Initialize(data_020ef13a, (const unsigned char*)amblData))
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
                    if (strcmp(data_020ef13e, extension) == 0)
                        ProcessNSBTXFile(innerFilePtr, innerFilesize, innerFilePath);
                }
                else if (pass == 1)
                {
                    // bmbl file
                    if (strcmp(data_020ef145, extension) == 0)
                        ProcessBMBLFile(innerFilePtr, innerFilesize);
                    // dat file
                    else if (strcmp(data_020ef14b, extension) == 0)
                    {
                        SafeAllocator* alloc = pAllocator_68_;
                        unsigned int decompressedSize;
                        const void* decompressed = DecompressLZ77FileIntoScratchSpace(*alloc, innerFilePtr, decompressedSize);
                        // this call is responsible for setting the top-screen map
                        func_0205e104(mapListInfo_.maybeModelName, alloc, decompressed, decompressedSize);
                    }
                    // bpos file. From testing these seem to be a grotto thing
                    else if (strcmp(data_020ef150, extension) == 0)
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
                func_020c9be0();
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

bool Zone3D::ProcessBATSFile(const void* filedata, unsigned int /*filesize*/)
{
    SafeAllocator* allocator = pAllocator_68_;
    unsigned int decompressedLength;
    void* decompressed = DecompressLZ77FileIntoScratchSpace(*allocator, filedata, decompressedLength);
    lighting_.Initialize();
    lighting_.LoadFromScript(decompressed, decompressedLength, allocator);
    return true;
}

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
                func_0207df90(graphicsPtr);
                modelNode->model_.SetRawFile(decompressed, decompressedLength);
                modelNode->model_.ClearRawFileCache();
                modelNode->model_.ProcessRawFile(Model3D::TextureStagingMode_Immediate);
                func_0207dfac(graphicsPtr);
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
        sprintf(filenameBuffer, data_020ef156, data_020ef116, environ);
    }
    else if (IsGrottoBossFloorZone(currentZoneID_))
    {
        int environ = grotto_.GetActiveGrottoEnviron();
        sprintf(filenameBuffer, data_020ef166, data_020ef116, environ);
    }
    else
    {
        if (currentZoneID_ == 10000 || currentZoneID_ == 10100)
        {
            if (unknown_42c_ == 0)
            {
                sprintf(filenameBuffer, data_020ef176, data_020ef116, pUnknownStruct_8_->mapShortName_);
                unknown_42c_++;
            }
            else if (unknown_42c_ == 1)
            {
                sprintf(filenameBuffer, data_020ef182, data_020ef116, pUnknownStruct_8_->mapShortName_);
                unknown_42c_++;
            }
        }
        else
        {
            sprintf(filenameBuffer, data_020ef18e, data_020ef116, pUnknownStruct_8_->mapShortName_);
        }
    }
    mapAMDJLoadHandle_ = loader->QueueLoadFile(filenameBuffer, NULL);
}

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
    if (narc.Initialize(data_020ef13a, (unsigned char*)amdjData))
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
            if (strcmp(data_020ef199, extension) == 0)
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
            func_02014a24(this, item);
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

bool Zone3D::ProcessBMDJFile(const void* filedata, unsigned int filesize, ZoneFeatures::Opcode64Entry* misc)
{
    SafeAllocator* allocator = pAllocator_68_;
    Zone3D_BMDJStruct* newStruct = (Zone3D_BMDJStruct*)allocator->Allocate(sizeof(Zone3D_BMDJStruct));
    if (newStruct == NULL)
        return false;

    func_02013454(newStruct);
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

