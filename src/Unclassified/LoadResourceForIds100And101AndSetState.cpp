#include <globaldefs.h>
ARM
extern "C" char data_020f057c[],data_020f0594[],data_ov031_02257180[];
extern "C" void ResourceHandle_AllocateLoadAndReadValue(void*,const char*,void*,int,int);
extern "C" unsigned ResourceHandle_ReadValueIfPresent(void*);
extern "C" bool TestBoundedResourceValueAfterStateInitialization(void*,int);
struct State {char pad[0xb0];unsigned first;short id;short padb6;unsigned second;unsigned unused;unsigned third;};
// Original: arm9/main @ 0x0205EA20; symbol: func_0205ea20; size: 0x80.
extern "C" void LoadResourceForIds100And101AndSetState(State* p,int id) {
    const char* path=0;
    if(id==100)path=data_020f057c;else if(id==101)path=data_020f0594;
    if(path)ResourceHandle_AllocateLoadAndReadValue(p,path,data_ov031_02257180,0x4b000,0);
    p->first=ResourceHandle_ReadValueIfPresent(p);p->id=id;
    TestBoundedResourceValueAfterStateInitialization(p,id);
    unsigned result=ResourceHandle_ReadValueIfPresent(p);p->third=result;p->second=result;
}
