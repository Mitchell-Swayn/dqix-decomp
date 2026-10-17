#include <globaldefs.h>
extern "C" void* ReadWordAtOffset0();
extern "C" unsigned ReadZoneFloorOrActiveGrottoBossFloor(void*);
extern "C" void SetNestedSecondWordForTypeThree(unsigned,unsigned);
// Original: arm9/main @ 0x0209D658; symbol: func_0209d658; size: 0x30.
extern "C" int WriteResolvedStateValueThroughOutputParameter(unsigned value) { void* p=ReadWordAtOffset0(); if (!p) return 0; SetNestedSecondWordForTypeThree(value,ReadZoneFloorOrActiveGrottoBossFloor(p));return 1; }
