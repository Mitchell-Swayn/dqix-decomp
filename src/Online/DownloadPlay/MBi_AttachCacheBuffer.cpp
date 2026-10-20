#include <globaldefs.h>
#include <System/Interrupts.h>
ARM
extern "C" void DisableInterruptsAndHaltForever(void);
struct AttachedCacheEntry { unsigned offset,length; void *buffer; unsigned state; };
struct AttachedCache { unsigned char pad[0x30]; AttachedCacheEntry entries[4]; };
// Original: arm9/ov027 @ 0x021DD118; symbol: func_ov027_021dd118; size: 0x68.
// Fills the first unused cache entry under IRQ protection, halting when every entry is occupied.
extern "C" void MBi_AttachCacheBuffer(AttachedCache *cache,unsigned offset,unsigned length,void *buffer,unsigned state)
{
    AttachedCacheEntry *end;
    int irq;
    AttachedCacheEntry *entry;
    irq=DisableIRQInterrupts();
    entry=cache->entries;
    end=cache->entries+4;
    for(;;) {
        if(entry>=end)DisableInterruptsAndHaltForever();
        if(entry->state==0) {
            entry->offset=offset; entry->length=length; entry->buffer=buffer; entry->state=state; break;
        }
        entry++;
    }
    SetIRQInterruptState(irq);
}
