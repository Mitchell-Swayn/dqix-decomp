#include <globaldefs.h>
extern "C" unsigned short DebugTextWriteTileString_UnknownRoleZeroInitializedStorage[];
#pragma always_inline on
static inline void WriteRow(int x,unsigned short palette,const char* text,unsigned short* row){
 while(*text){row[x++]=(unsigned short)*text|palette;if(x>=256)return;++text;}
}
// Original: arm9/main @ 0x0202AD4C; symbol: func_0202ad4c; size: 0x4C.
extern "C" ARM void DebugText_WriteTileString(int x,int y,unsigned color,const char* text){WriteRow(x,(unsigned short)(color<<12),text,DebugTextWriteTileString_UnknownRoleZeroInitializedStorage+y*32);}
