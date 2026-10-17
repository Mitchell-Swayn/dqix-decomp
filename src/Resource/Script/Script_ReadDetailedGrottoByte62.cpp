#include <globaldefs.h>
#include "Grotto/Main/ActiveGrottoClass.h"
extern "C" char* ReadGlobalValueAt020FB3F0();extern "C" void SetNestedSecondWordForTypeThree(void*,int);
// Original: arm9/main @ 0x0209D7EC; symbol: func_0209d7ec; size: 0x50.
extern "C" ARM int Script_ReadDetailedGrottoByte62(void* p){ActiveGrottoClass* grotto=(ActiveGrottoClass*)(ReadGlobalValueAt020FB3F0()+0x23ec);if(!grotto)return 0;unsigned char* data=(unsigned char*)grotto->GetDetailedData();if(!data)return 0;if(data[1]!=1)return 0;SetNestedSecondWordForTypeThree(p,data[0x62]);return 1;}
