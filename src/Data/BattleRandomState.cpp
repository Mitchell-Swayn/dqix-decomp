#include "std_library_functions.h"
#include "Util/Random.h"

// POD BSS state returned by GetBTRandom. Existing release .init initializes it
// with CreateRandom(&data_02108ddc, "public", 1); this definition adds no constructor.
Random data_02108ddc;

typedef char RandomStateSize[sizeof(Random) == 32 ? 1 : -1];
typedef char RandomStateWordWidth[sizeof(unsigned long long) == 8 ? 1 : -1];
typedef char RandomStateNameOffset[offsetof(Random, name) == 0x18 ? 1 : -1];
typedef char RandomStateFlagOffset[offsetof(Random, unk_1C) == 0x1c ? 1 : -1];
