#include <globaldefs.h>
#include <System/RuntimeUnwindTable.h>
ARM
#pragma optimization_level 4
#pragma optimize_for_size off
typedef unsigned int u32;
struct Descriptor { unsigned a,b; signed char* action; unsigned d,e,f; };
struct Registers { unsigned words[21]; };
struct Context { unsigned a,b,c,d,e,f,g; Registers regs; };
// Unwind action iterator: the frame's exception descriptor followed by a copy of the throw context.
struct Info { Descriptor desc; Context context; };
struct CatchBlock { unsigned type; unsigned offset; unsigned frame; };
struct CatchList { unsigned count; unsigned pad[2]; const unsigned char* entries; };
extern "C" {
unsigned char RuntimeUnwindTable_ReadActionOpcode(const RuntimeUnwindTable* state);
unsigned Runtime_AdvanceUnwindActionDescriptor(Info* self);
signed char* Runtime_DecodeCompactSignedInteger(signed char* src,u32* out);
int __throw_catch_compare(void*,unsigned,int*);
int System_ExceptionMatchesCatchList(void* type,CatchList* list);
void RuntimeUnwind_EnterMatchingCatchHandler(Context* context,Descriptor* descriptor,CatchList* specification,signed char* action);
void RuntimeExceptionHandler_InvokeObservedCallback();
}
// Original: arm9/main @ 0x0200EA68; symbol: func_0200ea68; size: 0x1DC.
// Compiler runtime exception handling (FindExceptionHandler): walks the unwind actions from the
// throwing frame, returns the catch-block action whose type matches the thrown type (storing the
// adjustment), enters the unexpected-exception handler for violated exception specifications, and
// terminates on unknown actions.
extern "C" signed char* RuntimeUnwind_FindMatchingCatchOrExceptionSpecification(Context* self,Descriptor* descriptor,int* adjustment) {
 Info scan;
 CatchBlock block;
 CatchList specification;
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
 int op=RuntimeUnwindTable_ReadActionOpcode((const RuntimeUnwindTable*)&scan);
 for(;;) {
  switch(op) {
  case 0:case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9:case 10:case 11:case 13:case 16:case 17:case 18:case 19:
   break;
  case 12: {
   signed char* p=scan.desc.action;
   block.type=(unsigned char)p[1]|((unsigned char)p[2]<<8)|((unsigned char)p[3]<<16)|((unsigned char)p[4]<<24);
   Runtime_DecodeCompactSignedInteger((signed char*)RuntimeUnwind_ReadCompactUnsignedInteger((const unsigned char*)p+5,&block.offset),&block.frame);
   if(!__throw_catch_compare((void*)self->a,block.type,adjustment)) break;
   goto found;
  }
  case 15: {
   const unsigned char* q=RuntimeUnwind_ReadCompactUnsignedInteger((const unsigned char*)scan.desc.action+1,&specification.count);
   q=RuntimeUnwind_ReadCompactUnsignedInteger(q,&specification.pad[0]);
   specification.entries=(const unsigned char*)Runtime_DecodeCompactSignedInteger((signed char*)q,&specification.pad[1]);
   if(!System_ExceptionMatchesCatchList((void*)self->a,&specification))
    RuntimeUnwind_EnterMatchingCatchHandler(self,descriptor,&specification,scan.desc.action);
   break;
  }
  case 1:case 14:default:
   RuntimeExceptionHandler_InvokeObservedCallback();
   goto found;
  }
  op=Runtime_AdvanceUnwindActionDescriptor(&scan);
 }
found:
 return scan.desc.action;
}
