#include <globaldefs.h>
ARM
extern "C" {int Network_IsSocketHandleInvalid();void* Network_AllocateSocketCommand(void(*)(),void*,signed char);int Network_SubmitSendCommand(void*,void*);void System_RunCallbackForState0Or4();}
// Original: arm9/ov031 @ 0x022067F0; symbol: BeginOwnerCallbackWhenFlagsReady; size: 0xac.
// Validates owner readiness flags, marks in-progress and submits keyed callback record.
extern "C" int Network_ShutdownSocketSend(char* self){if(Network_IsSocketHandleInvalid())return -28;int valid=0;if(self)valid=(*(volatile short*)(self+0x70)&1)!=0;if(!valid)return -39;if(!(*(volatile short*)(self+0x70)&4)||(*(volatile short*)(self+0x70)&8))return -56;*(volatile short*)(self+0x70)|=8;char* inner=*(char**)(self+0x68);if(inner && *(void**)(inner+0x10c)){void* record=Network_AllocateSocketCommand(System_RunCallbackForState0Or4,*(void**)(inner+0x10c),self[0x72]);if(!record)return -33;return Network_SubmitSendCommand(*(void**)(inner+0x10c),record);}return 0;}
