class GameState
{
    public: static GameState *GetInstance();
};
extern "C"
{
    void *Object_GetGlobalConnectionState();
    int IsFirstWordNonzero(void*);
    int TestResolvedBitInByteField100C(void*,int);
    int GameState_ReadProtagonistObjectIndex(void*);
    unsigned char *GameState_FindIndexedObjectWithFlag1000(void*,int);
    int ReadFieldAtOffset2D0(void*);
    void RegisterUpToFourIndexedSlots(void*,void*,int);
    void GameState_CopyOffset571DByteBufferAndSetLength(void*,int,void*);
    void GameState_CopyField5718BufferFromSource(void*,int,void*);
}
// Layout projections describe observed offsets; higher-level ownership is unresolved.
// Original: arm9/ov017 @ 0x02191234; symbol: func_ov017_02191234; size: 0x19C.
extern "C" void BuildActiveAndProtagonistSlotLists(unsigned char *p)
{
    void *state=GameState::GetInstance();
    void *connection=Object_GetGlobalConnectionState();
    unsigned char allCount=0,heroCount=0;
    unsigned char all[4],hero[4];
    if(IsFirstWordNonzero(connection))
    {
        for(int i=0;i<4;++i)
        {
            if(TestResolvedBitInByteField100C(connection,i))
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
                    if(object && i==ReadFieldAtOffset2D0(object))
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
    RegisterUpToFourIndexedSlots(*(void**)(p+0x36d0),all,allCount);
    GameState_CopyOffset571DByteBufferAndSetLength(state,allCount,all);
    GameState_CopyField5718BufferFromSource(state,heroCount,hero);
}
