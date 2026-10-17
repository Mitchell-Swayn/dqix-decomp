// Original: arm9/ov025 @ 0x021eb05c; symbol: func_ov025_021eb05c; size: 0x28.
extern "C" void AppendNonnegativeValueToBoundedHalfwordList(unsigned char* p,int v) { if(v<0)return;unsigned n=p[0x582];if(n<8){p[0x582]=n+1;*(short*)(p+0x584+n*2)=v;} }
