
#include <utest.h>
#include <stdio.h>
#include <stdlib.h>


void secondTestSetup(void)
{
	utest_print("Setup...\r\n");
}

void secondTestCase01(void)
{
	utest_assertEqualsInt(5,5);

}

void secondTestCase02(void)
{
	utest_assertEqualsInt(5,5);

}
