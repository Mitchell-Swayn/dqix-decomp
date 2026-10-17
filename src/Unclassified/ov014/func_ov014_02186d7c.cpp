extern "C" {
struct Table { unsigned short first, count, n, m; unsigned pad; unsigned* base; unsigned char* relocBase; };
struct Node { Node* next; };
struct Owner { unsigned char pad[0xb8]; Node* head; Node* selected; void* service; unsigned char gap[0xc]; short* linked; unsigned char gap2[0xa6]; unsigned char state, phase, other[3], closed; };
struct Stream { unsigned char data[0x14]; short index; unsigned short active; int handle; void* source; };
void Graphics_ResetCountedTransferRecordsAtOffset2C(void*); void ProcessEachE0ByteRecord(void*); void func_0207fe80(void*,int,int,int); void SetValueZeroForEachThirtyTwoByteEntry(void*); void func_ov014_02186e2c(void*);
// Original: arm9/ov014 @ 0x02186D7C; symbol: func_ov014_02186d7c; size: 0x4C.
 void func_ov014_02186d7c(Owner* p) { if(!p->state)return;Graphics_ResetCountedTransferRecordsAtOffset2C(p->service);ProcessEachE0ByteRecord(p->service);func_0207fe80(p->service,1,0,1);SetValueZeroForEachThirtyTwoByteEntry(p->service);func_ov014_02186e2c(p); }
}
