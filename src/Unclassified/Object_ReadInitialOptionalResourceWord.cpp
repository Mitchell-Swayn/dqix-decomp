#include <globaldefs.h>
extern "C" {unsigned int *ReadSignedWordAtOffset4();
// Original: arm9/main @ 0x02055090; symbol: func_02055090; size: 0x18.
unsigned int Object_ReadInitialOptionalResourceWord(){unsigned int *p=ReadSignedWordAtOffset4();return p==0?0:*p;}}
