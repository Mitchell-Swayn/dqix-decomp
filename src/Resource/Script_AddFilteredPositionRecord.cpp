#include <globaldefs.h>
ARM
struct Context {unsigned char c,b,a,pad[7];unsigned short serial,group;unsigned short gap;void* head;void* allocator;};
struct Bits {unsigned char value:2,rest:6;};
extern "C" Context data_02108cec;
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" bool _ZNK9GameState21IsMorningDayOrEveningEv(void*);
extern "C" void LinkedList_UnlinkMatchedKeyFromDoublyLinkedNodes(void*,int);
extern "C" char* _ZN13SafeAllocator8AllocateEj(void*,unsigned);
extern "C" void InitializeRecordAndInvalidHalfwordIndices(char*);
extern "C" char* _ZN6Script9Parameter9ToVec3fixEP8Vector3i(void*,void*);
extern "C" float _ZNK6Script9Parameter7ToFloatEv(void*);
extern "C" void SelectNodeRankFromEntryFlags(void*,void*);
// Original: arm9/main @ 0x0206C0F8; symbol: func_0206c0f8; size: 0x1C8.
extern "C" bool Script_AddFilteredPositionRecord(char* args,int count) {
 char* record;
 data_02108cec.serial++;
 int a=_ZNK6Script9Parameter5ToIntEv(args);
 if(a!=data_02108cec.a)return true;
 int b=_ZNK6Script9Parameter5ToIntEv(args+8);
 if(b!=data_02108cec.b)return true;
 int c=_ZNK6Script9Parameter5ToIntEv(args+16);
 if(c!=data_02108cec.c)return true;
 int mode=_ZNK6Script9Parameter5ToIntEv(args+24);
 void* game=_ZN9GameState11GetInstanceEv();
 if(mode==1) {if(_ZNK9GameState21IsMorningDayOrEveningEv(game))return true;}
 else if(mode==0) {if(!_ZNK9GameState21IsMorningDayOrEveningEv(game))return true;}
 int group=_ZNK6Script9Parameter5ToIntEv(args+32);
 int key=_ZNK6Script9Parameter5ToIntEv(args+40);
 if(group!=data_02108cec.group) {
 LinkedList_UnlinkMatchedKeyFromDoublyLinkedNodes(data_02108cec.head,key);return true;
 }
 record=_ZN13SafeAllocator8AllocateEj(data_02108cec.allocator,120);
 if(!record)return false;
 InitializeRecordAndInvalidHalfwordIndices(record);
 record[4]=a;record[5]=b;record[6]=c;
 ((Bits*)(record+10))->value=(unsigned char)mode;
 *(unsigned short*)(record+2)=group;
 record[0]=key;
 if(count<7) {LinkedList_UnlinkMatchedKeyFromDoublyLinkedNodes(data_02108cec.head,key);return true;}
 char* next=_ZN6Script9Parameter9ToVec3fixEP8Vector3i(args+48,record+16);
 *(short*)(record+28)=(int)(4096.0f*_ZNK6Script9Parameter7ToFloatEv(next));
 if(count>10)record[30]=_ZNK6Script9Parameter5ToIntEv(next+8);
 *(unsigned short*)(record+0x44)=data_02108cec.serial;
 SelectNodeRankFromEntryFlags(data_02108cec.head,record);
 return true;
}
