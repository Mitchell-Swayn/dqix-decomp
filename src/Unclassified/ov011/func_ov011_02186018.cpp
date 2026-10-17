#include <globaldefs.h>
struct Vector { int x,y,z; };
extern "C" unsigned func_ov011_02184c30(void*);
extern "C" float func_ov011_02184c4c(void*);
extern "C" void* func_ov017_021b2164();
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*,unsigned);
extern "C" void Graphics_InitializeObjectVectorRecord(void*,void*,unsigned,Vector*,int,int);
// Original: arm9/ov011 @ 0x02186018; symbol: func_ov011_02186018; size: 0x10C.
extern "C" unsigned func_ov011_02186018(void* self) {
 unsigned id=func_ov011_02184c30(self);
 Vector vector;
 vector.x=(int)(4096.0f*func_ov011_02184c4c((char*)self+8));
 vector.y=(int)(4096.0f*func_ov011_02184c4c((char*)self+16));
 vector.z=(int)(4096.0f*func_ov011_02184c4c((char*)self+24));
 int a=(int)(4096.0f*func_ov011_02184c4c((char*)self+32));
 int b=(int)(4096.0f*func_ov011_02184c4c((char*)self+40));
 void* owner=func_ov017_021b2164();
 void* list=func_ov011_021849c8(owner);
 if(!func_ov023_021f6880(list,id)) return 0;
 void* item=func_ov023_021f6880(list,0xffff);
 if(!item) return 0;
 Graphics_InitializeObjectVectorRecord(item,owner,(unsigned short)id,&vector,a,b);
 return 1;
}
