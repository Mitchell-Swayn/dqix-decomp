#include <globaldefs.h>
ARM
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
extern "C" unsigned Util_ParseDecimalAndAdvanceCursor(const unsigned char*,const unsigned char**);
// Original: arm9/ov031 @ 0x02204B84; symbol: ParseFourDotSeparatedByteValues; size: 0x9c.
extern "C" int Network_ParseDottedIpv4Address(const unsigned char* text,unsigned* output){
unsigned value=0;int i=0;do{const unsigned char* end;unsigned part=Util_ParseDecimalAndAdvanceCursor(text,&end);if(text==end)return 0;text=end;if(part>255||(i!=3&&*text++!='.')||(i==3&&*text))return 0;++i;value=part|(value<<8);}while(i<4);*output=value;return 1;
}
