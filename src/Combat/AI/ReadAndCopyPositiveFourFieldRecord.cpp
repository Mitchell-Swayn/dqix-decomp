#include <globaldefs.h>
ARM
#include <std_library_functions.h>
extern "C" void __clear(void *, unsigned int);
extern "C" int Combat_CollectEligiblePartyIds(void *, void *, unsigned int, unsigned int);
// Original: arm9/ov024 @ 0x021F18A0; symbol: ReadAndCopyPositiveFourFieldRecord; size: 0x5C.
// Queries a four-field record into temporary storage; for a positive count, stores the length and copies eight bytes to output.
extern "C" int ReadAndCopyPositiveFourFieldRecord(void *object, void *unused1, void *unused2, int *lengthOut, const void *record) {
 unsigned char temp[8];
 __clear(temp, 8);
 int length = Combat_CollectEligiblePartyIds(*(void **)object, temp, 4, 1);
 if (length <= 0) return 0;
 *lengthOut = length;
 memcpy((void *)record, temp, 8);
 return 1;
}
