#include <globaldefs.h>
ARM
struct Record { unsigned entry,unknown,count,parameters; };
struct Frame { unsigned returnValue; unsigned char* locals; Record* record; };
struct State { unsigned char pad[0x14]; unsigned char* top; unsigned char pad2[0x10]; Frame* frame; Frame* end; unsigned char* locals; Record* record; unsigned char pad3[0x10]; unsigned char* code; };
extern "C" { void Runtime_RunEarlyExitHandlerAndTerminate(int); void* memset(void*,int,unsigned); }
// Original: arm9/ov017 @ 0x021D4AF8; symbol: func_ov017_021d4af8; size: 0xA4.
extern "C" unsigned char* System_PushExecutionFrameAndClearLocalSlots(State* p,Record* record,unsigned returnValue) {
 Frame* frame=p->frame;
 if(frame>=p->end) Runtime_RunEarlyExitHandlerAndTerminate(-2);
 frame->returnValue=returnValue;
 p->frame->record=p->record;
 p->frame->locals=p->locals;
 p->locals=p->top-record->parameters*8;
 p->top=p->locals+record->count*8;
 p->record=record;
 ++p->frame;
 memset(p->locals+p->record->parameters*8,0,(p->record->count-p->record->parameters)*8);
 return p->code+record->entry;
}
