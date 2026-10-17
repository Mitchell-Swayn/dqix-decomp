#include <globaldefs.h>
#pragma optimize_for_size off

extern "C" void InitializeFourWordsWithInvalidIndex(int);

// Original: arm9/main @ 0x02046A8C; symbol: func_02046a8c; size: 0x7C.
extern "C" void RemoveLinkedNodeByPointer(int *param_1, int param_2) {
    int iVar1;
    int iVar2;
    int iVar3;
    iVar3=*param_1;
    if (iVar3 == 0) return;
    if (iVar3 == param_2) {
        *param_1=*(int *)(param_2+4);
    } else {
        iVar1=*(int *)(iVar3+4);
        if (*(int *)(iVar3+4) == 0) return;
        while ((iVar2=iVar1), iVar2 != param_2) {
            if (iVar2 == 0) return;
            iVar3=iVar2;
            iVar1=*(int *)(iVar2+4);
        }
        *(int *)(iVar3+4)=*(int *)(iVar2+4);
    }
    iVar3=*param_1;
    param_1[1]=0;
    for (; iVar3 != 0; iVar3=*(int *)(iVar3+4))
        param_1[1]=iVar3;
    InitializeFourWordsWithInvalidIndex(param_2);
}
