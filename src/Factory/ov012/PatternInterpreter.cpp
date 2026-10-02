#include "PatternState.h"

extern "C" unsigned int strlen(const char*);
extern "C" int func_ov012_021859f4(PatternState*, const unsigned char*, int, int);

// Pattern bytes use the game's character encoding. Repetition digits are
// represented by codes 8..17; delimiter codes come from PatternInit.
// Local declaration and initialization order preserves MWCC's allocation.
extern "C" int func_ov012_02185684(PatternState* state,
    const unsigned char* pattern, const unsigned char* input,
    unsigned int, int positions)
{
    unsigned int colon = state->delimiters[0];
    unsigned int setOpen = state->delimiters[1];
    unsigned int setClose = state->delimiters[2];
    unsigned int repeatOpen = state->delimiters[3];
    unsigned int repeatClose = state->delimiters[4];
    unsigned int wildcard = state->delimiters[7];
    for (int position = 0; position < positions; ++position, ++input) {
        const unsigned char* atom = pattern;
        const unsigned char* cursor = input;
        for (;;) {
            const unsigned char* suffix;
            unsigned int token = *atom;
            if (token == 0) return 1;
            unsigned int value = *cursor;
            int count;
            int minimum = 1;
            int maximum = minimum;
            suffix = atom;
            if (token == setOpen) {
                for (;;) {
                    if (*suffix == setClose) {
                        ++suffix;
                        break;
                    }
                    ++suffix;
                }
            } else {
                suffix = atom + 1;
            }
            if (*suffix == repeatOpen) {
                minimum = suffix[1] - 8;
                maximum = suffix[3] - 8;
                if (suffix[4] - 8 == 0) maximum *= 10;
            }
            int matched = 1;
            if (token == wildcard) {
                if (minimum == 0 && maximum == 60) {
                    int terminator = atom[7];
                    for (;;) {
                        int next = *cursor;
                        if (next == 0 || next == 255) return 0;
                        if (terminator == next) break;
                        ++cursor;
                    }
                    atom += 8;
                    ++cursor;
                    continue;
                }
            } else if (token == colon) {
                if (value < 0x12 || value > 0x2b) matched = 0;
            } else if (token == setOpen) {
                unsigned char members[8] = {};
                int range = 0;
                const unsigned char* source;
                unsigned char* output = members;
                source = atom + 1;
                // This scratch value first contributes the inversion bit,
                // then holds the set length once the member scan is finished.
                count = range;
                unsigned int dash;
                unsigned int inversion;
                unsigned int close = state->delimiters[2];
                inversion = state->delimiters[5];
                dash = state->delimiters[6];
                while (*source != close) {
                    unsigned int member = *source;
                    *output = member;
                    if (member == inversion) count = 2;
                    if (member == dash) range = 1;
                    ++source;
                    ++output;
                }
                range += count;
                count = strlen((const char*)members);
                if (range == 0) {
                    matched = func_ov012_021859f4(state, members, count, value);
                } else if (range == 1) {
                    unsigned int upper = members[count - 1];
                    unsigned int lower = members[0];
                    matched = lower <= value && value <= upper;
                } else if (range == 2) {
                    matched = !func_ov012_021859f4(state, members + 1, count - 1, value);
                } else if (range == 3) {
                    unsigned char* span = members + 1;
                    unsigned int upper = span[count - 2];
                    unsigned int lower = members[1];
                    matched = !(lower <= value && value <= upper);
                }
                atom += count + 1;
            } else {
                if (token != value) matched = 0;
            }
            if (matched) {
                for (int consumed = 0; consumed < minimum; ++consumed, ++cursor) {
                    if (value != *cursor) {
                        matched = 0;
                        break;
                    }
                }
                if (!matched) break;
                for (; minimum < maximum; ++minimum, ++cursor) {
                    if (value != *cursor) break;
                }
            } else if (!matched && minimum != 0) {
                break;
            }
            ++atom;
            if (*atom == repeatOpen) {
                for (;;) {
                    if (*atom == repeatClose) break;
                    ++atom;
                }
                ++atom;
            }
        }
    }
    return 0;
}
