#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
extern "C" {void GameState_ClearByteSlots(GameState*);void GameState_EmitObjectPositionAndZoneRequest(void*,int);int ComputeMaskedIndexPopulationStrideAndBase(void*,unsigned,const void*,int);void Text_ParseDelimitedSignedIntegerSequence(void*,void*,int);char* ReadWordFieldAtOffset1C();void* func_02001a40(void*,const void*,unsigned);void Texture_FlushAndStageImageSegmentsAndPalette(void*);void func_02037640(void*);int String_CountBytesUntilTerminator(const char*);void Object_SetWordAtOffset1E20(void*,const void*);void AdvanceFadeAmountByScaledStep(void*,int);void PointField1E20AtEmbedded914(void*);int SaveContextReadFadePredicateAndRestoreContext(void*);void func_0205c5b0(void*,int);int Object_ReadIndexedBitAtOffset8EC(void*,int);int GameState_ReadAttributeBits12To19(GameState*,int);extern short data_020e8ab6[],data_020e8ac4[],data_020e8af2[];}
#pragma force_active on
// Original: arm9/main @ 0x02093080; symbol: func_02093080; size: 0x50.
extern "C" void AdvanceTwoStageStateTransition(unsigned char* p){GameState* state=GameState::GetInstance();unsigned char stage=p[53];if(!stage){GameState_ClearByteSlots(state);GameState_EmitObjectPositionAndZoneRequest(p,1);++p[53];return;}if(stage==1){p[52]=2;p[53]=0;}}
