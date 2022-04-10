//
// Created by matan on 05/04/2022.
//

#include "doctest.h"
#include "sources/Matrix.hpp"
#include <sstream>

using namespace std;
using namespace zich;

TEST_CASE("Arithmetic operations")
{
            SUBCASE("+ operator: good")
    {
        vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
        Matrix matrix1{vec1, 3, 3};
        Matrix check1 = matrix1 + matrix1;
        vector<double> ans_vec1 = {2, 0, 0, 0, 2, 0, 0, 0, 2};
        Matrix ans1{ans_vec1,3,3};
        bool check = check1 == ans1;
                CHECK(check == true);
        vector<double> vec2 = {-1, 0, 0, 0, -1, 0, 0, 0, -1};
        Matrix matrix2{vec2,3,3};
        Matrix check2 = matrix1 + matrix2;
        Matrix check3 = matrix2 + matrix1;
        vector<double> ans_vec2 = {0, 0, 0, 0, 0, 0, 0, 0, 0};
        Matrix ans2{ans_vec2,3,3};
        check = check2 == ans2;
                CHECK(check == true);
        check = check3 == ans2;
                CHECK(check == true);
        vector<double> vec3 = {-1, 1, 1, 1, -1, 1, 1, 1, -1};
        Matrix matrix3{vec3,3,3};
        Matrix check4 = matrix1 + matrix3;
        Matrix check5 = matrix3 + matrix1;
        vector<double> ans_vec3 = {0, 1, 1, 1, 0, 1, 1, 1, 0};
        Matrix ans3{ans_vec3,3,3};
        check = check4 == ans3;
                CHECK(check == true);
        check = check5 == ans3;
                CHECK(check == true);
    }

            SUBCASE("+ operator: bad")
    {
        vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0};
        Matrix matrix1{vec1, 2, 5};
        Matrix matrix2{ vec1, 5, 2};
        CHECK_THROWS(matrix1+matrix2);
        CHECK_THROWS(matrix2+matrix1);
        vector<double> vec2 = {1, 0, 0, 1, 0, 1, 1, 0};
        Matrix matrix3{vec2, 2, 4};
        Matrix matrix4{vec2, 8, 1};
        CHECK_THROWS(matrix1+matrix3);
        CHECK_THROWS(matrix3+matrix1);
        CHECK_THROWS(matrix3+matrix2);
        CHECK_THROWS(matrix3+matrix4);
        CHECK_THROWS(matrix4+matrix3);
    }

            SUBCASE("+= operator: good")
    {
        vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
        Matrix matrix1{vec1, 3, 3};
        matrix1 += matrix1;
        vector<double> ans_vec1 = {2, 0, 0, 0, 2, 0, 0, 0, 2};
        Matrix ans1{ans_vec1,3,3};
                CHECK_EQ(matrix1 == ans1, true);
        vector<double> vec2 = {-1, 0, 0, 0, -1, 0, 0, 0, -1};
        Matrix matrix2{vec2,3,3};
        matrix2 += matrix1;
        Matrix ans2{vec1,3,3};
                CHECK_EQ(matrix2 == ans2, true);
        vector<double> vec3 = {-1, 1, 1, 1, -1, 1, 1, 1, -1};
        Matrix matrix3{vec3,3,3};
        matrix3 += matrix2;
        vector<double> ans_vec2 = {0, 1, 1, 1, 0, 1, 1, 1, 0};
        Matrix ans3{ans_vec2,3,3};
                CHECK_EQ(matrix3 == ans3, true);
    }

            SUBCASE("+= operator: bad")
    {
        vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0};
        Matrix matrix1{vec1, 2, 5};
        Matrix matrix2{ vec1, 5, 2};
        CHECK_THROWS(matrix1+=matrix2);
        CHECK_THROWS(matrix2+=matrix1);
        vector<double> vec2 = {1, 0, 0, 1, 0, 1, 1, 0};
        Matrix matrix3{vec2, 2, 4};
        Matrix matrix4{vec2, 8, 1};
        CHECK_THROWS(matrix1+=matrix3);
        CHECK_THROWS(matrix3+=matrix1);
        CHECK_THROWS(matrix3+=matrix2);
        CHECK_THROWS(matrix3+=matrix4);
        CHECK_THROWS(matrix4+=matrix3);
    }

            SUBCASE("- operator: good")
    {
        vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
        Matrix matrix1{vec1, 3, 3};
        Matrix check1 = matrix1 - matrix1;
        vector<double> ans_vec1 = {0, 0, 0, 0, 0, 0, 0, 0, 0};
        Matrix ans1{ans_vec1,3,3};
                CHECK_EQ(check1 == ans1, true);
        vector<double> vec2 = {-1, 0, 0, 0, -1, 0, 0, 0, -1};
        Matrix matrix2{vec2,3,3};
        Matrix check2 = matrix1 - matrix2;
        Matrix check3 = matrix2 - matrix1;
        vector<double> ans_vec2 = {2, 0, 0, 0, 2, 0, 0, 0, 2};
        vector<double> ans_vec3 = {-2, 0, 0, 0, -2, 0, 0, 0, -2};
        Matrix ans2{ans_vec2,3,3};
        Matrix ans3{ans_vec3,3,3};
                CHECK_EQ(check2 == ans2, true);
                CHECK_EQ(check3 == ans3, true);
        vector<double> vec3 = {-1, 1, 1, 1, -1, 1, 1, 1, -1};
        Matrix matrix3{vec3,3,3};
        Matrix check4 = matrix1 - matrix3;
        Matrix check5 = matrix3 - matrix1;
        vector<double> ans_vec4 = {2, -1, -1, -1, 2, -1, -1, -1, 2};
        Matrix ans4{ans_vec4,3,3};
                CHECK_EQ(check4 == ans4, true);
        vector<double> ans_vec5 = {-2, 1, 1, 1, -2, 1, 1, 1, -2};
        Matrix ans5{ans_vec5,3,3};
                CHECK_EQ(check5 == ans5, true);
    }

            SUBCASE("- operator: bad")
    {
        vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0};
        Matrix matrix1{vec1, 2, 5};
        Matrix matrix2{ vec1, 5, 2};
        CHECK_THROWS(matrix1-matrix2);
        CHECK_THROWS(matrix2-matrix1);
        vector<double> vec2 = {1, 0, 0, 1, 0, 1, 1, 0};
        Matrix matrix3{vec2, 2, 4};
        Matrix matrix4{vec2, 8, 1};
        CHECK_THROWS(matrix1-matrix3);
        CHECK_THROWS(matrix3-matrix1);
        CHECK_THROWS(matrix3-matrix2);
        CHECK_THROWS(matrix3-matrix4);
        CHECK_THROWS(matrix4-matrix3);
    }

            SUBCASE("-= operator: good")
    {
        vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
        Matrix matrix1{vec1, 3, 3};
        matrix1 -= matrix1;
        vector<double> ans_vec1 = {0, 0, 0, 0, 0, 0, 0, 0, 0};
        Matrix ans1{ans_vec1,3,3};
                CHECK_EQ(matrix1 == ans1, true);
        vector<double> vec2 = {-1, 0, 0, 0, -1, 0, 0, 0, -1};
        Matrix matrix2{vec2,3,3};
        matrix1 -= matrix2;
        Matrix ans2{vec1,3,3};
                CHECK_EQ(matrix1 == ans2, true);
        vector<double> vec3 = {-1, 1, 1, 1, -1, 1, 1, 1, -1};
        Matrix matrix3{vec3,3,3};
        matrix3 -= matrix1;
        vector<double> ans_vec4 = {-2, 1, 1, 1, -2, 1, 1, 1, -2};
        Matrix ans4{ans_vec4,3,3};
                CHECK_EQ(matrix3 == ans4, true);
    }

            SUBCASE("-= operator: bad")
    {
        vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0};
        Matrix matrix1{vec1, 2, 5};
        Matrix matrix2{ vec1, 5, 2};
        CHECK_THROWS(matrix1-=matrix2);
        CHECK_THROWS(matrix2-=matrix1);
        vector<double> vec2 = {1, 0, 0, 1, 0, 1, 1, 0};
        Matrix matrix3{vec2, 2, 4};
        Matrix matrix4{vec2, 8, 1};
        CHECK_THROWS(matrix1-=matrix3);
        CHECK_THROWS(matrix3-=matrix1);
        CHECK_THROWS(matrix3-=matrix2);
        CHECK_THROWS(matrix3-=matrix4);
        CHECK_THROWS(matrix4-=matrix3);
    }

            SUBCASE("+ (unari) operator")
    {
        vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
        Matrix matrix1{vec1, 3, 3};
        Matrix check1 = +matrix1;
                CHECK_EQ(matrix1 == check1, true);
        vector<double> vec2 = {-1, 1, 2, -3, -4, 10, 1, 7};
        Matrix matrix2{vec2,2,4};
        Matrix check2 = +matrix2;
                CHECK_EQ(matrix2 == check2, true);
    }

            SUBCASE("- (unari) operator")
    {
        vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
        Matrix matrix1{vec1, 3, 3};
        Matrix check1 = -matrix1;
                CHECK_NE(matrix1 == check1, true);
        matrix1 *= -1;
                CHECK_EQ(matrix1 == check1, true);
        vector<double> vec2 = {-1, 1, 2, -3, -4, 10, 1, 7};
        Matrix matrix2{vec2,2,4};
        Matrix check2 = -matrix2;
                CHECK_NE(matrix2 == check2, true);
        matrix2 *= -1;
                CHECK_EQ(matrix2 == check2, true);
    }

            SUBCASE("++ (postfix) operator")
    {
        vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
        Matrix matrix1{vec1, 3, 3};
        Matrix mat_check = (matrix1++)++;
        vector<double> ans_vec1 = {2, 1, 1, 1, 2, 1, 1, 1, 2};
        Matrix ans1{ans_vec1,3,3};
        Matrix check_ans{vec1, 3, 3};
                CHECK_EQ(matrix1 == ans1, true);
                CHECK_EQ(mat_check == check_ans, true);
        vector<double> vec2 = {-1, 0, 0, 0, -1, 0, 0, 0, -1};
        Matrix matrix2{vec2,3,3};
        matrix2++;
        vector<double> ans_vec2 = {0, 1, 1, 1, 0, 1, 1, 1, 0};
        Matrix ans2{ans_vec2,3,3};
                CHECK_EQ(matrix2 == ans2, true);
        vector<double> vec3 = {-1, 1, 1, 1, -1, 1, 1, 1, -1};
        Matrix matrix3{vec3,3,3};
        Matrix matrix4 = matrix3;
        matrix3++;
        vector<double> ans_vec3 = {0, 2, 2, 2, 0, 2, 2, 2, 0};
        Matrix ans3{ans_vec3,3,3};
                CHECK_EQ(matrix3 == ans3, true);
                CHECK_NE(matrix3 == matrix4, true);
    }

            SUBCASE("++ (prefix) operator")
    {
        vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
        Matrix matrix1{vec1, 3, 3};
        Matrix mat_check = (++matrix1)++;
        vector<double> ans_vec1 = {3, 2, 2, 2, 3, 2, 2, 2, 3};
        vector<double> check_vec = {2, 1, 1, 1, 2, 1, 1, 1, 2};
        Matrix ans1{ans_vec1,3,3};
        Matrix check_ans{check_vec, 3, 3};
                CHECK_EQ(matrix1 == ans1, true);
                CHECK_EQ(mat_check == check_ans, true);
        vector<double> vec2 = {-1, 0, 0, 0, -1, 0, 0, 0, -1};
        Matrix matrix2{vec2,3,3};
        ++matrix2;
        vector<double> ans_vec2 = {0, 1, 1, 1, 0, 1, 1, 1, 0};
        Matrix ans2{ans_vec2,3,3};
                CHECK_EQ(matrix2 == ans2, true);
        vector<double> vec3 = {-1, 1, 1, 1, -1, 1, 1, 1, -1};
        Matrix matrix3{vec3,3,3};
        Matrix matrix4 = matrix3;
        ++(++matrix3);
        vector<double> ans_vec3 = {1, 3, 3, 3, 1, 3, 3, 3, 1};
        Matrix ans3{ans_vec3,3,3};
                CHECK_EQ(matrix3 == ans3, true);
                CHECK_NE(matrix3 == matrix4, true);
    }

            SUBCASE("-- (postfix) operator")
    {
        vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
        Matrix matrix1{vec1, 3, 3};
        matrix1--;
        vector<double> ans_vec1 = {0, -1, -1, -1, 0, -1, -1, -1, 0};
        Matrix ans1{ans_vec1,3,3};
                CHECK_EQ(matrix1 == ans1, true);
        vector<double> vec2 = {-1, 0, 0, 0, -1, 0, 0, 0, -1};
        Matrix matrix2{vec2,3,3};
        matrix2--;
        vector<double> ans_vec2 = {-2, -1, -1, -1, -2, -1, -1, -1, -2};
        Matrix ans2{ans_vec2,3,3};
                CHECK_EQ(matrix2 == ans2, true);
        vector<double> vec3 = {-1, 1, 1, 1, -1, 1, 1, 1, -1};
        Matrix matrix3{vec3,3,3};
        Matrix matrix4 = matrix3;
        matrix3--;
        vector<double> ans_vec3 = {-2, 0, 0, 0, -2, 0, 0, 0, -2};
        Matrix ans3{ans_vec3,3,3};
                CHECK_EQ(matrix3 == ans3, true);
                CHECK_NE(matrix3 == matrix4, true);
    }

            SUBCASE("-- (prefix) operator")
    {
        vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
        Matrix matrix1{vec1, 3, 3};
        Matrix mat_check = (--matrix1)--;
        vector<double> ans_vec1 = {-1, -2, -2, -2, -1, -2, -2, -2, -1};
        vector<double> check_vec = {0, -1, -1, -1, 0, -1, -1, -1, 0};
        Matrix ans1{ans_vec1,3,3};
        Matrix check_ans{check_vec, 3, 3};
                CHECK_EQ(matrix1 == ans1, true);
                CHECK_EQ(mat_check == check_ans, true);
        vector<double> vec2 = {-1, 0, 0, 0, -1, 0, 0, 0, -1};
        Matrix matrix2{vec2,3,3};
        --matrix2;
        vector<double> ans_vec2 = {-2, -1, -1, -1, -2, -1, -1, -1, -2};
        Matrix ans2{ans_vec2,3,3};
                CHECK_EQ(matrix2 == ans2, true);
        vector<double> vec3 = {-1, 1, 1, 1, -1, 1, 1, 1, -1};
        Matrix matrix3{vec3,3,3};
        Matrix matrix4 = matrix3;
        --(--matrix3);
        vector<double> ans_vec3 = {-3, -1, -1, -1, -3, -1, -1, -1, -3};
        Matrix ans3{ans_vec3,3,3};
                CHECK_EQ(matrix3 == ans3, true);
                CHECK_NE(matrix3 == matrix4, true);
    }

            SUBCASE("matrix * num operator")
    {
        vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
        Matrix matrix1{vec1, 3, 3};
        matrix1 = matrix1*2;
        vector<double> ans_vec1 = {2, 0, 0, 0, 2, 0, 0, 0, 2};
        Matrix ans1{ans_vec1,3,3};
                CHECK_EQ(matrix1 == ans1, true);
        vector<double> vec2 = {-1, 0, 0, 0, -1, 0, 0, 0, -1};
        Matrix matrix2{vec2,3,3};
        matrix2 = matrix2*1;
        Matrix ans2{vec2,3,3};
                CHECK_EQ(matrix2 == ans2, true);
        vector<double> vec3 = {-1, 1, 1, 1, -1, 1, 1, 1, -1};
        Matrix matrix3{vec3,3,3};
        Matrix matrix4 = matrix3;
        matrix3 = matrix3 * -1;
        vector<double> ans_vec3 = {1, -1, -1, -1, 1, -1, -1, -1, 1};
        Matrix ans3{ans_vec3,3,3};
                CHECK_EQ(matrix3 == ans3, true);
                CHECK_NE(matrix3 == matrix4, true);
    }

            SUBCASE("matrix *= num operator")
    {
        vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
        Matrix matrix1{vec1, 3, 3};
        matrix1 *= 2;
        vector<double> ans_vec1 = {2, 0, 0, 0, 2, 0, 0, 0, 2};
        Matrix ans1{ans_vec1,3,3};
                CHECK_EQ(matrix1 == ans1, true);
        vector<double> vec2 = {-1, 0, 0, 0, -1, 0, 0, 0, -1};
        Matrix matrix2{vec2,3,3};
        matrix2 *= 1;
        Matrix ans2{vec2,3,3};
                CHECK_EQ(matrix2 == ans2, true);
        vector<double> vec3 = {-1, 1, 1, 1, -1, 1, 1, 1, -1};
        Matrix matrix3{vec3,3,3};
        Matrix matrix4 = matrix3;
        matrix3 *= -1;
        vector<double> ans_vec3 = {1, -1, -1, -1, 1, -1, -1, -1, 1};
        Matrix ans3{ans_vec3,3,3};
                CHECK_EQ(matrix3 == ans3, true);
                CHECK_NE(matrix3 == matrix4, true);
    }

            SUBCASE("num * matrix operator")
    {
        vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
        Matrix matrix1{vec1, 3, 3};
        matrix1 = 2*matrix1;
        vector<double> ans_vec1 = {2, 0, 0, 0, 2, 0, 0, 0, 2};
        Matrix ans1{ans_vec1,3,3};
                CHECK_EQ(matrix1 == ans1, true);
        vector<double> vec2 = {-1, 0, 0, 0, -1, 0, 0, 0, -1};
        Matrix matrix2{vec2,3,3};
        matrix2 = 1*matrix2;
        Matrix ans2{vec2,3,3};
                CHECK_EQ(matrix2 == ans2, true);
        vector<double> vec3 = {-1, 1, 1, 1, -1, 1, 1, 1, -1};
        Matrix matrix3{vec3,3,3};
        Matrix matrix4 = matrix3;
        matrix3 = -1*matrix3;
        vector<double> ans_vec3 = {1, -1, -1, -1, 1, -1, -1, -1, 1};
        Matrix ans3{ans_vec3,3,3};
                CHECK_EQ(matrix3 == ans3, true);
                CHECK_NE(matrix3 == matrix4, true);
    }

            SUBCASE("matrix * matrix operator: good")
    {
        vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
        Matrix matrix1{vec1, 3, 3};
        Matrix check1 = matrix1 * matrix1;
                CHECK_EQ(check1 == matrix1, true);
        vector<double> vec2 = {-1, 0, 0, 0, -1, 0, 0, 0, -1};
        Matrix matrix2{vec2,3,3};
        Matrix check2 = matrix1 * matrix2;
        Matrix check3 = matrix2 * matrix1;
                CHECK_EQ(check2 == matrix2, true);
                CHECK_EQ(check3 == matrix2, true);
        vector<double> vec3 = {-1, 1, 2, -3, -4, 10, 1, 7};
        Matrix matrix3{vec3,2,4};
        Matrix matrix4{vec3,4,2};
        Matrix check4 = matrix3 * matrix4;
        Matrix check5 = matrix4 * matrix3;
        vector<double> ans_vec4 = {-8, -5, 27, 25};
        Matrix ans4{ans_vec4,2,2};
                CHECK_EQ(check4 == ans4, true);
        vector<double> ans_vec5 = {-3, 9, -1, 10, 10, -28, 1, -27, -36, 96, 2, 82, -29, 71, 9, 46};
        Matrix ans5{ans_vec5,4,4};
                CHECK_EQ(check5 == ans5, true);
    }

            SUBCASE("matrix * matrix operator: bad")
    {
        vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0};
        Matrix matrix1{vec1, 2, 5};
        Matrix matrix2{ vec1, 1, 10};
        CHECK_THROWS(matrix1 * matrix1);
        CHECK_THROWS(matrix2 * matrix2);
        CHECK_THROWS(matrix1 * matrix2);
        CHECK_THROWS(matrix2 * matrix1);
        vector<double> vec2 = {1, 0, 0, 1, 0, 1, 1, 0};
        Matrix matrix3{vec2, 2, 4};
        Matrix matrix4{vec2, 8, 1};
        CHECK_THROWS(matrix1 * matrix3);
        CHECK_THROWS(matrix3 * matrix2);
        CHECK_THROWS(matrix3 * matrix4);
        CHECK_THROWS(matrix4 * matrix3);
    }

            SUBCASE("matrix *= matrix operator: good")
    {
        vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
        Matrix matrix1{vec1, 3, 3};
        Matrix check1 = matrix1;
        matrix1 *= matrix1;
                CHECK_EQ(check1 == matrix1, true);
        vector<double> vec2 = {-1, 0, 0, 0, -1, 0, 0, 0, -1};
        Matrix matrix2{vec2,3,3};
        matrix1 *= matrix2;
                CHECK_EQ(matrix1 == matrix2, true);
        vector<double> vec3 = {-1, 1, 2, -3, -4, 10, 1, 7};
        Matrix matrix3{vec3,2,4};
        Matrix matrix4{vec3,4,2};
        matrix3 *= matrix4;
        vector<double> ans_vec2 = {-8, -5, 27, 25};
        Matrix check2{ans_vec2,2,2};
                CHECK_EQ(matrix3 == check2, true);
    }

            SUBCASE("matrix *= matrix operator: bad")
    {
        vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0};
        Matrix matrix1{vec1, 2, 5};
        Matrix matrix2{ vec1, 1, 10};
        CHECK_THROWS(matrix1 *= matrix1);
        CHECK_THROWS(matrix2 *= matrix2);
        CHECK_THROWS(matrix1 *= matrix2);
        CHECK_THROWS(matrix2 *= matrix1);
        vector<double> vec2 = {1, 0, 0, 1, 0, 1, 1, 0};
        Matrix matrix3{vec2, 2, 4};
        Matrix matrix4{vec2, 8, 1};
        CHECK_THROWS(matrix1 *= matrix3);
        CHECK_THROWS(matrix3 *= matrix2);
        CHECK_THROWS(matrix3 *= matrix4);
        CHECK_THROWS(matrix4 *= matrix3);
    }
}

TEST_CASE("Comparison operations")
{
            SUBCASE("> operator: good")
    {
        vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
        Matrix matrix1{vec1, 3, 3};
        Matrix check1 = matrix1 + matrix1;
                CHECK_EQ(check1 > matrix1, true);
        vector<double> vec3 = {-1, 0, 0, 0, -1, 0, 0, 0, -1};
        Matrix matrix3{vec3,3,3};
                CHECK_NE(matrix3 > matrix1, true);
        vector<double> vec4 = {0, 0, 0, 0, 0, 0, 0, 0, 0};
        Matrix matrix4{vec4,3,3};
                CHECK_EQ(matrix4 > matrix3, true);
        vector<double> vec5 = {1, 1 ,1 ,0 ,0 ,0 ,0, 0, 0};
        Matrix matrix5{vec5, 3, 3};
                CHECK_NE(matrix1 > matrix5, true);
                CHECK_NE(matrix5 > matrix1, true);
    }

            SUBCASE("> operator: bad")
    {
        vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0};
        Matrix matrix1{vec1, 2, 5};
        Matrix matrix2{ vec1, 5, 2};
        CHECK_THROWS(bool check = matrix1>matrix2);
        CHECK_THROWS(bool check = matrix2>matrix1);
        vector<double> vec2 = {1, 0, 0, 1, 0, 1, 1, 0};
        Matrix matrix3{vec2, 2, 4};
        Matrix matrix4{vec2, 8, 1};
        CHECK_THROWS(bool check = matrix1>matrix3);
        CHECK_THROWS(bool check = matrix3>matrix1);
        CHECK_THROWS(bool check = matrix3>matrix2);
        CHECK_THROWS(bool check = matrix3>matrix4);
        CHECK_THROWS(bool check = matrix4>matrix3);
    }

            SUBCASE(">= operator: good")
    {
        vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
        Matrix matrix1{vec1, 3, 3};
        Matrix check1 = matrix1 + matrix1;
                CHECK_EQ(check1 >= matrix1, true);
        vector<double> vec3 = {-1, 0, 0, 0, -1, 0, 0, 0, -1};
        Matrix matrix3{vec3,3,3};
                CHECK_NE(matrix3 >= matrix1, true);
        vector<double> vec4 = {0, 0, 0, 0, 0, 0, 0, 0, 0};
        Matrix matrix4{vec4,3,3};
                CHECK_EQ(matrix4 >= matrix3, true);
        vector<double> vec5 = {1, 1 ,1 ,0 ,0 ,0 ,0, 0, 0};
        Matrix matrix5{vec5, 3, 3};
                CHECK_EQ(matrix1 >= matrix5, true);
                CHECK_EQ(matrix5 >= matrix1, true);
    }

            SUBCASE(">= operator: bad")
    {
        vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0};
        Matrix matrix1{vec1, 2, 5};
        Matrix matrix2{ vec1, 5, 2};
        CHECK_THROWS(bool check = matrix1>=matrix2);
        CHECK_THROWS(bool check = matrix2>=matrix1);
        vector<double> vec2 = {1, 0, 0, 1, 0, 1, 1, 0};
        Matrix matrix3{vec2, 2, 4};
        Matrix matrix4{vec2, 8, 1};
        CHECK_THROWS(bool check = matrix1>=matrix3);
        CHECK_THROWS(bool check = matrix3>=matrix1);
        CHECK_THROWS(bool check = matrix3>=matrix2);
        CHECK_THROWS(bool check = matrix3>=matrix4);
        CHECK_THROWS(bool check = matrix4>=matrix3);
    }

            SUBCASE("< operator: good")
    {
        vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
        Matrix matrix1{vec1, 3, 3};
        Matrix check1 = matrix1 + matrix1;
                CHECK_EQ(matrix1 < check1, true);
        vector<double> vec3 = {-1, 0, 0, 0, -1, 0, 0, 0, -1};
        Matrix matrix3{vec3,3,3};
                CHECK_NE(matrix1 < matrix3, true);
        vector<double> vec4 = {0, 0, 0, 0, 0, 0, 0, 0, 0};
        Matrix matrix4{vec4,3,3};
                CHECK_EQ(matrix3 < matrix4, true);
        vector<double> vec5 = {1, 1 ,1 ,0 ,0 ,0 ,0, 0, 0};
        Matrix matrix5{vec5, 3, 3};
                CHECK_NE(matrix5 < matrix1, true);
                CHECK_NE(matrix1 < matrix5, true);
    }

            SUBCASE("< operator: bad")
    {
        vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0};
        Matrix matrix1{vec1, 2, 5};
        Matrix matrix2{ vec1, 5, 2};
        CHECK_THROWS(bool check = matrix1<matrix2);
        CHECK_THROWS(bool check = matrix2<matrix1);
        vector<double> vec2 = {1, 0, 0, 1, 0, 1, 1, 0};
        Matrix matrix3{vec2, 2, 4};
        Matrix matrix4{vec2, 8, 1};
        CHECK_THROWS(bool check = matrix1<matrix3);
        CHECK_THROWS(bool check = matrix3<matrix1);
        CHECK_THROWS(bool check = matrix3<matrix2);
        CHECK_THROWS(bool check = matrix3<matrix4);
        CHECK_THROWS(bool check = matrix4<matrix3);
    }

            SUBCASE("!= operator: good")
    {
        vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
        Matrix matrix1{vec1, 3, 3};
        Matrix check1 = matrix1 + matrix1;
        vector<double> ans_vec1 = {2, 0, 0, 0, 2, 0, 0, 0, 2};
        Matrix ans1{ans_vec1,3,3};
                CHECK_NE(check1 != ans1, true);
                CHECK_EQ(matrix1 != check1, true);
                CHECK_EQ(ans1 != matrix1, true);
        vector<double> vec2 = {1, 0, 1, 0, 0, 0, 1, 0, 0};
        Matrix matrix2{vec2, 3, 3};
                CHECK_EQ(matrix1 != matrix2, true);
                CHECK_EQ(matrix2 != matrix1, true);
    }

            SUBCASE("!= operator: bad")
    {
        vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0};
        Matrix matrix1{vec1, 2, 5};
        Matrix matrix2{ vec1, 5, 2};
        CHECK_THROWS(bool check = matrix1!=matrix2);
        CHECK_THROWS(bool check = matrix2!=matrix1);
        vector<double> vec2 = {1, 0, 0, 1, 0, 1, 1, 0};
        Matrix matrix3{vec2, 2, 4};
        Matrix matrix4{vec2, 8, 1};
        CHECK_THROWS(bool check = matrix1!=matrix3);
        CHECK_THROWS(bool check = matrix3!=matrix1);
        CHECK_THROWS(bool check = matrix3!=matrix2);
        CHECK_THROWS(bool check = matrix3!=matrix4);
        CHECK_THROWS(bool check = matrix4!=matrix3);
    }

            SUBCASE("== operator: good")
    {
        vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
        Matrix matrix1{vec1, 3, 3};
        Matrix check1 = matrix1 + matrix1;
        vector<double> ans_vec1 = {2, 0, 0, 0, 2, 0, 0, 0, 2};
        Matrix ans1{ans_vec1,3,3};
                CHECK_EQ(check1 == ans1, true);
                CHECK_NE(matrix1 == check1, true);
                CHECK_NE(ans1 == matrix1, true);
        vector<double> vec2 = {1, 0, 1, 0, 0, 0, 1, 0, 0};
        Matrix matrix2{vec2, 3, 3};
                CHECK_NE(matrix1 == matrix2, true);
                CHECK_NE(matrix2 == matrix1, true);
    }

            SUBCASE("== operator: bad")
    {
        vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0};
        Matrix matrix1{vec1, 2, 5};
        Matrix matrix2{ vec1, 5, 2};
        CHECK_THROWS(bool check = matrix1==matrix2);
        CHECK_THROWS(bool check = matrix2==matrix1);
        vector<double> vec2 = {1, 0, 0, 1, 0, 1, 1, 0};
        Matrix matrix3{vec2, 2, 4};
        Matrix matrix4{vec2, 8, 1};
        CHECK_THROWS(bool check = matrix1==matrix3);
        CHECK_THROWS(bool check = matrix3==matrix1);
        CHECK_THROWS(bool check = matrix3==matrix2);
        CHECK_THROWS(bool check = matrix3==matrix4);
        CHECK_THROWS(bool check = matrix4==matrix3);
    }
}

TEST_CASE("Output operator")
{
    vector<double> vec1 = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
    vector<double> vec2 = {6, 5, 4, 3, 2, 1};
    vector<double> vec3 = {2, 0, 2, 0};
    stringstream stream;
    stream << Matrix(vec1, 4, 4);
            CHECK(stream.str() == "[1 0 0 0]\n[0 1 0 0]\n[0 0 1 0]\n[0 0 0 1]");
    stream.str(std::string());
    stream << Matrix(vec1, 2, 8);
            CHECK(stream.str() == "[1 0 0 0 0 1 0 0]\n[0 0 1 0 0 0 0 1]");
    stream.str(std::string());
    stream << Matrix(vec1, 16, 1);
            CHECK(stream.str() == "[1]\n[0]\n[0]\n[0]\n[0]\n[1]\n[0]\n[0]\n[0]\n[0]\n[1]\n[0]\n[0]\n[0]\n[0]\n[1]");
    stream.str(std::string());

    stream << Matrix(vec2, 2, 3);
            CHECK(stream.str() == "[6 5 4]\n[3 2 1]");
    stream.str(std::string());
    stream << Matrix(vec2, 3, 2);
            CHECK(stream.str() == "[6 5]\n[4 3]\n[2 1]");
    stream.str(std::string());
    stream << Matrix(vec2, 6, 1);
            CHECK(stream.str() == "[6]\n[5]\n[4]\n[3]\n[2]\n[1]");
    stream.str(std::string());
    stream << Matrix(vec2, 1, 6);
            CHECK(stream.str() == "[6 5 4 3 2 1]");
    stream.str(std::string());

    stream << Matrix(vec3, 2, 2);
            CHECK(stream.str() == "[2 0]\n[2 0]");
    stream.str(std::string());
    stream << Matrix(vec3, 1, 4);
            CHECK(stream.str() == "[2 0 2 0]");
    stream.str(std::string());
    stream << Matrix(vec3, 4, 1);
            CHECK(stream.str() == "[2]\n[0]\n[2]\n[0]");
    stream.str(std::string());
}

TEST_CASE("Creation operator: bad")
{
    vector<double> vec1 = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
    vector<double> vec2 = {6, 5, 4, 3, 2, 1};
    vector<double> vec3 = {2, 0, 2, 0};
    stringstream stream;
    CHECK_THROWS(stream << Matrix(vec1, 3, 4));
    stream.str(std::string());
    CHECK_THROWS(stream << Matrix(vec1, 2, 9));
    stream.str(std::string());
    CHECK_THROWS(stream << Matrix(vec1, 17, 1));
    stream.str(std::string());

    CHECK_THROWS(stream << Matrix(vec2, 2, 4));
    stream.str(std::string());
    CHECK_THROWS(stream << Matrix(vec2, 4, 2));
    stream.str(std::string());
    CHECK_THROWS(stream << Matrix(vec2, 6, 2));
    stream.str(std::string());
    CHECK_THROWS(stream << Matrix(vec2, 2, 6));
    stream.str(std::string());

    CHECK_THROWS(stream << Matrix(vec3, 2, 1));
    stream.str(std::string());
    CHECK_THROWS(stream << Matrix(vec3, 1, 3));
    stream.str(std::string());
    CHECK_THROWS(stream << Matrix(vec3, 5, 1));
    stream.str(std::string());
}