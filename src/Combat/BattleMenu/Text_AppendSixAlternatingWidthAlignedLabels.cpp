#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original data: arm9/ov000 @ 0x021834e0; symbol: data_ov000_021834e0.
// Text_AppendSixAlternatingWidthAlignedLabels uses order 0,3,1,4,2,5 to alternate the two display columns while resolving message IDs.
// Values (int32_t[6]): {0, 3, 1, 4, 2, 5}.
extern "C" int BattleMenu_TwoColumnLabelOrder[6];extern "C" void* ResourceStringTable_GetTextByKey(void*,void*);extern "C" int TextLayout_ComputeWidthWithGlyphSpacing(const char*,int),BattleMenu_HasTouchSelectionChanged(void*),TextMarkup_AppendFrameTag(char*,int,int,int,int,int),TextMarkup_AppendCursorTag(char*,int),Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*),Text_AppendFormatString(char*,const char*),TextMarkup_AppendXPositionTag(char*,int);
// Original: arm9/ov000 @ 0x02177ac8; symbol: Text_AppendSixAlternatingWidthAlignedLabels; size 0x128.
extern "C" void Text_AppendSixAlternatingWidthAlignedLabels(char* self,char* output){if(!output)return;int maximum=0;int selected=*(signed char*)(self+0x1d6c);for(int i=0;i<3;i++){const char* text=(const char*)ResourceStringTable_GetTextByKey(self+0xb8,(void*)(int)(short)(i+0x753e));int width=TextLayout_ComputeWidthWithGlyphSpacing(text,0);if(maximum<width)maximum=width;}if(BattleMenu_HasTouchSelectionChanged(self))TextMarkup_AppendFrameTag(output,selected,8,5,5,5);TextMarkup_AppendCursorTag(output,selected);for(int i=0;i<6;i++){int key=BattleMenu_TwoColumnLabelOrder[i];const char* text=(const char*)ResourceStringTable_GetTextByKey(self+0xb8,(void*)(int)(short)(key+0x753e));Text_AppendFormattedIntegerAndStringFragment(output,key,text);if(i==5)return;int odd=i&1;if(odd)Text_AppendFormatString(output,(const char*)ResourceStringTable_GetTextByKey(self+0xb8,0));if(!odd)TextMarkup_AppendXPositionTag(output,maximum+32);}}
