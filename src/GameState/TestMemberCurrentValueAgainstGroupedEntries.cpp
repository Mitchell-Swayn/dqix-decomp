#include <globaldefs.h>
#include <GameState/GameState.h>

struct Kind
{
    unsigned low : 4;
    unsigned kind : 5;
    unsigned high : 23;
};

extern "C" char* GameState_GetObjectWithFlag100(GameState*, unsigned);
extern "C" char* GameObject_GetLinkedActionDataWhenEnabled(void*);
extern "C" short* Inventory_GetGroupItemIds(void*, int);
// Original data: arm9/main @ 0x20e8a34; symbol: data_020e8a34.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 204e1450384ab04f4c4f78504051844ee84e9c4adc50a451.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" short TestMemberCurrentValueAgainstGroupedEntries_UnknownRoleInitializedBytes[];

// Original: arm9/main @ 0x0207C984; symbol: func_0207c984; size: 0x110.
extern "C" ARM int TestMemberCurrentValueAgainstGroupedEntries(void* p, unsigned member, int group,
                                  short* output, short* size)
{
    char* state = GameState_GetObjectWithFlag100(GameState::GetInstance(), member);
    if (!state)
        return 1;

    char* item = GameObject_GetLinkedActionDataWhenEnabled(state);
    int current = -1;
    if (item && ((Kind*)(item + 8))->kind <= 11)
        current = *(short*)(item + 24);

    register short count = 0;
    short target = TestMemberCurrentValueAgainstGroupedEntries_UnknownRoleInitializedBytes[group];
    if (current > 0 && target == (short)(current - current % 100))
    {
        output[count] = current;
        ++count;
    }

    short* values = Inventory_GetGroupItemIds(p, 0);
    for (int i = 0; i < 272; i = (i + 1) * 0x10000 >> 16)
    {
        short value = values[i];
        if (value != current && target == (short)(value - value % 100))
        {
            output[count] = value;
            ++count;
        }
    }
    *size = count;
    return 0;
}
