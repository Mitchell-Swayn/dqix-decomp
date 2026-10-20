#include <globaldefs.h>
struct Item { char pad[20]; unsigned short a,b; unsigned value; };
extern "C" void Vector3i_ClearThreeWords(void*); extern "C" void Network_InitializeRecordPoolAndPeerBuffers(void*);
// Original: arm9/main @ 0x0202C7BC; symbol: func_0202c7bc; size: 0x58.
extern "C" void* Network_ConstructCommandRecordPool(char* self) { Item* item=(Item*)self; char* end=self+0x1500; do { item->a=0;item->b=0;item->value=0;++item; }while((char*)item<end); Vector3i_ClearThreeWords(end);Vector3i_ClearThreeWords(self+0x150c);Vector3i_ClearThreeWords(self+0x1518);Network_InitializeRecordPoolAndPeerBuffers(self);return self; }
