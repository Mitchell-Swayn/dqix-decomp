#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e588; symbol: data_ov031_0224e588.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" {extern char* YssdClientRunWorker_UnknownRoleZeroInitializedStorage;void Overlay_EnsureContextStateTwoUnlessAlreadySet(int,int);int Network_ProcessInputChunkWithDefaults(unsigned,unsigned,unsigned);}
// Original: arm9/ov031 @ 0x0221042C; symbol: ProcessBoundedRequestInInputChunks; size: 0xb8.
// Processes bounded1044-byte request in chunks, reporting transport error6/-50.
extern "C" int YssdClient_SendLengthPrefixedPacket(unsigned char* input){int result=0;if(!YssdClientRunWorker_UnknownRoleZeroInitializedStorage)return -28;unsigned completed;unsigned length=*(unsigned*)input;if(length>1044){Overlay_EnsureContextStateTwoUnlessAlreadySet(6,-50);return -35;}completed=0;if(completed<length)do{result=Network_ProcessInputChunkWithDefaults(*(unsigned*)(YssdClientRunWorker_UnknownRoleZeroInitializedStorage+0x1b8),(unsigned)input,length-completed);if(result>0){completed+=result;input+=result;if(completed>=length)return completed;}else if(result<0){Overlay_EnsureContextStateTwoUnlessAlreadySet(6,-50);return result;}}while(completed<length);return result;}
