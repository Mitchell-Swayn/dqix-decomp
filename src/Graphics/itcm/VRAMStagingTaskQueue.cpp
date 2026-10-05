#include "Graphics/itcm/VRAMStaging.h"

// Fixed-capacity circular task queue. The original data_01fff270 label names
// the one-past pointer, preserved by a linker alias rather than extra storage.
VRAMStagingManager::Task g_vramStagingTaskQueue[0x100];

typedef char VRAMStagingTaskSizeCheck[
    sizeof(VRAMStagingManager::Task) == 16 ? 1 : -1];
