#include <globaldefs.h>
ARM
#pragma optimization_level 4
#pragma optimize_for_size off
struct Descriptor { unsigned a,b; signed char* action; unsigned d,e,f; };
struct Registers { unsigned words[21]; };
struct Context { unsigned a,b,c,d,e,f,g; Registers regs; };
struct Scan { Descriptor desc; Context context; };
extern "C" {
unsigned char RuntimeUnwindTable_ReadActionOpcode(const void*);
int Runtime_AdvanceUnwindActionDescriptor(void*);
signed char* Runtime_DecodeCompactSignedInteger(signed char*,unsigned*);
}
// Original: arm9/main @ 0x0200E830; symbol: func_0200e830; size: 0x154.
extern "C" void* Runtime_FindUnwindActionRecord(Context* self,Descriptor* descriptor) {
 Scan scan;
 scan.desc.a=descriptor->a;
 scan.desc.b=descriptor->b;
 scan.desc.action=descriptor->action;
 scan.desc.d=descriptor->d;
 scan.desc.e=descriptor->e;
 scan.desc.f=descriptor->f;
 scan.context.a=self->a;
 scan.context.b=self->b;
 scan.context.c=self->c;
 scan.context.d=self->d;
 scan.context.e=self->e;
 scan.context.f=self->f;
 scan.context.g=self->g;
 scan.context.regs=self->regs;
 int op=RuntimeUnwindTable_ReadActionOpcode(&scan);
 for(;;) {
  switch(op) {
  default:return 0;
  case 0:case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9:case 10:case 11:case 12:case 15:case 16:case 17:case 18:
   op=Runtime_AdvanceUnwindActionDescriptor(&scan);break;
  case 13: {
   unsigned offset;
   Runtime_DecodeCompactSignedInteger(scan.desc.action+1,&offset);
   unsigned* record=(unsigned*)(scan.context.g+offset);
   self->a=record[1];
   self->b=record[0];
   self->c=0;
   self->d=(unsigned)record;
   return record;
  }
  }
 }
}
