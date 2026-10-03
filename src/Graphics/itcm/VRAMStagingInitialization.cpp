#include "Graphics/itcm/VRAMStaging.h"

// Initialization entry points retain their address names until their original
// constructor/destructor identities can be established from callers.
extern "C" VRAMStagingManager::Task* func_01ff96d4(VRAMStagingManager::Task* task)
{
    task->Reset();
    return task;
}

extern "C" VRAMStagingManager::StagingSpaceAllocation* func_01ff96e8(
    VRAMStagingManager::StagingSpaceAllocation* allocation)
{
    allocation->flags_ = 0;
    allocation->start_ = 0;
    allocation->size_ = 0;
    return allocation;
}

extern "C" VRAMStagingManager::CommonVRAMRegionTaskSet* func_01ff96fc(
    VRAMStagingManager::CommonVRAMRegionTaskSet* taskSet,
    unsigned char* indices, unsigned short capacity)
{
    taskSet->pendingTaskIndices_ = indices;
    taskSet->maxNumTasks_ = capacity;
    taskSet->Reset();
    return taskSet;
}

extern "C" VRAMStagingManager* func_01ff9718(VRAMStagingManager* manager)
{
    manager->ZeroInitialize();
    return manager;
}

extern "C" VRAMStagingManager* func_01ff972c(VRAMStagingManager* manager)
{
    manager->CancelAllTasks();
    return manager;
}
