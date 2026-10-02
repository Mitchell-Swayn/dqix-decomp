#pragma force_active on

// Scene entry/exit hooks are deliberately empty in the original overlay.
// The main dispatcher calls these around the read-error scene driver.
extern "C" void func_ov019_0218b5a0() {}
extern "C" void func_ov019_0218b5a4(void*) {}

struct SceneCameraVector {
    int x, y, z; // signed 20.12 fixed point
};

// Retained allocation-size constant; the driver creates a heap of this size.
extern const unsigned int data_ov019_0218c290 = 0x19000;
extern const SceneCameraVector data_ov019_0218c294 = {0, 0, -0x1000};
extern const SceneCameraVector data_ov019_0218c2a0 = {0, 0x1000, 0};

// A single record preserves the byte-packed string fields. The original
// interior symbols are module-local linker aliases to these actual arrays.
struct SceneResourceNames {
    char iconArchive[20];
    char archiveSignature[4];
    char errorArchive[21];
    char errorLanguageFile[17];
    char penAnimations[17];
    unsigned char trailingAlignment[17];
};

SceneResourceNames data_ov019_0218c2c0 = {
    "data/bin/icon.nsarc", "ARC", "data/bin/str_err.gp2",
    "str_err_<LG>.nat", "data/ani/pen.pac", {0}
};
