#include <globaldefs.h>
ARM
extern "C" {void* __clear(void*,unsigned);unsigned GameObject_GetBattleGridIndexOrInvalid(unsigned char*);void CombatantMotion_SetPlannedGridCell(int,unsigned char);void BattleGrid_GetNeighborCells(unsigned char*,int*);void Combat_MapIndirectComponentIndicesToRecordValue(unsigned char*,unsigned char*);void BattleGrid_ClearCombatantOccupancy(unsigned char*,unsigned char);}
struct SixNeighbors {unsigned char v[6];};
#define IsBlocked(v) ((v)>=0xf2?1:0)
// Original: arm9/ov025 @ 0x021E1D54; symbol: func_ov025_021e1d54; size: 0x1B4.
// Scores adjacent grid cells by available neighbors and updates the indirect component position.
extern "C" void SelectGridCellWithMoreAvailableNeighbors(unsigned char* record,unsigned char* grid) {
 SixNeighbors adjacent,counts,other,built;
 int cell=GameObject_GetBattleGridIndexOrInvalid(*(unsigned char**)(record+8));
 BattleGrid_GetNeighborCells(built.v,&cell);adjacent=built;
 unsigned char available=0;
 for(int i=0;i<6;i++)if(adjacent.v[i]!=255 && !IsBlocked(grid[adjacent.v[i]]))available++;
 if(!*(int*)(record+4) && available>=4)return;
 __clear(counts.v,6);
 int bestCount=0,bestCell=255;
 for(int i=0;i<6;i++) {
 if(adjacent.v[i]==255)continue;
 SixNeighbors builtOther;int neighbor=adjacent.v[i];BattleGrid_GetNeighborCells(builtOther.v,&neighbor);other=builtOther;
 for(int j=0;j<6;j++)if(other.v[j]!=255 && !IsBlocked(grid[other.v[j]])) {
 counts.v[i]++;
 if(bestCount<counts.v[i]){bestCount=counts.v[i];bestCell=other.v[j];}
 }
 }
 if(bestCell<81 && (available<bestCount || *(int*)(record+4))) {
 BattleGrid_ClearCombatantOccupancy(grid,record[1]);
 if(bestCell<81)Combat_MapIndirectComponentIndicesToRecordValue(grid,record);
 CombatantMotion_SetPlannedGridCell(*(int*)(record+8),(unsigned char)bestCell);
 }
}
