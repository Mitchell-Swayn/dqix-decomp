#include <globaldefs.h>
ARM
extern "C" unsigned TextContext_GetSharedInstance();
extern "C" void TextContext_SetNumericArgument(unsigned*,int,unsigned);
extern "C" void TextContext_SetNumericArgumentAlignment(char*,int,int);
extern "C" void TextContext_SetNumericArgumentWidth(char*,int,int);
extern "C" void* ResourceStringTable_GetTextByKey(void*,void*);
extern "C" void TextMarkup_ExpandAndWrapText(void*,int,void*,void*,int,int,unsigned);
extern "C" char* strstr(const char*,const char*);
extern "C" int sprintf(char*,const char*,...);
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int GameState_ReadSupportedFirmwareLanguage(void*);
// Original data: arm9/ov023 @ 0x21fd75c; symbol: data_ov023_021fd75c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 01010100.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" int MenuCreateSecondaryPanelHeaderCanvases_UnknownRoleInitializedBytes[];
// Original data: arm9/ov023 @ 0x21fddb4; symbol: data_ov023_021fddb4.
// Source-defined character literal. Text: "%d". Original zero separators, trailing bytes and padding remain unchanged.
// Initial values: "%d".
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" char Resource_SetupTextAndLocalizedNumericFields_TextX[],ResourceSetupTextAndLocalizedNumericFields_TextD[];
// Original: arm9/ov023 @ 0x021E83C8; symbol: func_ov023_021e83c8; size: 0x174.
extern "C" void Resource_SetupTextAndLocalizedNumericFields(char* self) {
 char* state=(char*)TextContext_GetSharedInstance();
 int values[2]={*(unsigned short*)(self+0x60e),*(unsigned char*)(self+0x610)};
 int kinds[2]={MenuCreateSecondaryPanelHeaderCanvases_UnknownRoleInitializedBytes[14],MenuCreateSecondaryPanelHeaderCanvases_UnknownRoleInitializedBytes[15]};
 int* kindArray=kinds;
 for(int i=0;i<2;i++) {
  TextContext_SetNumericArgument((unsigned*)state,i,values[i]);
  TextContext_SetNumericArgumentAlignment(state,i,1);
  TextContext_SetNumericArgumentWidth(state,i,(unsigned char)kindArray[i]);
 }
 void* record=ResourceStringTable_GetTextByKey(self+0x4c,0);
 TextMarkup_ExpandAndWrapText(state,10,record,*(void**)(self+0x5d8),256,0,0);
 int a,b;
 char* first=strstr(*(char**)(self+0x5d8),Resource_SetupTextAndLocalizedNumericFields_TextX);
 char* second=strstr(first+1,Resource_SetupTextAndLocalizedNumericFields_TextX);
 a=130;b=180;
 switch(GameState_ReadSupportedFirmwareLanguage(_ZN9GameState11GetInstanceEv())){
 case 2:case 5:a=165;b=193;break;
 case 3:a=146;b=182;break;
 }
 char buf1[4],buf2[4];
 sprintf(buf1,ResourceSetupTextAndLocalizedNumericFields_TextD,a);
 sprintf(buf2,ResourceSetupTextAndLocalizedNumericFields_TextD,b);
 memcpy(first+3,buf1,3);
 memcpy(second+3,buf2,3);
}
