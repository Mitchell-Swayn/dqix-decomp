#include "World/Zone3DEmbeddedState.h"

// 999 skips that component; skipping both produces no matcher.
void SelectRecordAttributeMatcher(int first, int second, ZoneRecordMatchFunction* output)
{
    if (first == 999)
    {
        if (second == 999) *output = 0;
        else *output = MatchRecordSecondAttribute;
    }
    else
    {
        if (second == 999) *output = MatchRecordFirstAttribute;
        else *output = MatchRecordBothAttributes;
    }
}
