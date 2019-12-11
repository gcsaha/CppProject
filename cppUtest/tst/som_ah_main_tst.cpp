#include "CppUTest/TestHarness.h"
#include"som_ah_main.h"
TEST_GROUP(me_som_ah_main_test_group)
{
	void setup()
	{
	}

	void teardown()
	{
	}
};

TEST(me_som_ah_main_test_group, ut_ah_initialize)
{
	int xx;
	xx = getVal(6);
	CHECK(12 ==xx);
}

