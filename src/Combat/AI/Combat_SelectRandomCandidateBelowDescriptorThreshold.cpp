#include <globaldefs.h>
ARM
struct CandidateIds { short values[8]; };
extern "C" void* Combat_FindIndexedMonsterObject(void*,int);
extern "C" int Combatant_TestTargetCapabilityBit2(void*);
extern "C" int Combat_CollectGroupIndicesByDescriptorFlags(void*,short*,int,unsigned);
extern "C" char* _Z16GetCombatantByIDii(int,int);
extern "C" int Combatant_TestPrimaryStatusFlagBit9(void*);
extern "C" int Combat_SelectRandomCandidateInPlace(void**,int*,short*);
// Original data: arm9/ov024 @ 0x21fef4c; symbol: data_ov024_021fef4c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff0000000000000000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" CandidateIds CombatSelectRandomCandidateBelowDescriptorThreshold_UnknownRoleInitializedBytes;
// Original: arm9/ov024 @ 0x021F145C; symbol: Combat_SelectRandomCandidateBelowDescriptorThreshold; size: 0x11C.
// Filters the fixed candidate set by combatant flags and signed descriptor level, then selects one eligible ID.
extern "C" int Combat_SelectRandomCandidateBelowDescriptorThreshold(int* self,int requested,int unused,int* countOut,short* output){
    void* object=Combat_FindIndexedMonsterObject((void*)*self,requested);
    if(!object)return 0;
    if(!Combatant_TestTargetCapabilityBit2(object))return 0;
    CandidateIds ids=CombatSelectRandomCandidateBelowDescriptorThreshold_UnknownRoleInitializedBytes;
    int count=Combat_CollectGroupIndicesByDescriptorFlags((char*)*self,ids.values,8,1);
    if(count<=0)return 0;
    *countOut=0;
    for(int i=0;i<count;i++){
        void* combatant=_Z16GetCombatantByIDii(*self,ids.values[i]);
        if(!combatant)continue;
        if(Combatant_TestPrimaryStatusFlagBit9(combatant))continue;
        int level=(*(int*)(*(char**)((char*)combatant+0x138)+0x58)<<8)>>29;
        if(level>=2)continue;
        int outputIndex=*countOut;
        *countOut=outputIndex+1;
        output[outputIndex]=ids.values[i];
    }
    if(*countOut<=0)return 0;
    Combat_SelectRandomCandidateInPlace((void**)self,countOut,output);
    return 1;
}
