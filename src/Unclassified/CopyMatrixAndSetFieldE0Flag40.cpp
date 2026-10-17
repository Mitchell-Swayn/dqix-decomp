#include <globaldefs.h>
ARM
#pragma always_inline on
struct Words9 { unsigned words[9]; }; struct Words3 { unsigned words[3]; };
struct Matrix { Words9 rotation; Words3 translation; };
// Original: arm9/main @ 0x02033EDC; symbol: func_02033edc; size: 0x50.
extern "C" void CopyMatrixAndSetFieldE0Flag40(char *self,const Matrix *matrix) { ((unsigned char *)self)[0xe0]|=64; *(Words9 *)(self+0xe4)=matrix->rotation; *(Words3 *)(self+0x108)=matrix->translation; }
