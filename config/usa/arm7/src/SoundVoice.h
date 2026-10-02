#ifndef ARM7_SOUND_VOICE_H
#define ARM7_SOUND_VOICE_H

/* Runtime layouts recovered from ARM7 consumers. Unknown bytes retain offsets. */
typedef struct {
    unsigned char format, repeat;
    unsigned short unknown2, basePeriod, loopStart;
    unsigned int length;
} Waveform;

typedef struct {
    unsigned char unknown0, speed, depth, range;
    unsigned short delay, counter, phase;
} SoundModulation;

typedef struct SoundVoice SoundVoice;
struct SoundVoice {
    unsigned char channel, type, envelopeState;
    unsigned char active:1, pendingStart:1, advance:1, updates:5;
    unsigned char unknown4[12];
    int attenuation, elapsed, duration;            /* 0x10 */
    unsigned char attack, sustain;                /* 0x1c */
    unsigned short decay, release;
    unsigned char priority, pan;                 /* 0x22 */
    unsigned short volume, period;
    SoundModulation modulation;                  /* 0x28 */
    short sweep;                                 /* 0x32 */
    int startArgument;
    Waveform waveform;                           /* 0x38 */
    unsigned int source;                         /* 0x44 */
    void (*callback)(SoundVoice *, int, void *);
    void *userData;
    SoundVoice *next;                            /* 0x50 */
};

typedef char WaveformSizeCheck[sizeof(Waveform) == 0x0c ? 1 : -1];
typedef char SoundModulationSizeCheck[sizeof(SoundModulation) == 0x0a ? 1 : -1];
typedef char SoundVoiceSizeCheck[sizeof(SoundVoice) == 0x54 ? 1 : -1];

#endif
