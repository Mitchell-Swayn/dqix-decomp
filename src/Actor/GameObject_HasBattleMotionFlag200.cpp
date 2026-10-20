#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original: arm9/main @ 0x02048C10; symbol: func_02048c10; size: 0x28.
bool GameObject_HasBattleMotionFlag200(unsigned int **p){unsigned int *v=p[0x4f];if(v)return (v[8]&0x200)!=0;return false;}
}
