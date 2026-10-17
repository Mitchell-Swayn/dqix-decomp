#include "globaldefs.h"
#pragma optimize_for_size off
ARM
struct Parameter{unsigned words[2];};struct Node{unsigned char pad[12];unsigned flags;unsigned char pad2[0x2c];int value;unsigned pad3;unsigned short id;unsigned char pad4[0x2a];Node*next;};struct State{unsigned char pad[10];unsigned short id;unsigned pad2;void*list;};extern "C" State data_02108cec;extern "C" int _ZNK6Script9Parameter5ToIntEv(const Parameter*);extern "C" float _ZNK6Script9Parameter7ToFloatEv(const Parameter*);extern "C" Node* LinkedList_FindNodeByUnsignedKey(void*,int);
// Original: arm9/main @ 0x0206D3D4; symbol: func_0206d3d4; size: 0x90.
extern "C" int Script_SetMatchingNodeFixedPointValue(const Parameter*p){int id=_ZNK6Script9Parameter5ToIntEv(p);Node*n=LinkedList_FindNodeByUnsignedKey(data_02108cec.list,id);if(!n)return 0;while(n){if(n->id==data_02108cec.id)break;n=n->next;}if(!n)return 0;float value=_ZNK6Script9Parameter7ToFloatEv(p+1);n->value=(int)(4096.0f*value);n->flags|=0x800;return 1;}
