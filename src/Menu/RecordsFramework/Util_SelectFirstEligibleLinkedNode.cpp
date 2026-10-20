#include <globaldefs.h>
ARM
struct State;
extern "C" int ReadSelectedCoordinatePair(void*,int*,int*);
extern "C" void Menu_StartIndexedCallback(State*,unsigned);
// Original data: arm9/main @ 0x2114e54; symbol: data_02114e54.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 112 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant4[];
struct Node {virtual int V0();virtual int V1();virtual int V2();virtual int V3();virtual int V4();virtual int V5();virtual int V6();virtual int V7();virtual int V8();virtual int V9();virtual int V10();virtual int V11();virtual int V12();virtual int V13();virtual int V14();virtual int V15();virtual int V16();virtual int V17();virtual int V18();virtual int V19();virtual int V20();virtual int V21();virtual int V22();virtual int V23();virtual int V24();virtual int V25();virtual int V26();virtual int V27();virtual int V28();virtual int V29();virtual int V30();virtual int V31();virtual int V32();virtual int V33();virtual int V34();virtual int V35();virtual int V36();virtual int V37();virtual int V38();virtual int V39();virtual int V40();virtual int V41();virtual int V42();virtual int V43();virtual int V44();virtual int V45();virtual int V46();unsigned char pad[0x14];Node* next;};
// Original: arm9/ov023 @ 0x021F6A1C; symbol: func_ov023_021f6a1c; size: 0x9C.
extern "C" void Util_SelectFirstEligibleLinkedNode(Node** head,State* state){
 Node* node;
 if(Main_UnknownRoleZeroInitializedStorage_Variant4[0x55]){
 int x,y;ReadSelectedCoordinatePair(Main_UnknownRoleZeroInitializedStorage_Variant4,&x,&y);
 node=*head;
 while(node){
 if(node->V46() && node->V42()>0){
 Menu_StartIndexedCallback(state,node->V42());
 break;
 }
 node=node->next;
 }
 }
}
