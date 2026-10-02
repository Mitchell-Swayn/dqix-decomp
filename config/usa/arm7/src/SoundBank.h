#ifndef ARM7_SOUND_BANK_H
#define ARM7_SOUND_BANK_H
#include "SoundVoice.h"

/* Variable-length entry table immediately follows this archive header. */
typedef struct {
    unsigned char unknown0[0x38];
    unsigned int count;
} SoundWaveArchive;
typedef struct { SoundWaveArchive *archive; unsigned int unknown4; } SoundWaveArchiveLink;
typedef struct {
    unsigned char unknown0[0x18];
    SoundWaveArchiveLink waveArchives[4];
    unsigned int count;
} SoundBank;
typedef struct {
    unsigned short parameter0, parameter1;
    unsigned char baseKey, attack, decay, sustain, release, pan;
} SoundInstrumentParameters;
typedef struct {
    unsigned char type, unknown1;
    SoundInstrumentParameters parameters;
} SoundInstrument;
typedef char SoundInstrumentParametersSizeCheck[sizeof(SoundInstrumentParameters) == 10 ? 1 : -1];
typedef char SoundInstrumentSizeCheck[sizeof(SoundInstrument) == 12 ? 1 : -1];
typedef char SoundBankHeaderSizeCheck[sizeof(SoundBank) == 0x3c ? 1 : -1];
typedef char SoundWaveArchiveHeaderSizeCheck[sizeof(SoundWaveArchive) == 0x3c ? 1 : -1];
#endif
