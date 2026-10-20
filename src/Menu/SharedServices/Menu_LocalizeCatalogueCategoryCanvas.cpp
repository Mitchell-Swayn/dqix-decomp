#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
extern "C" {void* _ZN9GameState11GetInstanceEv();int GameState_ReadSupportedFirmwareLanguage(void*);void* Menu_GetDisplayRecordRegistry(void*);unsigned char* MenuRecordList_LocateByKey(void**,unsigned short);unsigned MenuRecord_GetType(void*);char* MenuLayerRecord_GetLayerTransferState(void*);void Graphics_UpdateBoundedSixteenByteEntry(void*,unsigned,unsigned,unsigned,unsigned short);void Graphics_CopyIndexedScreenRectangle(void*,unsigned,unsigned,unsigned,short,short,short,short,unsigned short);void Graphics_CleanAndTransferScreenBuffer(char*,void*);}
// Original: arm9/ov004 @0x02154f1c; symbol:Graphics_ConfigureLanguageSpecificIndexedRecord; size:0x110.
// Maps supported firmware language to indexed child record and configures bounded entry coordinates.
extern "C" int Menu_LocalizeCatalogueCategoryCanvas(void* self){unsigned language=GameState_ReadSupportedFirmwareLanguage(_ZN9GameState11GetInstanceEv());unsigned index=1;switch(language){case 2:index=2;break;case 4:index=3;break;case 3:index=4;break;case 5:index=5;break;}unsigned char* record=MenuRecordList_LocateByKey((void**)Menu_GetDisplayRecordRegistry(self),12);if(!record)return 0;if(MenuRecord_GetType(record)!=2)return 0;record[12]|=1;char* owner=MenuLayerRecord_GetLayerTransferState(record);Graphics_UpdateBoundedSixteenByteEntry(owner,1,0,0,65535);if(index>1)Graphics_CopyIndexedScreenRectangle(owner,index,0,0,22,2,9,2,65535);Graphics_CleanAndTransferScreenBuffer(owner,0);return 0;}
