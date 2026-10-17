#include <globaldefs.h>
ARM
extern "C" {
void _Z24InvalidateDataCacheRangePKvj(const void*,unsigned);
void _Z15CleanCacheRangePKvj(const void*,unsigned);
void DisableInterruptsAndHaltForever();
void MIi_CpuClear16(int,void*,unsigned);
void MIi_CpuCopy16(const void*,volatile void*,int);
void VectorizedMemset(void*,int,unsigned);
void MI_CpuCopy8(const void*,void*,unsigned);
int ResetIPCOperationStateUnderIRQProtection();
void System_ClearSharedHalfword96BitZero();
extern char data_021142e0[],data_02114330[],data_02114344[],data_02114354[];
}
typedef void (*Callback)(void*);
#define MH(o) (*(unsigned short*)(message+(o)))
#define MW(o) (*(unsigned*)(message+(o)))
#define CH(o) (*(unsigned short*)(context+(o)))
#define CW(o) (*(unsigned*)(context+(o)))
#define GH(o) (*(unsigned short*)(data_021142e0+(o)))
#define GW(o) (*(unsigned*)(data_021142e0+(o)))
// Original: arm9/main @ 0x020D42E0; symbol: func_020d42e0; size: 0x3AC.
extern "C" void WirelessCommand_DispatchSharedResponseAndPortEvents(int channel,char* message,int error) {
char* context=*(char**)(data_021142e0+4);
if(error) return;
_Z24InvalidateDataCacheRangePKvj(*(void**)(context+16),256);
if(!CH(22)) _Z24InvalidateDataCacheRangePKvj(*(void**)(context+4),2048);
if(message!=*(char**)(context+16)) _Z24InvalidateDataCacheRangePKvj(message,256);
if(MH(0)>=44) {
if(MH(0)==128) {
if(MH(2)==19) DisableInterruptsAndHaltForever();
if(*(Callback*)(context+200)) (*(Callback*)(context+200))(message);
} else if(MH(0)==130) {
if(*(Callback*)(context+MH(6)*4+204)) {
MW(28)=*(unsigned*)(context+MH(6)*4+268);
MH(34)=CW(332);
_Z24InvalidateDataCacheRangePKvj(*(void**)(message+8),*(unsigned short*)(*(char**)(context+4)+114));
(*(Callback*)(context+MH(6)*4+204))(message);
}
} else if(MH(0)==129) {
MH(0)=15;
if(*(Callback*)(message+28)) (*(Callback*)(message+28))(message);
}
} else {
if(MH(0)==14 && (unsigned short)(MH(4)+0xfff5)<=1 && MH(2)==0) {
_Z24InvalidateDataCacheRangePKvj(*(void**)(message+8),*(unsigned short*)(*(char**)(context+4)+114));
}
if(MH(0)==2 && MH(2)==0) {
Callback callback=*(Callback*)(context+MH(0)*4+24);
ResetIPCOperationStateUnderIRQProtection();
if(callback) callback(message);
return;
}
if(*(Callback*)(context+MH(0)*4+24)) {
(*(Callback*)(context+MH(0)*4+24))(message);
if(!GH(0)) return;
}
if(MH(0)==8 || MH(0)==12) {
unsigned short event,aid,reason; char* gameInfo; unsigned short child,mode; char* mac; unsigned short parent;
if(MH(0)==8) {
mac=message+10;event=MH(8);aid=MH(16);reason=MH(18);gameInfo=message+20;mode=0;parent=MH(44);child=MH(46);
} else if(MH(0)==12) {
event=MH(8);mode=MH(10);reason=MH(12);aid=0;gameInfo=0;mac=message+16;parent=MH(22);child=MH(24);
}
if(event==7 || event==9 || event==26) {
if(event==7) CW(332)|=1<<aid;
else CW(332)&=~(1<<aid);
CH(336)=mode;
VectorizedMemset(data_02114330,0,68);
GH(80)=130;GH(82)=0;GH(84)=event;
GW(88)=0;GW(92)=0;GH(96)=0;GH(98)=aid;GH(112)=mode;GH(114)=CW(332);GH(106)=65535;GH(140)=reason;
MI_CpuCopy8(mac,data_02114344,6);
if(gameInfo) MIi_CpuCopy16(gameInfo,data_02114354,24);
else MIi_CpuClear16(0,data_02114354,24);
GH(144)=mode==0?parent:child;
GH(146)=mode==0?child:parent;
for(unsigned short i=0;i<16;i++) {
GH(86)=i;
if(*(Callback*)(context+i*4+204)) {
GW(108)=*(unsigned*)(context+i*4+268);
(*(Callback*)(context+i*4+204))(data_02114330);
}
}
}
}
}
_Z24InvalidateDataCacheRangePKvj(*(void**)(context+16),256);
System_ClearSharedHalfword96BitZero();
if(message!=*(char**)(context+16)) {
MH(0)|=32768;
_Z15CleanCacheRangePKvj(message,256);
}
}
