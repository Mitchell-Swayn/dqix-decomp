#include "Resource/ResourceMutex.h"

#ifdef jpn
#define OS_InitThread func_020c8f28
#define ProcessorContext_ReadPrimaryContextSetupFlag func_020c9070
#endif

struct ResourceMutex
{
    unsigned char unknown_0;
    bool lockPrerequisiteA_;
    bool lockPrerequisiteB_;
    char padding_3;
    unsigned int lockCount_;
    Mutex mutex_;
};

static ResourceMutex s_resourceMutex;

extern "C"
{
    // set up the main context
    void OS_InitThread();
    // check if the main context has been set up
    bool ProcessorContext_ReadPrimaryContextSetupFlag();
}

// Original: arm9/main @ 0x020D96B0; symbol: _Z23InitializeResourceMutexv; size: 0x44.
void InitializeResourceMutex()
{
    if (!ProcessorContext_ReadPrimaryContextSetupFlag())
        OS_InitThread();

    ZeroInitializeMutex(&s_resourceMutex.mutex_);
    s_resourceMutex.lockPrerequisiteB_ = true;
    s_resourceMutex.unknown_0 = 1;
    s_resourceMutex.lockPrerequisiteA_ = true;
    s_resourceMutex.lockCount_ = 0;
}

// Original: arm9/main @ 0x020D96F4; symbol: _Z27SetResourceMutexOperationalb; size: 0x18.
bool SetResourceMutexOperational(bool to)
{
    bool oldStatus = s_resourceMutex.lockPrerequisiteA_;
    s_resourceMutex.lockPrerequisiteA_ = to;
    return oldStatus;
}

// Original: arm9/main @ 0x020D970C; symbol: _Z17LockResourceMutexv; size: 0x40.
void LockResourceMutex()
{
    if (s_resourceMutex.lockPrerequisiteB_ && s_resourceMutex.lockPrerequisiteA_)
    {
        LockMutex(&s_resourceMutex.mutex_);
        s_resourceMutex.lockCount_++;
    }
}

// Original: arm9/main @ 0x020D974C; symbol: _Z19UnlockResourceMutexv; size: 0x3C.
void UnlockResourceMutex()
{
    if (s_resourceMutex.lockPrerequisiteB_ && s_resourceMutex.lockPrerequisiteA_)
    {
        s_resourceMutex.lockCount_--;
        UnlockMutex(&s_resourceMutex.mutex_);
    }
}

// Original: arm9/main @ 0x020D9788; symbol: _Z29SleepIfResourceMutexNotLockedj; size: 0x20.
void SleepIfResourceMutexNotLocked(unsigned int milliseconds)
{
    if (s_resourceMutex.lockCount_ == 0)
        SleepCurrentContext(milliseconds);
}