#include <globaldefs.h>
#include <World/Zone3D.h>
#include <Resource/GameResources.h>

struct State828;
extern "C" {
void* Zone3D_GetMainInstance();
void* Network_GetConnectionManager();
void CharacterResourceContext_ResetIndexAndAllocators(unsigned char*);
void InitializeCharacterStateArraysAndDefaults(State828*);
void Memory_AllocateTenSizedBlocksAndFourExtraBuffers(unsigned char*, SafeAllocator*, int);
}

static inline char* ResourceBlock(GameResources* resources) { return resources->unknown_2cc; }

// Original: arm9/main @ 0x02097EC8; symbol: func_02097ec8; size: 0x1B8.
extern "C" ARM void ZoneState0840_PrepareCharacterResourcesForZoneEntry(ZoneState0840* self)
{
    Zone3D* zone = (Zone3D*)Zone3D_GetMainInstance();
    unsigned current = zone->currentZoneID_;
    unsigned previous = zone->previousZoneID_;
    if (!self->IsValueInRangeC3b5(current) && !self->IsValueInRangeC3b5(previous))
        return;
    if (current != 0xc3b5 && current != 0xc419 && current != 0xc47d && current != 0xc4e1)
        self->unknown_1b60 = 1;
    Network_GetConnectionManager();
    if (current == 0xc3b5 && self->unknown_1b3c >= 2) {
        zone->SetInstanceFlag4(9, 0);
        zone->SetInstanceFlag4(10, 0);
    } else if (current == 0xc41b && self->unknown_1b3c >= 4) {
        zone->SetInstanceFlag4(20, 0);
        zone->SetInstanceFlag4(21, 0);
    }
    if (!self->IsValueInRangeC3b5(current)) return;
    if (self->IsValueInRangeC545(current)) return;
    if (self->IsValueAtHundredBoundary(current)) return;
    if (current == 0xc3bb) return;

    GameResources* resources = GameResources_GetInstance();
    SafeAllocator* allocators = GameResources_GetInstance()->allocator_array_1a0;
    SafeAllocator* allocator = allocators + 2;
    allocator->Reset();
    self->unknown_1b58 = (int)allocator->Allocate(0x5ec);
    self->unknown_1b5c = (int)allocator->Allocate(0x964);
    CharacterResourceContext_ResetIndexAndAllocators((unsigned char*)self->unknown_1b58);
    InitializeCharacterStateArraysAndDefaults((State828*)self->unknown_1b5c);
    Memory_AllocateTenSizedBlocksAndFourExtraBuffers((unsigned char*)self->unknown_1b58,
        &resources->allocator_array_1a0[3], (int)(ResourceBlock(resources) + 0x930));
}
