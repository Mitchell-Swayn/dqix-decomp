#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
// Original data: arm9/ov004 @ 0x21707d8; symbol: data_ov004_021707d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
struct Mask13{unsigned short value:13;unsigned short unused:3;};extern "C" {unsigned char* _ZN9GameState11GetInstanceEv();unsigned TextContext_GetSharedInstance();void TextLayout_ResetFormattingWorkspace(signed char*);void* Menu_GetInventoryRecordSourceByKey(void*,unsigned);unsigned char* ZoneState2754_FindPrimaryRecordByKey(void*,int);void* Text_LookupNameTableEntry(void*,int);void Menu_QueueScriptEntry(void*,unsigned);void* Network_GetConnectionManager();bool Network_IsClientSession(unsigned*);int Network_IsSessionActive(void*);extern unsigned char MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[];}
// Original: arm9/ov004 @0x02158a60; symbol:Resource_ChoosePendingRecordOrConnectionMessage; size:0x118.
// Chooses pending serialized-record template or connection-state message using canonical lookup and13-bit shared mask.
extern "C" int Menu_RoutePendingItemOrConnectionStatus(void* self){unsigned char* state=_ZN9GameState11GetInstanceEv()+0x5e6c;if(H(state,0xf8)>0||U(state,0xfa)){unsigned char* owner=(unsigned char*)TextContext_GetSharedInstance();TextLayout_ResetFormattingWorkspace((signed char*)owner);unsigned char* record=ZoneState2754_FindPrimaryRecordByKey(Menu_GetInventoryRecordSourceByKey(self,5),H(state,0xf8));P(owner,24)=(unsigned char*)Text_LookupNameTableEntry(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage,8)+0x8c,H(record,24));Menu_QueueScriptEntry(self,0x3a3);return 0;}void* connection=Network_GetConnectionManager();if(Network_IsClientSession((unsigned*)connection)){Menu_QueueScriptEntry(self,0x3ae);return 0;}if(Network_IsSessionActive(connection)){Menu_QueueScriptEntry(self,0x24cd);return 0;}if(((Mask13*)(state+0x10c))->value&16){Menu_QueueScriptEntry(self,0x3a6);return 0;}Menu_QueueScriptEntry(self,0x3b0);return 0;}
