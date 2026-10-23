#include <globaldefs.h>
ARM
#include <std_library_functions.h>
#define I(p,o) (*(int*)((p)+(o)))
#define U(p,o) (*(unsigned*)((p)+(o)))
#define H(p,o) (*(unsigned short*)((p)+(o)))
#define S(p,o) (*(short*)((p)+(o)))
#define B(p,o) (*(unsigned char*)((p)+(o)))
#define C(p,o) (*(signed char*)((p)+(o)))
#define V(p,o) (*(char**)((p)+(o)))
#pragma always_inline on
struct CombatSelectionContext;struct CombatSelectionAction;
extern "C" int Combat_CollectEligiblePartyIds(void*,short*,int,int);inline int IsParty(int i){return i>=0&&i<=3;}
// Original: arm9/ov000 @ 0x02181B4C; symbol: Combat_CollectUniqueSecondaryRecordTargets; size: 0x120.
extern "C" int Combat_CollectUniqueSecondaryRecordTargets(CombatSelectionContext* context,CombatSelectionAction* action,int* output){
char* owner=(char*)action;int count=0;for(char* record=V(owner,20);record;record=V(record,32)){for(int i=0;i<B(record,23);++i){if(i>0){int kind=B(record+i,20);if(kind!=8&&kind!=6&&kind!=7)break;}int id=S(record+i*2,14);int unique=1;int* end=output;for(int j=0;j<count;){if(*end==id){unique=0;break;}++j;++end;}if(unique){if(IsParty(id)){short party[4];count=Combat_CollectEligiblePartyIds(context,party,4,0);end=output;short* source=party;for(int j=0;j<count;++j){*end=*source;++source;++end;}return count;}*end=id;++count;}}}return count;
}
