extern "C" {
struct Node { Node* next; unsigned char gap[0x16]; short index; };
struct Service { unsigned char pre[0x36]; short selected; };
struct VisualItem { unsigned char pre[4]; short x,y; unsigned char gap[0xd]; unsigned char flags; };
struct Owner { unsigned char pre[0x5c]; void* pageData; unsigned char gap0[0x38]; void* currentValues; unsigned char gap1[0x1c]; Node* head; Node* page; Service* service; unsigned char gap2[0xc]; short* selected; void* d4; void* visual; unsigned char gap3[0x1c]; unsigned char animation[0x6c]; int visualParameter; unsigned char gap4[8]; short category,choice,unused,count,previous; unsigned char state,phase; unsigned char gap5[6]; short values[8]; };
short FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(Service*,int);void TextCanvas_CreateAndConfigureDisplayPart(Service*,int);void BestiaryScreen_UpdateSelectedMonsterValue(Owner*,int);
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
extern unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];extern unsigned char Main_UnknownRoleZeroInitializedStorage_Variant4[];int Input_IsKeyMaskNewlyPressed(unsigned short*,unsigned);void ReadSelectedCoordinatePair(unsigned char*,unsigned*,unsigned*);short TextCanvas_SelectEntryAtPoint(Service*,int,short,short,unsigned char*,unsigned char);
// Original: arm9/ov014 @ 0x02186F10; symbol: func_ov014_02186f10; size: 0xE0.
int BestiaryScreen_ProcessSelectionActivation(Owner* p){ unsigned x,y;unsigned char changed=0;if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x401))changed=1;if(Main_UnknownRoleZeroInitializedStorage_Variant4[0x55] && p->selected){ReadSelectedCoordinatePair(Main_UnknownRoleZeroInitializedStorage_Variant4,&x,&y);int index=TextCanvas_SelectEntryAtPoint(p->service,p->category,(short)x,(short)y,&changed,1);if(index<0)return 0;*p->selected=index;if(p->previous!=*p->selected){p->service->selected=*p->selected;TextCanvas_CreateAndConfigureDisplayPart(p->service,p->category);}}return changed;}
}
