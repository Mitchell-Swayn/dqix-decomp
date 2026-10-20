#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original: arm9/main @ 0x020863E0; symbol: func_020863e0; size: 0x24.
void CharacterState_ClampHealthAndMagicToMaximum(unsigned short *p){if(p[54]<p[14])p[14]=p[54];if(p[55]<p[15])p[15]=p[55];}
}
