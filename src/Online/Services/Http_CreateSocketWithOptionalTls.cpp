#include <globaldefs.h>
ARM
extern "C" int Network_CreateSocketByType(int,int,int);
extern "C" void SeedRandomStateFromLowEntropy();
extern "C" void Http_ClearCertificateVerificationFlag();
extern "C" int Network_ValidateAndAttachSslContext(int,void*);
extern "C" void NetworkSocket_Close(int);
// Original: arm9/ov031 @ 0x02241338; symbol: AllocateAndConfigureCallbackSlot; size: 0x80.
extern "C" int Http_CreateSocketWithOptionalTls(char *self) {
 int slot=Network_CreateSocketByType(2,1,0);
 if(slot>=0 && *(int*)(self+8)) {
 SeedRandomStateFromLowEntropy();
 *(int*)(*(char**)(self+32)+0x814)=*(int*)(self+28);
 *(int*)(*(char**)(self+32)+0x818)=*(int*)(self+24);
 *(void(**)())(*(char**)(self+32)+0x810)=Http_ClearCertificateVerificationFlag;
 if(Network_ValidateAndAttachSslContext(slot,*(void**)(self+32))<0) {NetworkSocket_Close(slot);slot=-1;}
 }return slot;
}
