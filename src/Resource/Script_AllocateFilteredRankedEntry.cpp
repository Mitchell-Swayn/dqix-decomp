#include <globaldefs.h>
ARM
extern "C" {
struct Context {short a,b,blocked,key,last;unsigned short serial,group,pad;char** list;unsigned allocator;};
extern Context data_02108cec;
int _ZNK6Script9Parameter5ToIntEv(const void*);
float _ZNK6Script9Parameter7ToFloatEv(void*);
void* _ZN6Script9Parameter9ToVec3fixEP8Vector3i(void*,void*);
char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
void* _ZN9GameState11GetInstanceEv();
int _ZNK9GameState21IsMorningDayOrEveningEv(void*);
void* ReadGlobalValueAt02108844();
void InitializeRecordAndInvalidHalfwordIndices(char*);
void SelectNodeRankFromEntryFlags(void*,void*);
void LinkedList_UnlinkMatchedKeyFromDoublyLinkedNodes(char**,int);
int ReadOneOf204PackedTwoBitValues(volatile unsigned char*,int);
unsigned int Object_ReadParitySelectedFlagForBoundedIndex(unsigned char*,int);
unsigned int TestOneOf204PackedNibbleHighFlags(unsigned char*,int);
}
inline bool HasState(unsigned char* obj,int index,int state){return ReadOneOf204PackedTwoBitValues(obj,index)==state;}
// Original: arm9/main @ 0x0206CBCC; symbol: func_0206cbcc; size: 0x38C.
extern "C" int Script_AllocateFilteredRankedEntry(char* params,int count){
 (data_02108cec.serial)++;
 unsigned char* obj;
 int index=_ZNK6Script9Parameter5ToIntEv(params);
 int state=_ZNK6Script9Parameter5ToIntEv(params+8);
 int time=_ZNK6Script9Parameter5ToIntEv(params+16);
 int group=_ZNK6Script9Parameter5ToIntEv(params+24);
 int key=_ZNK6Script9Parameter5ToIntEv(params+32);
 if(data_02108cec.key!=key){data_02108cec.key=key;data_02108cec.last=-1;data_02108cec.blocked=-1;}
 if(data_02108cec.blocked>0)return 1;
 obj=(unsigned char*)ReadGlobalValueAt02108844();
 if(data_02108cec.last!=index&&data_02108cec.last>-1){
  if(!HasState(obj,index,1)&&!HasState(obj,index,2)&&HasState(obj,data_02108cec.last,3)&&HasState(obj,index,3)){
   if(data_02108cec.last>index)return 1;
  }
 }
 switch(state){
 case -1:if(!HasState(obj,index,0))return 1;break;
 case 3:if(!HasState(obj,index,1))return 1;break;
 case 0:if(!HasState(obj,index,2))return 1;break;
 case 1:if(!Object_ReadParitySelectedFlagForBoundedIndex(obj,index))return 1;break;
 case 2:if(!HasState(obj,index,3))return 1;break;
 case 4:if(!TestOneOf204PackedNibbleHighFlags(obj,index)||!HasState(obj,index,0))return 1;break;
 }
 void* game=_ZN9GameState11GetInstanceEv();
 if(time==1){if(_ZNK9GameState21IsMorningDayOrEveningEv(game))return 1;}
 else if(time==0){if(!_ZNK9GameState21IsMorningDayOrEveningEv(game))return 1;}
 if(group!=data_02108cec.group){
  LinkedList_UnlinkMatchedKeyFromDoublyLinkedNodes(data_02108cec.list,key);return 1;
 }
 obj=(unsigned char*)_ZN13SafeAllocator8AllocateEj(data_02108cec.allocator,0x78);
 if(!obj)return 0;
 InitializeRecordAndInvalidHalfwordIndices((char*)obj);
 *(short*)(obj+0x46)=index;
 obj[10]=(obj[10]&~3)|((unsigned char)time&3);
 *(short*)(obj+2)=group;obj[0]=key;
 if(count<6){LinkedList_UnlinkMatchedKeyFromDoublyLinkedNodes(data_02108cec.list,key);data_02108cec.last=index;return 1;}
 char* next=(char*)_ZN6Script9Parameter9ToVec3fixEP8Vector3i(params+40,obj+16);
 *(short*)(obj+28)=(int)(4096.0f*_ZNK6Script9Parameter7ToFloatEv(next));
 if(count>9)obj[30]=_ZNK6Script9Parameter5ToIntEv(next+8);
 *(unsigned short*)(obj+0x44)=data_02108cec.serial;
 SelectNodeRankFromEntryFlags(data_02108cec.list,obj);
 data_02108cec.last=index;return 1;
}
