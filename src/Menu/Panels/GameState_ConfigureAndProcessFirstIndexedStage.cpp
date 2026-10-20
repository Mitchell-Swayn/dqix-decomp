#include <globaldefs.h>
ARM
struct GameState;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetIndexList(GameState*);
extern "C" unsigned int TextContext_GetSharedInstance();
extern "C" void TextContext_SetNumericArgument(unsigned int*,int,unsigned int);
extern "C" void TextContext_SetNumericArgumentAlignment(char*,int,int);
extern "C" void TextContext_SetNumericArgumentWidth(char*,int,int);
extern "C" void TextMarkup_ExpandAndWrapText(void*,int,void*,void*,int,int,unsigned);
extern "C" void* ResourceStringTable_GetTextByKey(void*,void*);
// Original: arm9/ov023 @ 0x021E8604; symbol: func_ov023_021e8604; size: 0x88.
extern "C" void GameState_ConfigureAndProcessFirstIndexedStage(unsigned char* p){
 unsigned char* list=(unsigned char*)GameState_GetIndexList((GameState*)_ZN9GameState11GetInstanceEv());
 unsigned int* obj=(unsigned int*)TextContext_GetSharedInstance();
 TextContext_SetNumericArgument(obj,0,*(unsigned int*)(list+0xf74));
 TextContext_SetNumericArgumentAlignment((char*)obj,0,1);
 TextContext_SetNumericArgumentWidth((char*)obj,0,10);
 void* record=ResourceStringTable_GetTextByKey(p+0x4c,(void*)2);
 TextMarkup_ExpandAndWrapText(obj,10,record,*(void**)(p+0x5d8),256,0,0);
}
