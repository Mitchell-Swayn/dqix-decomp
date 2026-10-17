// ARM range reviewed; all named globals checked against exact relocations.
struct Mode{int low:18;int value:3;int high:11;};extern "C" signed char data_020e8ebc[];extern "C" char data_02107850[];extern "C" unsigned int data_02101640[];
// Original: arm9/main @ 0x020489B0; symbol: func_020489b0; size: 0xC.
extern "C" void* Object_GetGlobalExtendedObjectState(){return data_02107850;}
