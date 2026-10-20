#include <globaldefs.h>
ARM
extern "C" char* TextContext_GetSharedInstance();extern "C" void TextLayout_InitializePanelControlDefaults(void*);extern "C" void Selection_ResetInputControls(void*);extern "C" void WindowFrame_ResetTransitionRecord(void*);extern "C" void TextEntry_ReleaseGlyphRunReferences(void*,void*,unsigned);extern "C" void* memset(void*,int,unsigned);
// Original: arm9/main @ 0x0205C840; symbol: func_0205c840; size: 0xC4.
extern "C" void TextLayout_ResetBuffersAndLoadedLineEntries(unsigned char* p){char* state=TextContext_GetSharedInstance();state[0x19b0]=0;TextLayout_InitializePanelControlDefaults(p+4);Selection_ResetInputControls(p+28);WindowFrame_ResetTransitionRecord(p+180);*(unsigned*)(p+208)=0;if(p[562]){state=TextContext_GetSharedInstance();for(int i=0;i<p[562];++i)TextEntry_ReleaseGlyphRunReferences(state,p+288+*(unsigned short*)(p+544+i*2)*2,256);}memset(p+288,0,256);memset(p+544,0,16);*(unsigned short*)(p+560)=0;p[562]=0;p[563]=0;p[564]=0;}
