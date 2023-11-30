#include "pch.h"
#include "CppUnitTest.h"
#include "../PR9_2/PR9_2_a.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest92A
{
	TEST_CLASS(UnitTest92A)
	{
	public:
		
        TEST_METHOD(TestMethod1)
        {
            const int N = 1;
            Student students[N];

            students[0].physicm = 5.0;
            students[0].mathm = 5.0;
            students[0].itm = 5.0;

            double result = SearchProc(students, N);
            Assert::AreEqual(100.0, result, 0.000001);
        }

	};
}
