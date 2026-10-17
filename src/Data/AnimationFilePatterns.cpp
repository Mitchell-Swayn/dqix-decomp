// Effect suffix followed by four animation resource filename patterns.
struct AnimationFilePatterns { char effectSuffix[8]; char resourcePatterns[4][17]; };
extern "C" AnimationFilePatterns data_020f04b8 = { ".beff", {
    "data/ani/%s.NCER",
    "data/ani/%s.NANR",
    "data/ani/%s.NCGR",
    "data/ani/%s.NCLR",
} };
