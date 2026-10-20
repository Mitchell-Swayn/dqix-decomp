#include <globaldefs.h>
ARM
extern "C" {char* TextContext_GetSharedInstance();void TextLayout_ResetFormattingWorkspace(void*);const char* ResourceStringTable_GetTextByKey(void*,short);void TextContext_SetStringArgument(void*,int,const char*);void TextContext_SetNumericArgument(void*,int,unsigned);void TextWindow_StartFormattedMessage(void*,const char*,int,int);}
// Original: arm9/ov003 @ 0x0216D8D4; symbol: ConfigureNamedOwnerMessageAndOptionalValues; size: 0xbc.
// Clears owner message fields, fills optional name/values and displays selected indexed text.
extern "C" void Inn_ShowServiceMessage(char* self,int text,int name,int first,int second){char* owner=TextContext_GetSharedInstance();TextLayout_ResetFormattingWorkspace(owner);if(name>=0)TextContext_SetStringArgument(owner,5,ResourceStringTable_GetTextByKey(self+0x1324,(short)name));if(first>=0)TextContext_SetNumericArgument(owner,1,first);if(second>=0)TextContext_SetNumericArgument(owner,0,second);TextWindow_StartFormattedMessage(owner,ResourceStringTable_GetTextByKey(self+0x1324,(short)text),0,0xe3);owner[0x19b2]=1;*(int*)(owner+0x99c)=2;}
