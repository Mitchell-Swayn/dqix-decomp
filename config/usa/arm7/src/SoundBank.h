#ifndef ARM7_SOUND_BANK_H
#define ARM7_SOUND_BANK_H
#include "SoundVoice.h"

/* Variable-length entry table immediately follows this archive header. */
typedef struct {
    unsigned char unknown0[0x38];
    unsigned int count;
} SoundWaveArchive;
typedef char SoundWaveArchiveHeaderSizeCheck[sizeof(SoundWaveArchive) == 0x3c ? 1 : -1];
#endif
