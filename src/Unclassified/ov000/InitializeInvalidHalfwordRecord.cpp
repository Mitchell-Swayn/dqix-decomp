extern "C"
{
    void *memset(void *,int,unsigned);
    struct Record
    {
        char head[12];
        short index;
        char entries[6];
        char rest[12];
        unsigned tail;
    };
}
// Layout projections describe observed offsets; higher-level ownership is unresolved.
// Original: arm9/ov000 @ 0x02157CDC; symbol: func_ov000_02157cdc; size: 0x38.
extern "C" void InitializeInvalidHalfwordRecord(Record *p)
{
    memset(p,0,0x20);
    memset(p->entries,-1,6);
    p->index=-1;
    p->tail=0;
}
