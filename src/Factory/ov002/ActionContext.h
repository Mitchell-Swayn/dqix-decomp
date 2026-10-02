#pragma once

#include "globaldefs.h"
#include "std_library_functions.h"

// Partial callback context. Field names describe observed use, not established
// gameplay semantics. The member count is supplied by the caller.
struct ActionResult {
    unsigned char status;
    unsigned char padding1;
    short value;
    unsigned char unavailable;
    unsigned char padding5;
};

struct ActionContext {
    short item;
    signed char owner;
    unsigned char count;
    signed char members[4];
    ActionResult results[4];
    ActionResult alternateResults[4];
};

typedef char ActionResultSizeCheck[sizeof(ActionResult) == 6 ? 1 : -1];
typedef char ActionResultsOffsetCheck[
    offsetof(ActionContext, results) == 8 ? 1 : -1];
typedef char AlternateActionResultsOffsetCheck[
    offsetof(ActionContext, alternateResults) == 0x20 ? 1 : -1];

// Dispatcher and item-record layouts remain unresolved. Dispatch at
// 0x021536ec supplies bank 0 for its first table and bank 1 for its second.
extern "C" int func_ov002_02153ea4(void* dispatcher, ActionContext* context,
                                  void* itemRecord, int alternate);
