#include <globaldefs.h>
ARM
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
#include <Memory/SafeAllocator.h>
#include <World/Zone3D.h>
#include <World/Object3D.h>
#include <World/ZonePredicates.h>
#include <Grotto/Main/ActiveGrottoClass.h>
#include <std_library_functions.h>

extern "C" int GameState_GetFieldAddress468(int self);
extern "C" void* Zone3D_GetMainInstance();
extern "C" void Script_ClearSelectedIdCount(int param_1);
extern "C" void* Actor_ClearChoiceEntries(void* p);
extern "C" void* Clear456ByteBufferAndInitializeTrailingWords(char* p);
extern "C" void* MonsterData_ClearView(void* p);
extern "C" void ScriptRecordList_InitializeEmpty(unsigned int* output);
extern "C" void* MonsterOverrideTable_Reset(void* p);
extern "C" void Zone3D_BuildGrottoNavigationGraph(void* zone, int remainder, void* tracked, int unused, int extra);
extern "C" char ZoneEncounterLoader_BeginZoneDataLoad_FormatSP00Bin[10];
extern "C" char ZoneEncounterLoader_BeginZoneDataLoad_FormatSBin[7];
extern "C" char ZoneEncounterLoader_BeginZoneDataLoad_PathDataPackLv5PathGp2[23];
extern "C" char ZoneEncounterLoader_BeginZoneDataLoad_PathDataMapZ0DM01Ambl[22];
extern "C" char ZoneEncounterLoader_BeginZoneDataLoad_PathDataPrmEncmonsBin[21];

struct E {
    unsigned short key;
    char pad[14];
};
struct T {
    E* data;
    int count;
};
extern "C" E* ZoneTable_FindEntryById(T* p, unsigned int key);

// Original: arm9/ov017 @ 0x021B478C; symbol: func_ov017_021b478c; size: 0x200.
// Clears tracked-zone tables, then queues path GP2, grotto ambience, or encounter
// monster data depending on zone id, allocator, and grotto-floor state.
extern "C" void ZoneEncounterLoader_BeginZoneDataLoad(unsigned char* self)
{
    char storage[0xb4];
    GameState* game = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    T* table = (T*)GameState_GetFieldAddress468((int)game);
    Zone3D* zone = (Zone3D*)Zone3D_GetMainInstance();
    int zoneId;
    unsigned char* tracked;
    ActiveGrottoClass* grotto = &zone->grotto_;
    tracked = *(unsigned char**)(self + 8);
    zoneId = *(unsigned short*)tracked;
    E* entry = ZoneTable_FindEntryById(table, zoneId);
    tracked = *(unsigned char**)(self + 8);
    Script_ClearSelectedIdCount((int)(tracked + 0x44));
    Actor_ClearChoiceEntries(tracked + 0x60);
    Clear456ByteBufferAndInitializeTrailingWords((char*)(tracked + 0x124));
    MonsterData_ClearView(tracked + 0x2f8);
    ScriptRecordList_InitializeEmpty((unsigned int*)(tracked + 0x304));
    MonsterOverrideTable_Reset(tracked + 0x30c);
    tracked = *(unsigned char**)(self + 8);
    if (*(unsigned short*)tracked == 3 ||
        !((SafeAllocator*)*(void**)(tracked + 0x10))->GetSignedAllocator()) {
        self[1] = 1;
        return;
    }
    if (!IsMainGrottoFloorZone(zoneId)) {
        char* zoneName = (char*)entry + 5;
        if (strlen(zoneName) < 6) {
            sprintf(storage, ZoneEncounterLoader_BeginZoneDataLoad_FormatSP00Bin, zoneName);
        } else {
            sprintf(storage, ZoneEncounterLoader_BeginZoneDataLoad_FormatSBin, zoneName);
        }
        storage[3] = 0x50;
        strcpy(storage + 0x64, storage);
        *(int*)(self + 0xc) = loader->QueueLoadFileInGP2(
            ZoneEncounterLoader_BeginZoneDataLoad_PathDataPackLv5PathGp2, storage + 0x64, 0);
        self[0x10] = 1;
        return;
    }
    if (zoneId != ((Object3D*)game->GetProtagonist())->GetField06()) {
        sprintf(storage + 0x14, ZoneEncounterLoader_BeginZoneDataLoad_PathDataMapZ0DM01Ambl, grotto->GetActiveGrottoEnviron());
        *(int*)(self + 0xc) = loader->QueueLoadFile(storage + 0x14, 0);
        self[0x10] = 2;
        return;
    }
    if (IsMainGrottoFloorZone(zoneId)) {
        int remainder = zoneId % 0x14;
        if (*(int*)&grotto->floorMap_ && !zone->unknown_424_) {
            Zone3D_BuildGrottoNavigationGraph(zone, remainder, *(void**)(self + 8), 0, 0);
        } else {
            return;
        }
    }
    unsigned char* current = *(unsigned char**)(self + 8);
    int loaded = 1;
    current[0xc] = (unsigned char)loaded;
    *(int*)(self + 0xc) = loader->QueueLoadFile(
        ZoneEncounterLoader_BeginZoneDataLoad_PathDataPrmEncmonsBin, 0);
    self[0x10] = 3;
}
