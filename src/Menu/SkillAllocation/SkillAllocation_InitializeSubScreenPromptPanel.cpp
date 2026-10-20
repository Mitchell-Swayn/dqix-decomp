#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
// Original data: arm9/ov013 @ 0x2187d94; symbol: data_ov013_02187d94.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00020202.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov013.md.
extern "C" {void Window_BindNextCanvasResourceByFormatAndLayer(void*,unsigned,unsigned);void* memset(void*,int,unsigned);void Graphics_AppendModeSelectedSizeTaggedText(void*,void*);void Window_PushTextCanvas(void*,void*,int,int,int,int,void*,int);extern char SkillAllocationInitializeSubScreenPromptPanel_UnknownRoleInitializedBytes[];}
// Original: arm9/ov013 @ 0x02185828; symbol: Graphics_InitializeBoundTextMenuLayout; size: 0xd8.
extern "C" void SkillAllocation_InitializeSubScreenPromptPanel(unsigned char* self){self[0x6bc]&=~1;Window_BindNextCanvasResourceByFormatAndLayer(self+56,0,2);H(self,0xd8)=32;H(self,0xda)=9;H(self,0xdc)=0;H(self,0xde)=15;H(self,0xe0)=12;H(self,0xe2)=10;H(self,0xe4)=12;H(self,0xe6)=20;self[0xe9]=2;if(self[0x640])self[0xed]=0;else self[0xed]=1;self[0x63a]=0;memset(P(self,0x658),0,2400);Graphics_AppendModeSelectedSizeTaggedText(self,P(self,0x658));Window_PushTextCanvas(self+56,P(self,0x658),0,0,0,1,SkillAllocationInitializeSubScreenPromptPanel_UnknownRoleInitializedBytes,1);}
