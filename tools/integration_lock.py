"""One process gate for all main integrations, plus a fail-closed publication gate."""
import fcntl
from pathlib import Path

class integration_guard:
    def __init__(self, project, recovery=False):
        self.directory = Path(project) / 'build/progress'
        self.publication = self.directory / 'integration.lock'
        self.stream = None
        self.changed = False
        self.recovery = recovery

    def __enter__(self):
        self.directory.mkdir(parents=True, exist_ok=True)
        self.stream = (self.directory / 'integration-process.lock').open('a')
        fcntl.flock(self.stream, fcntl.LOCK_EX)
        if self.publication.exists() and not self.recovery:
            self.stream.close()
            raise RuntimeError('An unfinished integration publication lock exists; restore and verify its accepted state before retrying.')
        if self.recovery:
            if not self.publication.exists():
                self.stream.close()
                raise RuntimeError('Recovery requires an unfinished publication lock')
            self.changed = True
        return self

    def begin_changes(self):
        # Exclusive creation prevents silently taking over another publisher.
        self.publication.open('x').close()
        self.changed = True

    def release_publication(self):
        self.publication.unlink(missing_ok=True)
        self.changed = False

    def __exit__(self, kind, value, traceback):
        # Failed rollback retains the publication gate; process ownership always ends.
        if not self.changed:
            self.publication.unlink(missing_ok=True)
        fcntl.flock(self.stream, fcntl.LOCK_UN)
        self.stream.close()
