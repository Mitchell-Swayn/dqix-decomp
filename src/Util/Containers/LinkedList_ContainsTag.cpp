// Reconstructed from original ARM instructions; field names remain unresolved.
struct Node { signed char tag; char pad[3]; Node* next; };
// Original: arm9/main @ 0x02046B60; symbol: func_02046b60; size: 0x2C.
 extern "C" int LinkedList_ContainsTag(Node** p,int tag) { Node* n=*p; while(n) { if(n->tag==tag) return 1; n=n->next; } return 0; }
