#include <globaldefs.h>
ARM
extern "C" char* FindLowestEligibleIdAboveThreshold(void*,int);
// Original: arm9/main @ 0x020721F8; symbol: func_020721f8; size: 0x40.
extern "C" void LinkedList_ResolveHalfwordLinksToPointers(char** p){*p=FindLowestEligibleIdAboveThreshold(p,-1);char* q=*p;if(!q)return;while(q){char* next=FindLowestEligibleIdAboveThreshold(p,*(short*)(q+26));*(char**)(q+28)=next;q=next;}}
