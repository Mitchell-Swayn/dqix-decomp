#include <globaldefs.h>
ARM
extern "C" int _ZNK8Object3D19HasAnimationStoppedEv(void*);
struct Slot {unsigned type;int pad[2];unsigned char* object;};
// Original: arm9/ov001 @ 0x02164624; symbol: func_ov001_02164624; size: 0x94.
extern "C" int Graphics_HasIndexedSlotAnimationStopped(Slot* slots,int index){
 if(index<0 || index>=32)return 0;
 Slot* p=&slots[index];
 switch(p->type){
 case 0:case 1:case 4:case 5:
 if(!p->object)return 0;
 return _ZNK8Object3D19HasAnimationStoppedEv(p->object);
 case 6:
 if(!p->object)return 0;
 void* obj=*(void**)(p->object+0x18);
 if(!obj)return 0;
 return _ZNK8Object3D19HasAnimationStoppedEv(obj);
 default:return 0;
 }
}
