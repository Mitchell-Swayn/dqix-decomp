#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" int TestActiveInputAndSelectionFlags(void*,int);extern "C" int ReadIndexFromEnabledPrimaryOrSecondarySelection(void*);
// Original: arm9/main @ 0x0205CECC; symbol: func_0205cecc; size: 0x2C.
extern "C" int Object_ReadSelectionResultWhenGridReady(unsigned char* p){if(!TestActiveInputAndSelectionFlags(p+32,1))return -1;return ReadIndexFromEnabledPrimaryOrSecondarySelection(p+28);}
