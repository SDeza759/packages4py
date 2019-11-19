#!/usr/bin/env python
# This file is closely based on tests.py from matplotlib
#
# This allows running the matplotlib tests from the command line: e.g.
#
#   $ python run_tests.py -v -d
#
# The arguments are identical to the arguments accepted by nosetests.
#
# See https://nose.readthedocs.org/ for a detailed description of
# these options.
import nose


env = {"NOSE_WITH_COVERAGE": 1,
       'NOSE_COVER_PACKAGE': ['cycler'],
       'NOSE_COVER_HTML': 1}
plugins = []


def run():

    nose.main(addplugins=[x() for x in plugins], env=env)


if __name__ == '__main__':
    run()
