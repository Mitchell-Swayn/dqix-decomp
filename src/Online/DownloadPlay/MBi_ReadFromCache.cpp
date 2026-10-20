#include <globaldefs.h>
#include <System/Interrupts.h>
#include <System/Memory.h>
ARM
struct CacheEntry { unsigned offset,length; unsigned char *data; unsigned state; };
struct Cache { unsigned miss; unsigned char pad[0x2c]; CacheEntry entries[4]; };
// Original: arm9/ov027 @ 0x021DD180; symbol: func_ov027_021dd180; size: 0x98.
// Copies a fully covered range from a ready cache entry while interrupts are masked.
extern "C" int MBi_ReadFromCache(Cache *cache,unsigned offset,void *destination,unsigned length)
{
    int result=0;
    int irq=DisableIRQInterrupts();
    for(CacheEntry *entry=cache->entries;entry<cache->entries+4;entry++) {
        if(entry->state>=2) {
            int relative=offset-entry->offset;
            if(relative>=0 && (unsigned)relative+length<=entry->length) {
                MI_CpuCopy8(entry->data+relative,destination,length);
                cache->miss=0;
                result=1;
                break;
            }
        }
    }
    SetIRQInterruptState(irq);
    return result;
}
