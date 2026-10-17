extern "C" {
void *_ZN9GameState11GetInstanceEv(); void *ReadGlobalValueAt02108EA8(void*); void *Object_GetGlobalConnectionState(); void *GameResources_GetInstance();
int ToggleMaskedFlagsAtOffset34(void*,unsigned char); void func_ov000_02174a50(void*,int); void ClearMaskedFlagsAtOffset34(void*,unsigned char); void ClearIndexedTextRecordStatesAndNotify(void*,unsigned char); void func_ov017_02191b40(void*,int); int TestInactiveOrPrimaryIndexState(void*); void *GameState_ReadProtagonistObjectIndex(void*); void *InitializeRecordOwnerIfNegative(void*,unsigned short,void*); void GameState_UpdateStoredProtagonistIndex(void*,void*); void InitializeQueuedRecordOwner(unsigned short,int); void func_ov000_0215fb04(void*,int); int GameState_TestProtagonistIndexMatchesStoredByte(void*); void func_ov026_021dbf04(void*); void Resource_MoveQueuedRecordWithTaggedInput(unsigned short);
}
// Original: arm9/ov026 @ 0x021DBD1C; symbol: func_ov026_021dbd1c; size: 0x128.
extern "C" void func_ov026_021dbd1c(char *state,int index,int mode) {
void *game=_ZN9GameState11GetInstanceEv(); char *base=state+0x760; char *actor=*(char**)(state+0x2a0); void *field=*(void**)(state+0x29c); void *party=ReadGlobalValueAt02108EA8(game); void *manager=Object_GetGlobalConnectionState(); void *scene=GameResources_GetInstance(); int active=0;
if(ToggleMaskedFlagsAtOffset34(actor,(unsigned char)index)) {active=1; state[0x7748]=1;}
func_ov000_02174a50(base+0x3000,index); ClearMaskedFlagsAtOffset34(actor,(unsigned char)index); ClearIndexedTextRecordStatesAndNotify(party,(unsigned char)index); func_ov017_02191b40(scene,index);
if(index==*(signed char*)(actor+0x2a)) {if(TestInactiveOrPrimaryIndexState(manager)){void *info=GameState_ReadProtagonistObjectIndex(game); void *result=InitializeRecordOwnerIfNegative(party,*(unsigned short*)(actor+8),info);GameState_UpdateStoredProtagonistIndex(state,result);}else InitializeQueuedRecordOwner(*(unsigned short*)(actor+8),index);}
func_ov000_0215fb04(field,index);
if(mode && *(int*)(state+0xeac)!=17 && active && GameState_TestProtagonistIndexMatchesStoredByte(actor)){func_ov026_021dbf04(state);Resource_MoveQueuedRecordWithTaggedInput(*(unsigned short*)(actor+8));}
}
