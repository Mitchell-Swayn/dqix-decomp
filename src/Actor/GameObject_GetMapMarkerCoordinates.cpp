// Original ARM fields and widths reviewed.
struct Flags{unsigned int value:12;unsigned int rest:20;};
// Original: arm9/main @ 0x02053F58; symbol: func_02053f58; size: 0x14.
extern "C" void GameObject_GetMapMarkerCoordinates(char* p,int* a,int* b){*a=*(int*)(p+0x1a8);*b=*(int*)(p+0x1ac);}
