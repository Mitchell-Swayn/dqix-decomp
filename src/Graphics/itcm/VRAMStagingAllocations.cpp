#include "Graphics/itcm/VRAMStaging.h"

// Descriptors for portions of the 20 KiB staging buffer. The allocator tracks
// occupied spans here; released descriptors become available for reuse.
VRAMStagingManager::StagingSpaceAllocation g_vramStagingAllocations[0x80];

typedef char StagingSpaceAllocationSizeCheck[
    sizeof(VRAMStagingManager::StagingSpaceAllocation) == 6 ? 1 : -1];
