#pragma optimize_for_size off
#include <globaldefs.h>
extern "C" unsigned char* FindRecordPointerByKey();
// Original: arm9/main @ 0x0205A370; symbol: func_0205a370; size: 0x3C.
extern "C" ARM void Object_ResetSelectedEntryCoordinatesAndFlags(){unsigned char* object=FindRecordPointerByKey();if(!object)return;if(object[21]&1){*(unsigned short*)(object+16)=0;*(unsigned short*)(object+18)=0;}object[21]&=~7;object[21]|=2;}
