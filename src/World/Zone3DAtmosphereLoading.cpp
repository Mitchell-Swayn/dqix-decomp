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

}


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

