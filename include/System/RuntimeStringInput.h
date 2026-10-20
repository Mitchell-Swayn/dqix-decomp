#pragma once

struct RuntimeStringInputState {
    const char* cursor;
    int endOfInput;
};
typedef int (*RuntimeReadCharacter)(RuntimeStringInputState*, int, int);
extern "C" int RuntimeStringInput_ReadUnreadOrTestEnd(RuntimeStringInputState*, int, int);
typedef char RuntimeStringInputStateSizeCheck[sizeof(RuntimeStringInputState) == 8 ? 1 : -1];
