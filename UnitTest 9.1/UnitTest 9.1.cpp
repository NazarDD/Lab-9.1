#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 9.1/Lab 9.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace YourProjectTests
{
    TEST_CLASS(StudentFunctionsTest)
    {
    public:

        TEST_METHOD(TestCalculatePercentageWith45PhysicsGrade)
        {
            const int N = 3; 
            Student* students = new Student[N];

            students[0] = { 1, "Smith", 2, PC_Science, 4, 5, { 4 } };  
            students[1] = { 2, "Johnson", 3, IT, 5, 4, { 5 } }; 
            students[2] = { 3, "Williams", 1, Math_Economic, 3, 3, { 4 } }; 

            double result = CalculatePercentageWith45PhysicsGrade(students, N);
            double expected = 66.66666;

            Assert::AreEqual(result, expected, 0.01);
        }
    };
}
