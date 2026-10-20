#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
int BitArray_ReadNonnegativeIndexMask(char *,char *,int);
// Original: arm9/main @ 0x0206EB98; symbol: func_0206eb98; size: 0x30.
int Script_GetRemappedProgressFlagMask(char *p,int i){if(i>=0x400)return BitArray_ReadNonnegativeIndexMask(p,p+0x8c,i+0x6fa);return BitArray_ReadNonnegativeIndexMask(p,p+0x8c,i);}
}
