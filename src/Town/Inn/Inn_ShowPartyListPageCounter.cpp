#include <globaldefs.h>
ARM
extern "C" void TextCanvas_ShowEntry(unsigned char*,int);
extern "C" void TextCanvas_SetEntryNumericValue(char*,int,int);
#pragma always_inline on
static inline int RoundMemberCountToPageBoundary(int count) {return (count+3)&~3;}
#pragma force_active on
// Original: arm9/ov003 @ 0x0215F5E8; symbol: func_ov003_0215f5e8; size: 0x68.
extern "C" void Inn_ShowPartyListPageCounter(void* canvas,int page,int count) {
    if(count<=4) return;
    int rounded=RoundMemberCountToPageBoundary(count);
    TextCanvas_ShowEntry((unsigned char*)canvas,0xd3);
    TextCanvas_ShowEntry((unsigned char*)canvas,0xd4);
    TextCanvas_ShowEntry((unsigned char*)canvas,0xd5);
    TextCanvas_SetEntryNumericValue((char*)canvas,0xd4,page+1);
    TextCanvas_SetEntryNumericValue((char*)canvas,0xd5,rounded/4);
}
