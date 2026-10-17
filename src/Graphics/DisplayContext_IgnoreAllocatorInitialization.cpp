class SafeAllocator;
// Original: arm9/main @ 0x02094A20; symbol: func_02094a20; size: 0x4.
// Disabled allocator initialization hook, called after constructing the display context.
// The second argument is the SafeAllocator used to allocate that context. Return is unused.
// Proposed descriptive name: DisplayContext_IgnoreAllocatorInitialization.
extern "C" void DisplayContext_IgnoreAllocatorInitialization(void *context, SafeAllocator *allocator)
{
}
