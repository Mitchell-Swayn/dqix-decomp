// Original: arm9/main @ 0x02012DE4; symbol: func_02012de4; size: 0x4.
// Returns without touching the allocator. Callers pass the same allocator
// as the allocation/free wrappers; any former maintenance intent is unproven.
// Proposed descriptive symbol: AllocatorUnion_LeaveUnchanged (integrator migrates ABI).
extern "C" void AllocatorUnion_LeaveUnchanged(void* allocator)
{
}
