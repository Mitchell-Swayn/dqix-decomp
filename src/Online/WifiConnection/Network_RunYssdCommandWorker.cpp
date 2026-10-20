#include <globaldefs.h>
ARM
extern "C" int Network_WaitForYssdRequest(...);
extern "C" int Network_SendYssdCommand203AndWait(...);
extern "C" int Network_SendYssdCommand206AndClearResult(...);
extern "C" int Network_SendYssdCommand210AndWait(...);
extern "C" int Network_SendYssdCommand209AndWait(...);
extern "C" int System_SendSharedConfigurationPacketAndReset(...);
extern "C" int YssdClient_RequestSocketShutdown(...);
extern "C" int Network_ResolveYssdRequestHandle(...);
extern "C" int _Z19SleepCurrentContextj(...);
extern "C" int Network_WaitForYssdRequest(...);
extern "C" int Network_CancelAndDetachTransfer(...);
extern "C" int Network_ResolveYssdRequestHandle(...);
extern "C" int System_SendSharedConfigurationPacketAndReset(...);
extern "C" int Network_SendChunkedSharedRequestBody(...);
extern "C" int Network_SendYssdCommand206AndClearResult(...);
extern "C" int Network_SendYssdCommand203AndWait(...);
extern "C" int Network_SendYssdCommand208WithInitializedHandle(...);
extern "C" int Network_SendYssdCommand218WithInitializedHandle(...);
extern "C" int Network_SendYssdCommand210AndWait(...);
extern "C" int Network_SendYssdCommand209AndWait(...);
extern "C" int YssdClient_RequestSocketShutdown(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);
// Original data: arm9/ov031 @ 0x224e580; symbol: data_ov031_0224e580.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char StoreReadySharedValue_UnknownRoleZeroInitializedStorage[];

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov031 @ 0x0220F5B4; symbol: DrainSharedRequestKindsAndWaitForMappedContext.
extern "C" void Network_RunYssdCommandWorker(void){
if(!P(StoreReadySharedValue_UnknownRoleZeroInitializedStorage,0))return;for(;;){Network_WaitForYssdRequest();char* request=P(P(StoreReadySharedValue_UnknownRoleZeroInitializedStorage,0),36);if(!request){Network_CancelAndDetachTransfer();break;}switch(W(request,0)){case 1:Network_ResolveYssdRequestHandle();break;case 2:System_SendSharedConfigurationPacketAndReset();break;case 3:Network_SendChunkedSharedRequestBody();break;case 4:Network_SendYssdCommand203AndWait();break;case 5:Network_SendYssdCommand206AndClearResult();break;case 6:Network_SendYssdCommand208WithInitializedHandle();break;case 7:Network_SendYssdCommand218WithInitializedHandle();break;case 8:Network_SendYssdCommand210AndWait();break;case 9:Network_SendYssdCommand209AndWait();break;}Network_CancelAndDetachTransfer();}while(!YssdClient_RequestSocketShutdown())_Z19SleepCurrentContextj(100);
}
