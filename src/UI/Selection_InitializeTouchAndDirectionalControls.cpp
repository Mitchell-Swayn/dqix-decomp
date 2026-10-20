#include <globaldefs.h>
#include <GameState/GameState.h>
#include <System/Interrupts.h>
#include <System/Matrix.h>
ARM
extern "C" {int Card_IsReadManagerIdle();void SoundCommand_InvokeGenerationMatchedCallback(int);char* LinkedList_FindNodeByInitialIntegerKey(void*,int);int ObjectPool_SpawnFromTemplate(void*,void*,void*);void Grid_InitializeTouchSelection(void*);void Grid_InitializeDirectionalSelection(void*);int String_CountBytesUntilTerminator(const char*);int sprintf(char*,const char*,...);void* ResourceManager_ExchangeGlobalValue(void*);void ResourceHandle_StopOrFadeSequence(void*,int);void* Network_IsParentOrOffline(void*);int Network_GetWirelessPeerMask(void*);char* Network_GetReceivedMemberPacket(void*,int);void ActorPathGraph_InitializeEmpty(void*);void Actor_ClearChoiceEntries(void*);void Clear456ByteBufferAndInitializeTrailingWords(void*);void ScriptRecordList_InitializeEmpty(void*);void func_02037aa4(void*,int);void InitializeRecordWithEnabledAndPercentDefaults(void*);void GameObject_SetMotionStateAndRefreshAnimation(void*,int);void InitializeVectorTransitionAndStepValues(void*,const Vector3fix*,const Vector3fix*,const Vector3fix*,int,int);int WMi_CheckIdle();void WMi_SetCallbackTable(int,void*);int WMi_SendCommand(int,int,...);void GameState_RemoveOrApplyTexturesForRelatedObjects(void*,int);}
#pragma force_active on
// Original: arm9/main @ 0x0205C53C; symbol: func_0205c53c; size: 0x28.
extern "C" void Selection_InitializeTouchAndDirectionalControls(char* p){Grid_InitializeTouchSelection(p+4);Grid_InitializeDirectionalSelection(p+84);p[148]=0;p[149]=0;}
