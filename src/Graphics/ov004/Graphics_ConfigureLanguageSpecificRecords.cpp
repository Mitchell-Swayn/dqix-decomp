#include <globaldefs.h>
ARM
extern "C" {
void* _ZN9GameState11GetInstanceEv();
int GameState_ReadSupportedFirmwareLanguage(void*);
void UpdateProvidedOrStoredChildResource(char*,void*);
void DispatchIndexedRecordWithCoordinates(void*,unsigned,unsigned,unsigned,short,short,short,short,unsigned short);
void Graphics_UpdateBoundedSixteenByteEntry(void*,unsigned,unsigned,unsigned,unsigned short);
void* func_ov011_021849c8(void*);
unsigned char* func_ov023_021f6880(void*,unsigned short);
unsigned OV023_ReadHalfwordField04(void*);
char* OV023_GetEmbeddedField28(void*);
void func_ov023_021fb25c(void*,unsigned,unsigned,unsigned,unsigned);
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
 unsigned char* record=func_ov023_021f6880(func_ov011_021849c8(p),3);
 if(!record) return 0;
 if(OV023_ReadHalfwordField04(record)!=2) return 0;
 record[0xc]|=1;
 char* child=OV023_GetEmbeddedField28(record);
 Graphics_UpdateBoundedSixteenByteEntry(child,0,0,0,0xffff);
 if(index) DispatchIndexedRecordWithCoordinates(child,index,0,0,22,2,9,3,0xffff);
 UpdateProvidedOrStoredChildResource(child,0);
 record=func_ov023_021f6880(func_ov011_021849c8(p),0x1f8);
 if(record && OV023_ReadHalfwordField04(record)==1) {
  if(!record) return 0;
  func_ov023_021fb25c(record,0,0,width,17);
 }
 return 0;
}
