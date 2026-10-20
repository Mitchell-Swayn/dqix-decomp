#include <globaldefs.h>
ARM
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
struct Nibble{unsigned char lower:4,upper:4;};
extern "C" unsigned Network_SelectFallbackSsidScanPhase(...);
extern "C" unsigned Resource_RebuildPriorityStateByMode(...);
extern "C" unsigned Network_StartAccessPointSearchPhase(...);
extern "C" unsigned Network_StartSecondAccessPointSearchPass(...);
// Original: arm9/ov031:02214fc8
extern "C" int Network_AdvanceAndPublishAccessPointScanPhase(unsigned char* p,int state){switch(state){case 3:if(B(p,0xd12)||H(p,0xd16)){if(Resource_RebuildPriorityStateByMode(1))state=4;else state=Network_SelectFallbackSsidScanPhase(p);}else{if(((Nibble*)(p+0xd0b))->upper>=1)state=6;else state=Network_StartSecondAccessPointSearchPass(p);}break;case 4:state=Network_SelectFallbackSsidScanPhase(p);break;case 5:if(((Nibble*)(p+0xd0b))->upper>=1)state=6;else state=Network_StartSecondAccessPointSearchPass(p);break;}Network_StartAccessPointSearchPhase(state);return state;}
