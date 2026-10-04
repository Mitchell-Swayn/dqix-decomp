#include "Filesystem/FileIOConfiguration.h"

#if defined(usa)
typedef char FileIOConfigurationSizeCheck[sizeof(FileIOConfiguration) == 88 ? 1 : -1];
FileIOConfiguration gFileIOConfiguration = {
    "de", "it", "fr", "es", "en", "ja", { 0, 0 },
    gFileIOConfiguration.revisionText, 0, "$Revision: 17659 $",
    { gFileIOConfiguration.japanese, gFileIOConfiguration.english,
      gFileIOConfiguration.french, gFileIOConfiguration.german,
      gFileIOConfiguration.italian, gFileIOConfiguration.spanish },
    "ARC", "arc:/", "<LG>"
};

#pragma define_section init ".init" RX
extern "C" __declspec(section "init") void __sinit_020e60e0()
{
    gFileIOConfiguration.revisionNumber = gFileIOConfiguration.revision + 11;
}
#endif
