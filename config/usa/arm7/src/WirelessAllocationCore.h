#ifndef DQIX_ARM7_WIRELESS_ALLOCATION_CORE_H
#define DQIX_ARM7_WIRELESS_ALLOCATION_CORE_H
/* Owner-tagged intrusive allocation headers precede the payload by 12 bytes. */
typedef struct WirelessAllocationHeader WirelessAllocationHeader;
struct WirelessAllocationHeader {
    WirelessAllocationHeader *previous, *next;
    unsigned short owner, magic;
};
typedef struct {
    WirelessAllocationHeader *first, *last;
    volatile unsigned short count;
    unsigned short owner;
} WirelessAllocationList;
extern unsigned int ARM7_DisableSpecificInterrupts(unsigned int mask);
extern unsigned int ARM7_EnableSpecificInterrupts(unsigned int state);
extern int ARM7_RemoveWirelessAllocation(WirelessAllocationList *, WirelessAllocationHeader *);
extern int ARM7_AppendValidatedWirelessAllocation(WirelessAllocationList *, WirelessAllocationHeader *);
#endif
