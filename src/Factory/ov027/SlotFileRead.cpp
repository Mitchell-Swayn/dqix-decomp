#include <globaldefs.h>
#include <Filesystem/FileAccessor.h>
#include <Filesystem/LowNitroHandle.h>

struct SlotReadRequest {
    unsigned int offset;
    int length;
    void* destination;
    unsigned int state;
};

struct SlotArchive {
    unsigned char unknown[0x10];
    char signature[4];
    int signatureLength;
    NitroHandle* fallback;
};

struct SlotReadTask {
    unsigned char unknown[0x10];
    SlotReadRequest* request;
    SlotArchive* archive;
};

#pragma optimize_for_size off
extern "C" ARM void func_ov027_021d989c(SlotReadTask* task) {
    SlotArchive* archive = task->archive;
    SlotReadRequest* request = task->request;
    NitroHandle* handle = NitroHandle_FindBySignature(archive->signature, archive->signatureLength);
    if (!handle) handle = archive->fallback;
    NitroVM vm;
    NitroVM_Initialize(&vm);
    if (NitroVM_PrepareRead(&vm, handle, request->offset,
                            request->offset + request->length, -1)) {
        if (NitroVM_ReadSync(&vm, request->destination, request->length) == request->length)
            request->state = 2;
        NitroVM_FinishRead(&vm);
    }
    switch (request->state) {
    case 2: return;
    default:
        request->offset = 0;
        request->state = 2;
        break;
    }
}
