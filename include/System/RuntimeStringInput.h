#pragma once

struct RuntimeStringInputState {
    const char* cursor;
    int endOfInput;
};
typedef int (*RuntimeReadCharacter)(RuntimeStringInputState*, int, int);
extern "C" int func_02003d58(RuntimeStringInputState*, int, int);
typedef char RuntimeStringInputStateSizeCheck[sizeof(RuntimeStringInputState) == 8 ? 1 : -1];
