extern "C" char* strncpy(char*,const char*,unsigned int); struct Buffer { char pad[0x4ac]; char names[16][64]; };
// Original: arm9/main @ 0x02046574; symbol: func_02046574; size: 0x4C.
 extern "C" void TextContext_SetStringArgument(Buffer* p,int i,const char* s) { if(!s) return; if(i<0) return; if(i>=16) return; strncpy(p->names[i],s,63); p->names[i][63]=0; }
