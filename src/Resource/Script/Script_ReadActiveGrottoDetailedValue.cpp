#include <globaldefs.h>
#include <Grotto/Main/ActiveGrottoClass.h>
extern "C" int Zone3D_GetMainInstance(void);
extern "C" void Script_WriteIntegerReferenceOutput(void*, int);
// Original: arm9/main @ 0x0209DBAC; symbol: func_0209dbac; size: 0x50.
extern "C" int Script_ReadActiveGrottoDetailedValue(void* parameter) {
    char* zone=(char*)Zone3D_GetMainInstance();
    ActiveGrottoClass* active=(ActiveGrottoClass*)(zone+0x23EC);
    if(active==0) return 0;
    DetailedTreasureMapData* data=active->GetDetailedData();
    if(data==0) return 0;
    if(*((unsigned char*)data+1)!=1) return 0;
    Script_WriteIntegerReferenceOutput(parameter, *((unsigned char*)data+0x50));
    return 1;
}
