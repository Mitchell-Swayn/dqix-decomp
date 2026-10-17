#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
int ReadNonnegativeIndexedBit(char *,char *,int);
// Original: arm9/main @ 0x0206EB98; symbol: func_0206eb98; size: 0x30.
int Object_ReadFlagWithHighIdentifierRemapping(char *p,int i){if(i>=0x400)return ReadNonnegativeIndexedBit(p,p+0x8c,i+0x6fa);return ReadNonnegativeIndexedBit(p,p+0x8c,i);}
}
