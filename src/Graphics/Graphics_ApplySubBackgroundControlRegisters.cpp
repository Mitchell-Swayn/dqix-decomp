// Original: arm9/main @ 0x02074E54; symbol: func_02074e54; size: 0x23c.
#include <globaldefs.h>
struct BackgroundControlBits { unsigned short priority:2; unsigned short characterBase:4; unsigned short mosaic:1; unsigned short colorMode:1; unsigned short screenBase:5; unsigned short extendedPalette:1; unsigned short size:2; };
struct BackgroundLayerConfig { unsigned short unknown; BackgroundControlBits control; };
struct SubBackgroundConfig { BackgroundLayerConfig layer[4]; unsigned char unknown; unsigned char enabled; };
// ARM9 main, original func_02074e54 at 0x02074e54.
// Proposed semantic name: ApplySubBackgroundControlRegisters.
extern "C" ARM void Graphics_ApplySubBackgroundControlRegisters(const SubBackgroundConfig *config)
{
    if (!config->enabled) return;
    volatile unsigned short *registers = (volatile unsigned short *)0x04001008;
    registers[0] = ((short)config->layer[0].control.size << 14) | (registers[0] & 0x43) | ((short)config->layer[0].control.colorMode << 7) | ((short)config->layer[0].control.screenBase << 8) | ((short)config->layer[0].control.characterBase << 2) | ((short)config->layer[0].control.extendedPalette << 13);
    registers[1] = ((short)config->layer[1].control.size << 14) | (registers[1] & 0x43) | ((short)config->layer[1].control.colorMode << 7) | ((short)config->layer[1].control.screenBase << 8) | ((short)config->layer[1].control.characterBase << 2) | ((short)config->layer[1].control.extendedPalette << 13);
    registers[2] = ((short)config->layer[2].control.size << 14) | (registers[2] & 0x43) | ((short)config->layer[2].control.colorMode << 7) | ((short)config->layer[2].control.screenBase << 8) | ((short)config->layer[2].control.characterBase << 2);
    registers[3] = ((short)config->layer[3].control.size << 14) | (registers[3] & 0x43) | ((short)config->layer[3].control.colorMode << 7) | ((short)config->layer[3].control.screenBase << 8) | ((short)config->layer[3].control.characterBase << 2);
    registers[0] = (registers[0] & ~3) | (short)config->layer[0].control.priority;
    registers[1] = (registers[1] & ~3) | (short)config->layer[1].control.priority;
    registers[2] = (registers[2] & ~3) | (short)config->layer[2].control.priority;
    registers[3] = (registers[3] & ~3) | (short)config->layer[3].control.priority;
    if ((short)config->layer[0].control.mosaic) *(volatile unsigned short *)0x04001008 |= 0x40;
    else *(volatile unsigned short *)0x04001008 &= ~0x40;
    if ((short)config->layer[1].control.mosaic) *(volatile unsigned short *)0x0400100a |= 0x40;
    else *(volatile unsigned short *)0x0400100a &= ~0x40;
    if ((short)config->layer[2].control.mosaic) *(volatile unsigned short *)0x0400100c |= 0x40;
    else *(volatile unsigned short *)0x0400100c &= ~0x40;
    if ((short)config->layer[3].control.mosaic) *(volatile unsigned short *)0x0400100e |= 0x40;
    else *(volatile unsigned short *)0x0400100e &= ~0x40;
}
