#ifndef ARM7_CARD_REMOVAL_H
#define ARM7_CARD_REMOVAL_H
typedef struct {unsigned int unknown0,notified,initialized,removed;} CardRemovalState;
extern CardRemovalState ARM7_CardRemovalState;
#endif
