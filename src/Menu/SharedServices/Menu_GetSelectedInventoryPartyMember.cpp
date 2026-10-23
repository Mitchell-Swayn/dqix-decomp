#include <globaldefs.h>
ARM
// Original data: arm9/ov004 @ 0x21707d8; symbol: data_ov004_021707d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" {void* Menu_GetSelectedGridNode(void*,unsigned short);unsigned MenuRecord_GetType(void*);unsigned MenuRecord_GetKey(void*);int Menu_GetListedPartyMemberIndex(int);extern char MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[];}
// Original: arm9/ov004 @ 0x02157128; symbol: ReadTypeEightSelectionModeOrSharedFallback; size: 0xb0.
// Maps type8 entry codes322-327 to selection mode or returns shared signed-byte fallback.
extern "C" int Menu_GetSelectedInventoryPartyMember(void* self){void* entry=Menu_GetSelectedGridNode(self,95);if(!entry)return (signed char)*(short*)(*(char**)(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage+8)+0x3c);if(MenuRecord_GetType(entry)!=8)return 0;int index=0;switch(MenuRecord_GetKey(entry)){case 0x322:index=0;break;case 0x323:index=1;break;case 0x324:index=2;break;case 0x325:index=3;break;case 0x326:index=4;break;case 0x327:return -1;}return Menu_GetListedPartyMemberIndex(index);}
