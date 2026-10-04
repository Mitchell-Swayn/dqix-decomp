"""Compile independently verified function views from shared human-authored files."""
import argparse
import json
from pathlib import Path
from functools import lru_cache


@lru_cache(maxsize=4)
def _catalog(path, mtime, size):
    return json.loads(Path(path).read_text())


def catalog(root):
    path = (Path(root) / 'config/usa/unit_sources.json').resolve()
    if not path.exists():
        return None
    stat = path.stat()
    return _catalog(str(path), stat.st_mtime_ns, stat.st_size)


def views(root):
    document = catalog(root)
    if document is None:
        return {}
    result = {}
    for identity, key in document['functions'].items():
        unit = document['units'][key]
        if not unit['placeholder']:
            continue
        module, address = identity.split(':')
        name = f'src/UnitObjects/{module}/fn_{address}.cpp'
        result[name] = dict(source_path=unit['source_path'], define='DQIX_FUNCTION_' + address.upper(),
                            function_id=identity, unit_id=key, object_source_path=name)
    return result


def active_views(root):
    all_views = views(root)
    active = {}
    for path in (Path(root) / 'config/usa/arm9').rglob('delinks.txt'):
        for line in path.read_text().splitlines():
            name = line.strip().rstrip(':')
            if name in all_views:
                active[name] = all_views[name]
    return active


def source_path(root, object_source):
    # Only generated view identities require resolving the catalog.
    if not object_source.startswith('src/UnitObjects/'):
        return object_source
    view = views(root).get(object_source)
    return view['source_path'] if view else object_source


def reserved_sources(root):
    document = catalog(root)
    if document is None:
        return set()
    return {u['source_path'] for u in document['units'].values() if u['placeholder']}


def patch_objdiff(root, path):
    configured = active_views(root)
    document = json.loads(path.read_text())
    for unit in document['units']:
        name = unit['name'] + '.cpp'
        if name in configured:
            view = configured[name]
            unit.setdefault('metadata', {})['source_path'] = view['source_path']
            scratch = unit.get('scratch')
            if scratch:
                scratch['c_flags'] += ' -d ' + view['define']
    path.write_text(json.dumps(document, indent=2) + '\n', encoding='utf-8')


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('action', choices=['objdiff'])
    p.add_argument('--root', type=Path, default=Path('.'))
    p.add_argument('--path', type=Path, default=Path('objdiff.json'))
    args = p.parse_args()
    patch_objdiff(args.root, args.path)


if __name__ == '__main__':
    main()
