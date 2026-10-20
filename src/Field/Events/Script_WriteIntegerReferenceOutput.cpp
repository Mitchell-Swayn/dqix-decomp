extern "C"
{
    struct Node
    {
        unsigned type;
        unsigned *nested;
    };
}
// Layout projections describe observed offsets; higher-level ownership is unresolved.
// Original: arm9/ov017 @ 0x021D6134; symbol: func_ov017_021d6134; size: 0x14.
extern "C" void Script_WriteIntegerReferenceOutput(Node *p,unsigned value)
{
    if(p->type==3)p->nested[1]=value;
}
