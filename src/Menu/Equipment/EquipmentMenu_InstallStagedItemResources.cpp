#include <globaldefs.h>
#include <std_library_functions.h>
#include <Memory/SafeAllocator.h>
#include "World/Zone3DContainers.h"
ARM
struct Owner;
extern "C" {
void ZoneContainerRenderPart_SetPositionComponents(int self, unsigned int first, unsigned int second, unsigned int third);
void ZoneContainerRenderPart_LoadSerializedFramesAndAnimations(ZoneContainerRenderPart*, void*, unsigned);
void TextureVRAM_SnapshotAllocationBounds(char *p);
void Graphics_RestoreTextureImageAndPaletteVRAMState(const unsigned char* state);
void Object_InvokeSaveTextureImageVRAMState(char *p);
void EquipmentMenu_ResetItemDisplayResource(Owner* self);
}
struct Row { short id; unsigned char unused, skip; char* snapshot; char* render; int x, y, offset; short loaded; short pad; };
#define B(o) (*(unsigned char*)(p+(o)))
#define H(o) (*(unsigned short*)(p+(o)))
#define W(o) (*(unsigned*)(p+(o)))
// Original: arm9/ov005 @ 0x02155D6C; symbol: func_ov005_02155d6c; size: 0x54C.
// Advances queued single-row and four-row graphics uploads using per-row allocators and VRAM snapshots.
extern "C" void EquipmentMenu_InstallStagedItemResources(unsigned char* p) {
 if (B(0x3db7)) {
 if (B(0x3dab) == 1) {
  Row* row = (Row*)(p + 0x2d90) + *(short*)(p + 0x3d78);
  if (row->offset == 0) {
   ((ZoneContainerRenderPart*)(p + 0x3cf0))->ResetIfFlag0();
   TextureVRAM_SnapshotAllocationBounds((char*)p + 0xd84);
   Graphics_RestoreTextureImageAndPaletteVRAMState(p + 0xd84);
   ((SafeAllocator*)(p + 0x208))->Reset();
   ZoneContainerRenderPart_LoadSerializedFramesAndAnimations((ZoneContainerRenderPart*)(p + 0x3cf0), (void*)W(0x3d8c), (unsigned)(p + 0x208));
   Object_InvokeSaveTextureImageVRAMState((char*)p + 0xd84);
  }
  row->offset = -1; row->skip = 0; memset((void*)W(0x3d8c), 0, 0x200); --B(0x3db7); B(0x3dab) = 0;
 } else if (B(0x3da8) == 1) {
  Row* row = (Row*)(p + 0x2d90) + H(0x3dac); char* snapshot = row->snapshot; char* render = row->render;
  if (row->offset == 0) {
   EquipmentMenu_ResetItemDisplayResource((Owner*)row);
   Graphics_RestoreTextureImageAndPaletteVRAMState((const unsigned char*)snapshot);
   ((SafeAllocator*)(p + 0x28 + H(0x3dac) * 20))->Reset();
   ZoneContainerRenderPart_LoadSerializedFramesAndAnimations((ZoneContainerRenderPart*)render, (void*)W(0x3d94), (unsigned)(p + 0x28 + H(0x3dac) * 20));
   row->loaded = row->id;
   Object_InvokeSaveTextureImageVRAMState(snapshot);
  }
  *(unsigned short*)(render + 0x82) = 31; *(unsigned short*)(render + 0x80) = 0x7fff;
  ZoneContainerRenderPart_SetPositionComponents((int)render, row->x, row->y, 0);
  row->offset = -1; row->skip = 0; memset((void*)W(0x3d94), 0, 0x200); --B(0x3db7); B(0x3da8) = 0;
 } else if (B(0x3da9) == 1) {
  for (int i = 0; i < 8; i++) ((SafeAllocator*)(p + 0x28 + i * 20))->Reset();
  ++B(0x3da9);
 } else if (B(0x3da9) == 2) {
  signed char count = 0; int index = H(0x3dae);
  for (; index < H(0x3db0); index++) {
   if (count == 4) break;
   Row* row = (Row*)(p + 0x2d90) + index; char* snapshot = row->snapshot; char* render = row->render; int offset = row->offset;
   if (offset >= 0) {
    EquipmentMenu_ResetItemDisplayResource((Owner*)row);
    Graphics_RestoreTextureImageAndPaletteVRAMState((const unsigned char*)snapshot);
    ((SafeAllocator*)(p + 0x28 + index * 20))->Reset();
    ZoneContainerRenderPart_LoadSerializedFramesAndAnimations((ZoneContainerRenderPart*)render, (void*)(W(0x3d90) + offset), (unsigned)(p + 0x28 + index * 20));
    row->loaded = row->id;
    Object_InvokeSaveTextureImageVRAMState(snapshot);
   }
   *(unsigned short*)(render + 0x82) = 31; *(unsigned short*)(render + 0x80) = 0x7fff;
   ZoneContainerRenderPart_SetPositionComponents((int)render, row->x, row->y, 0);
   row->offset = -1; row->skip = 0; count++;
  }
  memset((void*)W(0x3d90), 0, 0x800); H(0x3dae) += (unsigned short)count;
 } else if (B(0x3da9) == 3) { --B(0x3db7); B(0x3da9) = 0;
 } else if (B(0x3daa) == 1) {
  for (int i = 0; i < 16; i++) if (!((Row*)(p + 0x2d90))[i + 8].skip) ((SafeAllocator*)(p + 0xc8 + i * 20))->Reset();
  ++B(0x3daa);
 } else if (B(0x3daa) == 3) {
  signed char count = 0; int index = H(0x3db2);
  for (; index < H(0x3db4); index++) {
   if (count == 4) break;
   Row* row = (Row*)(p + 0x2d90) + index; char* snapshot = row->snapshot; char* render = row->render;
   if (row->skip) { count++; continue; }
   int offset = row->offset;
   if (offset >= 0) {
    EquipmentMenu_ResetItemDisplayResource((Owner*)row);
    Graphics_RestoreTextureImageAndPaletteVRAMState((const unsigned char*)snapshot);
    ((SafeAllocator*)(p + 0xc8 + (index - 8) * 20))->Reset();
    ZoneContainerRenderPart_LoadSerializedFramesAndAnimations((ZoneContainerRenderPart*)render, (void*)(W(0x3d88) + offset), (unsigned)(p + 0xc8 + (index - 8) * 20));
    row->loaded = row->id;
    Object_InvokeSaveTextureImageVRAMState(snapshot);
   }
   *(unsigned short*)(render + 0x82) = 31; *(unsigned short*)(render + 0x80) = 0x7fff;
   ZoneContainerRenderPart_SetPositionComponents((int)render, row->x, row->y, 0);
   row->offset = -1; row->skip = 0; count++;
  }
  memset((void*)W(0x3d88), 0, 0x800); H(0x3db2) += (unsigned short)count; B(0x3daa) = 2;
 } else if (B(0x3daa) == 4) { --B(0x3db7); B(0x3daa) = 0; }
 W(0x3dcc) |= 2;
 } else W(0x3dcc) &= ~2;
}
