import copy
import unittest
from naming_review import validate_review


class ReviewCoverageTests(unittest.TestCase):
    def setUp(self):
        self.f = dict(function_id='arm9/ov001:02158000',module='ov001',address='0x02158000',symbol='ReadWord',source='src/Unclassified/ov001/ReadWord.cpp')
        self.scope = [dict(source=self.f['source'],source_sha256='abc',functions=[self.f]),dict(source='src/Data/ov001/Table.cpp',source_sha256='def',functions=[])]
        self.review = dict(functions=[dict(self.f,source_sha256='abc',status='unresolved',evidence=['Loads pointer field 0x10'],next_dependency='Identify owning struct from allocator')],units=[dict(source=u['source'],source_sha256=u['source_sha256'],evidence=['Owner unresolved'])for u in self.scope],proposals=[])

    def test_complete_including_data_unit(self):
        self.assertEqual(validate_review(self.scope,self.review)['functions'],1)

    def test_overlapping_overlay_address_is_not_identity(self):
        self.review['functions'][0]['module']='ov002'
        with self.assertRaisesRegex(ValueError,'identity mismatch'): validate_review(self.scope,self.review)

    def test_omission_and_duplicate_refused(self):
        for rows in ([],self.review['functions']*2):
            r=copy.deepcopy(self.review);r['functions']=rows
            with self.assertRaisesRegex(ValueError,'exactly once'):validate_review(self.scope,r)

    def test_data_unit_omission_refused(self):
        self.review['units'].pop()
        with self.assertRaisesRegex(ValueError,'including data'):validate_review(self.scope,self.review)

    def test_stale_source_refused(self):
        self.review['functions'][0]['source_sha256']='old'
        with self.assertRaisesRegex(ValueError,'hash mismatch'):validate_review(self.scope,self.review)

    def test_unresolved_requires_dependency(self):
        self.review['functions'][0]['next_dependency']=''
        with self.assertRaisesRegex(ValueError,'next dependency'):validate_review(self.scope,self.review)


class IncrementalCoverageTests(unittest.TestCase):
    setUp = ReviewCoverageTests.setUp
    def test_partial_subset_does_not_wait_for_whole_scope(self):
        from naming_review import validate_incremental_review
        package=dict(units=self.scope)
        result=validate_incremental_review(package,dict(functions=[],proposals=[]))
        self.assertFalse(result['package_complete'])
        self.assertEqual(result['pending_function_ids'],[self.f['function_id']])
        self.assertTrue(validate_incremental_review(package,self.review)['package_complete'])

    def test_partial_subset_still_rejects_cross_overlay_identity(self):
        from naming_review import validate_incremental_review
        self.review['functions'][0]['module']='ov002'
        with self.assertRaisesRegex(ValueError,'identity mismatch'):
            validate_incremental_review(dict(units=self.scope),self.review)


class ProposalTransportTests(unittest.TestCase):
    def setUp(self):
        self.proposal = dict(new_symbol='ReadSignedByteAtOffset20', source='src/Unclassified/Old.cpp', destination='src/Unclassified/ReadSignedByteAtOffset20.cpp', evidence=dict(reviewed=True,note='Body sign-extends one byte at +0x20'))

    def test_valid_spelling_and_path_are_distinct(self):
        from naming_review import validate_proposal_shape
        validate_proposal_shape(self.proposal)

    def test_path_or_prose_cannot_be_a_symbol(self):
        from naming_review import validate_proposal_shape
        for value in ('src/Util/Name.cpp', 'Need caller evidence', ''):
            self.proposal['new_symbol']=value
            with self.assertRaisesRegex(ValueError,'linkage identifier'): validate_proposal_shape(self.proposal)

    def test_move_cannot_escape_or_change_language(self):
        from naming_review import validate_proposal_shape
        for value in ('/src/Name.cpp', 'src/../Name.cpp', 'src/Name.c', 'include/Name.cpp'):
            self.proposal['destination']=value
            with self.assertRaisesRegex(ValueError,'source path'): validate_proposal_shape(self.proposal)

    def test_heuristic_or_empty_evidence_not_reviewed(self):
        from naming_review import validate_proposal_shape
        for evidence in (dict(reviewed=False,note='guessed'),dict(reviewed=True,note=' ')):
            self.proposal['evidence']=evidence
            with self.assertRaisesRegex(ValueError,'reviewed evidence'): validate_proposal_shape(self.proposal)
