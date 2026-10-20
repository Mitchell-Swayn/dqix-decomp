#include <globaldefs.h>
#include <GameState/GameState.h>
#include <System/Interrupts.h>
#include <System/Matrix.h>
ARM
extern "C" {int Card_IsReadManagerIdle();void SoundCommand_InvokeGenerationMatchedCallback(int);char* LinkedList_FindNodeByInitialIntegerKey(void*,int);int ObjectPool_SpawnFromTemplate(void*,void*,void*);void Grid_InitializeTouchSelection(void*);void Grid_InitializeDirectionalSelection(void*);int String_CountBytesUntilTerminator(const char*);int sprintf(char*,const char*,...);void* ResourceManager_ExchangeGlobalValue(void*);void ResourceHandle_StopOrFadeSequence(void*,int);void* Network_IsParentOrOffline(void*);int Network_GetWirelessPeerMask(void*);char* Network_GetReceivedMemberPacket(void*,int);void ActorPathGraph_InitializeEmpty(void*);void Actor_ClearChoiceEntries(void*);void Clear456ByteBufferAndInitializeTrailingWords(void*);void ScriptRecordList_InitializeEmpty(void*);void func_02037aa4(void*,int);void InitializeRecordWithEnabledAndPercentDefaults(void*);void GameObject_SetMotionStateAndRefreshAnimation(void*,int);void InitializeVectorTransitionAndStepValues(void*,const Vector3fix*,const Vector3fix*,const Vector3fix*,int,int);int WMi_CheckIdle();void WMi_SetCallbackTable(int,void*);int WMi_SendCommand(int,int,...);void GameState_RemoveOrApplyTexturesForRelatedObjects(void*,int);}
#pragma force_active on
// Original: arm9/main @ 0x0205416C; symbol: func_0205416c; size: 0x38.
extern "C" void GameObject_AdvanceTextureSuppressionTimer(char* p){unsigned n=GameState::GetInstance()->GetEffectiveDeltaTime();unsigned left=*(unsigned short*)(p+448);if(left>=n)*(unsigned short*)(p+448)=left-n;else GameState_RemoveOrApplyTexturesForRelatedObjects(p,0);}
