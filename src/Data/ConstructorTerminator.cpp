// Overlay 32 has no static constructors. The loader stops at this null entry.
#pragma define_section overlay32_ctor ".ctor" RW
typedef void (*Overlay32Constructor)();
__declspec(section "overlay32_ctor") Overlay32Constructor SharedData_UnknownRoleInitializedBytes_Variant47 = 0;
