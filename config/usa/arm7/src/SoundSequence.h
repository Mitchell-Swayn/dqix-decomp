#ifndef ARM7_SOUND_SEQUENCE_H
#define ARM7_SOUND_SEQUENCE_H

#include "SoundVoice.h"

/* Only consumer-proven fields are named; remaining bytes retain offsets. */
typedef struct {
    unsigned char active:1, running:1, paused:1, unknownFlags:5;
    unsigned char index;
    unsigned char unknown2[6];
    unsigned char trackIds[16];
    unsigned char unknown18[8];
    unsigned int argument;                       /* 0x20 */
} SoundSequence;

typedef struct {
    unsigned char active:1, unknownFlag1:1, muted:1, unknownFlag3:1,
        unknownFlag4:1, unknownFlag5:1, unknownFlag6:1, parameter1EChanged:1;
    unsigned char unknown1;
    unsigned short unknown2;
    unsigned char unknown4, unknown5, unknown6, unknown7, unknown8, unknown9;
    unsigned short unknownA, unknownC;
    unsigned char unknownE, unknownF, unknown10, unknown11, unknown12, unknown13,
        unknown14, unknown15;
    unsigned short unknown16;
    SoundModulationParameters modulation;        /* 0x18 */
    unsigned short parameter1E;
    unsigned int unknown20;
    const unsigned char *start, *cursor; /* 0x24, 0x28 */
    unsigned char unknown2C[15];
    unsigned char unknown3B;
    SoundVoice *voices;                         /* 0x3c */
} SoundTrack;

typedef struct {
    unsigned int unknown0;
    const unsigned char *start, *end;
    unsigned int words[4];
} SoundReadCache;

typedef struct { short variables[16]; unsigned int ticks; } SoundSharedSequence;
typedef struct {
    unsigned int unknown0, activeSequences;
    unsigned char unknown8[24];
    SoundSharedSequence sequences[16];
    /* Global variables follow this prefix; their count is not yet established. */
} SoundSharedWork;

typedef char SoundSharedSequenceSizeCheck[sizeof(SoundSharedSequence) == 0x24 ? 1 : -1];
typedef char SoundSharedWorkPrefixCheck[sizeof(SoundSharedWork) == 0x260 ? 1 : -1];
typedef char SoundSequenceSizeCheck[sizeof(SoundSequence) == 0x24 ? 1 : -1];
typedef char SoundTrackSizeCheck[sizeof(SoundTrack) == 0x40 ? 1 : -1];
typedef char SoundReadCacheSizeCheck[sizeof(SoundReadCache) == 0x1c ? 1 : -1];
#endif
