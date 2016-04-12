#include <utest.h>
#include <stdio.h>
#include <stdlib.h>

void firstTestSetup(void)
{
	utest_print("Setup...\r\n");
}

void firstTestCase01(void)
{
	utest_assertEqualsInt(5,5);

}

void firstTestCase02(void)
{
    // Error
	utest_assertEqualsInt(4,5);

}

void firstTestCase03(void)
{
	utest_assertEqualsInt(5,5);

}
