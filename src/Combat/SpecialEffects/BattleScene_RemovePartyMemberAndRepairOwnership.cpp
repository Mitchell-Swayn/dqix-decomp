extern "C" {
void *_ZN9GameState11GetInstanceEv(); void *PartySync_GetSharedRecordTable(void*); void *Network_GetConnectionManager(); void *GameResources_GetInstance();
int PartySelection_GetMemberMask(void*,unsigned char); void BattleMenu_RemovePartyMember(void*,int); void PartySelection_DisableMember(void*,unsigned char); void ClearIndexedTextRecordStatesAndNotify(void*,unsigned char); void Field_ClearCombatantAppearanceFlags(void*,int); int Network_IsParentOrOffline(void*); void *GameState_ReadProtagonistObjectIndex(void*); void *PartySync_AssignRecordOwnerIfUnassigned(void*,unsigned short,void*); void GameState_UpdateStoredProtagonistIndex(void*,void*); void InitializeQueuedRecordOwner(unsigned short,int); void Combat_RemovePendingPartyJoin(void*,int); int GameState_TestProtagonistIndexMatchesStoredByte(void*); void BattleScene_ResetCommandSelectionAndRestoreFlags(void*); void Resource_MoveQueuedRecordWithTaggedInput(unsigned short);
}
// Original: arm9/ov026 @ 0x021DBD1C; symbol: func_ov026_021dbd1c; size: 0x128.
extern "C" void BattleScene_RemovePartyMemberAndRepairOwnership(char *state,int index,int mode) {
void *game=_ZN9GameState11GetInstanceEv(); char *base=state+0x760; char *actor=*(char**)(state+0x2a0); void *field=*(void**)(state+0x29c); void *party=PartySync_GetSharedRecordTable(game); void *manager=Network_GetConnectionManager(); void *scene=GameResources_GetInstance(); int active=0;
if(PartySelection_GetMemberMask(actor,(unsigned char)index)) {active=1; state[0x7748]=1;}
BattleMenu_RemovePartyMember(base+0x3000,index); PartySelection_DisableMember(actor,(unsigned char)index); ClearIndexedTextRecordStatesAndNotify(party,(unsigned char)index); Field_ClearCombatantAppearanceFlags(scene,index);
if(index==*(signed char*)(actor+0x2a)) {if(Network_IsParentOrOffline(manager)){void *info=GameState_ReadProtagonistObjectIndex(game); void *result=PartySync_AssignRecordOwnerIfUnassigned(party,*(unsigned short*)(actor+8),info);GameState_UpdateStoredProtagonistIndex(state,result);}else InitializeQueuedRecordOwner(*(unsigned short*)(actor+8),index);}
Combat_RemovePendingPartyJoin(field,index);
if(mode && *(int*)(state+0xeac)!=17 && active && GameState_TestProtagonistIndexMatchesStoredByte(actor)){BattleScene_ResetCommandSelectionAndRestoreFlags(state);Resource_MoveQueuedRecordWithTaggedInput(*(unsigned short*)(actor+8));}
}
