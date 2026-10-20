#include <globaldefs.h>
ARM
struct CombatCommandPayload {
    unsigned short action, field02;
    short field04, actorIndex;
    unsigned char actorCount, targetCount, field0A, flags, field0C;
    unsigned char padding0D[3];
    void* actorHead;
    void* targetHead;
    unsigned short parameters[7];
};
#pragma force_active on
// Original: arm9/ov000 @ 0x0215F500; symbol: func_ov000_0215f500; size: 0x7c.
// Copies the initialized command fields and seven parameter halfwords, preserving padding.
extern "C" CombatCommandPayload* Combat_CopyCommandPayloadAndLinks(CombatCommandPayload* output, const CombatCommandPayload* input)
{
    output->action = input->action;
    output->field02 = input->field02;
    output->field04 = input->field04;
    output->actorIndex = input->actorIndex;
    output->actorCount = input->actorCount;
    output->targetCount = input->targetCount;
    output->field0A = input->field0A;
    output->flags = input->flags;
    output->field0C = input->field0C;
    output->actorHead = input->actorHead;
    output->targetHead = input->targetHead;
    struct Parameters { unsigned short values[7]; };
    *(Parameters*)output->parameters = *(const Parameters*)input->parameters;
    return output;
}
#pragma force_active off
