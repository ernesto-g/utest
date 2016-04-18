/*
	utest : Unit test library for embedded C programs.
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
#include <stdio.h>
#include <stdlib.h>

char utest_printBuffer[256];
int utest_flagTestError;
int utest_lineTestError;
char* utest_fileTestError;
int utest_totalTestsCounter;
int utest_okTestsCounter;
int utest_varAux;

void utest_init(void)
{
	utest_totalTestsCounter=0;
	utest_okTestsCounter=0;
}

void utest_printStatistics(void)
{

	utest_print("\r\nUnit Tests Statistics\r\n");
	if(utest_totalTestsCounter>0)
	{
		int per = (int)(((float)utest_okTestsCounter/(float)utest_totalTestsCounter)*100.0);
		utest_print1("Tests OK : %d Percent.\r\n",per);
		utest_print2("Total Tests: \x1B[32m%d\x1B[0m\r\nFailed Tests: \x1B[31m%d\x1B[0m\r\n",utest_totalTestsCounter,(utest_totalTestsCounter-utest_okTestsCounter));
	}
	else
		utest_print("\x1B[31mNo tests executed.\x1B[0m\r\n");

}

void utest_startTest(void(*fncTest)(void),void(*fncBefore)(void),char* testName)
{
	if(fncTest!=0)
	{
	    utest_print("________________________________________\r\n");
		utest_flagTestError=0;
		utest_print1("TESTING:%s\r\n",testName);

		if(fncBefore!=0)
			fncBefore();
		utest_totalTestsCounter++;
		fncTest();
		if(utest_flagTestError==1)
		{
			utest_print2("TEST FAILED\r\n FILE:%s LINE:%d\r\n",utest_fileTestError,utest_lineTestError);
		}
		else
		{
			utest_print("TEST OK\r\n");
			utest_okTestsCounter++;
		}

	}
}

void utest_printStartTestingC(char* testName)
{

    utest_print("\r\n\r\n\x1B[34m********************************************************************\x1B[0m\r\n");
	utest_print1("\x1B[34m***********    Start Testing of: \x1B[36m%20s\x1B[34m   ************\x1B[0m\r\n",testName);
    utest_print("\x1B[34m********************************************************************\x1B[0m\r\n");

}
void utest_printStatisticsC(char* testName)
{

    utest_print("\x1B[34m********************************************************************\x1B[0m\r\n");
	utest_print1("\x1B[34m*******   Unit Tests Statistics: \x1B[36m%20s\x1B[34m   ************\x1B[0m\r\n",testName);
    utest_print("\x1B[34m********************************************************************\x1B[0m\r\n");

	if(utest_totalTestsCounter>0)
	{
		int per = (int)(((float)utest_okTestsCounter/(float)utest_totalTestsCounter)*100.0);
        utest_print("\x1B[34m**| Total Test  |  Succed Test  |  Failed Test  |  Effectiveness |**\x1B[0m\r\n");
       utest_print4("\x1B[34m**|    %3d      |      \x1B[32m%3d\x1B[34m      |      \x1B[31m%3d\x1B[34m      |     %3d perc.  |**\x1B[0m\r\n",utest_totalTestsCounter,utest_okTestsCounter,(utest_totalTestsCounter-utest_okTestsCounter),per);
	}
	else
		utest_print("\x1B[31mNo tests executed.\x1B[0m\r\n");

    utest_print("\x1B[34m********************************************************************\x1B[0m\r\n\r\n");
}

void utest_startTestC(void(*fncTest)(void),void(*fncBefore)(void),char* testName)
{
	if(fncTest!=0)
	{
	    utest_print("\x1B[30m--------------------------------------------------------------------\x1B[0m\r\n");
		utest_flagTestError=0;
		utest_print1("\x1B[34m%40-s\x1B[0m\r\n",testName);

		if(fncBefore!=0)
			fncBefore();
		utest_totalTestsCounter++;
		fncTest();
		if(utest_flagTestError==1)
		{
			utest_print2("\x1B[31mTEST FAILED\x1B[0m\r\n FILE:%s LINE:%d\r\n",utest_fileTestError,utest_lineTestError);
		}
		else
		{
			utest_print("\x1B[32mTEST OK\x1B[0m\r\n");
			utest_okTestsCounter++;
		}


	}
}



