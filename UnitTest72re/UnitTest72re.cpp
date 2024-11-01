#include "pch.h"
#include "CppUnitTest.h"
#include "../lab72re/lab72re.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest72re
{
	TEST_CLASS(UnitTest72re)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            int testMatrix[4][5] = {
                {10, 20, 30, 40, 50}, 
                {5, 15, 25, 35, 45},  
                {7, 14, 21, 28, 35},  
                {1, 2, 3, 4, 5}       
            };

            
            int expected = 35; 

            
            int result = findMinOfMaxInEvenRows(&testMatrix[0][0], 4, 5, 0, INT_MAX);

            
            Assert::AreEqual(expected, result);
		}
	};
}
