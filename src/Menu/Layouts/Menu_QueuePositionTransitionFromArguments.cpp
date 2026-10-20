#include <globaldefs.h>
struct Vector { int x,y,z; };
extern "C" unsigned Menu_ReadScriptArgumentAsInteger(void*);
extern "C" float Menu_ReadScriptArgumentAsFloat(void*);
extern "C" void* Resource_GetSharedLoadState();
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" void* MenuRecordList_LocateByKey(void*,unsigned);
extern "C" void Graphics_InitializeObjectVectorRecord(void*,void*,unsigned,Vector*,int,int);
// Original: arm9/ov011 @ 0x02186018; symbol: func_ov011_02186018; size: 0x10C.
extern "C" unsigned Menu_QueuePositionTransitionFromArguments(void* self) {
 unsigned id=Menu_ReadScriptArgumentAsInteger(self);
 Vector vector;
 vector.x=(int)(4096.0f*Menu_ReadScriptArgumentAsFloat((char*)self+8));
 vector.y=(int)(4096.0f*Menu_ReadScriptArgumentAsFloat((char*)self+16));
 vector.z=(int)(4096.0f*Menu_ReadScriptArgumentAsFloat((char*)self+24));
 int a=(int)(4096.0f*Menu_ReadScriptArgumentAsFloat((char*)self+32));
 int b=(int)(4096.0f*Menu_ReadScriptArgumentAsFloat((char*)self+40));
 void* owner=Resource_GetSharedLoadState();
 void* list=Menu_GetDisplayRecordRegistry(owner);
 if(!MenuRecordList_LocateByKey(list,id)) return 0;
 void* item=MenuRecordList_LocateByKey(list,0xffff);
 if(!item) return 0;
 Graphics_InitializeObjectVectorRecord(item,owner,(unsigned short)id,&vector,a,b);
 return 1;
}
