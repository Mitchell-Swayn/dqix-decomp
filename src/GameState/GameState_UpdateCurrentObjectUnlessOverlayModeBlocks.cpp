#include "globaldefs.h"
#pragma optimize_for_size off
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" void* ReadSignedWordField32C(void*);extern "C" int ReadIndirectByteOrMinusOne(void*);extern "C" void Record_ReadInitialWord(void*);extern "C" void* Object_GetGlobalSixteenEntryDisplayState();extern "C" int func_ov017_021b8b54(void*);extern "C" void DrawObjectWithTemporaryHeightOffset(void*);extern "C" void UpdateInactiveEntriesForMatchingParentObject(void*,int);
// Original: arm9/main @ 0x020A66A4; symbol: func_020a66a4; size: 0x84.
extern "C" void GameState_UpdateCurrentObjectUnlessOverlayModeBlocks(unsigned char*p){void*object;int type;void*state;void*g=_ZN9GameState11GetInstanceEv();state=*(void**)(p+0x36fc);object=ReadSignedWordField32C(g);type=ReadIndirectByteOrMinusOne(state);Record_ReadInitialWord(state);p=*(unsigned char**)(p+0x3718);state=Object_GetGlobalSixteenEntryDisplayState();if(!object)return;if(type==10&&p[3]&&func_ov017_021b8b54(p))return;DrawObjectWithTemporaryHeightOffset(object);UpdateInactiveEntriesForMatchingParentObject(state,201);}
