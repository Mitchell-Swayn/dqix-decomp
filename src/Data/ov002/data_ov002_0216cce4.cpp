#pragma define_section property_data ".data" RW
// Item property dispatch table. func_ov002_021536ec scans 12-byte
// records using signed 16-bit property IDs (-1 terminates), then calls
// the member target with object, selection, item record and property kind.
struct PropertyId { short id; unsigned short padding; };
extern "C" __declspec(section "property_data") PropertyId data_ov002_0216cce4 = { 0, 0 };
