// Inclusive 24-unit hit rectangles for the same 4 by 4 grid.
// Original: arm9/ov005 @ 0x02155670; symbol: func_ov005_02155670; size: 0x74.
extern "C" int func_ov005_02155670(void* unused,int x,int y) { for(int i=0;i<16;++i) { int column=i%4; int row=i/4; int left=141+column*26; int top=52+row*26; int right=left+24; int bottom=top+24; if(x>=left && y>=top && x<=right && y<=bottom) return i+8; } return -1; }
