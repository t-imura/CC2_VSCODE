#include "pch.h"
#include "../Include/CC.h"
#include "../Include/MyClass.h"
#include "../Include/MyClass2.h"

class TestFixture : public testing::Test
{
protected:
	MyClass sampletestMyClass;
	MyClass2 sampletestMyClass2; 
	virtual void SetUp() {
		sampletestMyClass.initsettings();
		sampletestMyClass2.initsettings();
	}
};

TEST_F(TestFixture, Testadd)
{
	sampletestMyClass.add_result = sampletestMyClass.add(1, 1);
	EXPECT_EQ(sampletestMyClass.add_result, 2);
}

TEST_F(TestFixture, Testkake)
{
	sampletestMyClass.kake_result = sampletestMyClass.kake(4, 1);
	EXPECT_EQ(sampletestMyClass.kake_result, 4);
}

TEST_F(TestFixture, Testsub)
{
	sampletestMyClass2.sub_result = sampletestMyClass2.sub(4, 1);
	EXPECT_EQ(sampletestMyClass2.sub_result, 3);
}


int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}