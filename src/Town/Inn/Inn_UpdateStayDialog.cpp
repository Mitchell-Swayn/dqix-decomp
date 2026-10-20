struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
ARM
extern "C" int Graphics_AdvanceDisplayTransitionRequest(...);
extern "C" WindowCanvasRecord* Window_GetSelectedTextCanvas(WindowCanvasOwner*);
extern "C" int Grid_SetLastTouchIndex(...);
extern "C" int Window_UpdateCanvasesAndSelection(...);
extern "C" int Inn_FinishStayDialogWhenTransitionsIdle(...);
extern "C" int Inn_DecrementRestSequenceDelay(...);
extern "C" int TextCanvas_IsReady(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);
// Original data: arm9/ov003 @ 0x217fe94; symbol: data_ov003_0217fe94.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex f0ca15020000000050d1150200000000fcd4150200000000fcd41502000000000cda150200000000.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
extern "C" char InnUpdateStayDialog_UnknownRoleProcedureReferenceRecords[];

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov003 @ 0x0215C924; symbol: UpdateDisplayTransitionAndDispatchStateHandler.
extern "C" int Inn_UpdateStayDialog(char*self,int amount){
if(B(self,0x3bc)==5)return 1;Graphics_AdvanceDisplayTransitionRequest(self);if(Inn_DecrementRestSequenceDelay(self,amount))return 0;if(B(self,0x3f4)&&!B(self,0x3f5)){Inn_FinishStayDialogWhenTransitionsIdle(self);return 0;}if(B(self,0x3bc)){char*record=C((int)Window_GetSelectedTextCanvas((WindowCanvasOwner*)(self+0x98)));if(record&&TextCanvas_IsReady(record)&&!(B(record,197)&2))Grid_SetLastTouchIndex(self+0x9c,-1);B(self,0x3ba)=Window_UpdateCanvasesAndSelection(self+0x98,amount);}struct Dispatcher{};typedef void(Dispatcher::*Handler)(int);unsigned state=B(self,0x3bc);Handler*handlers=(Handler*)InnUpdateStayDialog_UnknownRoleProcedureReferenceRecords;if(handlers[state])(((Dispatcher*)self)->*handlers[state])(amount);return 0;
}
