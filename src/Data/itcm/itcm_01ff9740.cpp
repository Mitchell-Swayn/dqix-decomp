// Fifteen KiB of zero-initialized storage for a loaded binary resource.
// func_020421c4 passes a view into this storage to func_02042998,
// which relocates the resource's two header offsets at +8 and +12.
// The content is supplied at runtime; this is storage, not executable bytes.
unsigned char TextInitializeSharedContextAndResources_UnknownRoleZeroInitializedStorage_Variant2[0x3c00];
