#include <globaldefs.h>
extern "C" {
ARM void* ReadGlobalValueAt02108D5C(); void SetRecordRGBColorScaleAndEnabledState(void*,void*,int,int,int); void DispatchStoredHalfwordIndexWithTwoArguments(void*,int,int); extern unsigned char data_02108760[];
// Original: arm9/main @ 0x0208AD1C; symbol: func_0208ad1c; size: 0x4C.
 void Object_ApplyGlobalRecordAndPlayEffect120(unsigned char* self) { void* value=ReadGlobalValueAt02108D5C(); if(value) { SetRecordRGBColorScaleAndEnabledState(value,self+12,20,5,15); DispatchStoredHalfwordIndexWithTwoArguments(data_02108760,120,0); } }
}
