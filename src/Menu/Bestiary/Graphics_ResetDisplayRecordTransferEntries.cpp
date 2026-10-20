extern "C" {
struct Table { unsigned short first, count, n, m; unsigned pad; unsigned* base; unsigned char* relocBase; };
struct Node { Node* next; };
struct Owner { unsigned char pad[0xb8]; Node* head; Node* selected; void* service; unsigned char gap[0xc]; short* linked; unsigned char gap2[0xa6]; unsigned char state, phase, other[3], closed; };
struct Stream { unsigned char data[0x14]; short index; unsigned short active; int handle; void* source; };
void Graphics_ResetCountedTransferEntriesWithModeZero(void*); void BestiaryDetail_RenderLoadedPanels(void*);
// Original: arm9/ov014 @ 0x02186DC8; symbol: func_ov014_02186dc8; size: 0x28.
 void Graphics_ResetDisplayRecordTransferEntries(Owner* p) { if(p->state) Graphics_ResetCountedTransferEntriesWithModeZero(p->service); BestiaryDetail_RenderLoadedPanels(p); }
}
