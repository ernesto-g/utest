/*
    utest : Unit test library for embedded C programs.
    Copyright (C) <2016>  <Ernesto Gigliotti>
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

#ifndef UTEST_H
#define UTEST_H

// Redefine this macros for specified architecture
#define utest_print(MSG)     printf(MSG)
#define utest_print1(MSG,VAR1)   { sprintf(utest_printBuffer,MSG,VAR1); printf(utest_printBuffer);}
#define utest_print2(MSG,VAR1,VAR2)  { sprintf(utest_printBuffer,MSG,VAR1,VAR2); printf(utest_printBuffer);}
//________________________________________________

#define utest_assertEqualsInt(A,B){ if(A!=B){ utest_print2("assert equals failed '%d' != '%d'\r\n",A,B); utest_flagTestError=1; utest_lineTestError = __LINE__;  utest_fileTestError = __FILE__;return; } }
#define utest_assertEqualsFloat(A,B){ if(A!=B){ utest_print2("assert equals failed '%f' != '%f'\r\n",(double)A,(double)B); utest_flagTestError=1; utest_lineTestError = __LINE__;  utest_fileTestError = __FILE__;return; } }
#define utest_assertEqualsPointer(A,B){ if(A!=B){ utest_print2("assert equals failed '0x%x' != '0x%x'\r\n",A,B); utest_flagTestError=1; utest_lineTestError = __LINE__;  utest_fileTestError = __FILE__;return; } }

#define utest_assertNotEqualsInt(A,B){ if(A==B){ utest_print2("assert not equals failed '%d' != '%d'\r\n",A,B); utest_flagTestError=1; utest_lineTestError = __LINE__;  utest_fileTestError = __FILE__;return; } }
#define utest_assertNotEqualsFloat(A,B){ if(A==B){ utest_print2("assert not equals failed '%f' != '%f'\r\n",(double)A,(double)B); utest_flagTestError=1; utest_lineTestError = __LINE__;  utest_fileTestError = __FILE__;return; $
#define utest_assertNotEqualsPointer(A,B){ if(A==B){ utest_print2("assert not equals failed '0x%x' != '0x%x'\r\n",A,B); utest_flagTestError=1; utest_lineTestError = __LINE__;  utest_fileTestError = __FILE__;return; } }

#define utest_assertNull(A){ if(A!=0){ utest_print1("assert null failed. Value: '0x%x' \r\n",A); utest_flagTestError=1; utest_lineTestError = __LINE__;  utest_fileTestError = __FILE__;return; } }
#define utest_assertNotNull(A){ if(A==0){ utest_print1("assert not null failed. Value: '0x%x' \r\n",A); utest_flagTestError=1; utest_lineTestError = __LINE__;  utest_fileTestError = __FILE__;return; } }

#define utest_assertEqualsString(A,B,S) \
{										\
	utest_varAux=0;						\
	while(utest_varAux<S)							\
	{									\
		if(A[utest_varAux]!=B[utest_varAux])	\
		{										\
			utest_print2("assert equals string. Value: '%s' != '%s' \r\n",A,B); utest_flagTestError=1; utest_lineTestError = __LINE__;  utest_fileTestError = __FILE__;return;	\
		}										\
		utest_varAux++;							\
	}											\
}

//-------utest_assert---with---message-------

#define utest_assertEqualsIntMsg(A,B,C){ if(A!=B){ utest_print2("assert equals failed '%d' != '%d'\r\n",A,B);utest_print1("%s\r\n",C); utest_flagTestError=1; utest_lineTestError = __LINE__;  utest_fileTestError = __FILE__;return; } }
#define utest_assertEqualsFloatMsg(A,B,C){ if(A!=B){ utest_print2("assert equals failed '%f' != '%f'\r\n",(double)A,(double)B); utest_print1("%s\r\n",C); utest_flagTestError=1; utest_lineTestError = __LINE__;  utest_fileTestError = __FILE__;return; } }
#define utest_assertEqualsPointerMsg(A,B,C){ if(A!=B){ utest_print2("assert equals failed '0x%x' != '0x%x'\r\n",A,B);utest_print1("%s\r\n",C); utest_flagTestError=1; utest_lineTestError = __LINE__;  utest_fileTestError = __FILE__;return; } }

#define utest_assertNotEqualsIntMsg(A,B,C){ if(A==B){ utest_print2("assert not equals failed '%d' != '%d'\r\n",A,B); utest_print1("%s\r\n",C); utest_flagTestError=1; utest_lineTestError = __LINE__;  utest_fileTestError = __FILE__;return; } }
#define utest_assertNotEqualsFloatMsg(A,B,C){ if(A==B){ utest_print2("assert not equals failed '%f' != '%f'\r\n",(double)A,(double)B); utest_print1("%s\r\n",C); utest_flagTestError=1; utest_lineTestError = __LINE__;  utest_fileTestError = __FILE__;return; $
#define utest_assertNotEqualsPointerMsg(A,B,C){ if(A==B){ utest_print2("assert not equals failed '0x%x' != '0x%x'\r\n",A,B); utest_print1("%s\r\n",B); utest_flagTestError=1; utest_lineTestError = __LINE__;  utest_fileTestError = __FILE__;return; } }

#define utest_assertNullMsg(A,B){ if(A!=0){ utest_print1("assert null failed. Value: '0x%x' \r\n",A); utest_print1("%s\r\n",B); utest_flagTestError=1; utest_lineTestError = __LINE__;  utest_fileTestError = __FILE__;return; } }
#define utest_assertNotNullMsg(A,B){ if(A==0){ utest_print1("assert not null failed. Value: '0x%x' \r\n",A); utest_print1("%s\r\n",B); utest_flagTestError=1; utest_lineTestError = __LINE__;  utest_fileTestError = __FILE__;return; } }

#define utest_assertEqualsStringMsg(A,B,S,C) \
{										\
	utest_varAux=0;						\
	while(utest_varAux<S)							\
	{									\
		if(A[utest_varAux]!=B[utest_varAux])	\
		{										\
			utest_print2("assert equals string. Value: '%s' != '%s' \r\n",A,B); utest_print1("%s\r\n",C); utest_flagTestError=1; utest_lineTestError = __LINE__;  utest_fileTestError = __FILE__;return;	\
		}										\
		utest_varAux++;							\
	}											\
}

extern char utest_printBuffer[256];
extern int utest_flagTestError;
extern int utest_lineTestError;
extern char* utest_fileTestError;
extern int utest_totalTestsCounter;
extern int utest_okTestsCounter;
extern int utest_varAux;

void utest_startTest(void(*fncTest)(void),void(*fncBefore)(void),char* testName);

void utest_init(void);

void utest_printStatistics(void);

#endif

