#include <globaldefs.h>
#include <System/Memory.h>
ARM
#pragma optimize_for_size off
struct PieceConfig;
// Original data: arm9/ov027 @ 0x21e3424; symbol: data_ov027_021e3424.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov027.md.
extern "C" PieceConfig IsGetAllRequestData_UnknownRoleZeroInitializedStorage;
extern "C" int IsGetAllRequestData(unsigned);
extern "C" void* ReceiveRequestDataPiece(unsigned char*, unsigned);
// Original: arm9/ov027 @ 0x021DD6BC; symbol: func_ov027_021dd6bc; size: 0x11C.
// Decodes request packet types 7/8/9, reassembling child fragments or copying
// fixed-size payloads. Field layout follows byte/halfword reads in the original.
extern "C" void* Network_DecodeRequestDataPacket(unsigned char* packet, unsigned char* output, unsigned child)
{
 unsigned char type = packet[0];
 unsigned char* result;
 output[0] = type;
 switch (type) {
 case 7: {
  if (IsGetAllRequestData(child)) return *(unsigned char**)((char*)&IsGetAllRequestData_UnknownRoleZeroInitializedStorage + 4) + (child - 1) * 32;
  unsigned char piece = packet[1];
  output[2] = piece;
  if ((int)piece > *(int*)((char*)&IsGetAllRequestData_UnknownRoleZeroInitializedStorage + 12)) return 0;
  MI_CpuCopy8(packet + 2, output + 3, *(unsigned*)((char*)&IsGetAllRequestData_UnknownRoleZeroInitializedStorage + 8));
  result = (unsigned char*)ReceiveRequestDataPiece(output, child);
  break;
 }
 case 8:
  *(unsigned short*)(output + 2) = packet[1];
  *(unsigned short*)(output + 2) |= (packet[2] << 8) & 0xff00;
  result = packet + 3;
  break;
 case 9: {
  *(unsigned short*)(output + 2) = packet[1];
  *(unsigned short*)(output + 2) |= (packet[2] << 8) & 0xff00;
  result = packet + 3;
  MI_CpuCopy8(result, output + 4, *(unsigned*)((char*)&IsGetAllRequestData_UnknownRoleZeroInitializedStorage + 8));
  result += *(unsigned*)((char*)&IsGetAllRequestData_UnknownRoleZeroInitializedStorage + 8);
  break;
 }
 default: return 0;
 }
 return result;
}
