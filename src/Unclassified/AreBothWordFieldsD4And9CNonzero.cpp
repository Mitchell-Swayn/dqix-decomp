// Original: arm9/main @ 0x0204C7E0; symbol: func_0204c7e0; size: 0x24.
extern "C" int AreBothWordFieldsD4And9CNonzero(char* p) { if(*(int*)(p+0xd4)==0) return 0; if(*(int*)(p+0x9c)) return 1; return 0; }
