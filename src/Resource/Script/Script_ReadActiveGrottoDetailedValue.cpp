#include <globaldefs.h>
#include <Grotto/Main/ActiveGrottoClass.h>
extern "C" int ReadGlobalValueAt020FB3F0(void);
extern "C" void SetNestedSecondWordForTypeThree(void*, int);
// Original: arm9/main @ 0x0209DBAC; symbol: func_0209dbac; size: 0x50.
extern "C" int Script_ReadActiveGrottoDetailedValue(void* parameter) {
    char* zone=(char*)ReadGlobalValueAt020FB3F0();
    ActiveGrottoClass* active=(ActiveGrottoClass*)(zone+0x23EC);
    if(active==0) return 0;
    DetailedTreasureMapData* data=active->GetDetailedData();
    if(data==0) return 0;
    if(*((unsigned char*)data+1)!=1) return 0;
    SetNestedSecondWordForTypeThree(parameter, *((unsigned char*)data+0x50));
    return 1;
}
