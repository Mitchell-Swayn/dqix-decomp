#include <globaldefs.h>

#pragma define_section empty_overlay_ctor ".ctor" RW

// Overlay 7 has no constructors. Its loader-visible list ends with this null entry.
typedef void (*OverlayConstructor)();
__declspec(section "empty_overlay_ctor") OverlayConstructor SharedData_UnknownRoleInitializedBytes_Variant6 = 0;
