#include "World/Zone3DContainers.h"
extern "C" void TextureVRAM_SnapshotAllocationBounds(void*);
struct Owner { unsigned unknown; void* transform; ZoneContainerRenderPart* renderPart; unsigned unknown2[3]; short state; };
// Original: arm9/ov005 @ 0x02155D38; symbol: func_ov005_02155d38; size: 0x34.
extern "C" void EquipmentMenu_ResetItemDisplayResource(Owner* self) { if(self->transform) TextureVRAM_SnapshotAllocationBounds(self->transform); if(self->renderPart) self->renderPart->ResetIfFlag0(); self->state=-1; }
