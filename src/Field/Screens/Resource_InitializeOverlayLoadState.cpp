class SafeAllocator
{
    public: void ResetAllocatorPointer();
};
extern "C"
{
    void LinkedQueue_InitializeNodeStatus(void*);
// Original data: arm9/ov017 @ 0x21d83f0; symbol: data_ov017_021d83f0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
    extern unsigned ResourceGetSharedLoadState_UnknownRoleZeroInitializedStorage[];
    struct Flags
    {
        unsigned a:1,b:1,c:1,d:1,e:1,f:1,rest:26;
    };
    struct Object
    {
        unsigned char tag;
        char pad[7];
        unsigned value,index;
        SafeAllocator allocator;
        char gap[0x13];
        unsigned char byte24;
        char gap2[11];
        unsigned word30;
        unsigned word34;
        Flags flags;
        unsigned char a,b,c,pad3;
        unsigned d,e;
        unsigned char f;
    };
}
// Layout projections describe observed offsets; higher-level ownership is unresolved.
// Original: arm9/ov017 @ 0x021B2174; symbol: func_ov017_021b2174; size: 0x8C.
extern "C" void Resource_InitializeOverlayLoadState(Object *p)
{
    LinkedQueue_InitializeNodeStatus(p);
    p->tag=0x2d;
    p->value=0;
    p->index=-1;
    ResourceGetSharedLoadState_UnknownRoleZeroInitializedStorage[1]=0;
    p->allocator.ResetAllocatorPointer();
    p->flags.a=0;
    p->flags.b=0;
    p->flags.c=0;
    p->byte24=0;
    p->word30=0;
    p->flags.d=1;
    p->flags.e=0;
    p->flags.f=0;
    p->a=0xff;
    p->b=0xff;
    p->c=0;
    p->d=0;
    p->e=0;
    p->f=0;
}
