#include <globaldefs.h>
ARM
extern "C" int Combat_GetLatestTargetFromHistory(char* p);
// Original: arm9/ov000 @ 0x02162908; symbol: CopyLinkedRecordValues; size: 0x4C.
// Walks the indexed linked records, writes each clamped halfword value to the output array, and returns the count.
extern "C" unsigned CombatScene_CollectCommandFinalTargets(char* self,unsigned index,int* output) {
 char* node=*(char**)(self+0x29C)+0x821C+index*0x28;
 node=*(char**)(node+0x14);
 unsigned count=0;
 while(node){output[count++]=Combat_GetLatestTargetFromHistory(node); node=*(char**)(node+0x20);}
 return count;
}
