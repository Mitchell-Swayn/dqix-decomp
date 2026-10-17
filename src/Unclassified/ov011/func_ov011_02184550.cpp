#include <globaldefs.h>
struct State { char header[0xa8]; unsigned fielda8,fieldac; char padb0[8]; char memberb8[0x54]; };
extern "C" void* _ZN13SafeAllocator8AllocateEj(void*,unsigned);
extern "C" void DisableInterruptsAndHaltForever();
extern "C" void Resource_InitializeSb2ScriptBuffers(void*,unsigned,void*,unsigned,void*,unsigned);
extern "C" void func_ov011_021888ec(void*);
// Original: arm9/ov011 @ 0x02184550; symbol: func_ov011_02184550; size: 0x78.
extern "C" void func_ov011_02184550(State* self,void* allocator,unsigned a,unsigned b) {
 self->fielda8=a;
 self->fieldac=b;
 void* block=_ZN13SafeAllocator8AllocateEj(allocator,0x400);
 void* other=_ZN13SafeAllocator8AllocateEj(allocator,0x1800);
 if(!block || !other) DisableInterruptsAndHaltForever();
 Resource_InitializeSb2ScriptBuffers(self->memberb8,self->fielda8,block,0x80,other,0x200);
 func_ov011_021888ec(self->memberb8);
}
