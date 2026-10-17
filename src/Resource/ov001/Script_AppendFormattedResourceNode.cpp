#include <globaldefs.h>
#include <std_library_functions.h>
ARM
struct GameResources;struct IntegerParameterView;
struct Node { unsigned char type;char text[0x22];char pad;int id;Node* next;unsigned char flag; };
extern "C" unsigned int data_ov001_021658b8;
extern "C" char data_ov001_02165745[];
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned int,unsigned int);
extern "C" GameResources* GameResources_GetInstance();
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView*);
extern "C" unsigned int OV017_ReadWordField04(void*);
// Original: arm9/ov001 @ 0x021612C8; symbol: func_ov001_021612c8; size: 0xAC.
extern "C" int Script_AppendFormattedResourceNode(unsigned char* parameters) {
Node* node;
unsigned char* status=*(unsigned char**)((unsigned char*)GameResources_GetInstance()+0x3734);
node=(Node*)_ZN13SafeAllocator8AllocateEj(data_ov001_021658b8,0x30);
node->type=0;memset(node->text,0,0x22);node->id=-1;node->next=0;node->flag=0;
sprintf(node->text,data_ov001_02165745,OV017_ReadWordField04(parameters));
node->type=ReadScriptParameterAsInteger((IntegerParameterView*)(parameters+8));
Node* tail=*(Node**)(status+0xd4);
if(!tail)*(Node**)(status+0xd4)=node;
else {while(tail->next)tail=tail->next;tail->next=node;}
return 1;
}
