#include <globaldefs.h>
ARM
extern "C" int Text_AppendFormattedIntegerFragmentAt020EFE78(char*,int);
extern "C" int AppendFormattedPair_Main02041A90(char*,int,int);
extern "C" int TextMarkup_AppendLineTag(char*,int);
extern "C" unsigned Text_AppendCenteredTextUsingComputedWidth(char*,const char*,int,int);
extern "C" void* ResolveIndexedRecordAndReturnSecondWord(void*,void*);
// Original: arm9/ov002 @ 0x021601E0; symbol: func_ov002_021601e0; size: 0x94.
extern "C" void Graphics_AppendTwoCenteredIndexedTextLines(char* self,char* out) {
 if(!out) return;
 Text_AppendFormattedIntegerFragmentAt020EFE78(out,0);
 const char* text=(const char*)ResolveIndexedRecordAndReturnSecondWord(self+0x20,(void*)0x1130);
 Text_AppendCenteredTextUsingComputedWidth(out,text,0x48,0);
 TextMarkup_AppendLineTag(out,0x10);
 AppendFormattedPair_Main02041A90(out,0,0x3a);
 text=(const char*)ResolveIndexedRecordAndReturnSecondWord(self+0x20,(void*)(short)(*(short*)(self+0x1c06)+0x1131));
 Text_AppendCenteredTextUsingComputedWidth(out,text,0x48,0);
}
