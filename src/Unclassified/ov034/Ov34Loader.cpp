#include "Ov34Loader.h"
#include "Filesystem/GPC.h"
#include "Resource/ResourceMutex.h"

#ifdef jpn
#define func_020a1a40 func_020a37b8
#define OverlayLoader_LoadIndexedOverlayWithSharedStatusLocks func_020a3a44
#endif

extern "C"
{
    // Capture platform state for the periodic loader timing sample.
    void OS_GetLowEntropyData(unsigned int*);
    void* AllocatorUnion_AllocateFourByteAligned(void*,unsigned int);
    extern char data_02114e20[];
    // get crc for string
    unsigned int FileCache_CalculateStringCRC(const char*);
    // alternate version of load overlay
    void func_020a1a40(int);
    // alternate unload overlay
    void OverlayLoader_LoadIndexedOverlayWithSharedStatusLocks(int);
}

static RuntimeDestructorNode destructorNode;
static Ov34LoaderStorage loaderStorage;
extern "C" Ov34LoaderDispatch ov34Dispatch,ov34BaseDispatch;
extern "C" void __register_global_object(void*,void(*)(void*,int),RuntimeDestructorNode*);

#pragma force_active on
// Original: arm9/ov034 @ 0x022A2180; symbol: func_ov034_022a2180; size: 0x28.
extern "C" void func_ov034_022a2180(void* fileLoadSpace,unsigned int capacity,int relativePrio)
{
    ((BackgroundLoader*)&loaderStorage)->Populate(fileLoadSpace,capacity,relativePrio);
}
#pragma force_active reset

// Original: arm9/ov034 @ 0x022A21A8; symbol: func_ov034_022a21a8; size: 0x810.
extern "C" int func_ov034_022a21a8(BackgroundLoader* loader)
{
    Ov34LoaderAccess& state=*(Ov34LoaderAccess*)loader;
    typedef BackgroundLoader::Task Task;
    typedef BackgroundLoader::TaskStatus TaskStatus;
    GPCFile* pGPC;
    LockResourceMutex();
    ZeroInitGPCPointer(&pGPC);
    unsigned int currentArchiveCRC = 0;
    while (true)
    {
        state.flags_78c_0_ = true;
        // Begin by doing overlay load/unload operations
        Task* pTask = &state.queuedTasks_[0];
        for (int i = 0; i < state.numPendingTasks_; i++, pTask++)
        {
            switch (pTask->type_)
            {
            case BackgroundLoader::TaskType_LoadOverlay:
            {
                pTask->status_ = BackgroundLoader::TaskStatus_InFlight;
                UnlockResourceMutex();
                func_020a1a40(pTask->fileLengthOrOverlayID_);
                LockResourceMutex();
                pTask->status_ = BackgroundLoader::TaskStatus_Complete;
                break;
            }
            case BackgroundLoader::TaskType_UnloadOverlay:
            {
                pTask->status_ = BackgroundLoader::TaskStatus_InFlight;
                UnlockResourceMutex();
                OverlayLoader_LoadIndexedOverlayWithSharedStatusLocks(pTask->fileLengthOrOverlayID_);
                LockResourceMutex();
                pTask->status_ = BackgroundLoader::TaskStatus_Complete;
                break;
            }
            default:
                continue;
            }
            // If we get here, we actually did something, so remove the task
            // and shift things up
            Task* qTask = pTask;
            for (int j = i + 1; j < state.numPendingTasks_; j++, qTask++)
            {
                qTask[0] = qTask[1];
            }
            pTask--;
            state.numPendingTasks_--;
        }

        bool allCompleteTasksAreExternallyAllocated = true;
        if (state.rightmostAllocationByte_ != 0)
        {
            Task* pTask = &state.queuedTasks_[0];
            for (int i = 0; i < state.numPendingTasks_; i++, pTask++)
            {
                if (pTask->externalAllocator_ == NULL && pTask->status_ == BackgroundLoader::TaskStatus_Complete)
                {
                    allCompleteTasksAreExternallyAllocated = false;
                    break;
                }
            }
        }
        if (allCompleteTasksAreExternallyAllocated)
            state.rightmostAllocationByte_ = 0;

        if (state.numPendingTasks_ <= 0)
            goto end;
        if (state.processLockBits_ != 0)
        {
            state.flags_78c_0_ = false;
            goto end;
        }

        Task* gpcTask = NULL;
        if (CheckGPCPairValid_020d917c(pGPC, state.reader_))
        {
            Task* pTask=&state.queuedTasks_[0];
            for (int j = 0; j < state.numPendingTasks_; j++,pTask++)
            {
                if (pTask->status_ == BackgroundLoader::TaskStatus_Fence)
                {
                    state.flags_78c_0_ = false;
                    goto end;
                }
                else if (pTask->status_ == BackgroundLoader::TaskStatus_Unallocated &&
                    pTask->type_ == BackgroundLoader::TaskType_LoadFromGP2 &&
                    currentArchiveCRC == FileCache_CalculateStringCRC(pTask->outerFilename_))
                {
                    state.flags_78c_0_ = false;
                    gpcTask = pTask;
                    break;
                }
            }
        }

        if (gpcTask == NULL)
        {
            ResetGPCPair(&pGPC, state.reader_);
            currentArchiveCRC = 0;
            state.scratchRightArenaUsage_ = 0;
            state.flagMaybeGP2OperationInFlight_ = false;
            Task* qTask = &state.queuedTasks_[0];
            for (int j = 0; j < state.numPendingTasks_; j++, qTask++)
            {
                if (qTask->status_ == BackgroundLoader::TaskStatus_Fence)
                {
                    state.flags_78c_0_ = false;
                    goto end;
                }
                else if (qTask->status_ == BackgroundLoader::TaskStatus_Unallocated)
                {
                    state.flags_78c_0_ = false;
                    gpcTask = qTask;
                    break;
                }
            }
        }

        if (gpcTask == NULL)
            goto end;

        gpcTask->status_ = BackgroundLoader::TaskStatus_InFlight;
        Task inFlightTask;
        inFlightTask = *gpcTask; // work with a copy, we'll copy changes back at the end
        state.flags_78c_3_ = true;
        UnlockResourceMutex();
        char fullName[80];
        inFlightTask.GetFullFilename(fullName);
        inFlightTask.pFileData = NULL;
        inFlightTask.fileLengthOrOverlayID_ = 0;
        switch (inFlightTask.type_)
        {
        case BackgroundLoader::TaskType_LoadFileDefault:
        case BackgroundLoader::TaskType_LoadGP1:
        {
            state.reader_.ZeroInitialize();
            if (!state.reader_.Open(fullName, false))
                inFlightTask.status_ = BackgroundLoader::TaskStatus_LoadFileFailed;
            else
            {
                if (inFlightTask.type_ == BackgroundLoader::TaskType_LoadFileDefault)
                    inFlightTask.fileLengthOrOverlayID_ = state.reader_.GetFileSize();
                else
                {
                    CompressionPrefix prefix;
                    *(unsigned int*)&prefix = 0;
                    state.reader_.Read(&prefix, 4);
                    inFlightTask.fileLengthOrOverlayID_ = prefix.GetDecompressedLength();
                    state.reader_.Seek(0);
                }
                unsigned int allocSize;
                if (inFlightTask.type_ == BackgroundLoader::TaskType_LoadFileDefault)
                    allocSize = inFlightTask.fileLengthOrOverlayID_;
                else
                    allocSize = (inFlightTask.fileLengthOrOverlayID_ + 7) & ~3;

                if (inFlightTask.externalAllocator_ != NULL)
                {
                    inFlightTask.pFileData = inFlightTask.externalAllocator_->Allocate(allocSize);
                    if (inFlightTask.pFileData == NULL)
                        inFlightTask.status_ = BackgroundLoader::TaskStatus_Unallocated;
                }
                else
                {
                    inFlightTask.pFileData = state.AllocateInScratchSpace(&inFlightTask.scratchAlloc_, allocSize);
                    if (inFlightTask.pFileData == NULL)
                        inFlightTask.status_ = BackgroundLoader::TaskStatus_Unallocated;
                }

                if (inFlightTask.pFileData != NULL && inFlightTask.status_ == BackgroundLoader::TaskStatus_InFlight)
                {
                    if (inFlightTask.type_ == BackgroundLoader::TaskType_LoadFileDefault)
                    {
                        state.reader_.Read(inFlightTask.pFileData, inFlightTask.fileLengthOrOverlayID_);
                    }
                    else // BackgroundLoader::TaskType_LoadGP1
                    {
                        unsigned int compressedSize = state.reader_.GetFileSize();
                        state.reader_.DecompressBytes(inFlightTask.pFileData, inFlightTask.fileLengthOrOverlayID_,
                            compressedSize, allocSize);
                    }
                }
                else
                {
                    state.FreeScratchSpace(&inFlightTask.scratchAlloc_);
                    inFlightTask.fileLengthOrOverlayID_ = 0;
                }
                state.reader_.Close();
            }
            break;
        }
        case BackgroundLoader::TaskType_LoadFromGP2:
        {
            state.flagMaybeGP2OperationInFlight_ = true;
            GPCFile::Header header;
            unsigned int outBufferRightMinusLeft = state.scratchSpaceSize_ - state.rightmostAllocationByte_ - state.scratchRightArenaUsage_;
            // this looks like the start of the buffer but we right-align the output so really
            // it's the end (we're not allowed to go any further left than this).
            // This coincides with the right endpoint of file data loaded into allocations
            // of the scratch space.
            unsigned char* outputBufferLeft = (unsigned char*)state.scratchSpace_ + state.rightmostAllocationByte_;
            unsigned int outLength = 0;
            bool outSuccess = false;
            if (!CheckGPCPairValid_020d917c(pGPC, state.reader_) &&
                !LoadAndDecompressGPCHeaderAndInnerFileInfo(&pGPC, state.reader_, fullName, outputBufferLeft,
                    outLength, outBufferRightMinusLeft, true, &outSuccess))
            {
                state.flagMaybeGP2OperationInFlight_ = false;
                if (outSuccess)
                    inFlightTask.status_ = BackgroundLoader::TaskStatus_Unallocated;
                else
                    inFlightTask.status_ = BackgroundLoader::TaskStatus_LoadFileFailed;
            }
            else
            {
                currentArchiveCRC = FileCache_CalculateStringCRC(inFlightTask.outerFilename_);
                // note that prior to this instruction, one of these is always zero:
                // if the previous iteration handled this archive, then we didn't reload
                // it (short-circuit && in the if-statement above) so outLength = 0,
                // and if we handled a different archive / null, then it's been reset
                // since and arena usage set back to zero.
                state.scratchRightArenaUsage_ += outLength;
                unsigned int innerFileLength = GetGPCInnerFileLengthByName(pGPC, state.reader_, inFlightTask.innerFilename_);
                unsigned int allocSize = (innerFileLength + 7) & ~3;
                if (inFlightTask.externalAllocator_ != NULL)
                {
                    inFlightTask.pFileData = inFlightTask.externalAllocator_->Allocate(allocSize);
                    if (inFlightTask.pFileData == NULL)
                        inFlightTask.status_ = BackgroundLoader::TaskStatus_Unallocated;
                    else
                    {
                        if (!DecompressFileFromGPCByName(pGPC, state.reader_, inFlightTask.pFileData, inFlightTask.fileLengthOrOverlayID_, allocSize, inFlightTask.innerFilename_))
                        {
                            inFlightTask.externalAllocator_->Free(inFlightTask.pFileData);
                            inFlightTask.pFileData = NULL;
                            inFlightTask.fileLengthOrOverlayID_ = 0;
                            inFlightTask.status_ = BackgroundLoader::TaskStatus_DecompressionFailed;
                        }
                    }
                }
                else
                {
                    inFlightTask.pFileData = state.AllocateInScratchSpace(&inFlightTask.scratchAlloc_, allocSize);
                    if (inFlightTask.pFileData == NULL)
                        inFlightTask.status_ = BackgroundLoader::TaskStatus_Unallocated;
                    else
                    {
                        if (!DecompressFileFromGPCByName(pGPC, state.reader_, inFlightTask.pFileData, inFlightTask.fileLengthOrOverlayID_, allocSize, inFlightTask.innerFilename_))
                        {
                            state.FreeScratchSpace(&inFlightTask.scratchAlloc_);
                            inFlightTask.pFileData = NULL;
                            inFlightTask.fileLengthOrOverlayID_ = 0;
                            inFlightTask.status_ = BackgroundLoader::TaskStatus_DecompressionFailed;
                        }
                    }
                }
            }
            break; // switch statement
        }
        }
        if (inFlightTask.pFileData != NULL)
        {
            inFlightTask.status_ = BackgroundLoader::TaskStatus_Complete;
            unsigned int sample[8];
            OS_GetLowEntropyData(sample);
            unsigned int fold=sample[0]^sample[1]^sample[2]^sample[3]^sample[4]^sample[5]^sample[6]^sample[7];
            int byte=((fold>>24)^(fold>>16)^(fold>>8)^fold)&0xff;
            unsigned char bucket=((byte>>6)^(byte>>4)^(byte>>2)^byte)&3;
            if(bucket==0)AllocatorUnion_AllocateFourByteAligned(data_02114e20,8);
        }

        LockResourceMutex();
        state.flags_78c_3_ = false;
        state.RefreshCounters();
        Task* pTaskToUpdate = NULL;
        Task* qTask = &state.queuedTasks_[0];
        for (int i = 0; i < state.numPendingTasks_; i++, qTask++)
        {
            if (qTask->taskID_ != inFlightTask.taskID_)
                continue;

            if (qTask->status_ == BackgroundLoader::TaskStatus_InFlight)
                pTaskToUpdate = qTask;
            break;
        }

        if (pTaskToUpdate != NULL)
        {
            *pTaskToUpdate = inFlightTask;
        }
        else
        {
            state.FreeScratchSpace(&inFlightTask.scratchAlloc_);
            if (inFlightTask.status_ == BackgroundLoader::TaskStatus_Complete && inFlightTask.externalAllocator_ != NULL)
                inFlightTask.externalAllocator_->Free(inFlightTask.pFileData);
            if (CheckGPCPairValid_020d917c(pGPC, state.reader_))
            {
                ResetGPCPair(&pGPC, state.reader_);
                currentArchiveCRC = 0;
                state.scratchRightArenaUsage_ = 0;
                state.flagMaybeGP2OperationInFlight_ = false;
            }
        }

        inFlightTask.ZeroInitialize();
    }

end:
    UnlockResourceMutex();
    ResetGPCPair(&pGPC, state.reader_);
    state.scratchRightArenaUsage_ = 0;
    state.flagMaybeGP2OperationInFlight_ = false;
    if (state.numPendingTasks_ <= 0)
        SleepIfResourceMutexNotLocked(5);
    ZeroDestroyGPCPointer(&pGPC);
    return 0;
}



#pragma dont_inline on
// Original: arm9/ov034 @ 0x022A29B8; symbol: func_ov034_022a29b8; size: 0x2C.
extern "C" BackgroundLoader* func_ov034_022a29b8(BackgroundLoader* p)
{
    *(const void**)p=&ov34BaseDispatch.process;
    p->InitializeOrReset();
    *(const void**)p=&ov34Dispatch.process;
    return p;
}
// Original: arm9/ov034 @ 0x022A29E4; symbol: func_ov034_022a29e4; size: 0x20.
extern "C" BackgroundLoader* func_ov034_022a29e4(BackgroundLoader* p,int flags)
{
    *(const void**)p=&ov34BaseDispatch.process;
    p->InitializeOrReset();
    return p;
}
#pragma define_section init ".init" RX
// Original: arm9/ov034 @ 0x022A2A04; symbol: __sinit_ov034_022a2a04; size: 0x2C.
extern "C" __declspec(section "init") void __sinit_ov034_022a2a04()
{
    func_ov034_022a29b8((BackgroundLoader*)&loaderStorage);
    __register_global_object(&loaderStorage,(void(*)(void*,int))func_ov034_022a29e4,&destructorNode);
}
#pragma define_section ctor ".ctor" RW
#pragma force_active on
static __declspec(section "ctor") void (*initializer)()=__sinit_ov034_022a2a04;
#pragma force_active reset

#pragma define_section dispatch_data ".data" RW
extern "C" {
    __declspec(section "dispatch_data") Ov34LoaderDispatch ov34Dispatch={{0,0},func_ov034_022a21a8};
    __declspec(section "dispatch_data") Ov34LoaderDispatch ov34BaseDispatch={{0,0},0};
}
