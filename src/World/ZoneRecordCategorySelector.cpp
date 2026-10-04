#include "World/Zone3DEmbeddedState.h"

void SelectRecordCategoryMatcher(int alternate, unsigned int kind, int first, int second,
    signed char* minimum, signed char* maximum, signed char* subtype, ZoneRecordMatchFunction* output)
{
    *minimum = first;
    *maximum = -1;
    *subtype = second;
    *output = 0;
    if (alternate)
    {
        switch (kind)
        {
        case 0: *minimum = 0; *maximum = 7; break;
        case 1: *minimum = 0; break;
        case 2: *minimum = 1; *maximum = 6; break;
        case 3: *minimum = 7; break;
        }
    }
    else
    {
        switch (kind)
        {
        case 0: *minimum = 8; *maximum = 9; break;
        case 1: *minimum = 8; break;
        case 2: *minimum = 9; break;
        }
    }
    if (*minimum == -1)
    {
        if (*subtype == -1) *output = 0;
        else *output = MatchRecordSubtype;
    }
    else if (*subtype == -1)
    {
        if (*maximum == -1) *output = MatchRecordCategory;
        else *output = MatchRecordCategoryRange;
    }
    else *output = MatchRecordCategoryAndSubtype;
}
