"""Browser smoke check for the generated local call graph (optional playwright)."""
from pathlib import Path
from playwright.sync_api import sync_playwright

root = Path(__file__).resolve().parents[1]
with sync_playwright() as p:
    browser = p.chromium.launch(headless=True)
    page = browser.new_page(viewport={'width':1440, 'height':1000})
    errors=[]
    page.on('pageerror',lambda error:errors.append(str(error)))
    page.goto((root/'build/call-graph/index.html').as_uri())
    page.wait_for_function("document.querySelector('#detail').textContent.includes('InitRandom')")
    assert page.evaluate('selected') == 'arm9/main:02074208'
    assert page.evaluate('shown.length') >= 3
    page.locator('#search').fill('CreateRandom')
    page.locator('#results button').first.click()
    assert page.evaluate('selected') == 'arm9/main:020741dc'
    assert 'InitRandom' in page.locator('#neighbors').inner_text()
    page.locator('#depth').select_option('2')
    assert page.evaluate("shown.includes('arm9/main:02074238')")
    assert 'Dependency layer 3' in page.locator('#detail').inner_text()
    page.locator('#layer').select_option('3')
    assert page.evaluate("shown.includes('arm9/main:02074208')")
    assert page.evaluate("shown.includes('arm9/main:02074238')")
    page.locator('#layer').select_option('')
    page.evaluate("select(graph.nodes.find(n=>n.lineage.recursive).id)")
    assert 'recursive group' in page.locator('#detail').inner_text()
    assert page.locator('#detail select').count() == 1
    with page.expect_download() as transfer:
        page.get_by_role('button',name='Download decompilation order (CSV)').click()
    import csv
    with open(transfer.value.path(),encoding='utf-8',newline='') as stream:
        rows=list(csv.reader(stream))
    assert len(rows)==page.evaluate('graph.nodes.length')+1
    assert [int(row[0]) for row in rows[1:]]==sorted(int(row[0]) for row in rows[1:])
    page.locator('#overview').click()
    assert page.evaluate('shown.length === graph.nodes.length')
    page.locator('#module').select_option('arm7/wram')
    assert page.evaluate("shown.every(id=>id.startsWith('arm7/wram:'))")
    page.locator('#search').fill('ARM7_')
    assert page.locator('#results button').count() > 0
    page.locator('#results button').first.click()
    page.mouse.move(800,500); page.mouse.wheel(0,-200)
    page.locator('#fit').click()
    page.screenshot(path=str(root/'build/call-graph/viewer-check.png'))
    assert not errors, errors
    print('PASS: offline load, search, navigation, traversal, layers, recursive groups, complete sorted CSV export, overview, ARM7 filter, zoom and fit; no browser errors.')
    browser.close()
