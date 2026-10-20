#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
extern "C" {unsigned CombatantMotion_GetPlannedGridCell(char*);unsigned GameObject_GetBattleGridIndexOrInvalid(unsigned char*);unsigned CombatantMotion_GetReservedGridCell(unsigned char*);void BattleGrid_PaintFootprintAfterClearance(void*,unsigned,unsigned,unsigned,int,int);}
// Original: arm9/ov025 @ 0x021E110C; symbol: Combat_MapLinkedComponentBytesToEntryKinds; size: 0x100.
// Maps three linked component identifiers and optional two-bit modes into81-entry kind table.
extern "C" void BattleGrid_BuildCombatantOccupancyMap(unsigned char* output,unsigned char* entries,int count){for(int i=0;i<81;++i)if(output[i]<255)output[i]=0;unsigned char* objectBase=entries+8;for(int i=0;i<count;++i){int offset=i*12;unsigned index=CombatantMotion_GetPlannedGridCell((char*)P(objectBase,offset));if(index>=81)index=GameObject_GetBattleGridIndexOrInvalid(P(objectBase,offset));if(index<81){unsigned value=(entries+offset)[1];if(index<81)output[index]=value;}unsigned char* object=P(objectBase,offset);if((U(object,0)&0x400)&&P(object,0x148)){unsigned kind=((unsigned)W(P(object,0x148),16)<<1)>>30;if(kind)BattleGrid_PaintFootprintAfterClearance(output,index,(entries+offset)[1],(unsigned char)kind,0,0);}index=CombatantMotion_GetReservedGridCell(P(objectBase,offset));if(index<81){unsigned value=(entries+offset)[1];if(index<81)output[index]=value;}}}
