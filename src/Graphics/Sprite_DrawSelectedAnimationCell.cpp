#include <globaldefs.h>
ARM
struct State{int pad[9];int** table;int pad28[13];unsigned short enabled;short pad5e;int x,y;};extern "C" {int Sprite_BuildCellOamAttributes(State*,int,int,int);
// Original: arm9/main @ 0x02075DB0; symbol: func_02075db0; size: 0x44.
int Sprite_DrawSelectedAnimationCell(State* p,int a,int b){if(!p->enabled)return 0;if(!p->table)return 0;return Sprite_BuildCellOamAttributes(p,p->table[p->y][p->x],a,b);}}
