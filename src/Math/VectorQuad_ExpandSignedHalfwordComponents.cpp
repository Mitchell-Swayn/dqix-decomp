#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
void VectorQuad_WriteThreeWordComponents(void *,int,int,int);
// Original: arm9/main @ 0x02031188; symbol: func_02031188; size: 0x60.
void VectorQuad_ExpandSignedHalfwordComponents(char *p,short *q){VectorQuad_WriteThreeWordComponents(p+36,q[9],q[10],q[11]);VectorQuad_WriteThreeWordComponents(p,q[0],q[1],q[2]);VectorQuad_WriteThreeWordComponents(p+12,q[3],q[4],q[5]);VectorQuad_WriteThreeWordComponents(p+24,q[6],q[7],q[8]);}
}
