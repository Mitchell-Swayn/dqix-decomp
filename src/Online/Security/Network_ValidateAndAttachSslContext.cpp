#include <globaldefs.h>
ARM
extern "C" int Network_IsSocketHandleInvalid(char*);
extern "C" int Network_QueueSslContextAttachment(char*,int);
// Original: arm9/ov031 @ 0x022078F0; symbol: ValidateStateAndEnabledFlagsThenDispatch; size: 0x80.
extern "C" int Network_ValidateAndAttachSslContext(char* self,int argument){
if(Network_IsSocketHandleInvalid(self))return -28;int state=*(signed char*)(self+0x73);int allowed=1;if(state!=0&&state!=4)allowed=0;if(!allowed)return -28;int enabled=0;if(self)enabled=(*(short*)(self+0x70)&1)!=0;if(!enabled)return -39;if(*(short*)(self+0x70)&2)return -28;return Network_QueueSslContextAttachment(self,argument);
}
