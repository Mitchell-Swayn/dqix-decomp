#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
unsigned int *ReadSignedWordAtOffset4();
// Original: arm9/main @ 0x02055120; symbol: func_02055120; size: 0x18.
unsigned int Object_ReadOptionalResourceWord18(){unsigned int *p=ReadSignedWordAtOffset4();unsigned int v;if(p==0)v=0;else v=p[6];return v;}
}
