#include <globaldefs.h>
struct Position{short x,y;char pad[8];void* pointer;};extern "C" void TileMap_SetRectanglePaletteIndex(Position*,int,int,int,int,int);
// Original: arm9/main @ 0x0204AE44; symbol: func_0204ae44; size: 0x38.
extern "C" ARM void Tilemap_SetWholeMapPalette(Position* p,int mode){if(p->pointer)TileMap_SetRectanglePaletteIndex(p,mode,0,0,p->x,p->y);}
