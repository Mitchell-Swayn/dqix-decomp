#include <globaldefs.h>
ARM
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" void __clear(void*,unsigned);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int TextMarkup_AppendXPositionTag(char*,int);
extern "C" int TextMarkup_AppendYTag(char*,int);
extern "C" int Text_AppendFormatString(char*,const char*);
extern "C" int TextLookup_FindGlyphIndexByText(const void*,int);
extern "C" char* TextLookup_FindMatchingByteKeyEntry(const void*,int);
extern "C" int Text_EncodeGlyphIndices(const char*,unsigned char*,unsigned);
extern "C" void Text_MapInputBytesToVariableLengthOutputSequences(const unsigned char*,unsigned char*,unsigned);
extern "C" unsigned String_CountBytesUntilTerminator(const signed char*);
// Original data: arm9/ov023 @ 0x21fdd6c; symbol: data_ov023_021fdd6c.
// Source-defined character literal. Text: "*". Original zero separators, trailing bytes and padding remain unchanged.
// Initial values: "*".
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" char TextAppendGlyphGrid_TextASTERISK[];
// Original: arm9/ov023 @ 0x021E8CDC; symbol: func_ov023_021e8cdc; size: 0x158.
extern "C" void Text_AppendGlyphGrid(unsigned char* self) {
 if(!*(int*)(self+0x5f4)) return;
 char* target=*(char**)(self+0x5d8);
 char* current=(char*)_ZN9GameState11GetInstanceEv()+0x569c;
 char input[0x3a]={0};
 char output[0x400]={0};
 int length;
 if(*(char**)(self+0x600)) length=Text_EncodeGlyphIndices(*(char**)(self+0x600),(unsigned char*)input,1);
 else {
  length=String_CountBytesUntilTerminator((signed char*)current+8);
  memcpy(input,current+8,length);
 }
 char pad=(char)TextLookup_FindGlyphIndexByText(TextAppendGlyphGrid_TextASTERISK,1);
 for(;length<57;++length) input[length]=pad;
 Text_MapInputBytesToVariableLengthOutputSequences((unsigned char*)input,(unsigned char*)output,1);
 current=output;
 int x=15, y=8, column=0;
 for(;;) {
  if(!*current) break;
  int advance=1;
  char* entry=TextLookup_FindMatchingByteKeyEntry(current,1);
  if(entry) {
   TextMarkup_AppendXPositionTag(target,x);
   Text_AppendFormatString(target,*(char**)entry);
   advance=((signed char)entry[5]<<26)>>26;
  }
  ++column;
  current+=advance;
  x+=12;
  if(column==19) {
   y+=19;
   x=15;
   column=0;
   TextMarkup_AppendYTag(target,y);
  }
 }
}
