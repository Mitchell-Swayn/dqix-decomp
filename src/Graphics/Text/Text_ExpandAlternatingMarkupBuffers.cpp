#include <globaldefs.h>
ARM
extern "C" int Text_StripMatchingTagAndConvertGlyphBytes(...);
extern "C" int TextMarkup_ExpandConditionalBranches(...);
extern "C" int TextMarkup_ExpandHandlersTokensAndBracketNames(...);
extern "C" int TextMask_CopyTokensMarkupAndSeparators(...);
extern "C" int Text_ExpandRecognizedAngleBracketTags(...);
extern "C" int Text_ProcessBufferedHalfwordCodesAndResetCounters(...);
extern "C" int TextMarkup_EncodeTagsAndNewlines(...);
extern "C" int Graphics_CopyTextAndResetParserRenderBuffers(...);
extern "C" void* memset(void*,int,unsigned);extern "C" unsigned strlen(const char*);
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
// Original: arm9/main @ 0x02067E98; symbol: ExpandTextThroughAlternatingMarkupBuffers; size: 0xc4.
extern "C" void Text_ExpandAlternatingMarkupBuffers(char* self,const char* text){
Text_ProcessBufferedHalfwordCodesAndResetCounters(self);memset(P(self,72),0,2400);char* first=P(self,96);char* second=P(self,100);Text_ExpandRecognizedAngleBracketTags(self,text,first);TextMask_CopyTokensMarkupAndSeparators(self,first,second,B(self,0x19dc));TextMarkup_ExpandConditionalBranches(self,second,first,B(self,0x19dc));TextMarkup_ExpandHandlersTokensAndBracketNames(self,first,second,B(self,0x19dc));Text_StripMatchingTagAndConvertGlyphBytes(self,second,first,B(self,0x19dc));TextMarkup_EncodeTagsAndNewlines(self,first,second);Graphics_CopyTextAndResetParserRenderBuffers(self,second,227);W(self,0x9a0)=5;
}
