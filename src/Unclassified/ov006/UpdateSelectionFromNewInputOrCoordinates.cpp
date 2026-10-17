extern "C"
{
    extern unsigned char data_02114e30[],data_02114e54[];
    int Object_TestNewlySetHalfwordMask(void*,int);
    int ReadBit(void*);
    int ReadSelectionWhenInputActiveOrMinusOne(void*);
    void ReadSelectedCoordinatePair(void*,int*,int*);
    int SelectHitEntryAndWriteFlagOutput(void*,int,int,int,unsigned char*,unsigned char);
    void Object_CreateAndConfigureSelectedDisplayPart(void*,int);
    struct Display
    {
        char pad[0x36];
        short selected;
    };
    struct Object
    {
        char pad[0x14];
        Display *display;
        void *input;
        char mid[0x28];
        short *selected;
        char rest[0x316];
        short previous;
        char gap[14];
        short kind;
        char tail[0x24];
        unsigned short flags;
    };
}
// Layout projections describe observed offsets; higher-level ownership is unresolved.
// Original: arm9/ov006 @ 0x02158A28; symbol: func_ov006_02158a28; size: 0x150.
extern "C" int UpdateSelectionFromNewInputOrCoordinates(Object *p)
{
    unsigned char active=0;
    if(Object_TestNewlySetHalfwordMask(data_02114e30,1))active=1;
    if(p->flags&2)
    {
        if(Object_TestNewlySetHalfwordMask(data_02114e30,0x400))active=1;
    }
    if(p->input && ReadBit(p->input))
    {
        int i=ReadSelectionWhenInputActiveOrMinusOne(p->input);
        if(i>=0)
        {
            active=1;
            *p->selected=i+0x22;
        }
    }
    else if(data_02114e54[0x55] && p->selected)
    {
        int x,y;
        ReadSelectedCoordinatePair(data_02114e54,&x,&y);
        p->previous=*p->selected;
        int i=SelectHitEntryAndWriteFlagOutput(p->display,p->kind,(short)x,(short)y,&active,1);
        if(i<0)return 0;
        *p->selected=i;
        if(p->previous!=*p->selected)
        {
            p->display->selected=*p->selected;
            Object_CreateAndConfigureSelectedDisplayPart(p->display,p->kind);
        }
    }
    return active;
}
