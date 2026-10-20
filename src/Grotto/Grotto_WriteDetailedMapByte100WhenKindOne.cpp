#include <globaldefs.h>
ARM
#include <Grotto/Main/ActiveGrottoClass.h>
extern "C" char* Zone3D_GetMainInstance();extern "C" void Script_WriteIntegerReferenceOutput(void*,int);
// Original: arm9/main @ 0x0209DBFC; symbol: func_0209dbfc; size: 0x50.
extern "C" int Grotto_WriteDetailedMapByte100WhenKindOne(void* p){ActiveGrottoClass* grotto=(ActiveGrottoClass*)(Zone3D_GetMainInstance()+0x23ec);if(!grotto)return 0;DetailedTreasureMapData* q=grotto->GetDetailedData();if(!q)return 0;unsigned char* data=(unsigned char*)q;if(data[1]!=1)return 0;Script_WriteIntegerReferenceOutput(p,data[100]);return 1;}
