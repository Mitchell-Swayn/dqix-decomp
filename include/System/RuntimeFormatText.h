#pragma once

struct RuntimeFormatText {
    char hexZero[8];
    char negativeInfinityUpper[8];
    char negativeInfinityLower[8];
    char infinityUpper[4];
    char infinityLower[4];
    char negativeNanUpper[8];
    char negativeNanLower[8];
    char nanUpper[4];
    char nanLower[4];
    unsigned short emptyWide[2];
    char emptyNarrow[4];
};

extern RuntimeFormatText data_020eeef0;
typedef char RuntimeFormatTextSizeCheck[sizeof(RuntimeFormatText) == 64 ? 1 : -1];
