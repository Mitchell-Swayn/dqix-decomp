/* Dispatch valid messages on the four SPI service channels. */
#pragma dont_inline on
extern void ARM7_TouchIpcReceive(unsigned int);
extern void ARM7_MicrophoneIpcReceive(unsigned int);
extern void ARM7_PowerIpcReceive(unsigned int);
extern void ARM7_SpiIpcReceiveExternal(unsigned int);
void ARM7_SpiIpcCallback(int channel,unsigned int message,int error)
{
 if(!error) {
  switch(channel) {
  case 6:ARM7_TouchIpcReceive(message);break;
  case 9:ARM7_MicrophoneIpcReceive(message);break;
  case 8:ARM7_PowerIpcReceive(message);break;
  case 4:ARM7_SpiIpcReceiveExternal(message);break;
  }
 }
}
