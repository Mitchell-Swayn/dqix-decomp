# Data symbols

The inventory covers 4,903 initially address-named ARM9 data symbols: 4,130 initialized-data symbols and 773 BSS symbols. All have contextual names and value records. 2,410 names have literal-content or existing-source support; 2,493 retain `UnknownRole` and remain required semantic naming work. Removing address-only spellings does not resolve their unknown meaning.

The ten previously reviewed battle-menu symbols are described in [BATTLE_MENU_DATA.md](BATTLE_MENU_DATA.md). The address-bound registry is [data_names.json](../config/usa/data_names.json).

Names scoped to consumers identify an observed reference, not exclusive subsystem ownership. Identical and similarly named copies remain separate. Original identifiers and addresses remain in comments and the registry.

Initialized byte spans stop at the next configured symbol and can include padding or only part of a larger object. BSS records describe zero initialization; runtime values can change. No data definitions, storage layouts, coverage denominators or reconstruction credit change.

- [dtcm](data-symbols/dtcm.md)
- [itcm](data-symbols/itcm.md)
- [main](data-symbols/main.md)
- [ov000](data-symbols/ov000.md)
- [ov001](data-symbols/ov001.md)
- [ov002](data-symbols/ov002.md)
- [ov003](data-symbols/ov003.md)
- [ov004](data-symbols/ov004.md)
- [ov005](data-symbols/ov005.md)
- [ov006](data-symbols/ov006.md)
- [ov007](data-symbols/ov007.md)
- [ov008](data-symbols/ov008.md)
- [ov009](data-symbols/ov009.md)
- [ov010](data-symbols/ov010.md)
- [ov011](data-symbols/ov011.md)
- [ov012](data-symbols/ov012.md)
- [ov013](data-symbols/ov013.md)
- [ov014](data-symbols/ov014.md)
- [ov015](data-symbols/ov015.md)
- [ov016](data-symbols/ov016.md)
- [ov017](data-symbols/ov017.md)
- [ov018](data-symbols/ov018.md)
- [ov019](data-symbols/ov019.md)
- [ov020](data-symbols/ov020.md)
- [ov021](data-symbols/ov021.md)
- [ov022](data-symbols/ov022.md)
- [ov023](data-symbols/ov023.md)
- [ov024](data-symbols/ov024.md)
- [ov025](data-symbols/ov025.md)
- [ov026](data-symbols/ov026.md)
- [ov027](data-symbols/ov027.md)
- [ov028](data-symbols/ov028.md)
- [ov029](data-symbols/ov029.md)
- [ov031](data-symbols/ov031.md)
- [ov032](data-symbols/ov032.md)
- [ov033](data-symbols/ov033.md)
- [ov034](data-symbols/ov034.md)

[Source data aliases](DATA_ALIASES.md) document fourteen additional field aliases and local literal labels. Japanese compatibility bindings preserve their regional identities.

Run `python3 tools/audit_data_names.py --output build/data-name-audit.json` to check owning symbols, original byte values and outstanding semantic review.
