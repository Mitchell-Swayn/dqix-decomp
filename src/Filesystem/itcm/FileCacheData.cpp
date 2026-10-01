#include "Filesystem/NitroVM.h"

#if defined(usa)
// CacheMainFileAccessors stores one CRC and one NitroFS handle/file-ID pair
// for each of the 61 configured paths. All entries and the ready flag start zero.
bool data_01ffd998;
unsigned int data_01ffd99c[61];
NitroFileAccessor data_01ffda90[61];
#endif
