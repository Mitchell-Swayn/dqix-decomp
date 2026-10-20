#include <globaldefs.h>
#include <std_library_functions.h>
#include <Util/Random.h>
ARM
extern "C" const short Combat_SelectRandomCollectedGroupIndex_CombatantSelectionInitialIds[8];
extern "C" int Combat_CollectGroupIndicesByDescriptorFlags(char*,short*,int,unsigned);
// Original: arm9/ov000 @ 0x02153D10; symbol: func_ov000_02153d10; size: 0x68.
// Initializes eight candidate IDs, collects eligible group indices and selects one using the owner RNG.
extern "C" void Combat_SelectRandomCollectedGroupIndex(char* owner,short* output)
{
 short candidates[8];
 COPY_ARRAY(candidates,Combat_SelectRandomCollectedGroupIndex_CombatantSelectionInitialIds);
 int count=Combat_CollectGroupIndicesByDescriptorFlags(owner,candidates,8,1);
 *output=candidates[NextRandomMax((Random*)owner,count)];
}
