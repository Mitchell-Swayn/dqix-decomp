#include <globaldefs.h>
ARM
struct GameState;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned TextContext_GetSharedInstance();
extern "C" void* GameState_GetIndexList(GameState*);
extern "C" void TextLayout_ResetFormattingWorkspace(signed char*);
extern "C" void TextContext_SetNumericArgument(unsigned*,int,unsigned);
extern "C" void TextContext_SetNumericArgumentWidth(char*,int,int);
extern "C" void TextContext_SetNumericArgumentAlignment(char*,int,int);
extern "C" void* Text_LookupStandardString(unsigned);
extern "C" void TextMarkup_ExpandAndWrapText(void*,int,void*,void*,int,int,unsigned);
// Original: arm9/ov003 @ 0x0215DE6C; symbol: func_ov003_0215de6c; size: 0xB0.
extern "C" void Graphics_InitializeFormattedStateValue(char* self,void* output) {
GameState* state=(GameState*)_ZN9GameState11GetInstanceEv();
char* context=(char*)TextContext_GetSharedInstance();
char* list=(char*)GameState_GetIndexList(state);
unsigned value=*(unsigned*)(list+0xf6c);
if(*(unsigned char*)(self+0x3bb)==2) value-=*(unsigned*)(self+0x3cc);
TextLayout_ResetFormattingWorkspace((signed char*)context);
TextContext_SetNumericArgument((unsigned*)context,0,value);
TextContext_SetNumericArgumentWidth(context,0,7);
TextContext_SetNumericArgumentAlignment(context,0,1);
void* resource=Text_LookupStandardString(1009);
TextMarkup_ExpandAndWrapText(context,8,resource,output,256,0,0);
}
