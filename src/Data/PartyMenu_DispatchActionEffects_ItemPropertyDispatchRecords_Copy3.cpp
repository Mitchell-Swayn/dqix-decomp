// Original data: arm9/ov002 @ 0x216cce4; symbol: data_ov002_0216cce4.
// Item property dispatch table. func_ov002_021536ec scans 12-byte records using signed 16-bit property IDs (-1 terminates), then calls the member target with object, selection, item record and property kind.
// Observed values: hex 00000000.
// Span: 4 bytes to next configured symbol; logical object size may differ.
#pragma define_section property_data ".data" RW
// Item property dispatch table. func_ov002_021536ec scans 12-byte
// records using signed 16-bit property IDs (-1 terminates), then calls
// the member target with object, selection, item record and property kind.
struct PropertyId { short id; unsigned short padding; };
extern "C" __declspec(section "property_data") PropertyId PartyMenu_DispatchActionEffects_ItemPropertyDispatchRecords_Copy3 = { 0, 0 };
