#include <globaldefs.h>
ARM
extern "C" {
void TextCanvas_ShowDisplayPart(unsigned char*,int);
void TextCanvas_SetGroupPalette(char*,int,unsigned char);
void TextCanvas_HideGroupEntries(char*,int);
void TextCanvas_DisableGroupEntryNavigation(unsigned char*,int);
void TextCanvas_SetGroupBottomCornerSymbolsEnabled(char*,int,int);
unsigned short* ZoneState2754_FindPrimaryRecordByKey(void*,int);
unsigned Shop_GetAdjustedItemPrice(char*,unsigned short*);
void TextCanvas_SetEntryHorizontalOffset(unsigned char*,int,int);
void TextCanvas_ShowEntry(unsigned char*,int);
void Graphics_ConfigureSelectedPartModes(char*,void*,int,int);
void TextCanvas_EnableEntryUppercaseFormatting(unsigned char*,int);
void TextCanvas_SetEntryTextPointer(char*,int,int);
void TextCanvas_SetEntryNumericValue(char*,int,int);
void TextCanvas_EnableEntryNavigation(unsigned char*,int);
int TextCanvas_CreateAndConfigureDisplayPart(char*,int);
}
// Original: arm9/ov003 @ 0x021767EC; symbol: func_ov003_021767ec; size: 0x200.
extern "C" void Graphics_UpdateSixEntryPageDisplay(char* self) {
 unsigned char* display=*(unsigned char**)(self+0x89c);
 short key=7,scaledKey=13,modeKey=19;
 TextCanvas_ShowDisplayPart(display,3);
 TextCanvas_SetGroupPalette((char*)display,3,0);
 TextCanvas_HideGroupEntries((char*)display,3);
 TextCanvas_DisableGroupEntryNavigation(display,3);
 TextCanvas_SetGroupBottomCornerSymbolsEnabled((char*)display,3,(*(unsigned short*)(self+0x1046)&0x400)!=0);
 unsigned char start=*(short*)(self+0x1014)*6;
 unsigned char end=start+6;
 for(unsigned char index=start;index<end;key++,scaledKey++,modeKey++,index++) {
  unsigned word=0;
  unsigned scaled=0;
  if(index<*(unsigned char*)(self+0x835)) {
   unsigned short* record=ZoneState2754_FindPrimaryRecordByKey(self+0x874,*(short*)(self+0x848+index*2));
   if(record) {
    word=*(unsigned*)(record+2);
    scaled=Shop_GetAdjustedItemPrice(self,record);
    TextCanvas_SetEntryHorizontalOffset(display,key,13);
    TextCanvas_ShowEntry(display,key);
    TextCanvas_ShowEntry(display,scaledKey);
    TextCanvas_ShowEntry(display,modeKey);
    Graphics_ConfigureSelectedPartModes(self,record,scaledKey,modeKey);
   }
   TextCanvas_EnableEntryUppercaseFormatting(display,key);
   TextCanvas_SetEntryTextPointer((char*)display,key,word);
   TextCanvas_SetEntryNumericValue((char*)display,scaledKey,scaled);
   TextCanvas_EnableEntryNavigation(display,key);
  }
 }
 TextCanvas_ShowEntry(display,25);
 TextCanvas_ShowEntry(display,26);
 TextCanvas_ShowEntry(display,27);
 TextCanvas_SetEntryNumericValue((char*)display,25,*(short*)(self+0x1014)+1);
 TextCanvas_SetEntryNumericValue((char*)display,26,*(short*)(self+0x1016));
 TextCanvas_CreateAndConfigureDisplayPart((char*)display,3);
}
