#include <globaldefs.h>
#include <Resource/Script.h>
#include <Memory/SafeAllocator.h>
#include <std_library_functions.h>
struct Node{char pad[0x44];unsigned short id;char pad2[14];void* a;void* b;char pad3[20];Node* next;};struct State{char pad[10];unsigned short id;char pad2[4];void* list;SafeAllocator* allocator;};extern "C" State data_02108cec;extern "C" Node* LinkedList_FindNodeByUnsignedKey(void*,int);
// Original: arm9/main @ 0x0206D7E4; symbol: func_0206d7e4; size: 0x104.
extern "C" ARM int Script_AllocateMatchingNodeStrings(Script::Parameter* params){Node* n=LinkedList_FindNodeByUnsignedKey(data_02108cec.list,params->ToInt());if(!n)return 0;while(n){if(n->id==data_02108cec.id)break;n=n->next;}if(!n)return 0;const char* a=params[1].ToString();unsigned short length=strlen(a);n->a=data_02108cec.allocator->Allocate(length+1);if(n->a){memset(n->a,0,length+1);memcpy(n->a,a,length);}const char* b=params[2].ToString();length=strlen(b);n->b=data_02108cec.allocator->Allocate(length+1);if(n->b){memset(n->b,0,length+1);memcpy(n->b,b,length);}return 1;}
