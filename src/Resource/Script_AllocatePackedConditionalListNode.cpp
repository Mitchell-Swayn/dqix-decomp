#include <globaldefs.h>
ARM
#pragma always_inline on
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" void* ReadGlobalValueAt02108844();
extern "C" int ReadOneOf204PackedTwoBitValues(volatile unsigned char*,int);
extern "C" void DecodePackedScriptParametersToLists(unsigned,int,void*,void*,void*);
extern "C" void PrependNodeToFieldA0List(unsigned char*,unsigned char*);
extern "C" unsigned data_02109404[];
extern "C" unsigned char data_02109418[];
struct Node {
 unsigned short id;
 unsigned short value:9,a:1,b:1,c:1,d:1,e:1,other:2;
 unsigned byte:8,six:6,five:5,rest:13;
 void* list;
 void* next;
 void SetValue(unsigned short n) {value=n;}
 void SetA(unsigned short n) {a=n;}
 void SetB(unsigned short n) {b=n;}
 void SetC(unsigned short n) {c=n;}
 void SetD(unsigned short n) {d=n;}
 void SetE(unsigned short n) {e=n;}
};
// Original: arm9/main @ 0x02094FE4; symbol: func_02094fe4; size: 0x1F4.
extern "C" int Script_AllocatePackedConditionalListNode(char* params,int count) {
 int value=_ZNK6Script9Parameter5ToIntEv(params);
 int id=_ZNK6Script9Parameter5ToIntEv(params+8);
 int byte=_ZNK6Script9Parameter5ToIntEv(params+16);
 int six=_ZNK6Script9Parameter5ToIntEv(params+24);
 int five=_ZNK6Script9Parameter5ToIntEv(params+32);
 int a=_ZNK6Script9Parameter5ToIntEv(params+40);
 unsigned char* global=(unsigned char*)ReadGlobalValueAt02108844();
 int gate=_ZNK6Script9Parameter5ToIntEv(params+48);
 if(gate>=0) {
 int enabled=ReadOneOf204PackedTwoBitValues(global,gate)==3;
 if(!enabled) return 0;
 }
 Node* node=(Node*)_ZN13SafeAllocator8AllocateEj(data_02109404[3],16);
 node->id=id;
 node->SetValue(value);
 node->byte=byte;
 node->six=six;
 node->five=five;
 node->SetA(a);
 node->SetC(_ZNK6Script9Parameter5ToIntEv(params+56));
 node->SetB(_ZNK6Script9Parameter5ToIntEv(params+64));
 node->SetD(_ZNK6Script9Parameter5ToIntEv(params+72));
 node->e=(unsigned short)_ZNK6Script9Parameter5ToIntEv(params+80);
 node->list=0;
 node->next=0;
 void* extended=0;
 DecodePackedScriptParametersToLists(data_02109404[3],count-11,params+88,&node->list,&extended);
 PrependNodeToFieldA0List(data_02109418,(unsigned char*)node);
 return 1;
}
