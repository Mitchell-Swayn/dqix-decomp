// Original: arm9/ov025 @ 0x021e8cf0; symbol: func_ov025_021e8cf0; size: 0x24.
extern "C" void* GetIndexedEntryPointerOrNull(void* p,int i) { if(i<0||i>=16)return 0;return (unsigned char*)p+0x1dc+i*4; }
