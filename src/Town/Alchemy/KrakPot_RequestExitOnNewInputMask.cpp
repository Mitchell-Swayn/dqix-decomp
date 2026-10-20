extern "C"
{
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern char KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
    int Input_IsKeyMaskNewlyPressed(void*,int);
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
extern "C" void KrakPot_RequestExitOnNewInputMask(Object *p)
{
    if(!Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x800))return;
    if(p->selected)*p->selected=-1;
    p->selected=0;
    p->state=12;
    p->flag=0;
}
