#include <iostream>
#include <vector>

using namespace std;

namespace zich
{
    class Matrix
    {
    private:
        // dimensions
        int num_of_rows;
        int num_of_columns;
        vector<double> values; // matrix values
    public:
        // constructors
        Matrix();
        Matrix(vector<double> values, int num_of_rows, int num_of_columns);
        Matrix(const Matrix& matrix);
        ~Matrix(); // destructor
        // getters
        int getNumberOfRows() const;
        int getNumberOfColumns() const;
        vector<double> getValues() const;
        // setters
        void setNumberOfRows(const int num);
        void setNumberOfColumns(const int num);
        void setValues(const vector<double>& values);
        static void check_same_size(const Matrix& matrix1, const Matrix& matrix2); // help func
        static void check_matrix(const Matrix& matrix);
        // arithmetic operations
        Matrix operator+ (const Matrix& matrix);
        Matrix& operator+= (const Matrix& matrix);
        Matrix operator- (const Matrix& matrix);
        Matrix& operator-= (const Matrix& matrix);
        Matrix operator+ ();
        Matrix operator- ();
        Matrix& operator++ ();// prefix
        Matrix operator++ (int); // postfix
        Matrix& operator-- (); // prefix
        Matrix operator-- (int); // postfix
        friend Matrix operator* (const double num, Matrix matrix);
        Matrix operator* (const double num);
        Matrix& operator*= (const double num);
        Matrix operator* (const Matrix& matrix);
        Matrix& operator*= (const Matrix& matrix);
        static void check_sum(const Matrix& matrix1,const Matrix& matrix2, double *sum1, double *sum2); // help func
        // comparison operations
        bool operator> (const Matrix& matrix) const;
        bool operator>= (const Matrix& matrix) const;
        bool operator< (const Matrix& matrix) const;
        bool operator<= (const Matrix& matrix) const;
        bool operator!= (const Matrix& matrix);
        bool operator== (const Matrix & matrix);
        friend ostream & operator<< (ostream& output, const Matrix& matrix); // output (cout)
        friend istream & operator>> (istream& input , Matrix& matrix); // input (cin)
    };
}