#include "ActionQueues.h"
#include "std_library_functions.h"

extern "C" {
void func_ov025_021ed124(Ov25ActionQueues* q)
{
    q->activeId = 0;
    q->secondaryActiveId = 0;
    q->delay = 0;
    q->activePayload = 0;
    q->count = 0;
    q->secondaryCount = 0;
    memset(q->ids, 0, sizeof(q->ids));
    memset(q->parameters, 0, sizeof(q->parameters));
    memset(q->serials, 0, sizeof(q->serials));
    memset(q->kinds, 0, sizeof(q->kinds));
    memset(q->payloads, 0, sizeof(q->payloads));
    memset(q->auxiliary, 0, sizeof(q->auxiliary));
    memset(q->secondaryValues, 0, sizeof(q->secondaryValues));
    memset(q->secondaryKinds, 0, sizeof(q->secondaryKinds));
    q->nextSerial = 0;
    q->secondarySerial = 0;
    q->name[0] = 0;
    q->unknown1ac = 0;
    q->defaultDelay = 750;
    q->insertionIndex = 0;
}

void func_ov025_021ed1f0(Ov25ActionQueues* q)
{
    if (q->count == 0) return;
    --q->count;
    for (int i = 0; i < q->count; ++i) {
        q->ids[i] = q->ids[i + 1];
        q->parameters[i] = q->parameters[i + 1];
        q->kinds[i] = q->kinds[i + 1];
        q->payloads[i] = q->payloads[i + 1];
        q->serials[i] = q->serials[i + 1];
        q->auxiliary[i] = q->auxiliary[i + 1];
        q->flags[i] = q->flags[i + 1];
    }
    --q->insertionIndex;
    if (q->insertionIndex < 0) q->insertionIndex = 0;
}

void func_ov025_021ed2a0(Ov25ActionQueues* q)
{
    if (q->secondaryCount == 0) return;
    --q->secondaryCount;
    // The original routine shifts these two arrays only; flags stay in place.
    for (int i = 0; i < q->secondaryCount; ++i) {
        q->secondaryValues[i] = q->secondaryValues[i + 1];
        q->secondaryKinds[i] = q->secondaryKinds[i + 1];
    }
}

bool func_ov025_021ed2f4(Ov25ActionQueues* q)
{
    return q->count == 0 && q->activeId == 0;
}

void func_ov025_021ed314(Ov25ActionQueues* q, void* context) { q->context = context; }
void func_ov025_021ed31c(Ov25ActionQueues* q, void* context) { q->auxiliaryContext = context; }

void func_ov025_021ed324(Ov25ActionQueues* q, const char* name)
{
    if (!name) { q->name[0] = 0; return; }
    strcpy(q->name, name);
}

void func_ov025_021ed344(Ov25ActionQueues* q, short delay) { q->delay = delay; }
void func_ov025_021ed350(Ov25ActionQueues* q, int index, unsigned short flags) { q->flags[index] = flags; }

void func_ov025_021ed35c(Ov25ActionQueues* q)
{
    q->activeId = 0;
    q->count = 0;
    q->nextSerial = 0;
    q->secondarySerial = 0;
    q->secondaryCount = 0;
    q->insertionIndex = 0;
}

}
