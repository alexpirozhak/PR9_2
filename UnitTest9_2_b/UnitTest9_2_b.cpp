#include "pch.h"
#include "CppUnitTest.h"
#include "../PR9_2_b/PR9_2_b.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest92b
{
	TEST_CLASS(UnitTest92b)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			
				Student st;
				st.spec = KN;
				st.physicm = 90.0;
				st.mathm = 80.0;
				st.pedagogs = 70.0;
				int N = 1;

				double result = Average(st, N);
				Assert::AreEqual(80.0, result);
			
		}
	};
}
