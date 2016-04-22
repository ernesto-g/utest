/*
    utest example : Unit test examples.
    Copyright (C) <2016>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <utest.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../inc/firstTest.h"
#include "../inc/secondTest.h"


void startTesting(void)
{

    // Start Group 01
    utest_print("\nStarting testings of sortNames()...\r\n\n");
    utest_init();
    utest_startTest(firstTestCase01,firstTestSetup,"Case: Order UP");
    utest_startTest(firstTestCase02,firstTestSetup,"Case: Order DOWN");
    utest_startTest(firstTestCase03,firstTestSetup,"Case: Invalid length [-1]");
    utest_startTest(firstTestCase04,firstTestSetup,"Case: Invalid length [0]");
    utest_startTest(firstTestCase05,firstTestSetup,"Case: Valid length");
    utest_printStatistics("sortNames()");
    // End Group 01


    // Start Group 02
    utest_print("\nStarting testings of findName()...\r\n\n");
    utest_init();
    utest_startTest(secondTestCase01,secondTestSetup,"Case: Found a name");
    utest_startTest(secondTestCase02,secondTestSetup,"Case: Not Found a name");
    utest_startTest(secondTestCase03,secondTestSetup,"Case: Invalid length");
    utest_printStatistics("findName()");
    // End Group 02




}
