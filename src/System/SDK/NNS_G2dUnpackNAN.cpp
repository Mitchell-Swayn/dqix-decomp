#include <globaldefs.h>
#pragma optimization_level 4
#pragma optimize_for_size off
typedef unsigned short u16;
typedef unsigned long sdk_u32;
typedef int NNSG2dAnimationPlayMode;
struct NNSG2dBinaryBlockHeader { sdk_u32 kind, size; };
struct NNSG2dUserExDataBlock { sdk_u32 kind, size; };
#define NNS_G2D_UNPACK_OFFSET_PTR(ptr, baseOffs) ((ptr) = (__typeof__(ptr))((sdk_u32)(ptr) + (sdk_u32)(baseOffs)))
typedef struct NNSG2dAnimFrameData {
    void * pContent;
    u16 frames;
    u16 pad16;
} NNSG2dAnimFrameData;

typedef struct NNSG2dAnimSequenceData {
    u16 numFrames;
    u16 loopStartFrameIdx;
    sdk_u32 animType;
    NNSG2dAnimationPlayMode playMode;
    NNSG2dAnimFrameData * pAnmFrameArray;
} NNSG2dAnimSequenceData;

typedef struct NNSG2dAnimBankData {
    u16 numSequences;
    u16 numTotalFrames;
    NNSG2dAnimSequenceData * pSequenceArrayHead;
    NNSG2dAnimFrameData * pFrameArrayHead;
    void * pAnimContents;
    void * pStringBank;
    void * pExtendedData;
} NNSG2dAnimBankData;

typedef struct NNSG2dAnimBankDataBlock {
    NNSG2dBinaryBlockHeader blockHeader;
    NNSG2dAnimBankData animBankData;
} NNSG2dAnimBankDataBlock;

typedef struct NNSG2dUserExAnimFrameAttr {
    sdk_u32 * pAttr;
} NNSG2dUserExAnimFrameAttr;

typedef struct NNSG2dUserExAnimSequenceAttr {
    u16 numFrames;
    u16 pad16;
    sdk_u32 * pAttr;
    NNSG2dUserExAnimFrameAttr * pAnmFrmAttrArray;
} NNSG2dUserExAnimSequenceAttr;

typedef struct NNSG2dUserExAnimAttrBank {
    u16 numSequences;
    u16 numAttribute;
    NNSG2dUserExAnimSequenceAttr * pAnmSeqAttrArray;
} NNSG2dUserExAnimAttrBank;


// Primary SDK C: ntrtwl/NitroSystem@d636fb5d2b212e8736f09859fff447be2bd0ac85
// libraries/g2d/src/load/g2d_NAN_load.c:101-152; SDK_FINALROM removes assertions/debug.
// SDK u32 is unsigned long; pointer-offset macro retains its original self-assignment.
// C++ adaptation uses a typed cast for the original C implicit void-pointer conversion.
// Original: arm9/main @ 0x020AFF0C; symbol: func_020aff0c; size: 0x150.
extern "C" ARM void NNS_G2dUnpackNAN (NNSG2dAnimBankData * pData)
{
    u16 i, j;



    pData->pSequenceArrayHead = NNS_G2D_UNPACK_OFFSET_PTR(pData->pSequenceArrayHead, pData);
    pData->pFrameArrayHead = NNS_G2D_UNPACK_OFFSET_PTR(pData->pFrameArrayHead, pData);
    pData->pAnimContents = NNS_G2D_UNPACK_OFFSET_PTR(pData->pAnimContents, pData);

    {
        NNSG2dAnimSequenceData * pSeq = pData->pSequenceArrayHead;
        NNSG2dAnimFrameData * pFrameBase = pData->pFrameArrayHead;
        void * pContentsBase = pData->pAnimContents;

        for (i = 0; i < pData->numSequences; i++) {
            pSeq[i].pAnmFrameArray = NNS_G2D_UNPACK_OFFSET_PTR(pSeq[i].pAnmFrameArray, pFrameBase);

            for (j = 0; j < pSeq[i].numFrames; j++) {
                pSeq[i].pAnmFrameArray[j].pContent =
                    NNS_G2D_UNPACK_OFFSET_PTR(pSeq[i].pAnmFrameArray[j].pContent, pContentsBase);
            }


        }
    }

    if (pData->pExtendedData != NULL) {
        pData->pExtendedData = NNS_G2D_UNPACK_OFFSET_PTR(pData->pExtendedData, pData);
        {
            sdk_u32 i = 0;
            sdk_u32 j = 0;

            NNSG2dUserExDataBlock * pExBlk = (NNSG2dUserExDataBlock *)pData->pExtendedData;
            NNSG2dUserExAnimAttrBank * pAnmExAttrBank = (NNSG2dUserExAnimAttrBank *)(pExBlk + 1);
            pAnmExAttrBank->pAnmSeqAttrArray = NNS_G2D_UNPACK_OFFSET_PTR(pAnmExAttrBank->pAnmSeqAttrArray, pAnmExAttrBank);

            for (i = 0; i < pAnmExAttrBank->numSequences; i++) {
                NNSG2dUserExAnimSequenceAttr * pSeqAttr = &pAnmExAttrBank->pAnmSeqAttrArray[i];

                pSeqAttr->pAttr = NNS_G2D_UNPACK_OFFSET_PTR(pSeqAttr->pAttr, pAnmExAttrBank);
                pSeqAttr->pAnmFrmAttrArray = NNS_G2D_UNPACK_OFFSET_PTR(pSeqAttr->pAnmFrmAttrArray, pAnmExAttrBank);
                for (j = 0; j < pSeqAttr->numFrames; j++) {
                    NNSG2dUserExAnimFrameAttr * pFrm = &pSeqAttr->pAnmFrmAttrArray[j];
                    pFrm->pAttr = NNS_G2D_UNPACK_OFFSET_PTR(pFrm->pAttr, pAnmExAttrBank);
                }
            }
        }
    }


}
