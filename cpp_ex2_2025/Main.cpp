//melissaliebowitz@yahoo.com

#include <iostream>
#include "SquareMat.hpp"
using namespace matrix;

int main(){
    
    SquareMat mat1(3);
    SquareMat mat2(3);
    SquareMat mat3(2);
    SquareMat mat4(2);
    SquareMat mat11(2);

    mat1.get_mat()[0][0] = 0;
    mat1.get_mat()[0][1] = 1;
    mat1.get_mat()[0][2] = 2;
    mat1.get_mat()[1][0] = 3;
    mat1.get_mat()[1][1] = 4;
    mat1.get_mat()[1][2] = 5;
    mat1.get_mat()[2][0] = 6;
    mat1.get_mat()[2][1] = 7;
    mat1.get_mat()[2][2] = 8;

    mat2.get_mat()[0][0] = -1;
    mat2.get_mat()[0][1] = -2;
    mat2.get_mat()[0][2] = 4;
    mat2.get_mat()[1][0] = 0;
    mat2.get_mat()[1][1] = 5;
    mat2.get_mat()[1][2] = -2;
    mat2.get_mat()[2][0] = 1.5;
    mat2.get_mat()[2][1] = 3;
    mat2.get_mat()[2][2] = 7;

    for (int i = 0; i < mat3.get_size(); i++)
    {
        for (int j = 0; j < mat4.get_size(); j++)
        {
            mat3.get_mat()[i][j] = 2;
            mat4.get_mat()[i][j] = 1.5;
            mat11.get_mat()[i][j] = 7;
        }
        
    }

    std:: cout << mat1 << std:: endl;
    std:: cout << mat4 << std:: endl;

    SquareMat mat5 = mat1 + mat2;
    std:: cout << "mat1 + mat2 = " << std:: endl;
    std:: cout << mat5 << std:: endl;

    SquareMat mat6 = mat3 - mat4;
    std:: cout << "mat3 - mat4 = " << std:: endl;
    std:: cout << mat6 << std:: endl;

    SquareMat mat7 = mat1 * mat2;
    std:: cout << "mat1 * mat2 = " << std:: endl;
    std:: cout << mat7 << std:: endl;

   SquareMat mat8 = 2 * mat3;
   std:: cout << "2 * mat3 = " << std:: endl;
   std:: cout << mat8 << std:: endl;

   SquareMat mat9 = mat1 * -2;
   std:: cout << "mat1 * (-2) = " << std:: endl;
   std:: cout << mat9 << std:: endl;

   SquareMat mat10 = mat11 % 4;
   std:: cout << "mat11 % 4 = " << std:: endl;
   std:: cout << mat10 << std:: endl;

   SquareMat mat12 = mat11 % mat3;
   std:: cout << "mat11 % mat3 = " << std:: endl;
   std:: cout << mat12 << std:: endl;

   SquareMat mat13 = -mat2;
   std:: cout << "(uniary) -mat2 =" << std:: endl;
   std:: cout << mat13 << std:: endl;

   SquareMat mat14 = mat11 / 3.5;
   std:: cout << "mat11 / 3.5 = " << std:: endl;
   std:: cout << mat14 << std:: endl;

   SquareMat mat15= mat3 ^ 3;
   std:: cout << "mat3 ^ 3 = " << std:: endl;
   std:: cout << mat15 << std:: endl;

    SquareMat mat16 = ~mat1;
    std:: cout << "transpose mat1" << std:: endl;
    std:: cout << mat16 << std:: endl;

    double det = !mat2;
    std:: cout << "The determinant of mat1 is: " << det << std:: endl;

    ++mat11;
    std:: cout << "Pre-increment on mat11: " << std:: endl;
    std:: cout << mat11 << std:: endl;

    std:: cout << "Post-increment on mat3: " << std:: endl;
    std:: cout << mat3++ << std:: endl;
    std:: cout << "Printing mat3 again: " << std:: endl;
    std:: cout << mat3 << std:: endl;

    std:: cout << "Comparison Operators: " << std:: endl;
    std:: cout << "mat1 == mat2 is: " << (mat1 == mat2) << std:: endl;
    std:: cout << "mat4 != mat3 is: " << (mat4 != mat3) << std:: endl;
    std:: cout << "mat1 > mat2 is: " << (mat1 > mat2) << std:: endl;
    std:: cout << "mat4 < mat11 is: " << (mat4 < mat11) << std:: endl;

    SquareMat mat20(3);
    SquareMat mat21(3);

    mat20.get_mat()[0][0] = 1;
    mat20.get_mat()[0][1] = 1;
    mat20.get_mat()[0][2] = 2;
    mat20.get_mat()[1][0] = 3;
    mat20.get_mat()[1][1] = -2;
    mat20.get_mat()[1][2] = -7;
    mat20.get_mat()[2][0] = 0;
    mat20.get_mat()[2][1] =5;
    mat20.get_mat()[2][2] = 1;
 
 
    mat21.get_mat()[0][0] = 0;
    mat21.get_mat()[0][1] = -10;
    mat21.get_mat()[0][2] = 9;
    mat21.get_mat()[1][0] = 4.5;
    mat21.get_mat()[1][1] = 4;
    mat21.get_mat()[1][2] = 0.5;
    mat21.get_mat()[2][0] = 5;
    mat21.get_mat()[2][1] = -4;
    mat21.get_mat()[2][2] = -5;

    std:: cout << "mat20 == mat21 is: " << (mat20 == mat21) << std:: endl;
    std:: cout << "mat20 =< mat21 is: " << (mat20 <= mat21) << std:: endl;
    std:: cout << std:: endl;

    mat11+=mat3;
    std:: cout << "mat11 += mat3: " << std::endl;
    std:: cout << mat11 << std:: endl;

    mat3-= mat11;
    std:: cout << "mat3 -= mat11: " << std::endl;
    std:: cout << mat3 << std:: endl;

    mat11*=mat3;
    std:: cout << "mat11 *= mat3: " << std::endl;
    std:: cout << mat11 << std:: endl;

    mat11/=mat3;
    std:: cout << "mat11 /= mat3: " << std::endl;
    std:: cout << mat11 << std::endl;

    mat3 *= 2;
    std:: cout << "mat3*=2: " << std::endl;
    std:: cout << mat3 << std::endl;

    mat3 %= mat11;
    std:: cout << "mat3%=mat11: " << std::endl;
    std:: cout << mat3 << std::endl;

    mat11%=3;
    std:: cout << "mat11%=3: " << std::endl;
    std:: cout << mat11 << std::endl;

    return 0;
}