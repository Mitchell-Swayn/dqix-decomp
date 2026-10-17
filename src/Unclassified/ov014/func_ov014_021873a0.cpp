extern "C" {
struct Node { Node* next; unsigned char gap[0x16]; short index; };
struct Service { unsigned char pre[0x36]; short selected; };
struct VisualItem { unsigned char pre[4]; short x,y; unsigned char gap[0xd]; unsigned char flags; };
struct Owner { unsigned char pre[0x5c]; void* pageData; unsigned char gap0[0x38]; void* currentValues; unsigned char gap1[0x1c]; Node* head; Node* page; Service* service; unsigned char gap2[0xc]; short* selected; void* d4; void* visual; unsigned char gap3[0x1c]; unsigned char animation[0x6c]; int visualParameter; unsigned char gap4[8]; short category,choice,unused,count,previous; unsigned char state,phase; unsigned char gap5[6]; short values[8]; };
short FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(Service*,int);void Object_CreateAndConfigureSelectedDisplayPart(Service*,int);void func_ov014_02188a8c(Owner*,int);
// Original: arm9/ov014 @ 0x021873A0; symbol: func_ov014_021873a0; size: 0xB0.
Node* func_ov014_021873a0(Owner* p) { Service* service=p->service; short first=FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(service,5); short index=p->count-first;Node* n=p->page;short offset=0;while(n){if(index==offset || !n->next)break;++offset;n=n->next;}if(!n){p->page=p->head;offset=0;}p->count=offset+FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(service,5);if(n){func_ov014_02188a8c(p,n->index);p->currentValues=p->values;}return n; }
}
