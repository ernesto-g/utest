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
static int sector[] = {1,1,2,3,4,6};
static float salary[] = {1000,1000,2000,3000,4000,8000};
static int id[] = {11,20,3,4,9,99};

static employee arrayEmployees[LENGTH];

void firstTestSetup(void)
{
	utest_print("Setup...\r\n");

}

void firstTestCase01(void)
{
    int i;
    initEmployees(arrayEmployees, LENGTH);
    for (i=0;i < LENGTH;i++)
    {
        utest_assertEqualsIntMsg(arrayEmployees[i].isEmpty,1,"Error value in <.isEmpty> the correct value is: (1)");
    }

}
void firstTestCase02(void)
{
    int i;
    i = initEmployees(arrayEmployees, 0);
    utest_assertEqualsIntMsg(-1,i, "Error in return value <initEmployees> if ok the correct value to return is: (-1)");

}

void firstTestCase03(void)
{
    int i;
    i = initEmployees(NULL, LENGTH);
    utest_assertEqualsIntMsg(-1,i, "Error in return value <initEmployees> correct value to return is: (-1)");

}

