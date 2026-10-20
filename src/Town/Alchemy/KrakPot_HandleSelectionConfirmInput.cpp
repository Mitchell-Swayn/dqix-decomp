extern "C"
{
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2114e54; symbol: data_02114e54.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 112 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern unsigned char KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[],Main_UnknownRoleZeroInitializedStorage_Variant4[];
    int Input_IsKeyMaskNewlyPressed(void*,int);
    int Window_IsVisible(void*);
    int Window_GetConfirmedOptionForActiveInput(void*);
    void ReadSelectedCoordinatePair(void*,int*,int*);
    int TextCanvas_SelectEntryAtPoint(void*,int,int,int,unsigned char*,unsigned char);
    void TextCanvas_CreateAndConfigureDisplayPart(void*,int);
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
extern "C" int KrakPot_HandleSelectionConfirmInput(Object *p)
{
    unsigned char active=0;
    if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,1))active=1;
    if(p->flags&2)
    {
        if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x400))active=1;
    }
    if(p->input && Window_IsVisible(p->input))
    {
        int i=Window_GetConfirmedOptionForActiveInput(p->input);
        if(i>=0)
        {
            active=1;
            *p->selected=i+0x22;
        }
    }
    else if(Main_UnknownRoleZeroInitializedStorage_Variant4[0x55] && p->selected)
    {
        int x,y;
        ReadSelectedCoordinatePair(Main_UnknownRoleZeroInitializedStorage_Variant4,&x,&y);
        p->previous=*p->selected;
        int i=TextCanvas_SelectEntryAtPoint(p->display,p->kind,(short)x,(short)y,&active,1);
        if(i<0)return 0;
        *p->selected=i;
        if(p->previous!=*p->selected)
        {
            p->display->selected=*p->selected;
            TextCanvas_CreateAndConfigureDisplayPart(p->display,p->kind);
        }
    }
    return active;
}
