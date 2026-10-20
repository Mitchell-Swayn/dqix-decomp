// Reviewed original ARM field widths and branch behavior. Hardware addresses are original MMIO literals.
extern "C" void func_02047230(void*);struct HalfCounter{unsigned low:16;unsigned high:16;};struct LowCounter{unsigned low:24;unsigned high:8;};
// Original: arm9/main @ 0x02044974; symbol: func_02044974; size: 0x30.
extern "C" void TextStream_AppendLittleEndianControlToken(unsigned char** p,unsigned v){v=(unsigned short)v;*(*p)++=v;*(*p)++=(int)v>>8;}
