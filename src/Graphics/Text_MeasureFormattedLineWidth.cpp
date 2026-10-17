#include <globaldefs.h>
ARM
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" int FindIndexedBinaryKeyByLengthComparison(const void*,int);
extern "C" char* TextLookup_FindMatchingByteKeyEntry(const void*,int);
extern "C" int FindSignedByteValueByPackedBytePairKey(unsigned,unsigned,int);
extern "C" unsigned int ReadFontMetricByIndex(int);
extern "C" int ClassifyValidatedFF20ThroughFF25Code(void*,const void*);
extern "C" bool IsCopiedHalfwordHighByteFF(int,void*);
extern "C" bool TextStream_TestControlMarkerRange(void*,const void*);
// Original: arm9/main @ 0x0206B37C; symbol: func_0206b37c; size: 0x1AC.
extern "C" int Text_MeasureFormattedLineWidth(unsigned char* self,const unsigned char* current) {
 if(!current) return 0;
 unsigned char metric=(unsigned char)ReadFontMetricByIndex(self[0x19dc]);
 unsigned char id=255, previous=255;
 int advance;
 int width=0;
 unsigned short code;
 short value;
 while(!TextStream_TestControlMarkerRange(self,current)) {
  memcpy(&code,current,2);
  if(IsCopiedHalfwordHighByteFF((int)self,&code)) {
   advance=ClassifyValidatedFF20ThroughFF25Code(self,&code);
   switch(code) {
    case 0xff19:
     previous=255;
     width+=FindSignedByteValueByPackedBytePairKey(255,id,self[0x19dc]);
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
    id=(unsigned char)FindIndexedBinaryKeyByLengthComparison(current,self[0x19dc]);
    width+=FindSignedByteValueByPackedBytePairKey(previous,id,self[0x19dc]);
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
