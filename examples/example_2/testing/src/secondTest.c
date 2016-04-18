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

//INCLUDE LIBRARY TO TEST
#include "../../inc/array.h"

//DEFINES OF THIS TEST
#define LENGTH 6

static char* unsortedList[] = {"Za","Zb","Xd","Xb","Ya","Yc"};


void secondTestSetup(void)
{
	utest_print("Setup...\r\n");
}

void secondTestCase01(void)
{
    int i;
    i = findName(unsortedList, LENGTH, "Xd");
    utest_assertEqualsInt(2,i);
}

void secondTestCase02(void)
{
    int i;
    i = findName(unsortedList, LENGTH, "Rd");
    utest_assertEqualsInt(-1,i);
}

void secondTestCase03(void)
{
    int i;
    i = findName(unsortedList, -1, "Xd");
    utest_assertEqualsInt(-1,i);
    i = findName(unsortedList, 0, "Xd");
    utest_assertEqualsInt(-1,i);

}
