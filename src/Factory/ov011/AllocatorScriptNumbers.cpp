#include "AllocatorScript.h"

int func_ov011_02184c30(Ov011ScriptArgument* argument)
{
    if (argument->type == 1) return (int)argument->value.real;
    return argument->value.integer;
}

float func_ov011_02184c4c(Ov011ScriptArgument* argument)
{
    if (argument->type == 0) return (float)argument->value.integer;
    return argument->value.real;
}
