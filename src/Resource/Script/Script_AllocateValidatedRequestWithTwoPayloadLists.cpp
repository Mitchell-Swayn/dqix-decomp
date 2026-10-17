#pragma opt_common_subs off
#include <globaldefs.h>
#include <Resource/Script.h>
#include <Memory/SafeAllocator.h>
struct RequestFlags { unsigned short id:9; unsigned short option0:1; unsigned short option1:1; unsigned short count:5; };
struct Request { RequestFlags flags; union { unsigned short values[21]; struct { unsigned short normal[13]; unsigned short count; unsigned short secondary[6]; unsigned short padding; } named; } payload; };
struct RequestState { unsigned char unrestricted; unsigned char unknown[11]; SafeAllocator* allocator; };
struct RequestDescriptor { unsigned id:9; unsigned other:23; unsigned unknown[3]; };
extern "C" RequestState data_02109404;
extern "C" unsigned char data_02109418[];
extern "C" RequestDescriptor data_0210941c[];
extern "C" void LinkedList_PrependNodeThroughOffset28(void*,Request*);
// Original: arm9/main @ 0x020951D8; symbol: func_020951d8; size: 0x18C.
extern "C" int Script_AllocateValidatedRequestWithTwoPayloadLists(Script::Parameter* args,int count) {
    Request* request;
    int normalCount,secondaryCount,i;
    unsigned id=args[0].ToInt();
    int option0=args[1].ToInt();
    Script::Parameter* third=args+2;
    args+=3;
    int option1=third->ToInt();
    unsigned available=data_02109418[0];
    RequestDescriptor* descriptors=data_0210941c;
    if(!data_02109404.unrestricted) {
        int i=0;
        for(;i<(int)available;++i) if(id==descriptors[i].id) break;
        if(i==available) return 0;
    }
    request=(Request*)data_02109404.allocator->Allocate(44);
    request->flags.id=(unsigned short)id;
    request->flags.option0=(unsigned short)option0;
    request->flags.option1=(unsigned short)option1;
    normalCount=0;
    secondaryCount=0;
    // The final two halfwords hold the queue link at byte offset 0x28.
    *(Request**)(&request->payload.values[19])=0;
    for(i=0;i<count-3;++i) {
        int value=args->ToInt();
        ++args;
        if((value>>16)==1000) {
            if(secondaryCount<=5) { request->payload.named.secondary[secondaryCount]=value; ++secondaryCount; }
        } else if(normalCount<=13) { request->payload.values[normalCount]=value; ++normalCount; }
    }
    request->flags.count=(unsigned short)normalCount;
    request->payload.named.count=secondaryCount;
    LinkedList_PrependNodeThroughOffset28(data_02109418,request);
    return 1;
}
