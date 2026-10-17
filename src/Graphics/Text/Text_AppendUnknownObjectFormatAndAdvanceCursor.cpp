#include <globaldefs.h>
ARM
#pragma opt_dead_assignments off
#pragma optimize_for_size off
#pragma opt_common_subs off
#include <GameState/GameState.h>

struct FormatHolder
{
    char reserved[0x134];
    const char* format;
};

extern "C"
{
    int sprintf(char* destination, const char* format, ...);

// Original: arm9/main @ 0x02069158; symbol: func_02069158; size: 0x34.
    void Text_AppendUnknownObjectFormatAndAdvanceCursor(void* unused, char** cursor)
    {
        FormatHolder* holder = (FormatHolder*)GameState::GetInstance()->GetUnknownGameObject();
        if (holder == 0)
            return;
        const char* format = holder->format;
        char* output = *cursor;
        int count = sprintf(output, format);
        *cursor += count;
    }
}
