"""Prepare integration records and dashboard before releasing publication ownership."""
import json
import os
from pathlib import Path
import stat
import tempfile

SCHEMA = 'arm9-integration-receipt-v1'


def atomic_write(path, content):
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    descriptor, temporary = tempfile.mkstemp(prefix='.' + path.name + '.', dir=path.parent)
    try:
        with os.fdopen(descriptor, 'wb') as stream:
            stream.write(content)
        os.replace(temporary, path)
    finally:
        Path(temporary).unlink(missing_ok=True)


def json_bytes(document):
    return (json.dumps(document, indent=2) + '\n').encode()


def integration_record(document):
    """Recognize marked records and narrowly support this gate's older receipts."""
    if not isinstance(document, dict) or document.get('accepted') is not True:
        return False
    if 'receipt_schema' in document and document['receipt_schema'] != SCHEMA:
        return False
    marked = document.get('receipt_schema') == SCHEMA
    legacy = all(key in document for key in ('functions', 'code_bytes', 'before', 'after',
                                             'validation_seconds', 'role'))
    if not marked and not legacy:
        return False  # Foreign object/layout/support validation, not an integration.
    if document.get('processor', 'ARM9') != 'ARM9':
        return False
    for key in ('functions', 'code_bytes', 'data_bytes', 'bss_bytes'):
        value = document.get(key, 0)
        if type(value) is not int or value < 0:
            raise ValueError('Invalid integration receipt counter: ' + key)
    if not all(key in document for key in ('functions', 'code_bytes', 'before', 'after')):
        raise ValueError('Incomplete marked integration receipt')
    return True


def accepted_receipts(directory):
    accepted = []
    for path in sorted(Path(directory).glob('*/receipt.json')):
        if any((path.parent / marker).exists() for marker in ('failure.json', 'rolled-back-receipt.json')):
            continue
        document = json.loads(path.read_text())
        if integration_record(document):
            accepted.append((path.parent.name, document))
    return accepted


def checkpoint(directory, current_label, current, measures, timestamp):
    records = accepted_receipts(directory)
    if any(label == current_label for label, _ in records):
        raise ValueError('Current integration receipt already published')
    if not integration_record(current):
        raise ValueError('Current receipt is not a valid integration record')
    records.append((current_label, current))
    run = Path(directory) / 'run.json'
    return {'timestamp': timestamp,
            'deadline': json.loads(run.read_text()).get('deadline_utc') if run.exists() else None,
            'new_functions': sum(record['functions'] for _, record in records),
            'new_code_bytes': sum(record['code_bytes'] for _, record in records),
            'new_data_bytes': sum(record.get('data_bytes', 0) for _, record in records),
            'new_bss_bytes': sum(record.get('bss_bytes', 0) for _, record in records),
            'prior_functions': 0, 'prior_code_bytes': 0, 'main': measures,
            'accepted_batches': [label for label, _ in records],
            'workers': {'worker_b': 'running', 'worker_c': 'running'}}


class Bookkeeping:
    """Snapshot only this transaction's workflow, checkpoint and dashboard outputs."""
    def __init__(self, root, receipts, label):
        self.root, self.receipts, self.label = Path(root), Path(receipts), label
        self.folder = self.receipts / label
        self.progress = self.root / 'build/progress'
        self.stage = self.folder / 'publication'
        workflow = self.root / 'build/workflow' / label
        files = [self.receipts / 'checkpoint.json', self.progress / 'index.html',
                 workflow / 'start.json', workflow / 'finish.json']
        self.snapshot_directory = self.progress / 'snapshots'
        self.old_snapshots = set(self.snapshot_directory.glob('*.json'))
        # Archived snapshots are immutable inputs, not transaction outputs. Do
        # not read, copy, rewrite or back up the complete historical archive.
        if any(path.is_symlink() for path in self.old_snapshots):
            raise ValueError('Bookkeeping snapshot must not be a symlink')
        self.before = {}
        for path in files:
            if path.is_symlink():
                raise ValueError('Bookkeeping output must not be a symlink: ' + str(path))
            if path.exists():
                info = path.stat()
                self.before[path] = (path.read_bytes(), stat.S_IMODE(info.st_mode), info.st_atime_ns, info.st_mtime_ns)
            else:
                self.before[path] = None
        self.generated_snapshots = set()
        self.prepared = False

    def prepare(self, record, measures, timestamp, render=None):
        # Preparation may fail without installing any accepted receipt/checkpoint/page.
        self.stage.mkdir(exist_ok=False)
        history = self.stage / 'snapshots'
        history.mkdir()
        record = {**record, 'receipt_schema': SCHEMA, 'processor': 'ARM9'}
        document = checkpoint(self.receipts, self.label, record, measures, timestamp)
        if render is None:
            from progress_dashboard import generate
            generate(self.root, self.root / 'build/usa/report.json',
                     self.root / 'build/usa/arm7/report.json', self.stage / 'index.html',
                     history_directory=self.snapshot_directory)
        else:
            render(self.root, self.root / 'build/usa/report.json',
                   self.root / 'build/usa/arm7/report.json', self.stage / 'index.html')
        # The staging page starts absent, so the public-page lock fallback cannot
        # return the previous page instead of rendering the verified new reports.
        if not (self.stage / 'index.html').is_file():
            raise ValueError('Dashboard staging did not produce a page')
        atomic_write(self.stage / 'receipt.json', json_bytes(record))
        atomic_write(self.stage / 'checkpoint.json', json_bytes(document))
        self.prepared = True

    def publish(self):
        if not self.prepared:
            raise ValueError('Bookkeeping must be prepared before publication')
        # Publication ownership remains held through every write. Replace the page
        # last; release the publication guard only after this method completes.
        for path in (self.stage / 'snapshots').glob('*.json'):
            target = self.snapshot_directory / path.name
            if path.is_symlink() or target.exists() or target.is_symlink():
                raise ValueError('Refusing to replace an archived snapshot: ' + path.name)
            self.generated_snapshots.add(target)  # Track even a partial write.
            atomic_write(target, path.read_bytes())
        atomic_write(self.folder / 'receipt.json', (self.stage / 'receipt.json').read_bytes())
        atomic_write(self.receipts / 'checkpoint.json', (self.stage / 'checkpoint.json').read_bytes())
        atomic_write(self.progress / 'index.html', (self.stage / 'index.html').read_bytes())

    def rollback(self):
        receipt = self.folder / 'receipt.json'
        if receipt.exists():
            receipt.replace(self.folder / 'rolled-back-receipt.json')
        for path in self.generated_snapshots:
            path.unlink(missing_ok=True)
        for path, original in self.before.items():
            if original is None:
                path.unlink(missing_ok=True)
            else:
                content, mode, atime, mtime = original
                atomic_write(path, content)
                path.chmod(mode)
                os.utime(path, ns=(atime, mtime))
