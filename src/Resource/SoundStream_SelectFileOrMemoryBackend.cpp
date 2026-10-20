#include <globaldefs.h>

ARM
#pragma optimize_for_size off
extern "C" {
unsigned int NNS_SndArcGetFileAddress(unsigned int);
int Filesystem_ReadSixtyFourByteHeaderAndPrepareStream(void *, void *); int Object_InvokeNitroVM_FinishRead(void *); void NitroVM_SeekAndReadSyncAtStoredOffset(void *,void *,int,int); void Filesystem_CancelEmbeddedNitroVMCommand(void *);
int ResourceState_ResolveAndCopySixtyFourBytes(void *, void *); int SoundStream_FinishMemoryReadNoOp(void *); void CopySourceRangeAndReturnLength(void *,void *,int,int); void ResourceBackend_CloseNoOp(void *);
struct State { unsigned char pad[0x164]; int (*open)(void *,void *); int (*ready)(void *); void (*read)(void *,void *,int,int); void (*close)(void *); };
// Original: arm9/main @ 0x020BFFC4; symbol: func_020bffc4; size: 0x80.
void SoundStream_SelectFileOrMemoryBackend(State *p, unsigned int id) {
    if (!NNS_SndArcGetFileAddress(id)) {
        p->open=Filesystem_ReadSixtyFourByteHeaderAndPrepareStream; p->ready=Object_InvokeNitroVM_FinishRead; p->read=NitroVM_SeekAndReadSyncAtStoredOffset; p->close=Filesystem_CancelEmbeddedNitroVMCommand;
        return;
    }
    else {
        p->open=ResourceState_ResolveAndCopySixtyFourBytes; p->ready=SoundStream_FinishMemoryReadNoOp; p->read=CopySourceRangeAndReturnLength; p->close=ResourceBackend_CloseNoOp; return;
    }
}
}
