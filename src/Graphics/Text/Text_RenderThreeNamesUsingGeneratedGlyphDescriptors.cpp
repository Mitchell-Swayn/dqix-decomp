#include <globaldefs.h>
extern "C" char data_020ee898[],data_020ee8b2[],data_020ee864[],data_020ee87e[];
extern "C" void BuildRecordsWithCumulativeHalfProductOffsets(void*,unsigned int,void*,void*,void*,void*);
extern "C" void ClearTwoWordsAndFollowingByte(void*),WriteFirstWordValue(void*,char*),Object_SetWord4AndByte8(void*,void*,unsigned char);
extern "C" int func_0205b234(void*,short,short,const char*,unsigned int,unsigned int);
extern "C" unsigned int String_CountBytesUntilTerminator(const char*);
struct Name {char text[0x48];};
struct Number {char text[8];};
struct Owner {char pad[0x5fc];Name names[3];Number numbers[3];};
// Original: arm9/main @ 0x020E0B4C; symbol: func_020e0b4c; size: 0x1B0.
extern "C" ARM void Text_RenderThreeNamesUsingGeneratedGlyphDescriptors(Owner* self,char* buffer,int offset) {
 char entries[156];unsigned int transfer[3];
 BuildRecordsWithCumulativeHalfProductOffsets(entries,13,data_020ee864,data_020ee87e,data_020ee898,data_020ee8b2);
 ClearTwoWordsAndFollowingByte(transfer);WriteFirstWordValue(transfer,buffer+offset);Object_SetWord4AndByte8(transfer,entries,13);
 for(int i=0;i<3;++i) {
  const char* text;
  int rowOffset=i*13;int y=rowOffset+16;func_0205b234(transfer,10,(short)y,self->names[i].text,15,0);
  text=self->numbers[i].text;
  if(String_CountBytesUntilTerminator(text)==3)func_0205b234(transfer,0x74,(short)y,text,15,0);
  else if(String_CountBytesUntilTerminator(text)==2)func_0205b234(transfer,0x78,(short)y,text,15,0);
  else if(String_CountBytesUntilTerminator(text)==1)func_0205b234(transfer,0x7d,(short)(rowOffset+15),text,15,0);
  else func_0205b234(transfer,0x74,(short)y,text,15,0);
 }
}
