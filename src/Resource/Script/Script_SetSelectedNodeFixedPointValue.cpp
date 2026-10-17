#include <globaldefs.h>
ARM
#pragma optimize_for_size off
#include <Resource/Script.h>
struct Node{unsigned char pad[0x38];int value;unsigned char pad3c[8];unsigned short id;unsigned char pad46[0x2a];Node* next;};struct State{unsigned char pad[10];unsigned short id;int padc;void* object;};extern "C" {extern State data_02108cec;Node* LinkedList_FindNodeByUnsignedKey(void*,int);
// Original: arm9/main @ 0x0206CB48; symbol: func_0206cb48; size: 0x84.
int Script_SetSelectedNodeFixedPointValue(Script::Parameter* p){int id=p->ToInt();Node* n=LinkedList_FindNodeByUnsignedKey(data_02108cec.object,id);if(!n)return 0;while(n){if(n->id==data_02108cec.id)break;n=n->next;}if(!n)return 0;n->value=(int)(4096.0f*(p+1)->ToFloat());return 1;}}
