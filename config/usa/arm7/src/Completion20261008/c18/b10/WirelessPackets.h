#ifndef ARM7_C18_WIRELESS_PACKETS_H
#define ARM7_C18_WIRELESS_PACKETS_H
/* Caller-owned command buffer. Six transport halfwords precede the command
 * and payload count; the reply frame follows the variable command payload. */
typedef struct WirelessPacket {
 volatile unsigned short transport[6];
 volatile unsigned short command;
 unsigned short wordCount;
 volatile unsigned short payload[];
} WirelessPacket;
extern WirelessPacket *ARM7_SubmitWirelessPacket(WirelessPacket *packet);
extern void ARM7_CopyBytes(const void *source,void *destination,unsigned int length);
extern volatile unsigned short *ARM7_WirelessCommandNoPayload(WirelessPacket *packet,unsigned short command,unsigned short replyWords);
#endif
