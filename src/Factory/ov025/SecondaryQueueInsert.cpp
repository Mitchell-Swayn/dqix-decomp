#include "ActionQueues.h"

extern "C" void func_ov025_021ed5f0(Ov25ActionQueues* q, int value, int kind, unsigned char flags)
{
    if (kind >= 6) return;
    if (q->secondaryCount >= 16) return;
    q->secondaryValues[q->secondaryCount] = value;
    q->secondaryKinds[q->secondaryCount] = kind;
    q->secondaryFlags[q->secondaryCount] = flags;
    ++q->secondaryCount;
}
