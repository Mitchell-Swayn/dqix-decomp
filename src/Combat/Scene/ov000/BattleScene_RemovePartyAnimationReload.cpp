#include <globaldefs.h>
ARM
// The key is read again after comparison in the original; volatile preserves that read contract.
// The underlying reason for repeated key reads is unresolved.
struct SixByteKeyRecord { volatile signed char key; unsigned char byte1; short value2; short value4; };
struct SixByteRecordOwner { unsigned char pad[0x77d6]; SixByteKeyRecord records[4]; unsigned char count; };
// Original: arm9/ov000 @ 0x0216867C; symbol: BattleScene_RemovePartyAnimationReload; size: 0xA4.
// Compacts six-byte records whose signed-byte key differs from the supplied key.
// If any key matched, decrements count once even if multiple records matched.
extern "C" void BattleScene_RemovePartyAnimationReload(SixByteRecordOwner* owner, int key)
{
 int found = 0;
 int written = 0;
 for (int read = 0; read < owner->count; read++) {
  if (key == owner->records[read].key) found = 1;
  else {
   owner->records[written].key = owner->records[read].key;
   owner->records[written].byte1 = owner->records[read].byte1;
   owner->records[written].value2 = owner->records[read].value2;
   owner->records[written].value4 = owner->records[read].value4;
   written++;
  }
 }
 if (found) --owner->count;
}
