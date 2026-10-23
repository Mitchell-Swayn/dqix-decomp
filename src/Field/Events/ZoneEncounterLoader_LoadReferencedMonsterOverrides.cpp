#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
ARM
extern "C" void* Network_GetConnectionManager();
extern "C" void __clear(void*,unsigned);
extern "C" unsigned char* Script_GetWeightedGroupByIndex(void*,int);
extern "C" void* MonsterOverrideTable_Reset(void*);
extern "C" void MonsterOverrideTable_LoadSelectedMonsters(void*,void*,const void*,unsigned,const short*,int);
extern "C" void ZoneEncounterLoader_FinalizeNavigationAndEncounterData(unsigned char*);
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
struct MonsterReference { unsigned id:12; unsigned rest:20; };
struct WeightedGroup {
    unsigned short key;
    unsigned char primaryCount, secondaryCount;
    struct Primary { MonsterReference monster; unsigned other; } primary[6];
    MonsterReference secondary[6];
};
// Original: arm9/ov017 @ 0x021B5458; symbol: func_ov017_021b5458; size: 0x1F0.
// Collects unique monster IDs from six weighted groups and loads their overrides.
extern "C" void ZoneEncounterLoader_LoadReferencedMonsterOverrides(unsigned char* self) {
    char* owner;
    GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    Network_GetConnectionManager();
    if (loader->GetTaskStatus(W(self,12))) {
        if (loader->GetDetailedTaskStatus(W(self,12)) == 2) {
            unsigned length; void* file;
            loader->GetLoadedFileByID(W(self,12),&file,&length);
            if (file) {
                short ids[64];
                __clear(ids,128);
                short count=0;
                owner=P(self,8);
                for (int i=0;i<6;++i) {
                    WeightedGroup* group=(WeightedGroup*)Script_GetWeightedGroupByIndex(owner+0x124,i);
                    if (!group) continue;
                    for (int j=0;j<group->primaryCount;++j) {
                        int id=group->primary[j].monster.id;
                        int unique=1;
                        for (int k=0;k<count;++k) {
                            if(id==ids[k]) { unique=0; break; }
                        }
                        if(unique) ids[count++]=id;
                    }
                    for (int j=0;j<group->secondaryCount;++j) {
                        int id=group->secondary[j].id;
                        int unique=1;
                        for (int k=0;k<count;++k) {
                            if(id==ids[k]) { unique=0; break; }
                        }
                        if(unique) ids[count++]=id;
                    }
                }
                owner=P(self,8);
                MonsterOverrideTable_Reset(owner+0x30c);
                MonsterOverrideTable_LoadSelectedMonsters(owner+0x30c,P(P(self,8),0x10),file,length,ids,count);
            }
        }
        loader->RemoveTask(W(self,12));
        W(self,12)=-1;
        ZoneEncounterLoader_FinalizeNavigationAndEncounterData(self);
    }
}
