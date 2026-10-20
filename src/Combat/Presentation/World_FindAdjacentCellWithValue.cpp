#include <globaldefs.h>
ARM
extern "C" void BattleGrid_GetNeighborCells(unsigned char*,int*);
// Original: arm9/ov025 @ 0x021E161C; symbol: func_ov025_021e161c; size: 0x80.
extern "C" int World_FindAdjacentCellWithValue(int cell,int unused,unsigned char* values,int value) {
struct Cells { unsigned char entries[6]; };
Cells copy, neighbors;
BattleGrid_GetNeighborCells(neighbors.entries,&cell);
copy=neighbors;
for(int i=0;i<6;i++){if(copy.entries[i]!=255 && values[copy.entries[i]]==value)return copy.entries[i];}
return cell;
}
