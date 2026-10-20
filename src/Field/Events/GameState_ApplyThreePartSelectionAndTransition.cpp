#include <globaldefs.h>
ARM
extern "C" { void* _ZN9GameState11GetInstanceEv(); int GameState_GetProgressChapter(void*); int GameState_ReadUnknown5cb4(void*); int GameState_ReadUnknownCb8(void*); void Ov017_InitializeZoneTintRecord(int); void* GameResources_GetInstance(); void _Z13SetBrightnessP13GameResourcesii(void*,int,int); void GameState_SetProgressChapter(void*,unsigned); void GameState_SetProgressStage(void*,unsigned); void GameState_SetProgressStep(void*,unsigned); }
// Original: arm9/ov017 @ 0x021AA41C; symbol: func_ov017_021aa41c; size: 0xB0.
extern "C" void GameState_ApplyThreePartSelectionAndTransition(unsigned char* command) {
 void* state=_ZN9GameState11GetInstanceEv();
 int first=GameState_GetProgressChapter(state);
 int second=GameState_ReadUnknown5cb4(state);
 int third=GameState_ReadUnknownCb8(state);
 int current=first*10000+second*100+third;
 int target=*(unsigned short*)(command+8)*10000+*(unsigned short*)(command+10)*100+*(unsigned short*)(command+12);
 if(current!=target) Ov017_InitializeZoneTintRecord(0);
 else _Z13SetBrightnessP13GameResourcesii(GameResources_GetInstance(),0,30);
 GameState_SetProgressChapter(state,*(unsigned short*)(command+8));
 GameState_SetProgressStage(state,*(unsigned short*)(command+10));
 GameState_SetProgressStep(state,*(unsigned short*)(command+12));
 command[1]=1;
}
