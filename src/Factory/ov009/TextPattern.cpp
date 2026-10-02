#include "TextPattern.h"

extern "C" bool func_ov009_0218a888(void*, const unsigned char*, int, int);

extern "C" bool func_ov009_0218a518(TextPatternContext* context,
                                   const unsigned char* pattern,
                                   const unsigned char* text, int,
                                   int positions)
{
    unsigned int category = context->syntax[0];
    unsigned int setOpen = context->syntax[1];
    unsigned int setClose = context->syntax[2];
    unsigned int repeatOpen = context->syntax[3];
    unsigned int repeatClose = context->syntax[4];
    unsigned int any = context->syntax[7];

    for (int position = 0; position < positions; ++position, ++text) {
        const unsigned char* p = pattern;
        const unsigned char* t = text;
        while (true) {
            if (*p == 0)
                return true;
            unsigned int value = *t;
            // The original compiler shares storage for the temporary negation
            // flag and the later set length; this declaration order also keeps
            // the repetition bounds in their original registers.
            int length;
            int minimum = 1;
            int maximum = minimum;
            const unsigned char* bounds = p;
            if (*p == setOpen) {
                for (;;) {
                    if (*bounds == setClose) {
                        ++bounds;
                        break;
                    }
                    ++bounds;
                }
            } else {
                bounds = p + 1;
            }
            if (*bounds == repeatOpen) {
                // Decimal digits arrive as encoded byte values, with zero at 8.
                minimum = bounds[1] - 8;
                maximum = bounds[3] - 8;
                if (bounds[4] - 8 == 0)
                    maximum *= 10;
            }

            bool match = true;
            if (*p == any) {
                if (minimum == 0 && maximum == 60) {
                    unsigned int delimiter = p[7];
                    while (true) {
                        unsigned int next = *t;
                        if (next == 0 || next == 255)
                            return false;
                        if (delimiter == next)
                            break;
                        ++t;
                    }
                    p += 8;
                    ++t;
                    continue;
                }
            } else if (*p == category) {
                if (value < 0x12 || value > 0x2b)
                    match = false;
            } else if (*p == setOpen) {
                unsigned char set[8] = {};
                // Preserve the original fixed set buffer and marker processing.
                int range = 0;
                const unsigned char* source;
                unsigned char* destination;
                destination = set;
                source = p + 1;
                length = 0;
                unsigned int separator;
                unsigned int negation;
                unsigned int close;
                close = context->syntax[2];
                negation = context->syntax[5];
                separator = context->syntax[6];
                while (*source != close) {
                    unsigned int item = *source;
                    *destination = item;
                    if (item == negation)
                        length = 2;
                    if (item == separator)
                        range = 1;
                    ++source;
                    ++destination;
                }
                range += length;
                length = strlen((const char*)set);
                if (range == 0)
                    match = func_ov009_0218a888(context, set, length, value);
                else if (range == 1) {
                    unsigned int last = set[length - 1];
                    unsigned int first = set[0];
                    match = first <= value && value <= last;
                }
                else if (range == 2)
                    match = !func_ov009_0218a888(context, set + 1, length - 1, value);
                else if (range == 3) {
                    const unsigned char* positiveSet = set + 1;
                    unsigned int last = positiveSet[length - 2];
                    unsigned int first = set[1];
                    match = !(first <= value && value <= last);
                }
                p += length + 1;
            } else {
                if (*p != value)
                    match = false;
            }

            if (match) {
                for (int count = 0; count < minimum; ++count, ++t) {
                    if (value != *t) {
                        match = false;
                        break;
                    }
                }
                if (!match)
                    break;
                for (; minimum < maximum; ++minimum, ++t) {
                    if (value != *t)
                        break;
                }
            } else if (!match && minimum != 0) {
                break;
            }

            ++p;
            if (*p == repeatOpen) {
                for (;;) {
                    if (*p == repeatClose)
                        break;
                    ++p;
                }
                ++p;
            }
        }
    }
    return false;
}
