#include <globaldefs.h>
ARM
extern "C" void WriteAngleAndUpdateThreeAngleFields(void*,int);
// Original: arm9/main @ 0x0202E784; symbol: func_0202e784; size: 0x50.
extern "C" void AddAndWrapAngleBy25736(char* p,int n){n+=*(int*)(p+112);if((float)n<0.0f)n+=25736;int wrap=25736;if(n>wrap){wrap=-wrap;n+=wrap;}WriteAngleAndUpdateThreeAngleFields(p,n);}
