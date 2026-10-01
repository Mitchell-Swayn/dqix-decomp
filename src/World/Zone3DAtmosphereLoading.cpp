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

void Zone3D::QueueLoadATS_AMBL()
{
    if (isInMainGrottoFloor_23b8_)
    {
        int environ = grotto_.GetActiveGrottoEnviron();
        if (environ == 0)
            environ = 1;
        if (currentGrottoFloor_23ba_ <= 4)
            sprintf(mapListInfo_.maybeModelName, data_020ef19f, environ);
        else if (currentGrottoFloor_23ba_ <= 8)
            sprintf(mapListInfo_.maybeModelName, data_020ef1a9, environ);
        else if (currentGrottoFloor_23ba_ <= 12)
            sprintf(mapListInfo_.maybeModelName, data_020ef1b3, environ);
        else if (currentGrottoFloor_23ba_ <= 16)
            sprintf(mapListInfo_.maybeModelName, data_020ef1bd, environ);
    }
    if (strlen(mapListInfo_.maybeModelName) == 0)
        LoadMapAMDJ();
    else
    {
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        char filename[40];
        sprintf(filename, data_020ef1c7, data_020ef116, mapListInfo_.maybeModelName[0]);
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
    sprintf(targetInnerFile, data_020ef1d6, mapListInfo_.maybeModelName);

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
    sprintf(path, data_020ef1de, stem);

    char* dot = strrchr(path, '.');
    if (dot)
    {
        strcpy(dot + 1, extension);
    }
    else
    {
        strcat(path, data_020ef1e6);
        strcat(path, extension);
    }
}

