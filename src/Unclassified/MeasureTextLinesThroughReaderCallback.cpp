#pragma optimize_for_size off
#pragma opt_propagation off
// Counts newline-separated lines produced by a character reader and scales by line pitch.
struct GlyphMetrics {
    char unk_0;
    signed char lineHeight;
};

struct TextCursor {
    unsigned long long counters;
    unsigned int text;
};

struct TextReader {
    GlyphMetrics* metrics;
    int (*readChar)(unsigned int* cursor);
};

// Original: arm9/main @ 0x020B0FAC; symbol: func_020b0fac; size: 0x74.
extern "C" int MeasureTextLinesThroughReaderCallback(TextReader* reader, int base, unsigned int text, unsigned int unused)
{
    int pitch;
    unsigned int* textCursor;
    int lines;
    TextCursor cursor;
    cursor.text = text;
    TextCursor* state = &cursor;
    state->counters = 0;
    int (*readChar)(unsigned int*) = reader->readChar;
    pitch = base;
    lines = 1;
    int c = readChar(&cursor.text);
    if (c != 0) {
    textCursor = &cursor.text;
    do {
        if (c == '\n')
            lines++;
        c = readChar(textCursor);
    } while (c != 0); }
    return lines * (pitch + reader->metrics->lineHeight) - pitch;
}
