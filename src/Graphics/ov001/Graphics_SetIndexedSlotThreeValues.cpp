#include <globaldefs.h>
ARM
extern "C" void SetThreeValuesOnFirstAvailableRepresentation(unsigned char*,unsigned,unsigned,unsigned);
struct Slot {unsigned type;int pad[2];unsigned char* object;};
// Original: arm9/ov001 @ 0x0216427C; symbol: func_ov001_0216427c; size: 0xA4.
extern "C" int Graphics_SetIndexedSlotThreeValues(Slot* slots,int index,unsigned a,unsigned b,unsigned c){
 if(index<0 || index>=32)return 0;
 Slot* p=&slots[index];
 switch(p->type){
 case 0:case 1:case 4:case 5:{
 unsigned char* obj=p->object;
 if(!obj)return 0;
 *(unsigned*)(obj+0x44)=a;*(unsigned*)(obj+0x48)=b;*(unsigned*)(obj+0x4c)=c;
 return 1;
 }
 case 2:case 6:
 if(!p->object)return 0;
 SetThreeValuesOnFirstAvailableRepresentation(p->object,a,b,c);
 return 1;
 default:return 0;
 }
}
