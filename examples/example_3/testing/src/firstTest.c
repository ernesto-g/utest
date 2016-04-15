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
static char* sortedListUp[] = {"Xb","Xd","Ya","Yc","Za","Zb"};
static char* sortedListDown[] = {"Zb","Za","Yc","Ya","Xd","Xb"};

void firstTestSetup(void)
{
	utest_print("Setup...\r\n");
}

void firstTestCase01(void)
{
    int i;
    //sortNames(unsortedList, LENGTH, 1); // Thirth parameter at 1 indicate UP order
    for (i=0;i < LENGTH;i++)
    {
        utest_assertEqualsStringMsg(sortedListUp[i],unsortedList[i],2,"Error in UP order ");
    }

}

void firstTestCase02(void)
{
    int i;
   // sortNames(unsortedList, LENGTH, 0); // Thirth parameter at 1 indicate UP order
    for (i=0;i < LENGTH;i++)
    {
        utest_assertEqualsStringMsg(sortedListDown[i],unsortedList[i],2,"Error in DOWN order ");
    }


}

void firstTestCase03(void)
{
    int i;

    //i = sortNames(unsortedList, -1, 0); // Thirth parameter at 1 indicate UP order
    utest_assertEqualsIntMsg(-1,i, "Error with [-1] like length parameter");

}

void firstTestCase04(void)
{
    int i;

    //i = sortNames(unsortedList, 0, 0); // Thirth parameter at 1 indicate UP order
    utest_assertEqualsIntMsg(-1,i, "Error with [0] like length parameter");

}

void firstTestCase05(void)
{
    int i;

   // i = sortNames(unsortedList, 1, 0); // Thirth parameter at 1 indicate UP order
    utest_assertEqualsIntMsg(0,i, "Error correct length parameter");
}
