#include <globaldefs.h>
ARM
extern "C" unsigned WM_GetAllowedChannel();
// Original: arm9/ov027 @ 0x021DB3C0; symbol: func_ov027_021db3c0; size: 0x70.
// Advances the scan channel to a different enabled channel, wrapping channels one through sixteen.
extern "C" int ChangeScanChannel(unsigned short *configuration)
{
    unsigned short tries;
    unsigned allowed=WM_GetAllowedChannel();
    if(!allowed)return 0;
    unsigned short original=configuration[2];
    unsigned short channel=original;
    tries=0;
    while(tries<16) {
        if((allowed&(1<<(channel-1))) && original!=channel) { configuration[2]=channel; break; }
        tries++;
        channel=channel==16?1:channel+1;
    }
    return 1;
}
