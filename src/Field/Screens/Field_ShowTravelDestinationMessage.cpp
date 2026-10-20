#include <globaldefs.h>
ARM
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
extern "C" char* TextContext_GetSharedInstance(void*);extern "C" void* ResourceStringTable_GetTextByKey(void*,int);extern "C" void TextWindow_StartFormattedMessage(void*,void*,int,int);
// Original: arm9/ov017 @ 0x021A933C; symbol: SetIndexedTextAndRangeDependentLayoutFlags; size: 0xb4.
extern "C" void Field_ShowTravelDestinationMessage(char* self,int index){
char* layout=TextContext_GetSharedInstance(self);if(index<=199&&index>=100&&W(self,20)==1)index+=100;TextWindow_StartFormattedMessage(layout,ResourceStringTable_GetTextByKey(self+0x278,(short)index),0,227);if(index<=299&&index>=100)B(layout,0x19b2)=1;else B(layout,0x19b2)=0;if(index>299||index<100)return;if(W(self,20)==0)W(layout,0x99c)=2;else W(layout,0x99c)=1;
}
