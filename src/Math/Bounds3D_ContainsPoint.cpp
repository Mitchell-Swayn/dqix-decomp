#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original: arm9/main @ 0x02031118; symbol: func_02031118; size: 0x70.
bool Bounds3D_ContainsPoint(int *p,int *q){int x=p[0];if(q[0]<x)return false;int y=p[1];if(q[1]<y)return false;int z=p[2];if(q[2]<z)return false;if(x<q[3])return false;if(y<q[4])return false;return z>=q[5];}
}
