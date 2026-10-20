#include <globaldefs.h>
ARM
struct VideoDecodeState {
    unsigned char* cursor;
    char prefix[0x3b0];
    unsigned decodedFrame;
};
struct AudioDecodeState {
    unsigned char* cursor;
    void* output;
    char storage[0x14f0];
};
struct ModsDecoder {
    char prefix[8];
    signed char signatureN, signatureVersion;
    char gap0[0x12];
    unsigned short audioFormat, channelCount;
    char gap1[0x14];
    VideoDecodeState* video;
    int (*decodeVideo)(VideoDecodeState*);
    char gap2[0x1c];
    AudioDecodeState* audio;
    char gap3[8];
    unsigned* frameTable;
    char gap4[0x34];
    unsigned consumedFrames, decodedFrames, initializeAudio, capacity;
    unsigned ringPositions[6];
    unsigned ringReadPosition;
    unsigned availableAudioBlocks, decodedAudioBlocks, channel;
};
extern "C" int ModsAudio_DecodePredictiveBlock(AudioDecodeState*);
extern "C" void func_ov016_021909cc_unk(AudioDecodeState*);
extern "C" void ModsAudio_InitializeAdpcmBlockState(int, int);
extern "C" void DecodeAdpcmBytePairs(int, unsigned char*, int, void*);
extern "C" void MIi_CpuCopy16(const void*, void*, unsigned);
// Original: arm9/ov016 @ 0x0218F340; symbol: func_ov016_0218f340; size: 0x1B0.
// Decodes one audio block using the stream format and advances its channel and cursor.
extern "C" int ModsDecoder_DecodeNextAudioBlock(ModsDecoder* decoder, void* output)
{
    if (decoder->decodedAudioBlocks == decoder->availableAudioBlocks) {
        return 0;
    }
    if (decoder->audioFormat == 0) {
        return 0;
    }
    if (decoder->audioFormat == 1) {
        decoder->audio[decoder->channel].cursor = decoder->video->cursor;
        decoder->audio[decoder->channel].output = output;
        int consumed = ModsAudio_DecodePredictiveBlock(&decoder->audio[decoder->channel]);
        decoder->video->cursor += consumed;
    } else if (decoder->audioFormat == 2) {
        decoder->audio[decoder->channel].cursor = decoder->video->cursor;
        decoder->audio[decoder->channel].output = output;
        func_ov016_021909cc_unk(&decoder->audio[decoder->channel]);
        decoder->video->cursor += 0x28;
    } else if (decoder->audioFormat == 3) {
        if (decoder->initializeAudio == 1) {
            ModsAudio_InitializeAdpcmBlockState(
                (int)&decoder->audio[decoder->channel], (int)decoder->video->cursor);
            decoder->video->cursor += 4;
        }
        DecodeAdpcmBytePairs((int)&decoder->audio[decoder->channel],
                            decoder->video->cursor, 0x80, output);
        decoder->video->cursor += 0x80;
    } else {
        MIi_CpuCopy16(decoder->video->cursor, output, 0x200);
        decoder->video->cursor += 0x200;
    }
    ++decoder->channel;
    if (decoder->channel == decoder->channelCount) {
        decoder->channel = 0;
        decoder->initializeAudio = 0;
    }
    ++decoder->decodedAudioBlocks;
    return 1;
}
