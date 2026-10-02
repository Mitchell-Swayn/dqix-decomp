#include "ActionQueues.h"

// Insertions return the assigned serial, or -1 for a rejected entry.
// The insertion point is maintained separately by the queue's processing owner.
extern "C" {
int func_ov025_021ed380(Ov25ActionQueues* q, unsigned short id, short parameter,
                       int kind, void* payload, short auxiliary, unsigned short flags)
{
    if (kind >= 6) return -1;
    int serial = -1;
    if (id != 0 && q->count < 16) {
        q->ids[q->count] = id;
        q->parameters[q->count] = parameter;
        q->kinds[q->count] = kind;
        q->payloads[q->count] = payload;
        if (q->nextSerial == 32767) q->nextSerial = 0;
        ++q->nextSerial;
        serial = q->nextSerial;
        q->serials[q->count] = serial;
        q->auxiliary[q->count] = auxiliary;
        q->flags[q->count] = flags;
        ++q->count;
    }
    return serial;
}

int func_ov025_021ed444(Ov25ActionQueues* q, unsigned short id, short parameter,
                       int kind, void* payload, short auxiliary, unsigned short flags)
{
    if (kind >= 6) return -1;
    int serial = -1;
    if (id != 0 && q->count < 16) {
        int index = q->insertionIndex;
        for (int i = q->count - 1; i >= index; --i) {
            q->ids[i + 1] = q->ids[i];
            q->parameters[i + 1] = q->parameters[i];
            q->kinds[i + 1] = q->kinds[i];
            q->payloads[i + 1] = q->payloads[i];
            q->serials[i + 1] = q->serials[i];
            q->auxiliary[i + 1] = q->auxiliary[i];
            q->flags[i + 1] = q->flags[i];
        }
        q->ids[index] = id;
        q->parameters[index] = parameter;
        q->kinds[index] = kind;
        q->payloads[index] = payload;
        if (q->nextSerial == 32767) q->nextSerial = 0;
        ++q->nextSerial;
        serial = q->nextSerial;
        q->serials[index] = serial;
        q->auxiliary[index] = auxiliary;
        q->flags[index] = flags;
        ++q->count;
    }
    return serial;
}

short func_ov025_021ed564(Ov25ActionQueues* q, int id, int parameter,
                         int kind, void* payload, int auxiliary)
{
    if (kind >= 6) return -1;
    if (id == 0) return -1;
    // Match all identifying fields; flags and assigned serial are not search keys.
    unsigned short* currentId = q->ids;
    for (int i = 0; i < q->count; ++i, ++currentId) {
        if (*currentId == id && q->parameters[i] == parameter &&
            q->payloads[i] == payload && q->auxiliary[i] == auxiliary &&
            q->kinds[i] == kind) return i;
    }
    return -1;
}
}
