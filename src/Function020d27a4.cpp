#include "System/Interrupts.h"

struct Function020d27a4Node
{
    Function020d27a4Node* next;
};

extern "C" unsigned int data_02112780[];

extern "C" int func_020d27a4()
{
    int previousState = DisableIRQInterrupts();
    volatile unsigned int* manager = data_02112780;
    Function020d27a4Node* node =
        reinterpret_cast<Function020d27a4Node*>(manager[2]);
    int count = 0;

    if (node != 0) {
        do {
            ++count;
            node = node->next;
        } while (node != 0);
    }

    SetIRQInterruptState(previousState);
    return count;
}
