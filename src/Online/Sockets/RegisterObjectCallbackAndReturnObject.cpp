#include <globaldefs.h>
ARM
extern "C" void *Network_AllocateSocketStorage(void);
extern "C" char *Network_AllocateSocketCommand(unsigned int, void *, unsigned int);
extern "C" int ForwardGlobalPrimaryPointerAndSecondArgument(void *, char *);
extern "C" int Network_InitializeSocketProtocol(void *);
// Original: arm9/ov031 @ 0x02205364; symbol: RegisterObjectCallbackAndReturnObject; size: 0x3C.
// Returns sentinel -0x31 when no object exists; otherwise registers a callback/query record, applies the result to the object, and returns it.
extern "C" void *RegisterObjectCallbackAndReturnObject(void) {
 void *object = Network_AllocateSocketStorage();
 if (!object) return (void *)-0x31;
 char *result = Network_AllocateSocketCommand((unsigned int)&Network_InitializeSocketProtocol, object, 1);
 ForwardGlobalPrimaryPointerAndSecondArgument(object, result);
 return object;
}
