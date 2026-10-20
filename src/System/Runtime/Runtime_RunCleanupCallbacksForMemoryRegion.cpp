#include "System/Interrupts.h"
struct CleanupNode { CleanupNode* next; void (*cleanup)(unsigned int); unsigned int argument; };
struct MemoryRegion { unsigned int reserved, start, size, extraSize; };
// Original data: arm9/main @ 0x20f33b0; symbol: data_020f33b0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" CleanupNode* RuntimeRunCleanupCallbacksForMemoryRegion_UnknownRoleZeroInitializedStorage;
#pragma optimize_for_size off
// Original: arm9/main @ 0x020CD494; symbol: func_020cd494; size: 0xF0.
extern "C" void Runtime_RunCleanupCallbacksForMemoryRegion(MemoryRegion* region)
{
    for (;;) {
        CleanupNode* first = 0;
        CleanupNode* last = 0;
        unsigned int start = region->start;
        unsigned int end = start + (region->size + region->extraSize);
        int irq = DisableIRQInterrupts();
        CleanupNode* previous = 0;
        CleanupNode* head = RuntimeRunCleanupCallbacksForMemoryRegion_UnknownRoleZeroInitializedStorage;
        CleanupNode* node = head;
        if (node) { do {
            CleanupNode* next = node->next;
            unsigned int argument = node->argument;
            unsigned int callbackAddress = (unsigned int)node->cleanup;
            if ((!argument && callbackAddress >= start && callbackAddress < end) ||
                (argument >= start && argument < end)) {
                if (last) last->next = node; else first = node;
                if (head == node) { RuntimeRunCleanupCallbacksForMemoryRegion_UnknownRoleZeroInitializedStorage = next; head = next; }
                node->next = 0;
                last = node;
                if (previous) previous->next = next;
            } else previous = node;
            node = next;
        } while (node); }
        SetIRQInterruptState(irq);
        if (!first) return;
        do {
            CleanupNode* next = first->next;
            if (first->cleanup) first->cleanup(first->argument);
            first = next;
        } while (first);
    }
}
