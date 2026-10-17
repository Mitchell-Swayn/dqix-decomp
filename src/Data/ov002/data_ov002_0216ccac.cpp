#pragma define_section menu_overlay_ctor ".ctor" RW
// Overlay 2 has no constructors; the loader-visible list is one null entry.
typedef void (*OverlayConstructor)();
extern "C" __declspec(section "menu_overlay_ctor") OverlayConstructor data_ov002_0216ccac = 0;
