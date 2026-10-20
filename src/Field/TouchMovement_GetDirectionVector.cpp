// Original integer/short access widths and branch control flow reviewed; deferred candidate revision.
// Original: arm9/main @ 0x020968A4; symbol: func_020968a4; size: 0x20.
extern "C" void TouchMovement_GetDirectionVector(char* p,int* out){p+=0x200;out[0]=*(short*)(p+40);out[1]=*(short*)(p+42);out[2]=*(short*)(p+44);}
