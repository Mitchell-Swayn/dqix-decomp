#include <globaldefs.h>
extern "C" unsigned char* FindRecordPointerByKey();
// Original: arm9/main @ 0x0205A3AC; symbol: func_0205a3ac; size: 0x24.
extern "C" ARM void SetGlobalObjectLowFlagBitsToOne(){unsigned char* object=FindRecordPointerByKey();if(object){object[21]&=~7;object[21]|=1;}}
