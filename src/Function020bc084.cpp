#include <asmhacks.h>

extern "C" void func_020bc084(unsigned int** owner)
{
    unsigned int* volatile* reloadableOwner = owner;
    unsigned int* value = *reloadableOwner;
    if (value == 0) {
        return;
    }

    DECLARE_ASM_NOP();
    unsigned int zero = 0;
    value = *reloadableOwner;
    *value = zero;
    *owner = 0;
}
