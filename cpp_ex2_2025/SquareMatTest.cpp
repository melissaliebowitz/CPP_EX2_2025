//melissaliebowitz@yahoo.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "SquareMat.hpp"
#include <iostream>
#include <sstream>
using namespace matrix;

TEST_CASE("Constructor Test"){
    SquareMat mat(3);
    CHECK(mat.get_size() == 3);
}

TEST_CASE("Copy Constructor Test"){
    SquareMat mat(3);

    for (int i = 0; i < mat.get_size(); i++)
    {
        for (int j = 0; j < mat.get_size(); j++)
        {
            mat.get_mat()[i][j] = 1;
           
        }  
    }

    SquareMat copy(mat);

    for (int i = 0; i < copy.get_size(); i++)
    {
        for (int j = 0; j < copy.get_size(); j++)
        {
            CHECK_EQ(copy.get_mat()[i][j], 1);
           
        }  
    }



}

TEST_CASE("Operator+ Test"){
    SquareMat mat1(2);
    SquareMat mat2(2);

    for (int i = 0; i < mat1.get_size(); i++)
    {
        for (int j = 0; j < mat1.get_size(); j++)
        {
            mat1.get_mat()[i][j] = 1;
            mat2.get_mat()[i][j] = 2;
        }  
    }
   
    
    SquareMat mat3 = mat1 + mat2;
    for (int i = 0; i < mat1.get_size(); i++)
    {
        for (int j = 0; j < mat1.get_size(); j++)
        {
            CHECK_EQ(mat3.get_mat()[i][j], 3);
        }
    }
}

TEST_CASE("Operator- Test"){
    SquareMat mat1(2);
    SquareMat mat2(2);

    for (int i = 0; i < mat1.get_size(); i++)
    {
        for (int j = 0; j < mat1.get_size(); j++)
        {
            mat1.get_mat()[i][j] = 4;
            mat2.get_mat()[i][j] = 1;
        }  
    }

    SquareMat mat3 = mat1 - mat2;
    for (int i = 0; i < mat1.get_size(); i++)
    {
        for (int j = 0; j < mat1.get_size(); j++)
        {
            CHECK_EQ(mat3.get_mat()[i][j], 3);
        }
    }
}

TEST_CASE("Operator- (Unary) Test"){
    SquareMat mat1(2);

    for (int i = 0; i < mat1.get_size(); i++)
    {
        for (int j = 0; j < mat1.get_size(); j++)
        {
            mat1.get_mat()[i][j] = -1;
        }  
    }

    SquareMat mat2 = -mat1;

    for (int i = 0; i < mat2.get_size(); i++)
    {
        for (int j = 0; j < mat2.get_size(); j++)
        {
            CHECK_EQ(mat2.get_mat()[i][j], 1);
        }
    }
}

TEST_CASE("Operator* Test (multiplication with another matrix)"){
    SquareMat mat1(2);
    SquareMat mat2(2);

    mat1.get_mat()[0][0] = 0;
    mat1.get_mat()[0][1] = 1;
    mat1.get_mat()[1][0] = 2;
    mat1.get_mat()[1][1] = 3;

    for (int i = 0; i < mat1.get_size(); i++)
    {
        for (int j = 0; j < mat1.get_size(); j++)
        {
            mat2.get_mat()[i][j] = 2;
        }  
    }

    SquareMat mat3 = mat1 * mat2;
    CHECK_EQ(mat3.get_mat()[0][0], 2);
    CHECK_EQ(mat3.get_mat()[0][1], 2);
    CHECK_EQ(mat3.get_mat()[1][0], 10);
    CHECK_EQ(mat3.get_mat()[1][1], 10);
}

TEST_CASE("Operator* Test (multiplication with scalar on both sides)"){
    SquareMat mat1(2);

    mat1.get_mat()[0][0] = 0;
    mat1.get_mat()[0][1] = 1;
    mat1.get_mat()[1][0] = 2;
    mat1.get_mat()[1][1] = 3;

    SquareMat mat2 = mat1 * 3;
    CHECK_EQ(mat2.get_mat()[0][0], 0);
    CHECK_EQ(mat2.get_mat()[0][1], 3);
    CHECK_EQ(mat2.get_mat()[1][0], 6);
    CHECK_EQ(mat2.get_mat()[1][1], 9);

    SquareMat mat3 = 4 * mat1;
    CHECK_EQ(mat3.get_mat()[0][0], 0);
    CHECK_EQ(mat3.get_mat()[0][1], 4);
    CHECK_EQ(mat3.get_mat()[1][0], 8);
    CHECK_EQ(mat3.get_mat()[1][1], 12);
}

TEST_CASE("Operator% Test (with another matrix)"){
    SquareMat mat1(2);
    SquareMat mat2(2);

    for (int i = 0; i < mat1.get_size(); i++)
    {
        for (int j = 0; j < mat1.get_size(); j++)
        {
            mat1.get_mat()[i][j] = 4;
            mat2.get_mat()[i][j] = 2;
        }  
    }

    SquareMat mat3 = mat1 % mat2;
    for (int i = 0; i < mat1.get_size(); i++)
    {
        for (int j = 0; j < mat1.get_size(); j++)
        {
            CHECK_EQ(mat3.get_mat()[i][j], 0);
        }
    }
}

TEST_CASE("Operator% Test (with scalar)"){
    SquareMat mat1(2);

    mat1.get_mat()[0][0] = 0;
    mat1.get_mat()[0][1] = 1;
    mat1.get_mat()[1][0] = 2;
    mat1.get_mat()[1][1] = 3;

    SquareMat mat2 = mat1 % 3;
    CHECK_EQ(mat2.get_mat()[0][0], 0);
    CHECK_EQ(mat2.get_mat()[0][1], 1);
    CHECK_EQ(mat2.get_mat()[1][0], 2);
    CHECK_EQ(mat2.get_mat()[1][1], 0);
}

TEST_CASE("Operator/ Test"){
    SquareMat mat1(2);

    mat1.get_mat()[0][0] = 0;
    mat1.get_mat()[0][1] = 1;
    mat1.get_mat()[1][0] = 2;
    mat1.get_mat()[1][1] = 3;

    SquareMat mat2 = mat1 / 2;
    CHECK_EQ(mat2.get_mat()[0][0], 0);
    CHECK_EQ(mat2.get_mat()[0][1], 0.5);
    CHECK_EQ(mat2.get_mat()[1][0], 1);
    CHECK_EQ(mat2.get_mat()[1][1], 1.5);
}

TEST_CASE("Operator^ Test"){
    SquareMat mat1(2);
    CHECK_THROWS_AS([&]() { SquareMat mat2 = mat1 ^ -1; }(), std::runtime_error);

    for (int i = 0; i < mat1.get_size(); i++)
    {
        for (int j = 0; j < mat1.get_size(); j++)
        {
            mat1.get_mat()[i][j] = 2;
        }  
    }

    SquareMat mat3 = mat1 ^ 3;
    for (int i = 0; i < mat3.get_size(); i++)
    {
        for (int j = 0; j < mat3.get_size(); j++)
        {
            CHECK_EQ(mat3.get_mat()[i][j], 32);
        }  
    }
}

TEST_CASE("Operator++ preincrement Test"){
    SquareMat mat(3);
    for (int i = 0; i < mat.get_size(); i++)
    {
        for (int j = 0; j < mat.get_size(); j++)
        {
            mat.get_mat()[i][j] = 2;
        }  
    }

    ++mat;

    for (int i = 0; i < mat.get_size(); i++)
    {
        for (int j = 0; j < mat.get_size(); j++)
        {
            CHECK_EQ(mat.get_mat()[i][j], 3);
        }  
    }
}

TEST_CASE("Operator++ postincrement Test"){
    SquareMat mat(3);
    for (int i = 0; i < mat.get_size(); i++)
    {
        for (int j = 0; j < mat.get_size(); j++)
        {
            mat.get_mat()[i][j] = 2;
        }  
    }

    mat++;

    for (int i = 0; i < mat.get_size(); i++)
    {
        for (int j = 0; j < mat.get_size(); j++)
        {
            CHECK_EQ(mat.get_mat()[i][j], 3);
        }  
    }
}

TEST_CASE("Operator~ (transopse) Test"){
    SquareMat mat(3);
    mat.get_mat()[0][0] = 1;
    mat.get_mat()[0][1] = 2;
    mat.get_mat()[0][2] = 3;
    mat.get_mat()[1][0] = 4;
    mat.get_mat()[1][1] = 5;
    mat.get_mat()[1][2] = 6;
    mat.get_mat()[2][0] = 7;
    mat.get_mat()[2][1] = 8;
    mat.get_mat()[2][2] = 9;

    SquareMat res = ~mat;
    CHECK_EQ(res.get_mat()[0][0],1);
    CHECK_EQ(res.get_mat()[0][1],4);
    CHECK_EQ(res.get_mat()[0][2],7);
    CHECK_EQ(res.get_mat()[1][0],2);
    CHECK_EQ(res.get_mat()[1][1],5);
    CHECK_EQ(res.get_mat()[1][2],8);
    CHECK_EQ(res.get_mat()[2][0],3);
    CHECK_EQ(res.get_mat()[2][1],6);
    CHECK_EQ(res.get_mat()[2][2],9);
}

TEST_CASE("Operator[] Test"){
    SquareMat mat(3);
    for (int i = 0; i < mat.get_size(); i++)
    {
        for (int j = 0; j < mat.get_size(); j++)
        {
            mat.get_mat()[i][j] = 2;
        }  
    }

    for (int i = 0; i < mat.get_size(); i++)
    {
        for (int j = 0; j < mat.get_size(); j++)
        {   
            CHECK_EQ(mat.get_mat()[i][j], 2);
        }  
    }

    mat.get_mat()[0][0] = -7;
    CHECK_EQ(mat.get_mat()[0][0], -7);

    CHECK_THROWS_AS(mat[9][6] = 9, std:: runtime_error);
}

 TEST_CASE("Operator== and Operator!= Test"){
    SquareMat mat1(2);
    SquareMat mat2(2);
    SquareMat mat3(3);
    SquareMat mat4(2);

    CHECK_THROWS_AS([&]() { (void)(mat1 == mat3); }(), std::runtime_error);

    for (int i = 0; i < mat1.get_size(); i++)
    {
        for (int j = 0; j < mat1.get_size(); j++)
        {
            mat1.get_mat()[i][j] = 4;
            mat2.get_mat()[i][j] = 4;
            mat4.get_mat()[i][j] = 1;
        }  
    }

    CHECK_EQ((mat1 == mat2), true);
    CHECK_EQ((mat1 != mat2) , false);
    CHECK_EQ((mat2 != mat4), true);
 }


 TEST_CASE("Comparison (>, <, >=, <=) Operators Test"){
    SquareMat mat1(2);
    SquareMat mat2(2);
    SquareMat mat3(2);

    for (int i = 0; i < mat1.get_size(); i++)
    {
        for (int j = 0; j < mat1.get_size(); j++)
        {
            mat1.get_mat()[i][j] = 4; //sum=16
            mat2.get_mat()[i][j] = 3; //sum=12
            mat3.get_mat()[i][j] = 3;
        }  
    }

    CHECK_EQ(mat1 >= mat2, true);
    CHECK_EQ(mat2 >= mat1, false);
    CHECK_EQ(mat3 >= mat2, true);
    CHECK_EQ(mat1 > mat2, true);
    CHECK_EQ(mat1 < mat2, false);
    CHECK_EQ(mat2 < mat1, true);
    CHECK_EQ(mat1 <= mat2, false);
    CHECK_EQ(mat2 <= mat3, true);
    CHECK_EQ(mat1 >= mat2, true);
    CHECK_EQ(mat3 < mat2, false);
    CHECK_EQ(mat3 > mat2, false);
 }

 TEST_CASE("Operator! (det) Test"){

 }

 TEST_CASE("Operator+= Test"){
    SquareMat mat1(2);
    SquareMat mat2(2);
    SquareMat mat3(4);

    CHECK_THROWS_AS(mat1+=mat3, std:: runtime_error);

    for (int i = 0; i < mat1.get_size(); i++)
    {
        for (int j = 0; j < mat1.get_size(); j++)
        {
            mat1.get_mat()[i][j] = 1;
            mat2.get_mat()[i][j] = 2;
        }  
    }
   
    mat1 += mat2;
    for (int i = 0; i < mat1.get_size(); i++)
    {
        for (int j = 0; j < mat1.get_size(); j++)
        {
            CHECK_EQ(mat1.get_mat()[i][j], 3);
        }
    }
 }

 TEST_CASE("Operator-= Test"){
    SquareMat mat1(2);
    SquareMat mat2(2);

    for (int i = 0; i < mat1.get_size(); i++)
    {
        for (int j = 0; j < mat1.get_size(); j++)
        {
            mat1.get_mat()[i][j] = 1;
            mat2.get_mat()[i][j] = 2;
        }  
    }
   
    mat1 -= mat2;
    for (int i = 0; i < mat1.get_size(); i++)
    {
        for (int j = 0; j < mat1.get_size(); j++)
        {
            CHECK_EQ(mat1.get_mat()[i][j], -1);
        }
    }
 }

 TEST_CASE("Operator*= Test"){
    SquareMat mat1(2);
    SquareMat mat2(2);

    for (int i = 0; i < mat1.get_size(); i++)
    {
        for (int j = 0; j < mat1.get_size(); j++)
        {
            mat1.get_mat()[i][j] = 1;
            mat2.get_mat()[i][j] = 2;
        }  
    }

    mat1 *= mat2;
    for (int i = 0; i < mat1.get_size(); i++)
    {
        for (int j = 0; j < mat1.get_size(); j++)
        {
            CHECK_EQ(mat1.get_mat()[i][j], 2);
        }
    }

 }

 TEST_CASE("Operator*= (with scalar )Test"){
    SquareMat mat(2);

    for (int i = 0; i < mat.get_size(); i++)
    {
        for (int j = 0; j < mat.get_size(); j++)
        {
            mat.get_mat()[i][j] = 6;
        }
        
    }

    mat*=2;

    for (int i = 0; i < mat.get_size(); i++)
    {
        for (int j = 0; j < mat.get_size(); j++)
        {
           CHECK_EQ(mat.get_mat()[i][j], 12);
        }
    } 
 }

 TEST_CASE("Operator/= Test"){
    SquareMat mat1(2);
    SquareMat mat2(2);

    for (int i = 0; i < mat1.get_size(); i++)
    {
        for (int j = 0; j < mat1.get_size(); j++)
        {
            mat1.get_mat()[i][j] = 1;
            mat2.get_mat()[i][j] = 2;
        }  
    }
   
    mat1 /= mat2;
    for (int i = 0; i < mat1.get_size(); i++)
    {
        for (int j = 0; j < mat1.get_size(); j++)
        {
            CHECK_EQ(mat1.get_mat()[i][j], 0.5);
        }
    }
 }

 TEST_CASE("Operator%= Test"){
    SquareMat mat1(2);
    SquareMat mat2(2);

    for (int i = 0; i < mat1.get_size(); i++)
    {
        for (int j = 0; j < mat1.get_size(); j++)
        {
            mat1.get_mat()[i][j] = 6;
            mat2.get_mat()[i][j] = 2;
        }  
    }
   
    mat1 %= mat2;
    for (int i = 0; i < mat1.get_size(); i++)
    {
        for (int j = 0; j < mat1.get_size(); j++)
        {
            CHECK_EQ(mat1.get_mat()[i][j], 0);
        }
    }
 }

 TEST_CASE("Operator%= (with scalar) Test"){
    SquareMat mat(2);

    for (int i = 0; i < mat.get_size(); i++)
    {
        for (int j = 0; j < mat.get_size(); j++)
        {
            mat.get_mat()[i][j] = 5;
        }
        
    }

    mat%=3;

    for (int i = 0; i < mat.get_size(); i++)
    {
        for (int j = 0; j < mat.get_size(); j++)
        {
           CHECK_EQ(mat.get_mat()[i][j], 2);
        }
    } 
 }
 

    






