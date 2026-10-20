// Original BSS: arm9/main @ 0x021127E0; symbol: data_021127e0; size: 0x280.
// SoundCommand_InitializeSharedDriverStatus (0x020D2A48) clears the status
// header, initializes 16 sequence records with 16 variables and one tick word
// each, initializes 16 global variables, and maintains exactly 640 cache bytes.
// ARM7 SoundSequence.h, SoundSequenceVariable.c, SoundSequenceAdvance.c,
// SoundSequenceStop.c and SoundSharedStatus.c independently establish the
// sequence variable/tick layout and the three active-state masks below.
struct SoundSharedSequenceStatus {
    short variables[16];
    unsigned ticks;
};
struct SoundSharedStatusHeader {
    unsigned unknownWord0; // Cleared by ARM9; no stronger field role is proven.
    unsigned activeSequences;
    unsigned short activeChannels;
    unsigned short activeCaptures;
    // These bytes form the remainder of the 32-byte header. Their contents are
    // not initialized by the recorded initializer; no additional role is assumed.
    unsigned char uninterpretedHeaderBytes[20];
};
struct SoundDriverSharedStatus {
    SoundSharedStatusHeader header; // 0x000..0x01F
    SoundSharedSequenceStatus sequences[16]; // 0x020..0x25F
    short globalVariables[16]; // 0x260..0x27F
};
typedef char SoundSharedHeaderSizeCheck[sizeof(SoundSharedStatusHeader) == 32 ? 1 : -1];
typedef char SoundSharedSequenceSizeCheck[sizeof(SoundSharedSequenceStatus) == 36 ? 1 : -1];
typedef char SoundDriverSharedStatusSizeCheck[sizeof(SoundDriverSharedStatus) == 640 ? 1 : -1];
// Retain the existing external linker identity; a semantic symbol rename is
// separate work. This POD definition reserves BSS and emits no initializer.
extern "C" {
SoundDriverSharedStatus SoundCommandInitializePoolAndSharedStatus_UnknownRoleZeroInitializedStorage;
}
