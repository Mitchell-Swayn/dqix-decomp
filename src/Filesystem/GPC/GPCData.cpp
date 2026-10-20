#include "Filesystem/GPCImplementation.h"

#if defined(usa)
// Runtime startup fills the revision suffix and numeric signatures. Keep their
// on-cartridge zero initializers distinct from the text used to construct them.
GPCStaticData gpcData = {
    { 0, gpcData.revision, 0, 0, 0 },
    "$Revision: 17659 $", "GPC0", "GPC1", "GPC2"
};
#endif
