#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
#include <Filesystem/FileIO.h>
ARM
#pragma opt_propagation off
#pragma opt_common_subs off
extern "C" void __clear(void*,unsigned);
extern "C" void* memset(void*,int,unsigned);
extern "C" void MonsterGroupScript_ExecuteWithValidationContext(void*,const void*,unsigned,void*,void*);
extern "C" int Script_CopySelectedIds(void*,short*);
// Original data: arm9/ov017 @ 0x021D7B85; symbol: data_ov017_021d7b85.
extern "C" char ZoneEncounterLoader_LoadBattleGroupsAndQueueMonsterData_PathDataPrmMonsDmyBin[];
// Original data: arm9/ov017 @ 0x021D7B9B; symbol: data_ov017_021d7b9b.
extern "C" char ZoneEncounterLoader_LoadBattleGroupsAndQueueMonsterData_PathDataPrmMonDataGp2[];
// Original data: arm9/ov017 @ 0x021D7BB1; symbol: data_ov017_021d7bb1.
extern "C" char ZoneEncounterLoader_LoadBattleGroupsAndQueueMonsterData_MarkupMonDataLGNat[];
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
// Original: arm9/ov017 @ 0x021B5070; symbol: func_ov017_021b5070; size: 0x1E0.
// Loads battle groups, maps selected IDs to dummy flags, and queues monster data.
extern "C" void ZoneEncounterLoader_LoadBattleGroupsAndQueueMonsterData(unsigned char* self) {
    GameState::GetInstance();
    BackgroundLoader* loader=BackgroundLoader::GetInstance();
    if(loader->GetTaskStatus(W(self,12))) {
        if(loader->GetDetailedTaskStatus(W(self,12))==2) {
            unsigned length;void* file;
            loader->GetLoadedFileByID(W(self,12),&file,&length);
            if(file) {
                char* owner=P(self,8);
                void* context=owner+0x60;
                MonsterGroupScript_ExecuteWithValidationContext(owner+0x124,file,length,P(P(self,8),0x10),P(self,8)+0x60);
            }
        }
        loader->RemoveTask(W(self,12));
        W(self,12)=-1;
        char* owner=P(self,8);
        short ids[12];__clear(ids,24);
        int count=(short)Script_CopySelectedIds(owner+0x44,ids);
        SafeAllocator* allocator=(SafeAllocator*)P(P(self,8),0x14);
        unsigned char* flags;
        if(!allocator) flags=0;
        else if(!(unsigned short)count) flags=0;
        else {
            BackgroundLoader::AddLockGlobal();
            BackgroundLoader::FreeAllocationsGlobal();
            unsigned size;
            short* table=(short*)LoadFileIntoMemory(ZoneEncounterLoader_LoadBattleGroupsAndQueueMonsterData_PathDataPrmMonsDmyBin,Main_UnknownRoleZeroInitializedStorage_Variant6,&size);
            BackgroundLoader::RemoveLockGlobal();
            if(!table) flags=0;
            else if(!size) flags=0;
            else {
                unsigned char* values;
                int entries=table[0];
                unsigned offset=entries*2+2;
                values=(unsigned char*)table+offset;
                flags=(unsigned char*)allocator->Allocate(12);
                memset(flags,0,12);
                int j;
                for(int i=0;i<(unsigned short)count;++i) {
                    int id=ids[i];
                    j=0;
                    short* item=table+1;
                    for(;j<entries;++j) { if(*item++==id) break; }
                    if(j>=0 && j<entries) flags[i]=values[j];
                }
            }
        }
        P(self,0x14)=(char*)flags;
        W(self,12)=loader->QueueLoadFileInGP2(ZoneEncounterLoader_LoadBattleGroupsAndQueueMonsterData_PathDataPrmMonDataGp2,ZoneEncounterLoader_LoadBattleGroupsAndQueueMonsterData_MarkupMonDataLGNat,0);
        self[0x10]=6;
    }
}
