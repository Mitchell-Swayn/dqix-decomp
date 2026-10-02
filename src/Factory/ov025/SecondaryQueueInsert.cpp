#include "ActionQueues.h"

extern "C" void func_ov025_021ed5f0(Ov25ActionQueues* q, void* payload, int kind, unsigned char flags)
{
    if (kind >= 6) return;
    if (q->secondaryCount >= 16) return;
    q->secondaryPayloads[q->secondaryCount] = payload;
    q->secondaryKinds[q->secondaryCount] = kind;
    q->secondaryFlags[q->secondaryCount] = flags;
    ++q->secondaryCount;
}
