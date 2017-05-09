from distutils.core import setup
setup(name='cicspendfrom',
      version='1.0',
      description='Command-line utility for clicoin "coin control"',
      author='Gavin Andresen',
      author_email='gavin@clicoinfoundation.org',
      requires=['jsonrpc'],
      scripts=['spendfrom.py'],
      )
