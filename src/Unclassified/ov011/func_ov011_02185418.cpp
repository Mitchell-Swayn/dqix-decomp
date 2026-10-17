#include <globaldefs.h>
extern "C" unsigned func_ov011_02184c30(void*);
extern "C" void* func_ov017_021b2164();
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*,unsigned);
extern "C" unsigned OV023_ReadHalfwordField04(void*);
extern "C" void func_ov023_021f7eb8(void*,void*,unsigned,int,int,int,int,unsigned,unsigned,bool);
extern "C" void func_ov011_02184ad8(void*);
// Original: arm9/ov011 @ 0x02185418; symbol: func_ov011_02185418; size: 0xEC.
extern "C" unsigned func_ov011_02185418(void* self) {
 unsigned value;
 unsigned id=func_ov011_02184c30(self);
 value=func_ov011_02184c30((char*)self+8);
 short a=func_ov011_02184c30((char*)self+16);
 short b=func_ov011_02184c30((char*)self+24);
 short c=func_ov011_02184c30((char*)self+32);
 short d=func_ov011_02184c30((char*)self+40);
 unsigned char e=func_ov011_02184c30((char*)self+48);
 unsigned char f=func_ov011_02184c30((char*)self+56);
 bool enabled=func_ov011_02184c30((char*)self+64)!=0;
 void* owner=func_ov017_021b2164();
 void* item=func_ov023_021f6880(func_ov011_021849c8(owner),id);
 if(!item) return 0;
 if(OV023_ReadHalfwordField04(item)!=6) return 0;
 func_ov023_021f7eb8(item,owner,value,a,b,c,d,e,f,enabled);
 func_ov011_02184ad8(owner);
 return 1;
}
