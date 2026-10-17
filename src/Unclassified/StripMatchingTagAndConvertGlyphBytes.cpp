#include <globaldefs.h>
ARM
#pragma optimize_for_size off
extern "C" const char data_020f0916[];extern "C" char* FindUnpairedGreaterThanCharacter(char*);extern "C" int RuntimeMemory_CompareByteRanges(const void*,const void*,unsigned);extern "C" void* memcpy(void*,const void*,unsigned);struct Glyph {char pad[5];signed char length:6;unsigned char reserved:1;signed char compressed:1;};extern "C" Glyph* TextLookup_FindMatchingByteKeyEntry(char*,int);extern "C" void Text_UppercaseBoundedASCIICharacters(char*,int);
// Original: arm9/main @ 0x020695F4; symbol: func_020695f4; size: 0xC8.
extern "C" void StripMatchingTagAndConvertGlyphBytes(void*,char* src,char* dst,int font) { const char* marker=data_020f0916;for(;;) {if(!*src)break;char* close;if(*src=='<' && (close=FindUnpairedGreaterThanCharacter(src)) && RuntimeMemory_CompareByteRanges(src+1,marker,4)==0) {src=close+1;Glyph* glyph=TextLookup_FindMatchingByteKeyEntry(src,font);if(glyph && glyph->compressed) {int length=glyph->length;memcpy(dst,src,length);Text_UppercaseBoundedASCIICharacters(dst,length);src+=length;dst+=length;} }else *dst++=*src++;}*dst=0; }
