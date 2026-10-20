#include <globaldefs.h>
ARM
struct Object;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState20GetGameObjectByIndexEi(void*,int);
extern "C" void* _ZN8Vector3iaSERKS_(void*,const void*);
extern "C" void* Network_GetCommandRecordPool();
extern "C" void Network_QueueOutgoingRecord(Object*,const void*,short);
struct Record {unsigned char type; int position[3]; unsigned short value; unsigned char index,mode;};
// Original: arm9/ov017 @ 0x021CEE78; symbol: func_ov017_021cee78; size: 0x68.
// Queues type 0x14 containing indexed object's position, word-0x54 low half and mode.
extern "C" void GameState_QueueIndexedObjectPosition(int index,int mode) {
 unsigned char *object=(unsigned char*)_ZN9GameState20GetGameObjectByIndexEi(_ZN9GameState11GetInstanceEv(),index);
 if(object){Object *queue=(Object*)Network_GetCommandRecordPool(); Record r; r.type=0x14;r.index=index;
 _ZN8Vector3iaSERKS_(r.position,object+0x44);r.value=*(int*)(object+0x54);r.mode=mode;
 Network_QueueOutgoingRecord(queue,&r,0);}
}
