//melissaliebowitz@yahoo.com

#include <iostream>
#include <cmath>
#include "SquareMat.hpp"
using namespace matrix;


SquareMat::SquareMat(int s) : size(s) {
    mat = new double *[size];
    for (int i = 0; i < size; i++)
    {
        mat[i] = new double[size];
    }
    
}

SquareMat::SquareMat(const SquareMat &other) : size(other.size)
{ 
    mat = new double*[size];
    for (int i = 0; i < size; i++)
    {
        mat[i] = new double[size];
        for (int j = 0; j < size; j++)
        {
            mat[i][j] = other.mat[i][j];
        }
        
    }
    
}

SquareMat::~SquareMat(){

    for (int i = 0; i < size; i++)
    {
        delete[] mat[i];
    }
    delete[] mat;
    
}

SquareMat& SquareMat::operator=(const SquareMat& other) {
    if (this == &other) return *this;

    for (int i = 0; i < size; i++) {
        delete[] mat[i];
    }
    delete[] mat;

    size = other.size;
    mat = new double*[size];
    for (int i = 0; i < size; i++) {
        mat[i] = new double[size];
        for (int j = 0; j < size; j++) {
            mat[i][j] = other.mat[i][j];
        }
    }

    return *this;
}

SquareMat SquareMat::operator+(const SquareMat &other)
{
    if (other.size != size)
    {
        throw std:: runtime_error("Matrices must be the same size in order to add between them.");
    }

    SquareMat sum_mat(size);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            sum_mat.mat[i][j] = mat[i][j] + other.mat[i][j];
        }
        
    }
    
    return sum_mat;
}

SquareMat SquareMat::operator-(const SquareMat &other)
{   
    if (other.size != size)
    {
        throw std:: runtime_error("Matrices must be the same size in order to subtract between them.");
    }

    SquareMat sub_mat(size);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            sub_mat.mat[i][j] = mat[i][j] - other.mat[i][j];
        }
        
    }
    
    return sub_mat;
}

SquareMat SquareMat::operator-() const
{
    SquareMat opposite_sign(size);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            opposite_sign.mat[i][j] = -1 * mat[i][j];
        }
        
    }

    return opposite_sign;
    
}

SquareMat SquareMat::operator*(const SquareMat &other)
{
    if (other.size != size)
    {
        throw std:: runtime_error("Matrices must be the same size in order to multiply between them");
    }

    SquareMat mult_mat(size);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {   
            mult_mat.mat[i][j] = 0;
            for (int k = 0; k < size; k++)
            {
                mult_mat.mat[i][j] += mat[i][k] * other.mat[k][j];
            } 
        }
        
    }

    return mult_mat;
}

SquareMat SquareMat::operator*(double scalar)
{
    SquareMat s_mat(size);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            s_mat.mat[i][j] = scalar * mat[i][j];
        }
        
    }

    return s_mat;
}

SquareMat SquareMat::operator%(const SquareMat &other)
{
    SquareMat mod_mat(size);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            mod_mat.mat[i][j] = fmod(mat[i][j], other.mat[i][j]);
        }
        
    }

    return mod_mat;
    
}

SquareMat SquareMat::operator%(double scalar)
{
    SquareMat mod_mat(size);
    for (int i = 0; i < size; i++)
    {
        for(int j=0; j< size; j++){
            mod_mat.mat[i][j] = fmod(mat[i][j], scalar);

        }
    }
    return mod_mat;
    
}

SquareMat SquareMat::operator/(double scalar)
{
    SquareMat div_mat(size);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            div_mat.mat[i][j] = mat[i][j] / scalar;
        }
        
    }

    return div_mat;
    
}

SquareMat SquareMat::operator^(int num)
{   
    if (num < 1)
    {
        throw std:: runtime_error("This exponent operator only works with positive integers");
    }

    if (num == 1)
    {
        return *this;
    }
    
    
    SquareMat exp_mat(size);
    SquareMat base(*this);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            exp_mat.mat[i][j] = (i == j ? 1 : 0);
        }
    }

    for (int i = 0; i < num; i++)
    {
        exp_mat = exp_mat * base;
    }

    return exp_mat;
}

SquareMat& SquareMat::operator++()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            mat[i][j]++;
        }
        
    }
    
    return *this;
}

SquareMat SquareMat::operator++(int dummy_flag)
{
    SquareMat copy(*this);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            mat[i][j]++;
        }
        
    }

    return copy;
}

SquareMat SquareMat::operator~() const
{
    SquareMat tran_mat(*this);
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            double temp = tran_mat.mat[i][j];
            tran_mat.mat[i][j]= tran_mat.mat[j][i];
            tran_mat.mat[j][i] = temp;
        }  
    }

    return tran_mat;
    
}

const double *SquareMat::operator[](int index) const
{   
    if (index < 0 || index >= size)
    {
        throw std:: runtime_error("Index is out of bound");
    }
    
    return mat[index];
}

double *SquareMat::operator[](int index)
{    if (index < 0 || index >= size)
    {
        throw std:: runtime_error("Index is out of bound");
    }
    
    return mat[index];
    
}

bool SquareMat::operator==(const SquareMat &other) const
{   
      if (other.size != size)
        {
            throw std:: runtime_error("Matrices must be of same size in order to compare.");
        }

    double sum_mat1 = 0;
    double sum_mat2 = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            sum_mat1+= mat[i][j];
            sum_mat2+=other.mat[i][j];
        }
        
    }
    if (sum_mat1 == sum_mat2)
    {
        return true;
    }
    
    return false;
}

bool SquareMat::operator!=(const SquareMat &other) const
{
    if (!other.operator==(*this))
    {
        return true;
    }
    
    return false;
}

bool SquareMat::operator>(const SquareMat &other) const
{   if (other.size != size)
{
    throw std:: runtime_error("Matrices must be of same size in order to compare.");
}

    double sum_mat1 = 0;
    double sum_mat2 = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            sum_mat1 += mat[i][j];
            sum_mat2 += other.mat[i][j];
        }
        
    }

    if(sum_mat1 > sum_mat2){
        return true;
    }
    
    return false;
}

bool SquareMat::operator<(const SquareMat &other) const
{
    if ((!this->operator>(other)) && (!this->operator==(other)))
    {
        return true;
    }
    
    return false;
    
}

bool SquareMat::operator>=(const SquareMat &other) const
{   
    if (this->operator==(other) || this->operator>(other))
    {
        return true;
    }
    
    return false;
}

bool SquareMat::operator<=(const SquareMat &other) const
{   
    if ((this->operator<(other))|| (this->operator==(other)))
    {
        return true;
    }
    
    return false;
}

SquareMat SquareMat:: get_sub_mat(int skip_row, int skip_col) const{
    SquareMat sub(size -1);

    int s_row = 0;
    for (int i = 0; i < size; i++)
    {
        if (i == skip_row) 
        {
            continue;
        }
        int s_col = 0;
        for (int j = 0; j < size; j++)
        {
            if (j == skip_col)
            {
                continue;
            }
            sub.mat[s_row][s_col] = mat[i][j];
            ++s_col;
            
        }
        ++s_row; 
    }

    return sub;
    
} 

double SquareMat::operator!() const
{
    if (size == 1)
    {
        return mat[0][0];
    }

    if (size == 2)
    {
        return (mat[0][0]*mat[1][1]) - (mat[0][1]*mat[1][0]);
    }

    double det = 0 ;
    for (int j = 0; j < size; j++)
    {
        SquareMat sub_mat = get_sub_mat(0, j);
        double a = ((j % 2 == 0) ? 1 : -1);
        det += a * mat[0][j] * !sub_mat;
    }
    
    return det;
}

SquareMat& SquareMat::operator+=(const SquareMat &other)
{
    if (size != other.size)
    {
        throw std:: runtime_error("Addition must be between two matrices of the same time.");
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            mat[i][j] += other.mat[i][j];            
        }
        
    }
    return *this;
    
}

SquareMat& SquareMat::operator-=(const SquareMat &other)
{
    if (size != other.size)
    {
        throw std:: runtime_error("Subtraction must be between two matrices of the same time.");
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            mat[i][j] -= other.mat[i][j];
        }
        
    }

    return *this;
}

SquareMat& SquareMat::operator*=(const SquareMat &other)
{
    if (size != other.size)
    {
        throw std:: runtime_error("Multiplication must be between two matrices of the same time.");
    }

    SquareMat res(size);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            res.mat[i][j] = 0;
            for (int k = 0; k < size; k++)
            {
                res.mat[i][j] = mat[i][k] * other.mat[k][j];
            } 
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
           mat[i][j] = res.mat[i][j];
        }
    }

    return *this;
}  

SquareMat& SquareMat::operator*=(double scalar)
{   
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            mat[i][j] *= scalar;
        }
        
    }

    return *this; 
}

SquareMat& ::SquareMat::operator/=(const SquareMat &other)
{
    if (size != other.size)
    {
        throw std:: runtime_error("Division must be between two matrices of the same time.");
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            mat[i][j] /= other.mat[i][j];
        }
        
    }

    return *this;
}

SquareMat& SquareMat::operator%=(const SquareMat &other)
{
    if (size != other.size)
    {
        throw std:: runtime_error("Modulo must be between two matrices of the same time.");
    }

    for (int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            mat[i][j] = fmod(mat[i][j], other.mat[i][j]);
        }
    }
    return *this;
}

SquareMat& SquareMat::operator%=(double scalar)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            mat[i][j] = fmod(mat[i][j], scalar);
        }
        
    }

    return *this;
}



std::ostream& matrix:: operator<<(std::ostream& output, const SquareMat &mat)
{
    for (int i = 0; i < mat.get_size(); i++)
    {
        for(int j = 0; j< mat.get_size(); j++)
        {
            output << mat.get_mat()[i][j];
        
        if (j != mat.get_size() - 1)
            {
                output << " ";
            }
        
        }

        output << std:: endl;
    }

    return output; 
}

SquareMat matrix:: operator*(double scalar, const SquareMat &mat)
{
    int size = mat.get_size();
    SquareMat res(size);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            res.get_mat()[i][j] = scalar * mat.get_mat()[i][j];
        }
        
    }

    return res;
}