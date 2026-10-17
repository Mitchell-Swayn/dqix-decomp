#include <globaldefs.h>
ARM
extern "C" unsigned ResolveOptionalRelativePointer(unsigned,unsigned,int);
// Original: arm9/main @ 0x02097248; symbol: func_02097248; size: 0x38.
extern "C" int Object_ResolveTwoResourceValues(unsigned object,unsigned* values){values[1]=ResolveOptionalRelativePointer(object,values[1],0);values[2]=ResolveOptionalRelativePointer(object,values[2],0);return 1;}
