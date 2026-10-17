#include <globaldefs.h>
extern "C" void ClearMatchingAssociationUnderIRQProtection(void*,unsigned,unsigned);extern "C" void SoundCommand_SubmitOpcodeThirty(void*,void*);
// Original: arm9/main @ 0x020BE44C; symbol: func_020be44c; size: 0x28.
extern "C" void InitializeObjectAndDispatchRelativeDataPointer(char* self,unsigned offset,unsigned a,unsigned b) {ClearMatchingAssociationUnderIRQProtection(self,a,b);SoundCommand_SubmitOpcodeThirty(self,self+offset);}
