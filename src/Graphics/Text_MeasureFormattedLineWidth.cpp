#include <globaldefs.h>
ARM
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" int TextLookup_FindGlyphIndexByText(const void*,int);
extern "C" char* TextLookup_FindMatchingByteKeyEntry(const void*,int);
extern "C" int TextLookup_GetKerningAdjustment(unsigned,unsigned,int);
extern "C" unsigned int TextLookup_GetPackedFontMetrics(int);
extern "C" int TextStream_GetExtendedControlArgumentCount(void*,const void*);
extern "C" bool TextStream_IsControlToken(int,void*);
extern "C" bool TextStream_TestControlMarkerRange(void*,const void*);
// Original: arm9/main @ 0x0206B37C; symbol: func_0206b37c; size: 0x1AC.
extern "C" int Text_MeasureFormattedLineWidth(unsigned char* self,const unsigned char* current) {
 if(!current) return 0;
 unsigned char metric=(unsigned char)TextLookup_GetPackedFontMetrics(self[0x19dc]);
 unsigned char id=255, previous=255;
 int advance;
 int width=0;
 unsigned short code;
 short value;
 while(!TextStream_TestControlMarkerRange(self,current)) {
  memcpy(&code,current,2);
  if(TextStream_IsControlToken((int)self,&code)) {
   advance=TextStream_GetExtendedControlArgumentCount(self,&code);
   switch(code) {
    case 0xff19:
     previous=255;
     width+=TextLookup_GetKerningAdjustment(255,id,self[0x19dc]);
     break;
    case 0xff20:
     previous=255;
     memcpy(&value,current+2,2);
     if(width<value) width=value;
     break;
    case 0xff23:
     previous=255;
     memcpy(&value,current+2,2);
     width+=value;
     break;
   }
   current=current+2+advance*2;
  } else {
   advance=1;
   int glyphWidth=metric;
   char* entry=TextLookup_FindMatchingByteKeyEntry(current,self[0x19dc]);
   if(entry) {
    id=(unsigned char)TextLookup_FindGlyphIndexByText(current,self[0x19dc]);
    width+=TextLookup_GetKerningAdjustment(previous,id,self[0x19dc]);
    previous=id;
    id=255;
    advance=((signed char)entry[5]<<26)>>26;
    glyphWidth=(signed char)entry[4];
   }
   width+=glyphWidth+1;
   current+=advance;
  }
 }
 return width;
}
