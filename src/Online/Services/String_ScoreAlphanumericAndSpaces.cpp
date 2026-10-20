#include <globaldefs.h>
ARM

// Original: arm9/ov031 @ 0x02242B5C; symbol: func_ov031_02242b5c; size: 0x68.
extern "C" int String_ScoreAlphanumericAndSpaces(const signed char *text) {
    int score = 0;
    int character = *text++;
    if (character != 0) {
        do {
            if ((character >= '0' && character <= '9') ||
                (character >= 'A' && character <= 'Z') ||
                (character >= 'a' && character <= 'z') || character == ' ') {
                score++;
            } else {
                score += 3;
            }
            character = *text++;
        } while (character != 0);
    }
    return score;
}
