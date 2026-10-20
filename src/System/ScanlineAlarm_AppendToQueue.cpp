#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2111654; symbol: data_02111654.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Node {unsigned char pad[20];Node* next;Node* prev;};struct Queue {unsigned char pad[12];Node* head;Node* tail;};extern Queue OSInitVAlarm_UnknownRoleZeroInitializedStorage;extern "C" void System_ConfigureInterruptFourAndDisplayStatusBit();
// Original: arm9/main @ 0x020C934C; symbol: func_020c934c; size: 0x38.
extern "C" void ScanlineAlarm_AppendToQueue(Node* node){Node* tail=OSInitVAlarm_UnknownRoleZeroInitializedStorage.tail;node->next=tail;node->prev=0;OSInitVAlarm_UnknownRoleZeroInitializedStorage.tail=node;if(tail){tail->prev=node;return;}OSInitVAlarm_UnknownRoleZeroInitializedStorage.head=node;System_ConfigureInterruptFourAndDisplayStatusBit();}
