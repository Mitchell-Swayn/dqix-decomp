#pragma dont_inline on

/* VBlank increments the shared counter and dispatches the callback snapshot.
 * The channel-prefix view preserves the original callback load at offset 0x60.
 * Only the final VBlank response record is newly owned storage in this unit. */
typedef void (*Handler)(void);
typedef struct { Handler callback; unsigned int stayEnabledAfter; int userdata; } VBlankResponse;
typedef struct { char channelResponses[0x60]; VBlankResponse verticalBlank; } InterruptResponseView;
extern InterruptResponseView ARM7_InterruptResponses;
VBlankResponse ARM7_VBlankResponse;
#define VBLANK_COUNT (*(volatile unsigned int*)0x027ffc3c)
#define FIRED (*(volatile unsigned int*)0x0380fff8)
void ARM7_VBlankInterruptHandler(void)
{
 Handler callback=ARM7_InterruptResponses.verticalBlank.callback;
 VBLANK_COUNT++;
 if(callback)callback();
 FIRED|=1;
}
