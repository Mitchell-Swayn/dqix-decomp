#include <globaldefs.h>
ARM
struct Tree;
extern "C" Tree* Menu_FindArenaNodeById(Tree*, unsigned);
// Original: arm9/ov011 @ 0x021845F8; symbol: func_ov011_021845f8; size: 0xC.
extern "C" Tree* Menu_FindSessionArenaById(Tree* tree, unsigned id)
{
    return Menu_FindArenaNodeById(tree, id);
}
