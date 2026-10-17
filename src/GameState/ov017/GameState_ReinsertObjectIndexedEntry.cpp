#include <globaldefs.h>
ARM
struct Owner;
extern "C" void* GameState_GetObjectWithFlag100(void*,int);
extern "C" unsigned char* ReadWordFieldAtOffset150(void*);
extern "C" void UpdateIndexedEntryAndReinsertIntoList(Owner*,int,int,unsigned,int,unsigned,unsigned,unsigned char);
// Original: arm9/ov017 @ 0x021CE658; symbol: func_ov017_021ce658; size: 0xA8.
extern "C" void GameState_ReinsertObjectIndexedEntry(void*,unsigned char* record,void* gs,Owner* owner){
 int index=*(signed char*)(record+4);
 void* obj=GameState_GetObjectWithFlag100(gs,index);
 if(!obj)return;
 unsigned char* p=ReadWordFieldAtOffset150(obj);
 if(!p)return;
 unsigned value=*(unsigned*)(p+0x950);
 int type=*(signed char*)(record+5);
 unsigned short previous=*(unsigned short*)(p+0x16c+value*2);
 if(type<0)return;
 if(type==0)UpdateIndexedEntryAndReinsertIntoList(owner,index,previous,value,0,0,0,record[6]);
 else UpdateIndexedEntryAndReinsertIntoList(owner,index,type,value,0,0,0,record[6]);
}
