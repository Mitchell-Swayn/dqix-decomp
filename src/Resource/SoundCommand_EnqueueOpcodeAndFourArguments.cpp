#include <globaldefs.h>

extern "C" int *SoundCommand_AllocateRecordWithOptionalWait(int);
extern "C" void SND_PushCommand(void);

// Original: arm9/main @ 0x020D217C; symbol: func_020d217c; size: 0x44.
extern "C" void SoundCommand_EnqueueOpcodeAndFourArguments(int a, int b, int c, int d, int e) {
    int *entry=SoundCommand_AllocateRecordWithOptionalWait(1);
    if (entry == 0) return;
    entry[1]=a; entry[2]=b; entry[3]=c; entry[4]=d; entry[5]=e;
    SND_PushCommand();
}
