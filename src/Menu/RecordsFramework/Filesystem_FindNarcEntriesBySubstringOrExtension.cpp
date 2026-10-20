#include <globaldefs.h>
ARM
extern "C" int _Z26FindFilesInNarcBySubstringPKvPKcPS0_Pjj(const void* narc, const char* substring, const void** out, unsigned* sizes, unsigned flag);
extern "C" int ResourceFile_CollectPayloadsByExtension(void* narc, const char* extension, unsigned* out, int capacity, unsigned* sizes, const char** names);
// Original: arm9/ov023 @ 0x021FAD20; symbol: Filesystem_FindNarcEntriesBySubstringOrExtension; size: 0x64.
// Wraps the NARC substring search and falls back to extension collection when no match is found; caller is an ov023 wrapper.
extern "C" int Filesystem_FindNarcEntriesBySubstringOrExtension(const void* narc, const char* substring, const void** out, unsigned* sizes) {
    if (_Z26FindFilesInNarcBySubstringPKvPKcPS0_Pjj(narc, substring, out, sizes, 1)) return 1;
    return ResourceFile_CollectPayloadsByExtension((void*)narc, substring, (unsigned*)out, 1, sizes, 0) != 0;
}
