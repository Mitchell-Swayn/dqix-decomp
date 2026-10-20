"""Paths, configuration and the shared SQLite task database."""
import json
import os
from pathlib import Path
import sqlite3
import time

HERE = Path(__file__).resolve().parent
CONFIG = json.loads((HERE / 'config.json').read_text())

SCHEMA = '''
CREATE TABLE IF NOT EXISTS meta(key TEXT PRIMARY KEY, value TEXT NOT NULL);
CREATE TABLE IF NOT EXISTS symbols(module TEXT NOT NULL, name TEXT NOT NULL, address INTEGER NOT NULL,
  kind TEXT NOT NULL, mode TEXT, size INTEGER, PRIMARY KEY(module, address, kind));
CREATE INDEX IF NOT EXISTS symbols_by_name ON symbols(name);
CREATE TABLE IF NOT EXISTS relocs(module TEXT NOT NULL, site INTEGER NOT NULL, kind TEXT NOT NULL,
  target INTEGER NOT NULL, target_modules TEXT NOT NULL, PRIMARY KEY(module, site));
CREATE TABLE IF NOT EXISTS decls(name TEXT PRIMARY KEY, decl TEXT NOT NULL, path TEXT NOT NULL);
CREATE TABLE IF NOT EXISTS edges(caller TEXT NOT NULL, callee TEXT NOT NULL, PRIMARY KEY(caller, callee));
CREATE INDEX IF NOT EXISTS edges_by_callee ON edges(callee);
CREATE TABLE IF NOT EXISTS tasks(
  id TEXT PRIMARY KEY, module TEXT NOT NULL, name TEXT NOT NULL, address INTEGER NOT NULL,
  size INTEGER NOT NULL, mode TEXT NOT NULL, original BLOB NOT NULL, listing TEXT NOT NULL,
  pseudocode TEXT, referenced INTEGER NOT NULL, hints TEXT NOT NULL DEFAULT '', asm_likely INTEGER NOT NULL DEFAULT 0,
  status TEXT NOT NULL DEFAULT 'open', worker TEXT, lease_until REAL,
  checks INTEGER NOT NULL DEFAULT 0, best REAL NOT NULL DEFAULT 0, gave_up INTEGER NOT NULL DEFAULT 0,
  notes TEXT NOT NULL DEFAULT '', source TEXT, symbol TEXT, subsystem TEXT, profile TEXT, suffix TEXT, updated REAL);
CREATE INDEX IF NOT EXISTS tasks_by_status ON tasks(status, size);
CREATE TABLE IF NOT EXISTS renames(module TEXT NOT NULL, old TEXT NOT NULL, new TEXT NOT NULL,
  PRIMARY KEY(module, old));
CREATE TABLE IF NOT EXISTS events(time REAL NOT NULL, task TEXT, worker TEXT, kind TEXT NOT NULL, detail TEXT);
'''


def _enclosing_project():
    """The project containing the working directory, so a forgotten --project stays local."""
    for path in (Path.cwd(), *Path.cwd().parents):
        if (path / 'config' / 'usa' / 'arm9').is_dir():
            return path
    return None


class Project:
    def __init__(self, root=None):
        self.root = Path(root or os.environ.get('SWARM_PROJECT') or _enclosing_project() or HERE.parent).resolve()
        self.state = self.root / 'build' / 'swarm'
        self.db_path = self.state / 'swarm.db'
        self.inputs = Path(os.environ.get('SWARM_INPUTS', CONFIG['inputs'])).expanduser()

    def connect(self, create=False):
        if not create and not self.db_path.exists():
            raise SystemExit(f'No task database at {self.db_path}; run: swarm.py build')
        self.state.mkdir(parents=True, exist_ok=True)
        db = sqlite3.connect(self.db_path, timeout=60, isolation_level=None)
        db.row_factory = sqlite3.Row
        db.execute('PRAGMA journal_mode=WAL')
        db.execute('PRAGMA synchronous=NORMAL')
        if create:
            db.executescript(SCHEMA)
        return db

    def compiler(self, profile='default'):
        """(executable, flags, executable_field) for a named profile from config.json."""
        if profile not in CONFIG['profiles']:
            raise SystemExit(f"unknown profile {profile!r}; choose from {sorted(CONFIG['profiles'])}")
        p = CONFIG['profiles'][profile]
        flags = [p['opt'] if f == '-O2' else f for f in CONFIG['flags']]
        if not p['interworking']:
            flags = ['-nointerworking' if f == '-interworking' else f for f in flags]
        if p['version'] == '2.0/sp2p2':
            return self.inputs / CONFIG['compiler'], flags, 'configured_default'
        relative = f"tools/mwccarm/{p['version']}/mwccarm.exe"
        return self.root / relative, flags, relative

    def config_dir(self, module):
        """config/usa/arm9 directory owning a module id such as arm9/main or arm9/ov017."""
        base = self.root / 'config/usa/arm9'
        name = module.split('/', 1)[1]
        if name == 'main':
            return base
        if name in ('itcm', 'dtcm'):
            return base / name
        return base / 'overlays' / name


def log(db, kind, task=None, worker=None, **detail):
    db.execute('INSERT INTO events VALUES(?,?,?,?,?)',
               (time.time(), task, worker, kind, json.dumps(detail, sort_keys=True) if detail else None))


def module_from_reloc(field):
    """relocs.txt module field -> list of module ids."""
    if field in ('main', 'itcm', 'dtcm'):
        return ['arm9/' + field]
    if field.startswith('overlay(') or field.startswith('overlays('):
        ids = field[field.index('(') + 1:-1].split(',')
        return [f'arm9/ov{int(i):03d}' for i in ids if i.strip()]
    return []
