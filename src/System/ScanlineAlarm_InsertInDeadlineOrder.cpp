#include <globaldefs.h>
// Original data: arm9/main @ 0x2111654; symbol: data_02111654.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Node { unsigned pad[3];unsigned key;short priority;unsigned short unused; Node *prev,*next; };struct List { unsigned pad[3];Node *first; }; extern "C" List OSInitVAlarm_UnknownRoleZeroInitializedStorage;extern "C" void System_ConfigureInterruptFourAndDisplayStatusBit(Node *); extern "C" void ScanlineAlarm_AppendToQueue(Node *);
// Original: arm9/main @ 0x020C92D0; symbol: func_020c92d0; size: 0x7C.
 extern "C" void ScanlineAlarm_InsertInDeadlineOrder(Node *node) { Node *at=OSInitVAlarm_UnknownRoleZeroInitializedStorage.first;if(at) { unsigned key=node->key; do { if(at->key>=key && (at->key!=key || at->priority>node->priority)) { Node *prev=at->prev;node->prev=prev;node->next=at;at->prev=node;if(prev) { prev->next=node;return; } OSInitVAlarm_UnknownRoleZeroInitializedStorage.first=node;System_ConfigureInterruptFourAndDisplayStatusBit(node);return; } at=at->next; }while(at); }ScanlineAlarm_AppendToQueue(node); }
