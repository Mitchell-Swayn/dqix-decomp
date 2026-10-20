#include <globaldefs.h>
ARM
extern "C" int Graphics_CopyIndexedScreenRectangle(...);
extern "C" int GameState_ReadSupportedFirmwareLanguage(...);
extern "C" int Graphics_UpdateBoundedSixteenByteEntry(...);
extern "C" int MenuLayerRecord_GetLayerTransferState(...);
extern "C" int MenuRecord_GetType(...);
extern "C" int Graphics_CleanAndTransferScreenBuffer(...);
extern "C" int _ZN9GameState11GetInstanceEv(...);
extern "C" int Menu_GetDisplayRecordRegistry(...);
extern "C" int MenuRecordList_LocateByKey(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov004 @ 0x02155FA0; symbol: ConfigureLocalizedCanvasRecord12.
extern "C" int Menu_LocalizeAlternateCatalogueCategoryCanvas(char*self){
int language=GameState_ReadSupportedFirmwareLanguage(_ZN9GameState11GetInstanceEv());unsigned index=1;switch(language){case 0:case 1:break;case 2:index=2;break;case 4:index=3;break;case 3:index=4;break;case 5:index=5;break;}char*record=C(MenuRecordList_LocateByKey(Menu_GetDisplayRecordRegistry(self),12));if(!record)return 0;if(MenuRecord_GetType(record)!=2)return 0;B(record,12)|=1;char*canvas=C(MenuLayerRecord_GetLayerTransferState(record));Graphics_UpdateBoundedSixteenByteEntry(canvas,1,0,0,65535);if(index>1)Graphics_CopyIndexedScreenRectangle(canvas,index,0,0,22,2,9,2,65535);Graphics_CleanAndTransferScreenBuffer(canvas,0);return 0;
}
