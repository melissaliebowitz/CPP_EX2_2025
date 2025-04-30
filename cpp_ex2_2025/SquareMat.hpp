//melissaliebowitz@yahoo.com
#include <iostream>

namespace matrix{

    class SquareMat{
        private:
        double **mat;
        int size;

        SquareMat get_sub_mat(int row, int col) const;
        
        public:
        SquareMat(int s);
        SquareMat(const SquareMat& other);
        ~SquareMat();

        double* const* get_mat() const {return mat;}
        double **get_mat(){return mat;}
        int get_size() const {return size;}

        SquareMat& operator=(const SquareMat& other);
        SquareMat operator+(const SquareMat& other);
        SquareMat operator-(const SquareMat& other);

        SquareMat operator-() const;

        SquareMat operator*(const SquareMat& other);

        SquareMat operator*(double scalar);
        friend SquareMat operator*(double scalar, const SquareMat& mat);
        
        SquareMat operator%(const SquareMat& other);
        SquareMat operator%(double scalar);
        SquareMat operator/(double scalar);
        SquareMat operator^(int num);

        SquareMat& operator++();
        SquareMat operator++(int dummy_flag);

        SquareMat operator~() const;
        const double* operator[](int index) const;
        double* operator[](int index);
        bool operator==(const SquareMat& other) const;
        bool operator!=(const SquareMat& other) const;
        bool operator>(const SquareMat& other) const;
        bool operator<(const SquareMat& other) const;
        bool operator>=(const SquareMat& other) const;
        bool operator<=(const SquareMat& other) const;

        double operator!() const;

        SquareMat& operator+=(const SquareMat& other);
        SquareMat& operator-=(const SquareMat& other);
        SquareMat& operator*=(const SquareMat& other);
        SquareMat& operator*=(double scalar);
        SquareMat& operator/=(const SquareMat& other);
        SquareMat& operator%=(const SquareMat& other);
        SquareMat& operator%=(double scalar);

        friend std:: ostream& operator<<(std:: ostream& output, const SquareMat& mat);


    };

} 