#include <globaldefs.h>
ARM
extern "C" unsigned FindHalfwordValueByKeyOrReturnFullWidthSpace(unsigned,unsigned short*,int);
extern "C" unsigned short data_020e74ec[],data_020e74c8[],data_020e74bc[],data_020e743c[],data_020e752c[];
// Original: arm9/main @ 0x020328BC; symbol: func_020328bc; size: 0x568.
extern "C" void Text_ConvertUnicodeToShiftJis(char* output,const unsigned short* input,unsigned short count) {
while(*input && count--) {
unsigned ch=*input++;
int code;
if(ch==0xa5) code=0x5c;
else if(ch==0x5c) code=0x815f;
else if(ch==0x203e) code=0x7e;
else if(ch==13 || ch==10) code=ch;
else if(ch>=0x20 && ch<0x7e) code=ch;
else if(ch>=0xa2 && ch<=0xf7) code=FindHalfwordValueByKeyOrReturnFullWidthSpace(ch,data_020e74ec,0xab);
else if(ch>=0xff61 && ch<=0xff9f) code=(unsigned short)(ch-0xfec0);
else if(ch==0x4edd) code=0x8157;
else if(ch>=0xff01 && ch<=0xffe5) {
if(ch>=0xff10 && ch<=0xff19) code=(unsigned short)(ch-0x7cc1);
else if(ch>=0xff21 && ch<=0xff3a) code=(unsigned short)(ch-0x7cc1);
else if(ch>=0xff41 && ch<=0xff5a) code=(unsigned short)(ch-0x7cc0);
else code=FindHalfwordValueByKeyOrReturnFullWidthSpace(ch,data_020e74c8,0x54);
} else if(ch>=0x3000 && ch<=0x30fe) {
if(ch>=0x3041 && ch<=0x3093) code=(unsigned short)(ch+0x525e);
else if(ch>=0x30a1 && ch<=0x30f6) {
code=(unsigned short)(ch+0x529f);
if(ch>=0x30e0) code=(unsigned short)(code+1);
} else code=FindHalfwordValueByKeyOrReturnFullWidthSpace(ch,data_020e74bc,0x6c);
} else if(ch>=0x391 && ch<=0x3a9) {
code=(unsigned short)(ch+0x800e);
if(ch>=0x3a3) code=(unsigned short)(code-1);
} else if(ch>=0x3b1 && ch<=0x3c9) {
code=(unsigned short)(ch+0x800e);
if(ch>=0x3c3) code=(unsigned short)(code-1);
} else if(ch==0x401) code=0x8446;
else if(ch>=0x410 && ch<=0x42f) {
code=(unsigned short)(ch+0x8030);
if(ch>=0x416) code=(unsigned short)(code+1);
} else if(ch>=0x430 && ch<=0x44f) {
code=(unsigned short)(ch+0x8040);
if(ch>=0x436) {
code=(unsigned short)(code+1);
if(ch>=0x43e) code=(unsigned short)(code+1);
}
} else if(ch==0x451) code=0x8476;
else if(ch>=0x2500 && ch<=0x254b) code=FindHalfwordValueByKeyOrReturnFullWidthSpace(ch,data_020e743c,0x20);
else if((ch>=0x2010 && ch<=0x2312)||(ch>=0x25a0 && ch<=0x266f)) code=FindHalfwordValueByKeyOrReturnFullWidthSpace(ch,data_020e752c,0xa0);
else code=0x8140;
if(code&0xff00) *output++=code>>8;
*output++=code;
}
}
