#include <globaldefs.h>
#include <System/Matrix.h>
ARM
extern "C" void WfcUtility_ExpandSpriteCellTemplate(unsigned,unsigned,void*);
struct SpriteAttributes {unsigned positionAndMode;unsigned short tilePriorityPalette;};
struct AnimationState {unsigned unknown;SpriteAttributes* sprite;unsigned char palette,frame;};
// Original data: arm9/ov031 @ 0x2250ba4; symbol: data_ov031_02250ba4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" AnimationState* WfcUtilityDestroyAnimatedStatusSprite_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov031 @ 0x2248910; symbol: data_ov031_02248910.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0e0405000000a800.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityCreateAnimatedStatusSprite_UnknownRoleInitializedBytes[];
// Original: arm9/ov031 @ 0x02222C18; symbol: func_ov031_02222c18; size: 0xCC.
// Advances a forty-tick/eight-frame sprite animation and configures priority, palette and position.
extern "C" void AdvanceAnimatedSpriteFrameAndAttributes(void*,void*){
 WfcUtilityDestroyAnimatedStatusSprite_UnknownRoleZeroInitializedStorage->frame=FastIntModulus(WfcUtilityDestroyAnimatedStatusSprite_UnknownRoleZeroInitializedStorage->frame+1,40);
 unsigned frame=FastIntDivide(WfcUtilityDestroyAnimatedStatusSprite_UnknownRoleZeroInitializedStorage->frame,5);
 WfcUtility_ExpandSpriteCellTemplate(0,frame+0x47,WfcUtilityDestroyAnimatedStatusSprite_UnknownRoleZeroInitializedStorage->sprite);
 SpriteAttributes* sprite=WfcUtilityDestroyAnimatedStatusSprite_UnknownRoleZeroInitializedStorage->sprite;
 sprite->tilePriorityPalette=(sprite->tilePriorityPalette&~0xc00)|0x400;
 unsigned palette=WfcUtilityCreateAnimatedStatusSprite_UnknownRoleInitializedBytes[WfcUtilityDestroyAnimatedStatusSprite_UnknownRoleZeroInitializedStorage->palette];
 sprite=WfcUtilityDestroyAnimatedStatusSprite_UnknownRoleZeroInitializedStorage->sprite;
 sprite->positionAndMode&=~0xc00;
 sprite->tilePriorityPalette=(sprite->tilePriorityPalette&~0xf000)|(palette<<12);
 sprite=WfcUtilityDestroyAnimatedStatusSprite_UnknownRoleZeroInitializedStorage->sprite;
 sprite->positionAndMode=(sprite->positionAndMode&0xfe00ff00)|0xe6008b;
}
