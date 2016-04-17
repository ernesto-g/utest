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

#include "../inc/firstTest.h"
#include "../inc/secondTest.h"
#include "../inc/thirdTest.h"
#include "../inc/fourthTest.h"
#include "../inc/fifthTest.h"

void startTesting(int testGroup)
{


    switch(testGroup)
    {
        case 1:
            // Start Group 01
            utest_print("\nStarting testings of initEmployees()...\r\n\n");
            utest_init();
            utest_startTest(firstTestCase01,firstTestSetup," Case[Return of Array Init]");
            utest_startTest(firstTestCase02,firstTestSetup," Case[Return of init Employees array with NULL pointer to array]");
            utest_startTest(firstTestCase03,firstTestSetup," Case[Return of init Employees array with invalid array length]");
            utest_printStatistics();
            // End Group 01
            break;

        case 2:
            // Start Group 02
            utest_print("\nStarting testings of addEmployees()...\r\n\n");
            utest_init();
            utest_startTest(secondTestCase01,secondTestSetup," Case[Return of add Employees]");
            utest_startTest(secondTestCase02,secondTestSetup," Case[Content of added Employees]");
            utest_startTest(secondTestCase03,secondTestSetup," Case[Return of add Employees without space empty]");
            utest_startTest(secondTestCase04,secondTestSetup," Case[Return of add Employees with NULL pointer to array]");
            utest_startTest(secondTestCase05,secondTestSetup," Case[Return of add Employees with invalid array length]");
            utest_printStatistics();
            // End Group 02
            break;

        case 3:
            // Start Group 03
            utest_print("\nStarting testings of findEmployeeById()...\r\n\n");
            utest_init();
            utest_startTest(thirdTestCase01,thirdTestSetup," Case[Return when found a Employee]");
            utest_startTest(thirdTestCase02,thirdTestSetup," Case[Content of founded Employee]");
            utest_startTest(thirdTestCase03,thirdTestSetup," Case[Return of find Employee with NULL pointer to array]");
            utest_startTest(thirdTestCase04,thirdTestSetup," Case[Return of find Employee with invalid array length]");
            utest_printStatistics();
            // End Group 03
            break;

        case 4:
            // Start Group 04
            utest_print("\nStarting testings of findEmployeeById()...\r\n\n");
            utest_init();
            utest_startTest(fourthTestCase01,fourthTestSetup," Case[Return when remove a Employee]");
            utest_startTest(fourthTestCase02,fourthTestSetup," Case[Content of removed Employee]");
            utest_startTest(fourthTestCase03,fourthTestSetup," Case[Return of remove Employee with NULL pointer to array]");
            utest_startTest(fourthTestCase04,fourthTestSetup," Case[Return of remove Employee with invalid array length]");
            utest_printStatistics();
            // End Group 04
            break;

        case 5:
            // Start Group 05
            utest_print("\nStarting testings of sortEmployeeByName()...\r\n\n");
            utest_init();
            utest_startTest(fifthTestCase01,fifthTestSetup," Case[Return when sort a Employees array]");
            utest_startTest(fifthTestCase02,fifthTestSetup," Case[Content of sorted a Employees array UP]");
            utest_startTest(fifthTestCase02,fifthTestSetup," Case[Content of sorted a Employees array DOWN]");
            utest_startTest(fifthTestCase03,fifthTestSetup," Case[Return of sorted a Employees array with NULL pointer to array]");
            utest_startTest(fifthTestCase04,fifthTestSetup," Case[Return of sorted a Employees array with invalid array length]");
            utest_printStatistics();
            // End Group 05
            break;

    }


}
