#include <globaldefs.h>
ARM
typedef void (*Callback)(unsigned,unsigned,unsigned,unsigned); extern "C" Callback data_020f2bf4[][2];extern "C" void DispatchTwoPairsThroughIndexedFunctionTables(void*);struct Request { unsigned char enabled,kind,index;char pad[17];unsigned a,b,c,d; };
// Original: arm9/main @ 0x020E2C34; symbol: func_020e2c34; size: 0x48.
extern "C" void InvokeEnabledIndexedCallback(Request* p) { if(!p->enabled)return;DispatchTwoPairsThroughIndexedFunctionTables(p);data_020f2bf4[p->kind][p->index](p->a,p->b,p->c,p->d); }
