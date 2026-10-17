#include <globaldefs.h>
ARM
#include <std_library_functions.h>
struct Nibbles {unsigned char low:4,high:4;};struct Mode{unsigned char mode:2,rest:6;};
extern "C" void* ReadWordFieldAtOffset1C();extern "C" void ClearOwnerBuffersAndResetSignedByteSentinels(void*),SetOneOfSixteenWordFieldsAtOffset8B0(void*,int,unsigned);extern "C" void* FindRecordValueByKeyOrZero(unsigned,int);extern "C" void ProcessSixStagesUsingSharedWordScratchBuffer(void*,unsigned,void*,void*,int,int,int);extern "C" int TextLayout_ComputeWidthWithGlyphSpacing(void*);extern "C" void func_0204f41c(char*,int,int,void*,unsigned,unsigned,void*,void*,unsigned);
// Original: arm9/main @ 0x02081A14; symbol: func_02081a14; size: 0x128.
extern "C" void Text_RenderResolvedRecordWithStyleAndMeasuredOffset(unsigned* p,char* object,char* data){
 unsigned high=((Nibbles*)(data+19))->high;if(*(unsigned char*)(data+42)&4)high=5;void* font=ReadWordFieldAtOffset1C();memset((void*)p[6],0,2400);ClearOwnerBuffersAndResetSignedByteSentinels(font);SetOneOfSixteenWordFieldsAtOffset8B0(font,*(short*)(data+16),*(unsigned*)data);void* text=FindRecordValueByKeyOrZero(p[0],*(short*)(data+14));ProcessSixStagesUsingSharedWordScratchBuffer(font,((Nibbles*)(data+19))->low,text,(void*)p[6],256,0,0);int width=0;if(((Mode*)(data+20))->mode)width=TextLayout_ComputeWidthWithGlyphSpacing((void*)p[6]);unsigned low=((Nibbles*)(data+19))->low;*(unsigned short*)(object+180)=low;*(unsigned short*)(object+182)=low+1;
 func_0204f41c(object,(short)(*(short*)(data+6)+*(short*)(data+40)-width),*(short*)(data+8),(void*)p[6],((Nibbles*)(data+19))->low,high,data+10,data+12,0);
}
