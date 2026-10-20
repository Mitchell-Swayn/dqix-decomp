#include <globaldefs.h>
ARM
#pragma optimize_for_size off
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
// Original: arm9/ov016 @ 0x0218F088; symbol: func_ov016_0218f088; size: 0xE4.
// Decodes the next frame, advances its encoded cursor and updates the six ring positions.
extern "C" int ModsDecoder_DecodeVideoFrame(ModsDecoder* decoder)
{
    if (decoder->consumedFrames > decoder->decodedFrames) {
        return 0;
    }
    int headerBytes;
    if (*(unsigned short*)decoder->video->cursor & 0x8000) {
        decoder->initializeAudio = 1;
        headerBytes = 4;
    } else {
        decoder->initializeAudio = 0;
        headerBytes = 0;
    }
    int consumed = decoder->decodeVideo(decoder->video);
    decoder->video->cursor += consumed;
    if (decoder->signatureN == 'N' && decoder->signatureVersion == '3') {
        decoder->video->cursor += headerBytes;
    }
    decoder->frameTable[decoder->ringPositions[0]] = decoder->video->decodedFrame;
    decoder->decodedAudioBlocks = 0;
    decoder->channel = 0;
    int i = 0;
    do {
        struct RingPositionView {char prefix[0xac];unsigned value;};
        RingPositionView* position = (RingPositionView*)((char*)decoder + i * 4);
        unsigned next = position->value + 1;
        position->value = next;
        if (decoder->capacity == next) {
            position->value = 0;
        }
        ++i;
    } while (i < 6);
    ++decoder->decodedFrames;
    return 1;
}
