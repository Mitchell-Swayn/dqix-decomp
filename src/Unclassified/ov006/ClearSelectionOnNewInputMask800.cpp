extern "C"
{
    extern char data_02114e30[];
    int Object_TestNewlySetHalfwordMask(void*,int);
    struct Object
    {
        char pad[0x44];
        short *selected;
        char rest[0x347];
        unsigned char state,flag;
    };
}
// Layout projections describe observed offsets; higher-level ownership is unresolved.
// Original: arm9/ov006 @ 0x02158C28; symbol: func_ov006_02158c28; size: 0x48.
extern "C" void ClearSelectionOnNewInputMask800(Object *p)
{
    if(!Object_TestNewlySetHalfwordMask(data_02114e30,0x800))return;
    if(p->selected)*p->selected=-1;
    p->selected=0;
    p->state=12;
    p->flag=0;
}
