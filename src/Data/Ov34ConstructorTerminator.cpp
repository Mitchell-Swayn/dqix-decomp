// Null entry ending overlay 34's runtime constructor list.
// The preceding entry invokes __sinit_ov034_022a2a04.
typedef void (*OverlayConstructor)();
#pragma define_section overlay_ctor ".ctor" RW
extern "C" {
    __declspec(section "overlay_ctor") OverlayConstructor SharedData_UnknownRoleInitializedBytes_Variant49 = 0;
}
