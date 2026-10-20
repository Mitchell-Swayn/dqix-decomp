#include <globaldefs.h>
ARM
extern "C" {int WorldMap_IsTreasureMarkerEligible(void*,int);
// Original: arm9/main @ 0x02026A78; symbol: func_02026a78; size: 0x44.
unsigned char WorldMap_CountEligibleChestMarkers(unsigned char* p){unsigned char count=0;for(int i=0;i<p[0x780];i++)if(WorldMap_IsTreasureMarkerEligible(p,i))count++;return count;}}
