class GameState
{
    public: static GameState *GetInstance();
};
extern "C"
{
    void *Network_GetConnectionManager();
    int Network_IsSessionActive(void*);
    int Network_IsMemberActive(void*,int);
    int GameState_ReadProtagonistObjectIndex(void*);
    unsigned char *GameState_FindIndexedObjectWithFlag1000(void*,int);
    int GameObject_GetAssociatedPartyMemberIndex(void*);
    void PartyStatus_RegisterDisplayedMembers(void*,void*,int);
    void GameState_StoreActivePartySlotList(void*,int,void*);
    void GameState_StoreProtagonistPartySlotList(void*,int,void*);
}
// Layout projections describe observed offsets; higher-level ownership is unresolved.
// Original: arm9/ov017 @ 0x02191234; symbol: func_ov017_02191234; size: 0x19C.
extern "C" void Field_RebuildDisplayedAndProtagonistRosters(unsigned char *p)
{
    void *state=GameState::GetInstance();
    void *connection=Network_GetConnectionManager();
    unsigned char allCount=0,heroCount=0;
    unsigned char all[4],hero[4];
    if(Network_IsSessionActive(connection))
    {
        for(int i=0;i<4;++i)
        {
            if(Network_IsMemberActive(connection,i))
            {
                all[allCount++]=i;
                int isHero=0;
                if(i==GameState_ReadProtagonistObjectIndex(state))
                {
                    hero[heroCount++]=i;
                    isHero=1;
                }
                for(int j=1;j<4;++j)
                {
                    unsigned char *object=GameState_FindIndexedObjectWithFlag1000(state,j);
                    if(object && i==GameObject_GetAssociatedPartyMemberIndex(object))
                    {
                        all[object[0x2d2]]=j;
                        ++allCount;
                        if(isHero)
                        {
                            ++heroCount;
                            hero[object[0x2d2]]=j;
                        }
                    }
                }
            }
        }
    }
    else
    {
        all[allCount++]=0;
        hero[heroCount++]=0;
        for(int j=1;j<4;++j)
        {
            unsigned char *object=GameState_FindIndexedObjectWithFlag1000(state,j);
            if(object)
            {
                all[object[0x2d2]]=j;
                ++allCount;
                hero[object[0x2d2]]=j;
                ++heroCount;
            }
        }
    }
    PartyStatus_RegisterDisplayedMembers(*(void**)(p+0x36d0),all,allCount);
    GameState_StoreActivePartySlotList(state,allCount,all);
    GameState_StoreProtagonistPartySlotList(state,heroCount,hero);
}
