#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"
// Original: arm9/main @ 0x02069120; symbol: func_02069120; size: 0x38.
extern "C" void AppendFirstPartyMemberFormattedText(void* unused, int* cursor)
{
    GameObject* member = GameState::GetInstance()->GetPartyMemberByIndex(0);
    if (member != NULL) {
        const char* format = *(const char* volatile*)((unsigned char*)member + 0x134);
        int length = sprintf((char*)*cursor, format);
        *cursor += length;
    }
}
