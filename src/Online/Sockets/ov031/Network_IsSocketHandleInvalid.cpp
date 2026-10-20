#include <globaldefs.h>
ARM
extern "C" void **FindLinkFieldForNode(void **, void *);
extern "C" char *NetworkRegisterActiveSocket_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x02207180; symbol: Network_IsSocketHandleInvalid; size: 0x34.
// Reports nonpositive inputs or nodes absent from the global context list.
extern "C" int Network_IsSocketHandleInvalid(int value) {
 if(value <= 0 || !FindLinkFieldForNode((void **)&NetworkRegisterActiveSocket_UnknownRoleZeroInitializedStorage,(void *)value)) return 1;
 return 0;
}
