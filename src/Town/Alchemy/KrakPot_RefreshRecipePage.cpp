#include <globaldefs.h>
ARM
struct Node { unsigned char pad[0x1c]; Node* next; };
struct Record { short key; unsigned short flags; };
struct Table { char pad[0x20]; Record* volatile records; unsigned short count; };
extern "C" {
void* memset(void*,int,unsigned);
void TextCanvas_EnableEntryUppercaseFormatting(unsigned char*,int);
void TextCanvas_EnableGroupEntryNavigation(unsigned char*,int);
void TextCanvas_DisableEntryNavigation(unsigned char*,int);
void TextCanvas_HideEntry(unsigned char*,int);
void TextCanvas_ShowGroupEntries(unsigned char*,int);
void TextCanvas_SetGroupPalette(char*,int,unsigned char);
void TextCanvas_SetEntryTextColor(char*,int,unsigned);
void TextCanvas_SetEntryTextPointer(char*,int,int);
void TextCanvas_SetEntryNumericValue(char*,int,int);
void TextCanvas_SetGroupBottomCornerSymbolsEnabled(char*,int,int);
int TextCanvas_CreateAndConfigureDisplayPart(char*,int);
void TextCanvas_SetDisplayPartRefreshFlag(void*,int,int);
void* ResourceStringTable_GetTextByKey(void*,void*);
void String_ReplaceBracketedNamesByRowColumnTable(const signed char*,signed char*,int,unsigned,unsigned,int);
void* Text_LookupNameTableEntry(void*,int);
Record* FindNonnegativeHalfwordKeyInPackedTable(Table*,int);
Node* KrakPot_GetRecipePageHead(unsigned char*,int);
}
// Original: arm9/ov006 @ 0x0215F7E8; symbol: func_ov006_0215f7e8; size: 0x200.
// Configures sixteen linked-list name parts and their page indicators.
extern "C" void KrakPot_RefreshRecipePage(unsigned char* self) {
 *(Node**)(self+0x30)=KrakPot_GetRecipePageHead(self,self[0x388]);
 if(*(Node**)(self+0x30)) {
  *(unsigned short*)(self+0x394)&=~4;
  if(self[0x389]>1) *(unsigned short*)(self+0x394)|=4;
  unsigned char* display=*(unsigned char**)(self+0x14);
  TextCanvas_ShowGroupEntries(display,9);TextCanvas_EnableGroupEntryNavigation(display,9);
  TextCanvas_SetEntryNumericValue((char*)display,0x3a,self[0x388]+1);
  TextCanvas_SetEntryNumericValue((char*)display,0x3b,self[0x389]);
  unsigned char* entry=*(unsigned char**)(self+0x30);
  int defaultName=(int)ResourceStringTable_GetTextByKey(self+0x158,(void*)0x25);
  short key=0x29;
  for(unsigned char i=0;i<16;++key,++i) {
   if(entry) {
    TextCanvas_SetEntryTextPointer((char*)display,key,defaultName);
    TextCanvas_SetEntryTextColor((char*)display,key,3);
    unsigned char* packed=(unsigned char*)FindNonnegativeHalfwordKeyInPackedTable((Table*)(self+0x74),*(short*)entry);
    if(packed) {
     int name=defaultName;
     if((((unsigned)*(unsigned short*)(packed+2)<<30)>>31)!=0) {
      unsigned char* string=(unsigned char*)Text_LookupNameTableEntry(self+0x170,*(short*)(entry+2));
      if(string) {
       memset((*(void***)(self+4))[i],0,4);
       String_ReplaceBracketedNamesByRowColumnTable(*(signed char**)string,(*(signed char***)(self+4))[i],1,0,0,0);
       name=(int)(*(void***)(self+4))[i];
      }
     }
     TextCanvas_SetEntryTextPointer((char*)display,key,name);
     TextCanvas_EnableEntryUppercaseFormatting(display,key);
     TextCanvas_SetEntryTextColor((char*)display,key,0xf);
    }
    entry=*(unsigned char**)(entry+0x1c);
   } else {TextCanvas_DisableEntryNavigation(display,key);TextCanvas_HideEntry(display,key);}
  }
  TextCanvas_SetGroupPalette((char*)display,9,0);
  TextCanvas_SetDisplayPartRefreshFlag(display,9,0);
  TextCanvas_SetGroupBottomCornerSymbolsEnabled((char*)display,9,(*(unsigned short*)(self+0x394)&4)!=0);
  TextCanvas_CreateAndConfigureDisplayPart((char*)display,9);
 }
}
