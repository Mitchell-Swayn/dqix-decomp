#pragma once

struct Random {
    /* +00 */ unsigned long long lcg_state;
    /* +08 */ unsigned long long lcg_multiplier;
    /* +10 */ unsigned long long lcg_increment;
    /* +18 */ char const* name;
    /* +1C */ unsigned char unk_1C;
};

#ifdef jpn
#define GetBTRandom_UnknownRoleZeroInitializedStorage data_02108d20
#endif

// Original data: arm9/main @ 0x2108ddc; symbol: data_02108ddc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern struct Random GetBTRandom_UnknownRoleZeroInitializedStorage;

/* get instance of the global "BT" ("Hoimi table") random */
struct Random* GetBTRandom(void);

/* Random constructor */
struct Random* CreateRandom(struct Random* random, char const* name, unsigned char unk_1C);

void InitRandom(struct Random* random, unsigned long long lcg_state, char const* name, unsigned char unk_1C);

void SeedRandom64(struct Random* random, unsigned long long lcg_state);

void SeedRandom(struct Random* random, unsigned long long lcg_state);

void SeedRandom32(struct Random* random, unsigned int stateHi, unsigned int stateLo);

unsigned int GetRandomStateHi(struct Random* random);

unsigned int GetRandomStateLo(struct Random* random);

/* generate a random unsigned integer between 0 and 0xFFFFFFFFu (inclusive). */
unsigned int NextRandom(struct Random* random);

/* generate a random integer between 0 and maximum (exclusive).
 * if maximum <= 0, returns 0 without updating state. */
int NextRandomMax(struct Random* random, int maximum);

/* generate a random floating point number between 0.0f and 1.0f (inclusive). */
float NextRandomFloat01(struct Random* random);

/* generate a random floating point number between minimum and maximum (inclusive). */
float NextRandomFloatBetween(struct Random* random, float minimum, float maximum);

/* generate a random floating point number between minimum and maximum (inclusive) with digits precision. */
float NextRandomFloatScaled(struct Random* random, float minimum, float maximum, int digits);

/* generate a random integer between minimum and maximum (inclusive) */
int NextRandomBetween(struct Random* random, int minimum, int maximum);
