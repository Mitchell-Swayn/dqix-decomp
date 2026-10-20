#include <globaldefs.h>
ARM
extern "C" unsigned GameObject_GetBattleGridIndexOrInvalid(void*);
extern "C" unsigned CombatantMotion_GetReservedGridCell(void*);
extern "C" void BattleGrid_PaintFootprintAfterClearance(void*,int,unsigned,unsigned,int,int);
// Original: arm9/ov025 @ 0x021E13E0; symbol: Combat_MapIndirectComponentIndicesToRecordValue; size: 0xa0.
// Maps both indirect component indices below81 to record byte1 and propagates descriptor mode bits.
extern "C" void Combat_MapIndirectComponentIndicesToRecordValue(unsigned char* self,unsigned char* record) {
 if(!record||!*(void**)(record+8))return;
 unsigned a=GameObject_GetBattleGridIndexOrInvalid(*(void**)(record+8));if(a<81){unsigned value=record[1];if(a<81)self[a]=value;}
 unsigned b=CombatantMotion_GetReservedGridCell(*(void**)(record+8));if(b<81){unsigned value=record[1];if(b<81)self[b]=value;}
 char* object=*(char**)(record+8);if(!(*(unsigned short*)object&0x400))return;char* descriptor=*(char**)(object+0x148);if(!descriptor)return;
 unsigned mode=(*(unsigned*)(descriptor+16)<<1)>>30;if(!mode)return;
 BattleGrid_PaintFootprintAfterClearance(self,b,record[1],mode&255,0,0);
}
