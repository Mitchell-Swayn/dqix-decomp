#include <globaldefs.h>
struct State { char pad[0xc4]; char data[6]; short state; short unknown; short index; };
extern "C" void ResourceHandle_UpdateAndInvokeObjectCommand(State*,void*,int);
// Original: arm9/main @ 0x0209C7FC; symbol: func_0209c7fc; size: 0x34.
extern "C" void Bgm_CancelPendingTemporaryPlayback(State* self) { if(self->index<0) return; ResourceHandle_UpdateAndInvokeObjectCommand(self,self->data,0); self->index=-1; self->state=0; }
