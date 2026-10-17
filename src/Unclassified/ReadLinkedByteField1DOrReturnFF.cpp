// ARM instruction evidence reviewed; opaque field offsets preserve observed layout.
// Original: arm9/main @ 0x020493C8; symbol: func_020493c8; size: 0x14.
extern "C" unsigned int ReadLinkedByteField1DOrReturnFF(char* p) {char* q=*(char**)(p+0x13c);if(q) return (unsigned char)q[0x1d];return 255;}
