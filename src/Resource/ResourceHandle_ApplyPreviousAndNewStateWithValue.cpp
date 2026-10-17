#include <globaldefs.h>
extern "C" void InvokeHandleStateWhenPresent(void*,unsigned);extern "C" void TestBoundedResourceValueAfterStateInitialization(void*,unsigned);
struct Object{char pad[0xc0];unsigned state;unsigned short value;};
// Original: arm9/main @ 0x0205EB54; symbol: func_0205eb54; size: 0x2C.
extern "C" ARM void ResourceHandle_ApplyPreviousAndNewStateWithValue(Object* p,unsigned state,unsigned short value){InvokeHandleStateWhenPresent(p,p->state);TestBoundedResourceValueAfterStateInitialization(p,state);p->value=value;}
