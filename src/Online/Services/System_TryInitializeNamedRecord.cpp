#include <globaldefs.h>
ARM
#include <std_library_functions.h>
extern "C" int Memory_AllocateAndInitializeGlobalRecord(void (*)(void), void (*)(void));
extern "C" int NasServiceLocator_StartRequest(const char *, void *);
extern "C" void OnlineMemory_AllocateAligned(void);
extern "C" void OnlineMemory_FreeTagged(void);
extern "C" void NasServiceLocator_DestroySession(void);
extern "C" unsigned char System_TryInitializeNamedRecord_Text0000;
// Original: arm9/ov031 @ 0x02212524; symbol: System_TryInitializeNamedRecord; size: 0x74.
// Ensures global callbacks are initialized, substitutes a default name for empty text, tries the named-record operation, and calls cleanup when it fails.
extern "C" int System_TryInitializeNamedRecord(const char *text, void *context) {
 if (!Memory_AllocateAndInitializeGlobalRecord(OnlineMemory_AllocateAligned, OnlineMemory_FreeTagged)) return 0;
 int result;
 if (strlen(text) == 0) result = NasServiceLocator_StartRequest((const char *)&System_TryInitializeNamedRecord_Text0000, context);
 else result = NasServiceLocator_StartRequest(text, context);
 if (result) return 1;
 NasServiceLocator_DestroySession();
 return 0;
}
