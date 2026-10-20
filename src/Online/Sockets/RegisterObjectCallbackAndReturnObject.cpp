#include <globaldefs.h>
ARM
extern "C" void *Network_AllocateSocketStorage(void);
extern "C" unsigned int Network_AllocateSocketCommand(void (*)(void), void *, int);
extern "C" void ForwardGlobalPrimaryPointerAndSecondArgument(void *, unsigned int);
extern "C" void Network_InitializeSocketProtocol(void);
// Original: arm9/ov031 @ 0x02205364; symbol: RegisterObjectCallbackAndReturnObject; size: 0x3C.
// Returns sentinel -0x31 when no object exists; otherwise registers a callback/query record, applies the result to the object, and returns it.
extern "C" void *RegisterObjectCallbackAndReturnObject(void) {
 void *object = Network_AllocateSocketStorage();
 if (!object) return (void *)-0x31;
 unsigned int result = Network_AllocateSocketCommand(Network_InitializeSocketProtocol, object, 1);
 ForwardGlobalPrimaryPointerAndSecondArgument(object, result);
 return object;
}
