#include <globaldefs.h>
ARM
extern "C" {
void* _ZN9GameState11GetInstanceEv();
int GameState_ReadSupportedFirmwareLanguage(void*);
void Graphics_CleanAndTransferScreenBuffer(char*,void*);
void Graphics_CopyIndexedScreenRectangle(void*,unsigned,unsigned,unsigned,short,short,short,short,unsigned short);
void Graphics_UpdateBoundedSixteenByteEntry(void*,unsigned,unsigned,unsigned,unsigned short);
void* Menu_GetDisplayRecordRegistry(void*);
unsigned char* MenuRecordList_LocateByKey(void*,unsigned short);
unsigned MenuRecord_GetType(void*);
char* MenuLayerRecord_GetLayerTransferState(void*);
void Menu_SetSpriteCellTouchRectangle(void*,unsigned,unsigned,unsigned,unsigned);
}
// Original: arm9/ov004 @ 0x02165C04; symbol: func_ov004_02165c04; size: 0x170.
extern "C" int Graphics_ConfigureLanguageSpecificRecords(void* p) {
 int language=GameState_ReadSupportedFirmwareLanguage(_ZN9GameState11GetInstanceEv());
 int width=74;
 int index=0;
 switch(language) {
  case 2: index=1; width=90; break;
  case 4: index=2; width=128; break;
  case 3: index=3; break;
  case 5: index=4; width=120; break;
 }
 unsigned char* record=MenuRecordList_LocateByKey(Menu_GetDisplayRecordRegistry(p),3);
 if(!record) return 0;
 if(MenuRecord_GetType(record)!=2) return 0;
 record[0xc]|=1;
 char* child=MenuLayerRecord_GetLayerTransferState(record);
 Graphics_UpdateBoundedSixteenByteEntry(child,0,0,0,0xffff);
 if(index) Graphics_CopyIndexedScreenRectangle(child,index,0,0,22,2,9,3,0xffff);
 Graphics_CleanAndTransferScreenBuffer(child,0);
 record=MenuRecordList_LocateByKey(Menu_GetDisplayRecordRegistry(p),0x1f8);
 if(record && MenuRecord_GetType(record)==1) {
  if(!record) return 0;
  Menu_SetSpriteCellTouchRectangle(record,0,0,width,17);
 }
 return 0;
}
