// Original locations for overloaded or compiler-generated definitions in this unit:
// Original: arm9/main @ 0x020C6FB4; symbol: _Z13ReleaseGBABust; size: 0xC. (ReleaseGBABus(unsigned short))
#include "System/GamecardBusOwnership.h"
#include "System/Interrupts.h"
#include <globaldefs.h>
#include <asmhacks.h>
#include "std_library_functions.h"

// Original data: arm9/main @ 0x21112dc; symbol: data_021112dc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern int InitializeGamecardBusOwnership_UnknownRoleZeroInitializedStorage;

#define REG_EXTMEMCTRL (*(volatile unsigned short*)0x04000204)
#define EXTMEMCTRL_FLAG_RELINQUISH_GBA_BUS (1 << 7)
#define EXTMEMCTRL_FLAG_RELINQUISH_NDS_BUS (1 << 11)

#define ADDR_REGISTERED_OWNERS_LOW 0x027fffb0
#define REGISTERED_OWNER_FLAGS ((unsigned int*)ADDR_REGISTERED_OWNERS_LOW)


#define PTR_NDS_BUS_LOCK ((GamecardBusLock*)0x027fffe0)
#define PTR_GBA_BUS_LOCK ((GamecardBusLock*)0x027fffe8)
#define PTR_UNKNOWN_BUS_LOCK ((GamecardBusLock*)0x027ffff0)

#pragma optimize_for_size off

#if defined(jpn)
#define MI_SwapWord func_020cc2ac
#endif

extern "C"
{
    void WaitByLoop(int);

    // aligned memset clone
    void MIi_CpuClear32(int val, void* dst, unsigned len);

    // Performs an atomic swap
    unsigned int MI_SwapWord(unsigned int newValue, volatile unsigned int* atomic);
}

int TryLockGamecardBusLock(unsigned short owner, GamecardBusLock* lock, void (*onLock)(), bool strict);
int WeakLockGamecardBusLock(unsigned short owner, GamecardBusLock* lock, void (*onLock)());
int WeakUnlockGamecardBusLock(unsigned short owner, GamecardBusLock* lock, void (*onUnlock)());

void MarkGBABusAcquired(); // acquire gba bus
void MarkGBABusReleased(); // release gba bus

void MarkNDSBusAcquired();
void MarkNDSBusReleased();

#if false
// this is almost correct except the first bit, excluding it for now
void InitializeGamecardBusOwnership()
{
    if (InitializeGamecardBusOwnership_UnknownRoleZeroInitializedStorage)
    {
        return;
    }
    
    GamecardBusLock* ndsLock = PTR_UNKNOWN_BUS_LOCK;
    InitializeGamecardBusOwnership_UnknownRoleZeroInitializedStorage = true;
    ndsLock->atomic = 0;
    
    WeakLockGamecardBusLock(126, ndsLock, NULL);

    if (ndsLock->unknown_6)
    {
        do
        {
            WaitByLoop(0x400);
        } while (ndsLock->unknown_6);
    }

    REGISTERED_OWNER_FLAGS[0] = 0xffffffff;
    REGISTERED_OWNER_FLAGS[1] = 0xffff0000;

    MIi_CpuClear32(0, (void*)0x027fffc0, 0x28);
    REG_EXTMEMCTRL |= EXTMEMCTRL_FLAG_RELINQUISH_NDS_BUS;
    REG_EXTMEMCTRL |= EXTMEMCTRL_FLAG_RELINQUISH_GBA_BUS;

    WeakUnlockGamecardBusLock(126, ndsLock, NULL);
    WeakLockGamecardBusLock(127, ndsLock, NULL);
}
#endif

// can be static
// Original: arm9/main @ 0x020C6E48; symbol: _Z19LockGamecardBusLocktP15GamecardBusLockPFvvEb; size: 0x4C.
int LockGamecardBusLock(unsigned short owner, GamecardBusLock* lock, void (*onLock)(), bool strict)
{
    int result = TryLockGamecardBusLock(owner, lock, onLock, strict);
    if (result > 0)
    {
        do {
            WaitByLoop(0x400);
            result = TryLockGamecardBusLock(owner, lock, onLock, strict);
        } while (result > 0);
    }
    return result;
}

// can be static
// Original: arm9/main @ 0x020C6E94; symbol: _Z23WeakLockGamecardBusLocktP15GamecardBusLockPFvvE; size: 0x10.
int WeakLockGamecardBusLock(unsigned short owner, GamecardBusLock* lock, void (*onLock)())
{
    return LockGamecardBusLock(owner, lock, onLock, false);
}

// can be static
// Original: arm9/main @ 0x020C6EA4; symbol: _Z21UnlockGamecardBusLocktP15GamecardBusLockPFvvEb; size: 0x74.
int UnlockGamecardBusLock(unsigned short owner, GamecardBusLock* lock, void (*onUnlock)(), bool strict)
{
    if (owner != lock->ownerID)
        return -2;
    
    int priorState;
    if (strict)
        priorState = DisableIRQAndFIQInterrupts();
    else
        priorState = DisableIRQInterrupts();

    lock->ownerID = 0;
    if (onUnlock != NULL)
        onUnlock();

    lock->atomic = 0;

    if (strict)
        SetIRQAndFIQInterruptState(priorState);
    else
        SetIRQInterruptState(priorState);
    return 0;
}

// can be static
// Original: arm9/main @ 0x020C6F18; symbol: _Z25WeakUnlockGamecardBusLocktP15GamecardBusLockPFvvE; size: 0x10.
int WeakUnlockGamecardBusLock(unsigned short owner, GamecardBusLock* lock, void (*onUnlock)())
{
    return UnlockGamecardBusLock(owner, lock, onUnlock, false);
}

// can be static
// Original: arm9/main @ 0x020C6F28; symbol: _Z22TryLockGamecardBusLocktP15GamecardBusLockPFvvEb; size: 0x6C.
int TryLockGamecardBusLock(unsigned short owner, GamecardBusLock* lock, void (*onLock)(), bool strict)
{
    int priorState;
    if (strict)
        priorState = DisableIRQAndFIQInterrupts();
    else
        priorState = DisableIRQInterrupts();

    int oldAtomic = MI_SwapWord(owner, &lock->atomic);
    if (oldAtomic == 0)
    {
        if (onLock != NULL)
            onLock();
        lock->ownerID = owner;
    }

    if (strict)
        SetIRQAndFIQInterruptState(priorState);
    else
        SetIRQInterruptState(priorState);
    return oldAtomic;
}

// can be static
// Original: arm9/main @ 0x020C6F94; symbol: _Z21InternalReleaseGBABust; size: 0x20.
int InternalReleaseGBABus(unsigned short owner)
{
    return UnlockGamecardBusLock(owner, PTR_GBA_BUS_LOCK, &MarkGBABusReleased, true);
}

// must be exposed
#ifdef __MWERKS__
asm int ReleaseGBABus(unsigned short owner)
{
    ldr r1, =InternalReleaseGBABus
    bx r1
}
#else
int ReleaseGBABus(unsigned short owner)
{
    return InternalReleaseGBABus(owner);
}
#endif

// must be exposed
// Original: arm9/main @ 0x020C6FC0; symbol: _Z16TryAcquireGBABust; size: 0x20.
int TryAcquireGBABus(unsigned short owner)
{
    return TryLockGamecardBusLock(owner, PTR_GBA_BUS_LOCK, &MarkGBABusAcquired, true);
}

// can be static
// Original: arm9/main @ 0x020C6FE0; symbol: _Z18MarkGBABusAcquiredv; size: 0x18.
void MarkGBABusAcquired()
{
    REG_EXTMEMCTRL &= ~EXTMEMCTRL_FLAG_RELINQUISH_GBA_BUS;
}

// can be static
// Original: arm9/main @ 0x020C6FF8; symbol: _Z18MarkGBABusReleasedv; size: 0x18.
void MarkGBABusReleased()
{
    REG_EXTMEMCTRL |= EXTMEMCTRL_FLAG_RELINQUISH_GBA_BUS;
}

// must be exposed
// Original: arm9/main @ 0x020C7010; symbol: _Z13AcquireNDSBust; size: 0x1C.
int AcquireNDSBus(unsigned short owner)
{
    return WeakLockGamecardBusLock(owner, PTR_NDS_BUS_LOCK, &MarkNDSBusAcquired);
}

// must be exposed
// Original: arm9/main @ 0x020C702C; symbol: _Z13ReleaseNDSBust; size: 0x1C.
int ReleaseNDSBus(unsigned short owner)
{
    return WeakUnlockGamecardBusLock(owner, PTR_NDS_BUS_LOCK, &MarkNDSBusReleased);
}

// can be static
// Original: arm9/main @ 0x020C7048; symbol: _Z18MarkNDSBusAcquiredv; size: 0x18.
void MarkNDSBusAcquired()
{
    REG_EXTMEMCTRL &= ~EXTMEMCTRL_FLAG_RELINQUISH_NDS_BUS;
}

// can be static
// Original: arm9/main @ 0x020C7060; symbol: _Z18MarkNDSBusReleasedv; size: 0x18.
void MarkNDSBusReleased()
{
    REG_EXTMEMCTRL |= EXTMEMCTRL_FLAG_RELINQUISH_NDS_BUS;
}

// must be exposed
// Original: arm9/main @ 0x020C7078; symbol: _Z12GetLockOwnerP15GamecardBusLock; size: 0x8.
unsigned short GetLockOwner(GamecardBusLock* lock)
{
    return lock->ownerID;
}

inline int leadZeroCount(unsigned int what)
{
    int ret;
    __asm("clz %[output], %[input]" : : [output] "=r" (ret), [input] "r" (what));
    return ret;
}

// GenerateLockOwnerID and ReleaseLockOwnerID are the next two functions,
// but they appear to be written in assembly (they use clz which the compiler
// never emits, and more generally are quite weird for compiled code)