class GameState
{
    public: static GameState *GetInstance();
    void *GetCombatantByIndex(int);
};
extern "C"
{
    struct Values
    {
        unsigned short current,pad,maximum;
    };
    struct Object
    {
        char pad[0x138];
        Values *values;
    };
}
// Layout projections describe observed offsets; higher-level ownership is unresolved.
// Original: arm9/ov000 @ 0x0215A16C; symbol: func_ov000_0215a16c; size: 0x68.
extern "C" short Combat_AddHealthUpToMaximum(void *, int index, int amount, short *applied)
{
    Object *p=(Object*)GameState::GetInstance()->GetCombatantByIndex(index);
    if(!p)return 0;
    int value=p->values->current;
    *applied=amount;
    value+=amount;
    if(value>p->values->maximum)
    {
        *applied=p->values->maximum-p->values->current;
        value=p->values->maximum;
    }
    p->values->current=value;
    return value;
}
