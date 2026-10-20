#include <globaldefs.h>
ARM
struct GameState;struct Buffer;
extern "C"{
unsigned TextContext_GetSharedInstance();void* memset(void*,int,unsigned);void* Script_GetFacilityCommandContext();int TextMarkup_AppendTalkWrappedText(char*,int);void* ResourceStringTable_GetTextByKey(void*,void*);int Text_AppendFormatString(char*,const char*);
void* _ZN9GameState11GetInstanceEv();void* GameState_GetIndexList(GameState*);void* _ZN9GameState14GetProtagonistEv(void*);void TextLayout_ResetFormattingWorkspace(signed char*);void TextContext_SetStringArgument(Buffer*,int,const char*);void TextContext_SetNumericArgument(unsigned*,int,unsigned);void TextContext_SetNumericArgumentWidth(char*,int,int);void TextWindow_StartFormattedMessage(int,int,int,int);
void Bank_OpenHeldGoldWindow(char*);void Bank_OpenTransactionMenu(unsigned char*);void Window_SetCanvasDisplayAttribute(char*,int,int);
}
// Original: arm9/ov003 @ 0x02168B50; symbol: func_ov003_02168b50; size: 0x178.
// Formats the protagonist's transfer prompt, then prepares its layout once the owner acknowledges it.
extern "C" void AdvanceProtagonistTransferPrompt(unsigned char* p){
 char* owner=(char*)TextContext_GetSharedInstance();
 if(p[0x4e8]==0){
  memset(*(void**)(p+0x7c),0,0x960);char* global=(char*)Script_GetFacilityCommandContext();if(*(signed char*)(global+0x10))TextMarkup_AppendTalkWrappedText(*(char**)(p+0x7c),(int)(global+0x10));
  Text_AppendFormatString(*(char**)(p+0x7c),(const char*)ResourceStringTable_GetTextByKey(p+0x64,(void*)1000));
  void* game=_ZN9GameState11GetInstanceEv();char* list=(char*)GameState_GetIndexList((GameState*)game);TextLayout_ResetFormattingWorkspace((signed char*)owner);char* member=(char*)_ZN9GameState14GetProtagonistEv(game);TextContext_SetStringArgument((Buffer*)owner,0,*(const char**)(member+0x134));
  if(*(unsigned*)(list+0xf68)){TextContext_SetNumericArgument((unsigned*)owner,0,*(unsigned*)(list+0xf68));TextContext_SetNumericArgumentWidth(owner,0,0);Text_AppendFormatString(*(char**)(p+0x7c),(const char*)ResourceStringTable_GetTextByKey(p+0x64,(void*)1002));}
  else Text_AppendFormatString(*(char**)(p+0x7c),(const char*)ResourceStringTable_GetTextByKey(p+0x64,(void*)1001));
  *(int*)(owner+0x998)=1;TextWindow_StartFormattedMessage((int)owner,*(int*)(p+0x7c),0,0xe3);*(int*)(owner+0x99c)=2;++p[0x4e8];
 }else if(p[0x4e8]==1&&p[0x5a4]==0&&*(int*)(owner+0x9a0)==3){Bank_OpenHeldGoldWindow((char*)p);Bank_OpenTransactionMenu(p);Window_SetCanvasDisplayAttribute((char*)p+0xe4,0,0);p[0x4ec]=2;p[0x4e8]=0;}
}
