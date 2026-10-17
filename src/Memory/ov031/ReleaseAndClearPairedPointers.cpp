#include <globaldefs.h>
ARM
#pragma always_inline on
#pragma optimization_level 4
struct Pair { void* first; void* second; };
typedef void (*Cleanup)(void*,void*,void*);
extern "C" {extern char data_ov031_02249fd8[];extern char data_ov031_02249ff4[];}
// Original: arm9/ov031 @ 0x02218F18; symbol: func_ov031_02218f18; size: 0x88.
extern "C" void ReleaseAndClearPairedPointers(char* p,Pair* entries,int count){
Cleanup callback=*(Cleanup*)(p+0x1014);
int i=0;if(i<count){
void* firstContext=data_ov031_02249fd8;void* secondContext=data_ov031_02249ff4;
do{
if(entries[i].first){callback(firstContext,entries[i].first,0);entries[i].first=0;}
if(entries[i].second){callback(secondContext,entries[i].second,0);entries[i].second=0;}
++i;}while(i<count); }
}
