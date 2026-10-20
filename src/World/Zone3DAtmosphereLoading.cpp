#include "World/Zone3D.h"
#include "World/Zone3DPaths.h"
#include "World/MapArchive.h"
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
#define GameObject_GetLinkedIndexedState func_02054fe4
#define func_0207a5b8 func_0207b3f0
#define func_0207b9cc func_0207c804
#define TextureVRAM_SnapshotAllocationBounds func_0207ecd0
#define PartyProgress_GetInstance func_0208b2a8
#define func_02094d00 func_02096950
#define ZoneTable_FindEntryById func_0209b684
#define func_020de848 func_020e01c4


#endif

extern "C"
{
    void* GameState_GetFieldAddress468(GameState*);

    void* GameObject_GetLinkedIndexedState(void*);
    void Script_InitializeAndExecuteOwnerContextCode(const char*, SafeAllocator*, const void*, unsigned int);

    // Texture functions
    void* TextureVRAM_SnapshotAllocationBounds(void*);
    void Graphics_RestoreTextureImageAndPaletteVRAMState(void*);
    void Object_InvokeSaveTextureImageVRAMState(void*);

    void* PartyProgress_GetInstance();
    void func_02094d00(void*);
    Zone3D_StructPtr_8* ZoneTable_FindEntryById(void*, unsigned short id);

    void DisableInterruptsAndHaltForever(); // abort() or similar
    void func_020de848(void*);

    void func_02013750(Zone3D*, bool);

}


// Original: arm9/main @ 0x02014B04; symbol: _ZN6Zone3D17QueueLoadATS_AMBLEv; size: 0x100.
void Zone3D::QueueLoadATS_AMBL()
{
    if (isInMainGrottoFloor_23b8_)
    {
        int environ = grotto_.GetActiveGrottoEnviron();
        if (environ == 0)
            environ = 1;
        if (currentGrottoFloor_23ba_ <= 4)
            sprintf(mapListInfo_.maybeModelName, gZone3DPaths.grottoRoom0, environ);
        else if (currentGrottoFloor_23ba_ <= 8)
            sprintf(mapListInfo_.maybeModelName, gZone3DPaths.grottoRoom1, environ);
        else if (currentGrottoFloor_23ba_ <= 12)
            sprintf(mapListInfo_.maybeModelName, gZone3DPaths.grottoRoom2, environ);
        else if (currentGrottoFloor_23ba_ <= 16)
            sprintf(mapListInfo_.maybeModelName, gZone3DPaths.grottoRoom3, environ);
    }
    if (strlen(mapListInfo_.maybeModelName) == 0)
        LoadMapAMDJ();
    else
    {
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        char filename[40];
        sprintf(filename, gZone3DPaths.atmosphereArchive, gZone3DPaths.mapRoot, mapListInfo_.maybeModelName[0]);
        atsAMBLLoadHandle_ = loader->QueueLoadFile(filename, NULL);
    }
}

// Original: arm9/main @ 0x02014C04; symbol: _ZN6Zone3D14UnpackATS_AMBLEv; size: 0x114.
bool Zone3D::UnpackATS_AMBL()
{
    if (atsAMBLLoadHandle_ < 0)
        return true;
    
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (loader->GetTaskStatus(atsAMBLLoadHandle_) == 0)
        return false;

    if (loader->GetDetailedTaskStatus(atsAMBLLoadHandle_) != BackgroundLoader::TaskStatus_Complete)
    {
        loader->RemoveTask(atsAMBLLoadHandle_);
        atsAMBLLoadHandle_ = -1;
        LoadMapAMDJ();
        return true;
    }

    void* narcBuffer;
    unsigned int narcLength;
    loader->GetLoadedFileByID(atsAMBLLoadHandle_, &narcBuffer, &narcLength);
    char targetInnerFile[40];
    sprintf(targetInnerFile, gZone3DPaths.atmosphereBinary, mapListInfo_.maybeModelName);

    const void* batsFile;
    unsigned int batsFileLength;

    if (!GetFileInNarc(narcBuffer, targetInnerFile, &batsFile, &batsFileLength, 0))
    {
        loader->RemoveTask(atsAMBLLoadHandle_);
        atsAMBLLoadHandle_ = -1;
        LoadMapAMDJ();
        return true;
    }

    ProcessBATSFile(batsFile, batsFileLength);
    loader->RemoveTask(atsAMBLLoadHandle_);
    atsAMBLLoadHandle_ = -1;
    LoadMapAMDJ();
    return true;
}

// Original: arm9/main @ 0x02014D18; symbol: _Z18BuildArcMemberPathPKcS0_Pc; size: 0x68.
void BuildArcMemberPath(const char* stem, const char* extension, char* path)
{
    sprintf(path, gZone3DPaths.archiveMember, stem);

    char* dot = strrchr(path, '.');
    if (dot)
    {
        strcpy(dot + 1, extension);
    }
    else
    {
        strcat(path, gZone3DPaths.extensionSeparator);
        strcat(path, extension);
    }
}

