#include <globaldefs.h>
#include <Filesystem/FileAccessor.h>
#include <Filesystem/NitroVM.h>
#include <Filesystem/LowNitroHandle.h>
ARM
struct ReloadEntry { unsigned offset,length; void *buffer; unsigned state; };
struct ReloadSource { unsigned char pad[16]; char signature[4]; int index; NitroHandle *fallback; };
struct ReloadTask { unsigned char pad[16]; ReloadEntry *entry; ReloadSource *source; };
// Original: arm9/ov027 @ 0x021D989C; symbol: func_ov027_021d989c; size: 0xA4.
// Refills a cache entry from the named archive or fallback handle; failed fills reset its offset.
extern "C" void MBi_ReloadCache(ReloadTask *task)
{
    ReloadSource *source=task->source;
    ReloadEntry *entry=task->entry;
    NitroHandle *handle=NitroHandle_FindBySignature(source->signature,source->index);
    if(!handle)handle=source->fallback;
    NitroVM vm;
    NitroVM_Initialize(&vm);
    if(NitroVM_PrepareRead(&vm,handle,entry->offset,entry->offset+entry->length,-1)) {
        if((unsigned)NitroVM_ReadSync(&vm,entry->buffer,entry->length)==entry->length) entry->state=2;
        NitroVM_FinishRead(&vm);
    }
    if(entry->state!=2) {
        entry->offset=0;
        entry->state=2;
    }
}
