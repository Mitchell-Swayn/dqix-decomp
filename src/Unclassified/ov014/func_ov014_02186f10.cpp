extern "C" {
struct Node { Node* next; unsigned char gap[0x16]; short index; };
struct Service { unsigned char pre[0x36]; short selected; };
struct VisualItem { unsigned char pre[4]; short x,y; unsigned char gap[0xd]; unsigned char flags; };
struct Owner { unsigned char pre[0x5c]; void* pageData; unsigned char gap0[0x38]; void* currentValues; unsigned char gap1[0x1c]; Node* head; Node* page; Service* service; unsigned char gap2[0xc]; short* selected; void* d4; void* visual; unsigned char gap3[0x1c]; unsigned char animation[0x6c]; int visualParameter; unsigned char gap4[8]; short category,choice,unused,count,previous; unsigned char state,phase; unsigned char gap5[6]; short values[8]; };
short FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(Service*,int);void Object_CreateAndConfigureSelectedDisplayPart(Service*,int);void func_ov014_02188a8c(Owner*,int);
extern unsigned short data_02114e30[];extern unsigned char data_02114e54[];int Object_TestNewlySetHalfwordMask(unsigned short*,unsigned);void ReadSelectedCoordinatePair(unsigned char*,unsigned*,unsigned*);short SelectHitEntryAndWriteFlagOutput(Service*,int,short,short,unsigned char*,unsigned char);
// Original: arm9/ov014 @ 0x02186F10; symbol: func_ov014_02186f10; size: 0xE0.
int func_ov014_02186f10(Owner* p){ unsigned x,y;unsigned char changed=0;if(Object_TestNewlySetHalfwordMask(data_02114e30,0x401))changed=1;if(data_02114e54[0x55] && p->selected){ReadSelectedCoordinatePair(data_02114e54,&x,&y);int index=SelectHitEntryAndWriteFlagOutput(p->service,p->category,(short)x,(short)y,&changed,1);if(index<0)return 0;*p->selected=index;if(p->previous!=*p->selected){p->service->selected=*p->selected;Object_CreateAndConfigureSelectedDisplayPart(p->service,p->category);}}return changed;}
}
