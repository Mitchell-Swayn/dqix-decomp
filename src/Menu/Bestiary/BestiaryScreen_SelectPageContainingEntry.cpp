extern "C" {
struct Node { Node* next; unsigned char gap[0x16]; short index; };
struct Service { unsigned char pre[0x36]; short selected; };
struct VisualItem { unsigned char pre[4]; short x,y; unsigned char gap[0xd]; unsigned char flags; };
struct Owner { unsigned char pre[0x5c]; void* pageData; unsigned char gap0[0x38]; void* currentValues; unsigned char gap1[0x1c]; Node* head; Node* page; Service* service; unsigned char gap2[0xc]; short* selected; void* d4; void* visual; unsigned char gap3[0x1c]; unsigned char animation[0x6c]; int visualParameter; unsigned char gap4[8]; short category,choice,unused,count,previous; unsigned char state,phase; unsigned char gap5[6]; short values[8]; };
short FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(Service*,int);void TextCanvas_CreateAndConfigureDisplayPart(Service*,int);void BestiaryScreen_UpdateSelectedMonsterValue(Owner*,int);
// Original: arm9/ov014 @ 0x02187228; symbol: func_ov014_02187228; size: 0xB4.
void BestiaryScreen_SelectPageContainingEntry(Owner* p,Node* target){p->page=p->head;p->count=27;if(p->service)p->count=FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(p->service,5);if(!target)return;Node* n;Node* page;short index;Node* first=p->head;index=0;n=first;page=first;short reset=0;while(n){if(index%16==0){page=n;index=reset;}if(n==target)break;index++;n=n->next;}if(!n){index=0;page=first;}p->count+=index;p->page=page;}
}
