#include "Filesystem/FSInnerDefs.h"

#if defined(usa)
typedef char CardReadManagerSizeCheck[sizeof(CardReadManager) == 0x620 ? 1 : -1];
// Separate translation units preserve the original ordering of BSS objects.
CardReadManager data_021118e0;
#endif
