#include <globaldefs.h>
ARM
struct Eight {short values[8];};struct Triple {int x,y,z;};
extern "C" char* ResourceStringTable_GetTextByKey(...);
extern "C" int Text_ClearNameDescriptor(...);
extern "C" int GameState_BuildTwelveByteDescriptorForPartyMember(...);
extern "C" char* TextContext_GetSharedInstance(...);
extern "C" int TextLayout_ResetFormattingWorkspace(...);
extern "C" int TextMarkup_ExpandAndWrapText(...);
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov000 @ 0x02171A74; symbol: Graphics_FormatPriorityFlaggedPartyLabel; size: 0xc8.
// Graphics FormatPriorityFlaggedPartyLabel from listed field operations and calls.
extern "C" int Graphics_FormatPriorityFlaggedPartyLabel(char* self,void* output){if(!P(self,4))return -1;int key=-1;if(U(self,0x28)&1)key=4;else if(U(self,0x28)&8)key=2;else if(U(self,0x28)&16)key=3;else if(U(self,0x28)&0x80000)key=38;if(key>=0){void* text=ResourceStringTable_GetTextByKey(P(self,4),key);if(text){char descriptor[12];Text_ClearNameDescriptor(descriptor);GameState_BuildTwelveByteDescriptorForPartyMember(descriptor,W(self,0x4c));char* display=TextContext_GetSharedInstance();TextLayout_ResetFormattingWorkspace(display);P(display,0)=descriptor;TextMarkup_ExpandAndWrapText(display,10,text,output,256,0,0);}}return key;}
