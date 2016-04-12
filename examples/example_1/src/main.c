/*
    utest example : Unit test library for embedded C programs.
    Copyright (C) <2016>  <Ernesto Gigliotti>

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

#include "utest.h"
#include "utest.c"


void testSetup(void)
{
	utest_print("Setup...\r\n");
}

void testCase(void)
{
	utest_assertEqualsInt(5,5);
}

void startTesting(void)
{
    utest_print("starting testings...\r\n");

	utest_init();

	utest_startTest(testCase,testSetup,"Test Case 1");
	//...

	utest_printStatistics();
}

void main(void)
{
	startTesting();
}
