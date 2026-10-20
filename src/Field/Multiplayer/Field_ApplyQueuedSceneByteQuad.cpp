#include <globaldefs.h>
ARM
extern "C" void* Network_GetCommandRecordPool();
extern "C" void Network_QueueOutgoingRecord(void*,const void*,short);
// Original: arm9/ov017 @ 0x021CE2FC; symbol: func_ov017_021ce2fc; size: 0x30.
// Copies four signed payload bytes to the queued scene state at offsets 0x1b through 0x1e.
extern "C" void Field_ApplyQueuedSceneByteQuad(void*,signed char* message,void*,char* resources) {
 signed char* scene=*(signed char**)(resources+0x3b30);
 signed char* payload=message+4;
 for(int i=0;i<4;i++) (scene+i)[0x1b]=payload[i];
}
