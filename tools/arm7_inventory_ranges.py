"""Structural validation for independently evidenced ARM7 range partitions."""

CLASSIFICATIONS = {"instruction", "literal_pool", "initialized_data"}


def _sha1(value, field):
    if (not isinstance(value, str) or len(value) != 40
            or any(character not in "0123456789abcdefABCDEF" for character in value)):
        raise ValueError(f"{field} must be a 40-character SHA-1 hex string")
    return value.lower()


def _number(value, field):
    if not isinstance(value, str) or not value.startswith("0x"):
        raise ValueError(f"{field} must be a hexadecimal string")
    try:
        return int(value, 16)
    except ValueError as error:
        raise ValueError(f"{field} is not valid hexadecimal") from error


def validate_inventory(inventory, baseline, config):
    """Validate confirmed subranges without assigning any class to the remainder."""
    if inventory.get("schema_version") != 1:
        raise ValueError("unsupported inventory schema version")
    if _sha1(inventory.get("source_rom_sha1"), "inventory source ROM SHA-1") != _sha1(
            baseline.get("source_rom_sha1"), "baseline source ROM SHA-1"):
        raise ValueError("inventory source ROM SHA-1 differs from baseline")
    if _sha1(inventory.get("payload_sha1"), "inventory payload SHA-1") != _sha1(
            baseline.get("payload_sha1"), "baseline payload SHA-1"):
        raise ValueError("inventory payload SHA-1 differs from baseline")
    scopes = inventory.get("scopes")
    if not isinstance(scopes, list) or not scopes:
        raise ValueError("inventory scopes must be a nonempty list")

    autoloads = {item["name"]: item for item in config.get("autoloads", [])}
    all_ranges = []
    seen_scopes = set()
    for scope in scopes:
        name = scope.get("name")
        if not isinstance(name, str) or name in seen_scopes:
            raise ValueError("scope names must be unique strings")
        seen_scopes.add(name)
        scope_offset = _number(scope.get("payload_offset"), f"{name}.payload_offset")
        runtime = _number(scope.get("runtime_address"), f"{name}.runtime_address")
        size = _number(scope.get("size"), f"{name}.size")
        autoload_name = scope.get("autoload")
        if autoload_name is None:
            expected_offset = 0
            expected_runtime = baseline["load_address"]
            expected_size = config["startup_size"]
        else:
            try:
                owner = autoloads[autoload_name]
            except KeyError as error:
                raise ValueError(f"{name} names unknown autoload") from error
            expected_offset = owner["payload_offset"]
            expected_runtime = owner["runtime_address"]
            expected_size = owner["size"]
        if (scope_offset < expected_offset or scope_offset + size > expected_offset + expected_size
                or runtime != expected_runtime + scope_offset - expected_offset or size <= 0):
            raise ValueError(f"{name} scope is outside its configured payload/runtime mapping")

        cursor = scope_offset
        totals = {key: 0 for key in CLASSIFICATIONS}
        ranges = scope.get("ranges")
        if not isinstance(ranges, list) or not ranges:
            raise ValueError(f"{name} ranges must be nonempty")
        for item in ranges:
            offset = _number(item.get("payload_offset"), f"{name}.range.payload_offset")
            length = _number(item.get("size"), f"{name}.range.size")
            classification = item.get("classification")
            if classification not in CLASSIFICATIONS:
                raise ValueError(f"{name} has unknown classification {classification!r}")
            if offset != cursor or length <= 0:
                raise ValueError(f"{name} ranges must form a contiguous end-exclusive partition")
            end = offset + length
            if end > scope_offset + size:
                raise ValueError(f"{name} range exceeds its confirmed scope")
            if not isinstance(item.get("evidence"), str) or not item["evidence"].strip():
                raise ValueError(f"{name} range lacks evidence")
            totals[classification] += length
            all_ranges.append((offset, end, name))
            cursor = end
        if cursor != scope_offset + size:
            raise ValueError(f"{name} ranges do not cover their confirmed scope")
        recorded_totals = scope.get("totals")
        if recorded_totals != totals:
            raise ValueError(f"{name} classification totals do not match its ranges")

    all_ranges.sort()
    for left, right in zip(all_ranges, all_ranges[1:]):
        if left[1] > right[0]:
            raise ValueError(f"inventory scopes overlap: {left[2]} and {right[2]}")
    return True
