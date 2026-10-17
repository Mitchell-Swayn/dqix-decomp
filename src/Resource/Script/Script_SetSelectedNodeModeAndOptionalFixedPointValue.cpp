#include <globaldefs.h>
#include <Resource/Script.h>
struct Node{char pad[10];unsigned char low:3,mode:3,high:2;char pad2[0x39];unsigned short id;char pad3[0x1a];int value;char pad4[12];Node* next;};struct State{char pad[10];unsigned short id;char pad2[4];void* list;};extern "C" State data_02108cec;extern "C" Node* LinkedList_FindNodeByUnsignedKey(void*,int);
// Original: arm9/main @ 0x0206D734; symbol: func_0206d734; size: 0xB0.
extern "C" ARM int Script_SetSelectedNodeModeAndOptionalFixedPointValue(Script::Parameter* p,int count){Node* n=LinkedList_FindNodeByUnsignedKey(data_02108cec.list,p[0].ToInt());if(!n)return 0;while(n){if(n->id==data_02108cec.id)break;n=n->next;}if(!n)return 0;n->mode=(unsigned char)p[1].ToInt();if(count>2)n->value=(int)(4096.f*p[2].ToFloat());return 1;}
