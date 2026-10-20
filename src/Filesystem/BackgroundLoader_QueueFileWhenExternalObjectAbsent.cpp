#include <globaldefs.h>
#include <Filesystem/BackgroundLoader.h>
extern "C" {
// Original data: arm9/main @ 0x20f00cc; symbol: data_020f00cc.
// Source-defined character literal. Text: "data/effect/ev999991500.chr". Original zero separators, trailing bytes and padding remain unchanged.
// Initial values: "data/effect/ev999991500.chr".
// Observed span: 76 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern char BackgroundLoaderQueueFileWhenExternalObjectAbsent_TextDataEffectEv999991500ChrWithAdjacentText[];
// Original: arm9/main @ 0x02046C98; symbol: func_02046c98; size: 0x30.
void BackgroundLoader_QueueFileWhenExternalObjectAbsent(unsigned int *p){if(p[58])return;p[59]=(unsigned int)BackgroundLoader::GetInstance()->QueueLoadFile(BackgroundLoaderQueueFileWhenExternalObjectAbsent_TextDataEffectEv999991500ChrWithAdjacentText,0);}
}
