#include <globaldefs.h>
ARM
struct Ratios;
extern "C" int BattleHud_ClassifyHealthRatio(Ratios*);
struct ClassifiedRecord { unsigned char pad[0x25]; signed char classification; unsigned short tail; };
struct RecordOwner { unsigned char pad[0x170]; ClassifiedRecord* records; };
// Original: arm9/ov000 @ 0x0217F5E4; symbol: func_ov000_0217f5e4; size: 0x48.
// For a present ratio record, writes its signed-byte classification to slots 7..16.
extern "C" void BattleMenu_ApplyPartyHealthClassToDigitSprites(RecordOwner* owner,Ratios* ratios) {
    if (!ratios) return;
    signed char classification=BattleHud_ClassifyHealthRatio(ratios);
    for (int i=7;i<17;i++) owner->records[i].classification=classification;
}
