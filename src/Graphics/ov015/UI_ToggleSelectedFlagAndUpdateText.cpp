#include <globaldefs.h>
ARM
struct RangeState;struct State;
extern "C" int func_ov015_02191284(RangeState*);
extern "C" char* GetLinkedNodeByBoundedIndex(char*,int);
extern "C" void CopyBoundedDoubleByteTextWithoutSplittingCharacter(State*,const unsigned char*);
extern "C" unsigned char data_ov015_0219432e[],data_ov015_02194338[],data_ov015_02194342[],data_ov015_0219434b[],data_ov015_0219435a[],data_ov015_02194369[],data_ov015_02194378[],data_ov015_02194387[],data_ov015_02194396[];
// Original: arm9/ov015 @ 0x02191F04; symbol: func_ov015_02191f04; size: 0x160.
extern "C" void UI_ToggleSelectedFlagAndUpdateText(unsigned char* p) {
 int selected=func_ov015_02191284((RangeState*)(p+0x2c4));
 State* text=(State*)GetLinkedNodeByBoundedIndex((char*)p+0x2c4,*(short*)(p+0x324));
 switch(selected) {
 case 0: p[0x19c]=!p[0x19c]; if(p[0x19c]) CopyBoundedDoubleByteTextWithoutSplittingCharacter(text,data_ov015_0219432e); else CopyBoundedDoubleByteTextWithoutSplittingCharacter(text,data_ov015_02194338); break;
 case 1: p[0x19d]=!p[0x19d]; CopyBoundedDoubleByteTextWithoutSplittingCharacter(text,data_ov015_02194342); break;
 case 2: p[0x19e]=!p[0x19e]; if(p[0x19e]) CopyBoundedDoubleByteTextWithoutSplittingCharacter(text,data_ov015_0219434b); else CopyBoundedDoubleByteTextWithoutSplittingCharacter(text,data_ov015_0219435a); break;
 case 3: p[0x19f]=!p[0x19f]; if(p[0x19f]) CopyBoundedDoubleByteTextWithoutSplittingCharacter(text,data_ov015_02194369); else CopyBoundedDoubleByteTextWithoutSplittingCharacter(text,data_ov015_02194378); break;
 case 4: p[0x1a0]=!p[0x1a0]; if(p[0x1a0]) CopyBoundedDoubleByteTextWithoutSplittingCharacter(text,data_ov015_02194387); else CopyBoundedDoubleByteTextWithoutSplittingCharacter(text,data_ov015_02194396); break;
 }
 p[0x350]=1;
}
