#include <globaldefs.h>
ARM
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
extern "C" unsigned GameState_GetIndexList(...);
extern "C" unsigned TextContext_SetNumericArgumentAlignment(...);
extern "C" unsigned TextMarkup_ExpandAndWrapText(...);
extern "C" unsigned TextContext_GetSharedInstance(...);
extern "C" unsigned ResourceStringTable_GetTextByKey(...);
extern "C" unsigned TextContext_SetNumericArgument(...);
extern "C" unsigned TextMarkup_AppendLineTag(...);
extern "C" unsigned TextContext_SetNumericArgumentWidth(...);
extern "C" unsigned _ZN9GameState11GetInstanceEv(...);
// Original: arm9/ov023 @ 0x021e853c; symbol: FormatTwoIndexedListValues.
extern "C" void Menu_FormatPairedIndexListCounters(char* p){char* list=(char*)GameState_GetIndexList(_ZN9GameState11GetInstanceEv());void* formatter=(void*)TextContext_GetSharedInstance();TextMarkup_AppendLineTag((char*)U(p,0x5d8),24);unsigned values[2];values[0]=U(list,0xf6c);values[1]=U(list,0xf68);for(int i=0;i<2;i++){TextContext_SetNumericArgument(formatter,i,values[i]);TextContext_SetNumericArgumentAlignment(formatter,i,1);TextContext_SetNumericArgumentWidth(formatter,i,10);}void* text=(void*)ResourceStringTable_GetTextByKey(p+0x4c,1);TextMarkup_ExpandAndWrapText(formatter,10,text,(void*)U(p,0x5d8),256,0,0);}
