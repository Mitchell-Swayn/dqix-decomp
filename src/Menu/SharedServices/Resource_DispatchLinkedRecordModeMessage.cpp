#include <globaldefs.h>
ARM
extern "C" int Resource_ReadIndexedNodeAndFlag(void*,void*);
// Original data: arm9/ov004 @ 0x217101c; symbol: data_ov004_0217101c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" char* FilesystemQueuePositionRecord_UnknownRoleZeroInitializedStorage;
extern "C" void Menu_QueueScriptEntry(void*,unsigned);
struct ModeFlags {unsigned short mode:2;unsigned short a:1;unsigned short bit3:1;unsigned short rest:12;};
// Original: arm9/ov004 @ 0x02167370; symbol: Resource_DispatchLinkedRecordModeMessage; size: 0xb4.
// Finds matching linked record and dispatches mode-specific message103..106.
extern "C" int Resource_DispatchLinkedRecordModeMessage(void* self) {
 unsigned result;int key=Resource_ReadIndexedNodeAndFlag(self,&result);char* node=*(char**)(FilesystemQueuePositionRecord_UnknownRoleZeroInitializedStorage+8);while(node){if(*(short*)node==key)break;node=*(char**)(node+8);}
 if(node){unsigned message=0;switch(((ModeFlags*)(node+2))->mode){case 0:case 1:message=106;break;case 2:if(((ModeFlags*)(node+2))->bit3==1)message=104;else message=103;break;case 3:message=105;break;}if(message)Menu_QueueScriptEntry(self,message);}return 0;
}
