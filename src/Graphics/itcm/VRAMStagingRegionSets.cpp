#include "Graphics/itcm/VRAMStaging.h"

// One group of pending task indices for each VRAMRegion. Startup assigns their
// backing buffers and capacities; Reset clears only the task counts.
VRAMStagingManager::CommonVRAMRegionTaskSet g_vramStagingRegionalTaskSets[10];

typedef char VRAMStagingRegionTaskSetSizeCheck[
    sizeof(VRAMStagingManager::CommonVRAMRegionTaskSet) == 12 ? 1 : -1];
