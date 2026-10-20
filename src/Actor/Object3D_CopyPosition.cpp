// ARM instruction evidence reviewed; opaque field offsets preserve observed layout.
// Original: arm9/main @ 0x02059F38; symbol: func_02059f38; size: 0x1C.
extern "C" void Object3D_CopyPosition(char* p,int* q) {*(int*)(p+0x44)=q[0];*(int*)(p+0x48)=q[1];*(int*)(p+0x4c)=q[2];}
