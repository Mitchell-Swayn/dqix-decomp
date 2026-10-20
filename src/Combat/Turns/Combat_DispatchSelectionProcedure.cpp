#include <globaldefs.h>
typedef int (*SelectionProc)(void*,void*,int*);
// Original data: arm9/ov000 @ 0x218409c; symbol: data_ov000_0218409c.
// Combat target-selection procedure dispatch. Dispatcher021820bc bounds-checks selector0..57, forwards incoming context/action registers and output-array pointer (r3 becomes r2), then returns procedure result/count. Wrappers02181a5c and02181a74 pass the output array to0218177c; that routine stores signed combatant IDs as four-byte ints and returns their count. Context and action layouts remain unresolved; these are opaque pointer types.
// Initial values: hex 5c1a1802741a18028c1a1802a41a1802bc1a180200000000000000004c1d1802681d1802881d1802a41d1802c01d1802dc1d1802f81d1802141e1802301e1802 ...; full span in module reference.
// Observed span: 232 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" SelectionProc CombatDispatchSelectionProcedure_CombatTargetSelectionProcedureDispatch[58];
#pragma force_active on
// Original: arm9/ov000 @ 0x021820BC; symbol: func_ov000_021820bc; size: 0x40.
// Describes observed operations; underlying field roles remain uncertain.
extern "C" int Combat_DispatchSelectionProcedure(void* context, void* action, int selector, int* output)
{
    if (selector < 0 || (unsigned)selector >= 58) return 0; SelectionProc proc=CombatDispatchSelectionProcedure_CombatTargetSelectionProcedureDispatch[selector]; if (!proc) return 0; return proc(context,action,output);
}
