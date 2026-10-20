#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
#include <System/VRAM.h>
ARM
struct SubBgControlFields {
 unsigned short priority:2;
 unsigned short characterBase:4;
 unsigned short bit6:1;
 unsigned short colorMode:1;
 unsigned short screenBase:5;
 unsigned short overflow:1;
 unsigned short size:2;
};
extern "C" void Graphics_SetDisplayControlFields(unsigned, unsigned, unsigned, unsigned, unsigned);
extern "C" void Graphics_SetBg1ControlFields(unsigned, unsigned, unsigned, unsigned, unsigned);
// Original: arm9/ov000 @ 0x02172850; symbol: BattleMenu_RestoreSubDisplayResources; size: 0xF4.
// Resets an optional allocator and restores saved sub-screen BG0/BG1 control fields,
// their priorities, and the sub-object VRAM bank mapping.
extern "C" void BattleMenu_RestoreSubDisplayResources(char* owner)
{
 SafeAllocator* allocator = *(SafeAllocator**)(owner + 0x1af0);
 if (allocator) allocator->Reset();
 int banks = *(int*)(owner + 0x184);
 if (banks) MapVRAMBanksToSubBG(banks);

 Graphics_SetDisplayControlFields((*(SubBgControlFields*)(owner + 0x180)).size, (*(SubBgControlFields*)(owner + 0x180)).colorMode, (*(SubBgControlFields*)(owner + 0x180)).screenBase, (*(SubBgControlFields*)(owner + 0x180)).characterBase, (*(SubBgControlFields*)(owner + 0x182)).overflow);
 Graphics_SetBg1ControlFields((*(SubBgControlFields*)(owner + 0x182)).size, (*(SubBgControlFields*)(owner + 0x182)).colorMode, (*(SubBgControlFields*)(owner + 0x182)).screenBase, (*(SubBgControlFields*)(owner + 0x182)).characterBase, (*(SubBgControlFields*)(owner + 0x182)).overflow);
 volatile unsigned short* hardware = (volatile unsigned short*)0x04001008;
 hardware[0] = (hardware[0] & ~3) | (*(SubBgControlFields*)(owner + 0x180)).priority;
 hardware[1] = (hardware[1] & ~3) | (*(SubBgControlFields*)(owner + 0x182)).priority;
 MapVRAMBanksToSubObj(0x100);
}
