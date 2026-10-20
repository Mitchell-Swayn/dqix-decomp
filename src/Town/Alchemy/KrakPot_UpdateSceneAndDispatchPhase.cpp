#include <globaldefs.h>
ARM
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
// Original data: arm9/ov006 @ 0x215ff94; symbol: data_ov006_0215ff94.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 285e150200000000806b150200000000000000000000000008090900f0000307.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov006.md.
// Original data: arm9/main @ 0x20e6d5c; symbol: data_020e6d5c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" void Graphics_PollConditionalCanvasResourceLoad(char*);extern "C" void DisplayLayout_AdvanceActiveCanvases(void*,unsigned);extern "C" void KrakPot_PollItemPreviewSpriteLoads(char*);extern "C" void KrakPot_StartQueuedAlchemyEffect(char*);extern "C" void Graphics_UpdateFlaggedAnimationStages(char*);struct Handler{};typedef void(Handler::*Method)();struct Table{Method methods[3];};extern "C" Table KrakPotUpdateSceneAndDispatchPhase_UnknownRoleProcedureReferenceRecords;extern "C" Method ShopUpdateInterface_UnknownRoleInitializedBytes;
// Original: arm9/ov006 @ 0x021549AC; symbol: UpdateAnimationAndDispatchIndexedMemberHandler; size: 0xb4.
extern "C" void KrakPot_UpdateSceneAndDispatchPhase(char* self,unsigned argument){
Graphics_PollConditionalCanvasResourceLoad(self);if(P(self,0x1d4))DisplayLayout_AdvanceActiveCanvases(P(self,0x1d4),argument);KrakPot_PollItemPreviewSpriteLoads(self);KrakPot_StartQueuedAlchemyEffect(self);Table methods=KrakPotUpdateSceneAndDispatchPhase_UnknownRoleProcedureReferenceRecords;methods.methods[2]=ShopUpdateInterface_UnknownRoleInitializedBytes;if(methods.methods[B(self,0xadc)]){(((Handler*)self)->*methods.methods[B(self,0xadc)])();Graphics_UpdateFlaggedAnimationStages(self);}
}
