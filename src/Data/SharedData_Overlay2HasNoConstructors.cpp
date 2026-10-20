#pragma define_section menu_overlay_ctor ".ctor" RW
// Overlay 2 has no constructors; the loader-visible list is one null entry.
typedef void (*OverlayConstructor)();
// Original data: arm9/ov002 @ 0x216ccac; symbol: data_ov002_0216ccac.
// Overlay 2 has no constructors; the loader-visible list is one null entry.
// Initial values: hex 0000000000000000000000000000000000000000.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov002.md.
extern "C" __declspec(section "menu_overlay_ctor") OverlayConstructor SharedData_Overlay2HasNoConstructors = 0;
