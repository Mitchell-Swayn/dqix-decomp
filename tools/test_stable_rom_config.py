import os
from pathlib import Path
import subprocess
import tempfile
import unittest
from unittest.mock import patch

from stable_rom_config import generate


class StableConfigTests(unittest.TestCase):
    def test_identical_output_preserves_mtime_but_runs_dsd(self):
        with tempfile.TemporaryDirectory() as tmp:
            p=Path(tmp)/'rom.yaml';p.write_bytes(b'config');os.utime(p,ns=(10**15,10**15))
            with patch('stable_rom_config.subprocess.run',side_effect=lambda *a,**k:p.write_bytes(b'config')) as run:
                generate('dsd','arm9.o','config.yaml',p)
            run.assert_called_once();self.assertEqual(p.stat().st_mtime_ns,10**15)

    def test_changed_output_has_new_mtime(self):
        with tempfile.TemporaryDirectory() as tmp:
            p=Path(tmp)/'rom.yaml';p.write_bytes(b'old');os.utime(p,ns=(10**15,10**15))
            with patch('stable_rom_config.subprocess.run',side_effect=lambda *a,**k:p.write_bytes(b'new')):
                generate('dsd','arm9.o','config.yaml',p)
            self.assertEqual(p.read_bytes(),b'new');self.assertNotEqual(p.stat().st_mtime_ns,10**15)

    def test_missing_output_is_created(self):
        with tempfile.TemporaryDirectory() as tmp:
            p=Path(tmp)/'rom.yaml'
            with patch('stable_rom_config.subprocess.run',side_effect=lambda *a,**k:p.write_bytes(b'new')):
                generate('dsd','arm9.o','config.yaml',p)
            self.assertEqual(p.read_bytes(),b'new')

    def test_failure_does_not_restore_timestamp(self):
        with tempfile.TemporaryDirectory() as tmp:
            p=Path(tmp)/'rom.yaml';p.write_bytes(b'old');os.utime(p,ns=(10**15,10**15))
            def fail(*a,**k):p.write_bytes(b'broken');raise subprocess.CalledProcessError(1,['dsd'])
            with patch('stable_rom_config.subprocess.run',side_effect=fail):
                with self.assertRaises(subprocess.CalledProcessError):generate('dsd','arm9.o','config.yaml',p)
            self.assertNotEqual(p.stat().st_mtime_ns,10**15)

    def test_symlink_is_rejected(self):
        with tempfile.TemporaryDirectory() as tmp:
            target=Path(tmp)/'target';target.write_bytes(b'data');p=Path(tmp)/'link';p.symlink_to(target)
            with patch('stable_rom_config.subprocess.run') as run:
                with self.assertRaises(ValueError):generate('dsd','arm9.o','config.yaml',p)
            run.assert_not_called()


if __name__=='__main__':unittest.main()
