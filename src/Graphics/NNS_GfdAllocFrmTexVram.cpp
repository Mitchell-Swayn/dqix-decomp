// Community SDK reference: ntrtwl/NitroSystem@d636fb5d2b212e8736f09859fff447be2bd0ac85
// libraries/gfd/src/VramManager/gfd_FrameTexVramMan.c and gfd_TexVramMan_Types.h.
// Equivalent C++ reconstruction: the two nonempty fixed-count searches use do-loops.
// Per-file -ipa file preserves the library compiler's deferred inlining/register allocation.
#include "Graphics/VRAMImagePool.h"
#pragma optimize_for_size off
#pragma dont_inline off
typedef unsigned long u32;
typedef int BOOL;
typedef char CheckSDKWordIsFourBytes[(sizeof(u32) == 4) ? 1 : -1];
typedef char CheckPoolHasTwentyFourByteStride[(sizeof(Struct_020f1f14) == 24) ? 1 : -1];
extern Struct_020f1f14* data_020f1ef8[7];

static inline u32 GetCapacity(const Struct_020f1f14* p) { return (u32)(p->freeEnd_ - p->freeStart_); }
static inline u32 AllocateHead(Struct_020f1f14* p, u32 size) {
    const u32 result = p->freeStart_;
    p->freeStart_ += size;
    return result;
}
static inline u32 AllocateTail(Struct_020f1f14* p, u32 size) {
    p->freeEnd_ -= size;
    return p->freeEnd_;
}
static inline Struct_020f1f14* GetPairedPool(const Struct_020f1f14* p) {
    switch (p->relatedToPairing_) {
    case 0: return &data_020f1f14[1];
    case 3: return &data_020f1f14[2];
    default: break;
    }
    return 0;
}
static inline BOOL ReservePaired(u32 size, u32* address) {
    int i;
    Struct_020f1f14* p = 0;
    Struct_020f1f14* pair = 0;
    i = 0;
    do {
        p = data_020f1ef8[i];
        if (p->maybeIsUsable_ && GetCapacity(p) >= size) {
            pair = GetPairedPool(p);
            if (pair->maybeIsUsable_ && GetCapacity(pair) >= size / 2) {
                *address = AllocateHead(p, size);
                (void)AllocateHead(pair, size / 2);
                *address += p->poolBase_;
                return 1;
            }
        }
    } while (++i < 2);
    return 0;
}
static inline BOOL ReserveOrdinary(u32 size, u32* address) {
    int i;
    Struct_020f1f14* p = 0;
    i = 0;
    do {
        p = (&data_020f1ef8[2])[i];
        if (p->maybeIsUsable_) {
            if (GetCapacity(p) >= size) {
                *address = AllocateTail(p, size);
                *address += p->poolBase_;
                return 1;
            }
        }
    } while (++i < 5);
    return 0;
}
static inline u32 RoundSize(u32 size) {
    if (size == 0) return 16;
    return (size + 15) & ~15;
}
static inline u32 MakeKey(u32 address, u32 size, BOOL paired) {
    return ((size >> 4) << 16) | (0xFFFF & (address >> 3)) | (u32)paired << 31;
}
// Original: arm9/main @ 0x020BB588; symbol: func_020bb588; size: 0x170.
// Nintendo NNS frame texture allocator; third SDK option is unused.
extern "C" u32 NNS_GfdAllocFrmTexVram(u32 size, BOOL paired, u32 opt) {
#pragma unused(opt)
    u32 address;
    BOOL result;
    size = RoundSize(size);
    if (size >= 0x7fff0) return 0;
    if (paired) result = ReservePaired(size, &address);
    else result = ReserveOrdinary(size, &address);
    if (result) return MakeKey(address, size, paired);
    else return 0;
}
