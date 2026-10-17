#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
extern int data_021015a0[];void SetGlobalValueExceptModesNineAndTen(int);
// Original: arm9/main @ 0x0202D5EC; symbol: func_0202d5ec; size: 0x28.
void SetInitialStateOrReportMessageError(unsigned short *p){unsigned int v=p[1];if(!v){data_021015a0[4]=1;return;}SetGlobalValueExceptModesNineAndTen(v);}
}
