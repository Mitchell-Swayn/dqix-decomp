#ifndef ARM7_SOUND_SEQUENCE_H
#define ARM7_SOUND_SEQUENCE_H

#include "SoundVoice.h"

/* Only consumer-proven fields are named; remaining bytes retain offsets. */
typedef struct {
    unsigned char active:1, running:1, paused:1, unknownFlags:5;
    unsigned char index;
    unsigned char unknown2[6];
    unsigned char trackIds[16];
    unsigned char unknown18[12];
} SoundSequence;

typedef struct {
    unsigned char active:1, unknownFlags:7;
    unsigned char unknown1[35];
    const unsigned char *start, *cursor; /* 0x24, 0x28 */
    unsigned char unknown2C[16];
    SoundVoice *voices;                         /* 0x3c */
} SoundTrack;

typedef struct {
    unsigned int unknown0;
    const unsigned char *start, *end;
    unsigned int words[4];
} SoundReadCache;

typedef char SoundSequenceSizeCheck[sizeof(SoundSequence) == 0x24 ? 1 : -1];
typedef char SoundTrackSizeCheck[sizeof(SoundTrack) == 0x40 ? 1 : -1];
typedef char SoundReadCacheSizeCheck[sizeof(SoundReadCache) == 0x1c ? 1 : -1];
#endif
