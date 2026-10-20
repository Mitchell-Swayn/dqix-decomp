#include <globaldefs.h>
ARM
#define D(p) ((unsigned)(p))
#define U32(p) (*(unsigned*)(p))
#define U16(p) (*(unsigned short*)(p))
#define S16(p) (*(short*)(p))
#define U8(p) (*(unsigned char*)(p))
#define S8(p) (*(signed char*)(p))
#define V32(p) (*(volatile unsigned*)(p))
#define V16(p) (*(volatile unsigned short*)(p))
extern "C" unsigned Window_IsVisible(...);
extern "C" unsigned WindowControl_SetEnabled(...);
extern "C" unsigned Window_ResetResourceTransfers(...);
extern "C" unsigned Window_SetWidgetPositionAndToggleTwoOptions(...);
extern "C" unsigned WindowControl_SetInsideMaskWithEffect(...);
extern "C" unsigned Graphics_TransferScreenBuffer(...);
extern "C" unsigned EquipmentMenu_InstallStagedItemResources(...);
extern "C" unsigned EquipmentMenu_RefreshSortModeIndicator(...);
extern "C" unsigned EquipmentMenu_CacheEquippedItemNames(...);
// Original: arm9/ov005 @ 0x02155108; symbol: Graphics_UpdateIdleWindowResourceState; size: 0xcc.
extern "C" void EquipmentMenu_UpdateReadyDisplayResources(unsigned self){
if(U8(self+0x3dc4)!=255)return;Window_ResetResourceTransfers(self+0xee4);EquipmentMenu_RefreshSortModeIndicator(self);
if(U32(self+0x3dcc)&0x100){Graphics_TransferScreenBuffer(self+0xea4,0);U32(self+0x3dcc)&=~0x100;}if(U32(self+0x3dcc)&0x200){EquipmentMenu_CacheEquippedItemNames(self);U32(self+0x3dcc)&=~0x200;}
unsigned widget=U32(self+0xe64);if(widget){unsigned control=U32(widget+16);WindowControl_SetInsideMaskWithEffect(control+40,31,1);unsigned bit=Window_IsVisible(U32(self+0xe64));WindowControl_SetEnabled(control+40,bit);Window_SetWidgetPositionAndToggleTwoOptions(U32(self+0xe64));}EquipmentMenu_InstallStagedItemResources(self);
}