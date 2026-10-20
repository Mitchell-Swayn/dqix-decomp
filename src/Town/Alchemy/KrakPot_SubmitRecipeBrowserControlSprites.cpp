#include <globaldefs.h>
ARM
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define I(p,o) (*(int*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))

#define S(p,o) (*(signed char*)((char*)(p)+(o)))
// Original data: arm9/ov006 @ 0x215ffb4; symbol: data_ov006_0215ffb4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 101214000008000000080000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov006.md.
// Original data: arm9/ov006 @ 0x215ffc4; symbol: data_ov006_0215ffc4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 080009000d00.
// Observed span: 6 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov006.md.
// Original data: arm9/ov006 @ 0x215ffca; symbol: data_ov006_0215ffca.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 410042002600ffff.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov006.md.
extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" void* Zone3D_GetMainInstance();extern "C" void* _ZN13SafeAllocator8AllocateEj(void*,unsigned);extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);extern "C" void _ZN13ZoneState2754C1Ev(void*);extern "C" void World_ResetZoneStateAndClearThreeWords(unsigned char*);extern "C" void World_ResetTemporaryZoneResourceState(void*);extern "C" int Inventory_AddGroupedItemQuantityAndCacheResult(char*,unsigned,unsigned,...);extern "C" unsigned TextContext_GetSharedInstance();extern "C" unsigned char* TextCanvas_FindDisplayPartByKey(unsigned char*,unsigned);extern "C" int TestEnabledRecordTraversal(void*,int);extern "C" void Object_ConvertMappedKeyToTwoHalfwords(void*,int,short*,short*);extern "C" void Graphics_SubmitTransformedCellToOam(void*,void*);extern "C" const short KrakPotSubmitRecipeBrowserControlSprites_UnknownRoleInitializedBytes_Variant2[],KrakPotSubmitRecipeBrowserControlSprites_UnknownRoleInitializedBytes_Variant3[];extern "C" const unsigned char KrakPotSubmitRecipeBrowserControlSprites_UnknownRoleInitializedBytes[];
// Original: arm9/ov006 @ 0x02158914; symbol: Graphics_UpdateMappedCoordinateRecordsWhenFlagged; size: 0x114.
extern "C" void KrakPot_SubmitRecipeBrowserControlSprites(char* self){if(!(U(self,916)&128))return;if(TextCanvas_FindDisplayPartByKey((unsigned char*)P(self,20),1))return;unsigned char i=0;for(;KrakPotSubmitRecipeBrowserControlSprites_UnknownRoleInitializedBytes_Variant3[i]>=0;i++){int key=KrakPotSubmitRecipeBrowserControlSprites_UnknownRoleInitializedBytes_Variant3[i];if(TestEnabledRecordTraversal(self+256,key)){short x,y;Object_ConvertMappedKeyToTwoHalfwords(self+256,key,&x,&y);short index=KrakPotSubmitRecipeBrowserControlSprites_UnknownRoleInitializedBytes_Variant2[i];struct Record40{char data[40];};char* record=(char*)((Record40*)P(self,36)+index);if(i==2&&!(U(P(self,16),0x1258)&0x800))record=P(self,36)+(index+1)*40;W(record,20)=x<<12;W(record,24)=y<<12;B(record,34)=KrakPotSubmitRecipeBrowserControlSprites_UnknownRoleInitializedBytes[i];B(record,38)=2;if(index==8)B(record,37)=11;else if(index==9)B(record,37)=1;Graphics_SubmitTransformedCellToOam(self+172,record);}}}
