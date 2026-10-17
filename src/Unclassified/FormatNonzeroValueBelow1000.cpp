#pragma optimize_for_size off
#include <globaldefs.h>
ARM
#include "std_library_functions.h"
extern "C" const char data_020ef6d0[];
struct Object { unsigned char pad[0x6ec]; char text[0x7a]; unsigned short value; };
// Original: arm9/main @ 0x0202656C; symbol: func_0202656c; size: 0x3C.
extern "C" void FormatNonzeroValueBelow1000(Object* object,unsigned value) {object->value=value;if(object->value==0)return;if(object->value>=1000)return;sprintf(object->text,data_020ef6d0,value);}
