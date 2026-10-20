#include <globaldefs.h>
ARM
extern "C" {void* WfcUtility_GetSpriteGroupEntry(void*,int);void WfcUtility_SetSpriteGroupObjectMode(void*,int,unsigned,unsigned);void Graphics_SetObjectModeAndPalette(void*,int,int,int);void WfcUtility_SetSpriteGroupPriority(void*,int,unsigned);void Graphics_ArrangeOBJForCharacterRectangle(void*,int,int,int,int,int,int,int);}
// Original: arm9/ov031 @ 0x0223CA54; symbol: ConfigureSpriteEntryFromLayoutFields; size: 0x98.
// Resets entry flags/palette/priority and configures sprite from layout2C-2F.
extern "C" void WfcUtility_ConfigureTextCanvasSprites(unsigned char* layout,int tile,int coordinate,void* owner,unsigned priority){void* entry=WfcUtility_GetSpriteGroupEntry(owner,0);WfcUtility_SetSpriteGroupObjectMode(owner,-1,0,0);Graphics_SetObjectModeAndPalette(owner,-1,0,15);WfcUtility_SetSpriteGroupPriority(owner,-1,priority);Graphics_ArrangeOBJForCharacterRectangle(entry,layout[0x2e],layout[0x2f],tile,coordinate,0,*(unsigned short*)(layout+0x2c),2);}
