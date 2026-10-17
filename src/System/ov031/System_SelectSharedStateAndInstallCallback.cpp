#include <globaldefs.h>
ARM
struct Fields { unsigned long long identifier,other; unsigned short c,d; };
extern "C" void DecodePackedGlobalIdentifierFields(Fields*);
extern "C" int ReadSharedSignedByteAtOffset22();
extern "C" void SetSharedByteAtOffset16(signed char);
extern "C" void SetMainLoopCallback(void(*)());
extern "C" void Unclassified_DispatchGlobalIndexedByteToHandler();
extern "C" void System_ResolveGlobalGroupEntry(int);
extern "C" void SetSharedByteAndScheduleCallback();
extern "C" unsigned char data_ov031_02290c5c[];
// Original: arm9/ov031 @ 0x02229484; symbol: func_ov031_02229484; size: 0xA4.
extern "C" void System_SelectSharedStateAndInstallCallback() {
switch(ReadSharedSignedByteAtOffset22()){
case 0:System_ResolveGlobalGroupEntry(7);break;
case 1:{Fields fields;DecodePackedGlobalIdentifierFields(&fields);
if(data_ov031_02290c5c[0] && fields.identifier==0){System_ResolveGlobalGroupEntry(9);SetSharedByteAtOffset16(-1);return;}
System_ResolveGlobalGroupEntry(6);Unclassified_DispatchGlobalIndexedByteToHandler();data_ov031_02290c5c[1]=1;break;}
default:return;
}
SetMainLoopCallback(SetSharedByteAndScheduleCallback);
}
