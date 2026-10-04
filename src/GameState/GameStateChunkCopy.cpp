// Under the project-wide -inline noauto option, MWCC emits the implicit
// memberwise copy as a separate symbol. The original body embeds that copy.
#pragma always_inline on

struct GameStateChunkCopyWords3 {
    unsigned int words[3];
};

struct GameStateChunkCopyWords12 {
    unsigned int words[12];
};

// Neutral layout inferred only from the source and destination accesses.
// The implicit gaps at 0x0f and 0x6f are intentionally not fields.
struct GameStateChunkCopyLayout {
    unsigned short halfword_00;
    unsigned char byte_02;
    unsigned char byte_03;
    unsigned char byte_04;
    unsigned char byte_05;
    unsigned char byte_06;
    unsigned char byte_07;
    unsigned char byte_08;
    unsigned char byte_09;
    unsigned char byte_0a;
    signed char byte_0b;
    unsigned char byte_0c;
    unsigned char byte_0d;
    unsigned char byte_0e;
    GameStateChunkCopyWords3 aligned_10;
    short halfword_1c;
    short halfword_1e;
    unsigned int word_20;
    unsigned int word_24;
    unsigned int word_28;
    unsigned int word_2c;
    GameStateChunkCopyWords12 aligned_30;
    unsigned char byte_60;
    unsigned char byte_61;
    unsigned char byte_62;
    unsigned char byte_63;
    unsigned char byte_64;
    unsigned char byte_65;
    unsigned char byte_66;
    unsigned char byte_67;
    unsigned char byte_68;
    unsigned char byte_69;
    short halfword_6a;
    short halfword_6c;
    unsigned char byte_6e;
};

typedef char GameStateChunkCopyLayoutSizeCheck[
    sizeof(GameStateChunkCopyLayout) == 0x70 ? 1 : -1];

extern "C" void* func_0200fbb4(void* destination, const void* source)
{
    *(GameStateChunkCopyLayout*)destination =
        *(const GameStateChunkCopyLayout*)source;
    return destination;
}
