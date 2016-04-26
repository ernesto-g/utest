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

    utest_print("starting testings...\r\n");

    // Start Group 01
    utest_init();
    utest_startTest(firstTestCase01,firstTestSetup,"Test Group 01 Case 01");
    utest_startTest(firstTestCase02,firstTestSetup,"Test Group 01 Case 02");
    utest_startTest(firstTestCase03,firstTestSetup,"Test Group 01 Case 03");
    utest_printStatistics("Test Group 01");
    // End Group 01


    // Start Group 02
    utest_init();
    utest_startTest(secondTestCase01,secondTestSetup,"Test Group 02 Case 01");
    utest_startTest(secondTestCase02,secondTestSetup,"Test Group 02 Case 02");
    utest_printStatistics("Test Group 02");
    // End Group 02




}
