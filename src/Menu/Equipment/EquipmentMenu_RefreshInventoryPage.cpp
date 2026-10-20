class GameState
{
    public: static GameState *GetInstance();
};
extern "C"
{
    void *GameState_GetIndexList(void*);
    short *Inventory_GetGroupItemIds(void*,int);
    signed char *Inventory_GetGroupQuantities(void*,int);
// Original data: arm9/ov005 @ 0x215cd60; symbol: data_ov005_0215cd60.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0001040205030607.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov005.md.
    extern unsigned char EquipmentMenuRefreshInventoryPage_UnknownRoleInitializedBytes[];
    struct Row
    {
        short value;
        signed char quantity;
        unsigned char equal;
        char pad[20];
        short comparison;
        short tail;
    };
}
// Layout projections describe observed offsets; higher-level ownership is unresolved.
// Original: arm9/ov005 @ 0x021555C0; symbol: func_ov005_021555c0; size: 0xB0.
extern "C" void EquipmentMenu_RefreshInventoryPage(unsigned char *p)
{
    unsigned char *list=(unsigned char*)GameState_GetIndexList(GameState::GetInstance());
    short *values=Inventory_GetGroupItemIds(list+0x1d4,EquipmentMenuRefreshInventoryPage_UnknownRoleInitializedBytes[p[0x3dbc]]);
    signed char *quantities=Inventory_GetGroupQuantities(list+0x1d4,EquipmentMenuRefreshInventoryPage_UnknownRoleInitializedBytes[p[0x3dbc]]);
    int group=(signed char)p[0x3dbd];
    for(int i=0;i<16;++i)
    {
        Row *row=&((Row*)(p+0x2d90))[i+8];
        int n=i+(group<<4);
        short v=values[n];
        signed char q=quantities[n];
        if(v==row->comparison)row->equal=1;
        else row->equal=0;
        row->value=v;
        row->quantity=q;
    }
}
