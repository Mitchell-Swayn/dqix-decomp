#include <globaldefs.h>
ARM
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
extern "C" char* TextContext_GetSharedInstance(char*);extern "C" void* ResourceStringTable_GetTextByKey(void*,int);extern "C" void TextWindow_StartFormattedMessage(void*,void*,int,int);
// Original: arm9/ov013 @ 0x02185774; symbol: ApplyModeSelectedTextAndResetLayoutFlags; size: 0xb4.
extern "C" void SkillAllocation_ShowMainScreenPrompt(char* self){
char* layout=TextContext_GetSharedInstance(self);int mode=B(self,0x63c);if(mode==4)TextWindow_StartFormattedMessage(layout,ResourceStringTable_GetTextByKey(self+0x620,1000),0,227);else if(mode==3)TextWindow_StartFormattedMessage(layout,ResourceStringTable_GetTextByKey(self+0x620,1001),0,227);else if(mode==2)TextWindow_StartFormattedMessage(layout,ResourceStringTable_GetTextByKey(self+0x620,1002),0,227);B(layout,0x19b2)=0;W(layout,0x998)=1;
}
