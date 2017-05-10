Clicoin Core integration/staging tree
=====================================

[![Build Status](https://travis-ci.org/clicoin/clicoin.svg?branch=master)](https://travis-ci.org/clicoin/clicoin)

https://clicoincore.org

What is Clicoin?
----------------
Clicoin is based on the development of bitcoin, the total amount of 20 million to 21 million coin, the block automatically reward 0.07coin to 0.0001coin, every two years to reduce production time. Pre mining 20 million coin, used to reward miners, node people, developers, promoters, miners do not worry about competition, and endless hardware investment, the difficulty is very low. Block fixed 10 minutes out of a block. Difficulty adjustment cycle 10 years. Reward miners, everyone can receive subsidies, 3coin per month, after a cyclical reduction. Nodes, each person can receive subsidies, 2coin per month, after a cyclical reduction. Development, everyone can get subsidies, according to submit code, 100-10coin per month, after the periodic reduction. Promotion, everyone can get subsidies, recommend qualified miners, 1coin per person, after a cyclical reduction. Promotion, everyone can get subsidies, recommend qualified nodes, 1coin per person, after a cyclical reduction.

Clicoin is an experimental new digital currency that enables instant payments to
anyone, anywhere in the world. Clicoin uses peer-to-peer technology to operate
with no central authority: managing transactions and issuing money are carried
out collectively by the network. Clicoin Core is the name of open source
software which enables the use of this currency.

For more information, as well as an immediately useable, binary version of
the Clicoin Core software, see https://github.com/clicoin/clicoin/releases/tag/v0.12.0.

License
-------

Clicoin Core is released under the terms of the MIT license. See [COPYING](COPYING) for more
information or see https://opensource.org/licenses/MIT.

Development Process
-------------------

The `master` branch is regularly built and tested, but is not guaranteed to be
completely stable. [Tags](https://github.com/clicoin/clicoin/tags) are created
regularly to indicate new official, stable release versions of Clicoin Core.

The contribution workflow is described in [CONTRIBUTING.md](CONTRIBUTING.md).

The developer [mailing list](https://lists.linuxfoundation.org/mailman/listinfo/clicoin-dev)
should be used to discuss complicated or controversial changes before working
on a patch set.

Developer IRC can be found on Freenode at #clicoin-core-dev.

Testing
-------

Testing and code review is the bottleneck for development; we get more pull
requests than we can review and test on short notice. Please be patient and help out by testing
other people's pull requests, and remember this is a security-critical project where any mistake might cost people
lots of money.

### Automated Testing

Developers are strongly encouraged to write [unit tests](/doc/unit-tests.md) for new code, and to
submit new unit tests for old code. Unit tests can be compiled and run
(assuming they weren't disabled in configure) with: `make check`

There are also [regression and integration tests](/qa) of the RPC interface, written
in Python, that are run automatically on the build server.
These tests can be run with: `qa/pull-tester/rpc-tests.py`

The Travis CI system makes sure that every pull request is built for Windows
and Linux, OSX, and that unit and sanity tests are automatically run.

### Manual Quality Assurance (QA) Testing

Changes should be tested by somebody other than the developer who wrote the
code. This is especially important for large or high-risk changes. It is useful
to add a test plan to the pull request description if testing the changes is
not straightforward.

Translations
------------

Changes to translations as well as new translations can be submitted to
[Clicoin Core's Transifex page](https://www.transifex.com/projects/p/clicoin/).

Translations are periodically pulled from Transifex and merged into the git repository. See the
[translation process](doc/translation_process.md) for details on how this works.

**Important**: We do not accept translation changes as GitHub pull requests because the next
pull from Transifex would automatically overwrite them again.

Translators should also subscribe to the [mailing list](https://groups.google.com/forum/#!forum/clicoin-translators).
