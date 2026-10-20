#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
#include <System/Matrix.h>
// Original data: arm9/ov004 @ 0x21707d8; symbol: data_ov004_021707d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
typedef Vector3i Vec;struct Display{virtual void V0();virtual void V1();virtual void V2();virtual void V3();virtual void V4();virtual void V5();virtual void V6();virtual void SetPosition(const Vec&);virtual Vec GetPosition();};extern "C" {Display* Menu_FindInventorySpriteByKey(void*,unsigned);void _ZN8Vector3iaSERKS_(Vec*,const Vec*);extern unsigned char MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[];}
// Original: arm9/ov004 @ 0x021578A8; symbol: Graphics_PositionTwoObjectsFromSharedByte; size: 0xf4.
// Positions two virtual graphics objects from the shared byte62 value.
extern "C" void Menu_PositionDecimalDigitSelectionMarkers(void* self){Vec position;Display* first=Menu_FindInventorySpriteByKey(self,1303);if(first){position=first->GetPosition();position.x=(209-P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage,8)[62]*8)<<12;position.y=0x26000;first->SetPosition(position);}Display* second=Menu_FindInventorySpriteByKey(self,1304);if(second){position=second->GetPosition();position.x=(209-P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage,8)[62]*8)<<12;position.y=0x34000;second->SetPosition(position);}}
