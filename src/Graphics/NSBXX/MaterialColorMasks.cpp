#include "Graphics/NSBXX/RenderCommands_Common.h"

// Three material flags select low color, high color, and the bit-15 control.
const unsigned int data_020e9240[8] = {
    0x00000000, 0x00007fff, 0x7fff0000, 0x7fff7fff, 0x00008000, 0x0000ffff, 0x7fff8000, 0x7fffffff
};
