#include "ScriptRegistry.h"

// Separate unit because the intervening script loader is still fallback.
extern "C" {
RegistryRecord* func_ov015_0218bae8(ScriptRegistry* registry, int index)
{
    if (index < 0 || registry->recordCount <= index) return 0;
    return &registry->records[index];
}
RegistryGroup* func_ov015_0218bb14(ScriptRegistry* registry, int index)
{
    if (index < 0 || registry->groupCount <= index) return 0;
    return &registry->groups[index];
}
}
