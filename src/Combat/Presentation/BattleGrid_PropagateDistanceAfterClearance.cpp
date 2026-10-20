#include <globaldefs.h>
ARM
extern "C" int BattleGrid_GetNeighborCells(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov025 @ 0x021E120C; symbol: PropagateStaggeredGridDepthWithDelay.
extern "C" void BattleGrid_PropagateDistanceAfterClearance(unsigned char*grid,int cell,unsigned limit,unsigned char remaining,unsigned char depth){
if(remaining)remaining--;if(!remaining)depth++;struct Local{int cell;unsigned char neighbors[6];unsigned char copied[6];};Local local;local.cell=cell;BattleGrid_GetNeighborCells(local.neighbors,&local.cell);struct Six{unsigned char v[6];};*(Six*)local.copied=*(Six*)local.neighbors;for(int i=0;i<6;i++){unsigned index=local.copied[i];if(index>=81)continue;if(!remaining){int blocked=grid[index]>=242?1:0;if(blocked)continue;}if(depth<limit)BattleGrid_PropagateDistanceAfterClearance(grid,index,limit,remaining,depth);if((depth<grid[index]||grid[index]==0)&&remaining==0&&index<81)grid[index]=depth;}
}
