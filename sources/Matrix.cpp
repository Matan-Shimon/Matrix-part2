//
// Created by matan on 05/04/2022.
//
#include "Matrix.hpp"

using namespace zich;

// constructors
Matrix::Matrix()
{
    this->num_of_rows = 0;
    this->num_of_columns = 0;
}
Matrix::Matrix(vector<double> values, int num_of_rows, int num_of_columns)
{
    this->values = move(values);
    this->num_of_rows = num_of_rows;
    this->num_of_columns = num_of_columns;
    check_matrix(*this);
}
Matrix::Matrix(const Matrix& matrix) // copy constructor
{
    this->num_of_rows = matrix.num_of_rows;
    this->num_of_columns = matrix.num_of_columns;
    this->values = matrix.values;
}
Matrix::~Matrix(){} // default destructor
// getters
int Matrix::getNumberOfRows () const
{
    return this->num_of_rows;
}
int Matrix::getNumberOfColumns() const
{
    return this->num_of_columns;
}
vector<double> Matrix::getValues() const
{
    return this->values;
}
// setters
void Matrix::setNumberOfRows(const int num)
{
    if (num <= 0)
    {
        throw invalid_argument("Matrix dimension need to be positive");
    }
    this->num_of_rows = num;
    if (!this->values.empty() && this->num_of_columns != 0)
    {
        check_matrix(*this);
    }
}
void Matrix::setNumberOfColumns(const int num)
{
    if (num <= 0)
    {
        throw invalid_argument("Matrix dimension need to be positive");
    }
    this->num_of_columns = num;
    if (!this->values.empty() && this->num_of_rows != 0)
    {
        check_matrix(*this);
    }
}
void Matrix::setValues(const vector<double>& values)
{
    this->values = values;
    if (this->num_of_rows > 0 && this->num_of_columns > 0)
    {
        check_matrix(*this);
    }
}
/**
 * This function check if the values dimensions of the matrices are equal.
 */
void Matrix::check_same_size(const Matrix& matrix1, const Matrix& matrix2)
{
    if (matrix1.num_of_rows != matrix2.num_of_rows || matrix1.num_of_columns != matrix2.num_of_columns)
    {
        throw invalid_argument("Matrices sized must be equal!");
    }
}
/**
 * The function check if the row and column of the matrix make sense.
 */
void Matrix::check_matrix(const Matrix& matrix)
{
    if (int(matrix.values.size()) != matrix.num_of_rows * matrix.num_of_columns || matrix.num_of_rows <= 0 || matrix.num_of_columns <= 0)
    {
        throw invalid_argument("Matrices size doesn't make sense!");
    }
}
// arithmetic operations
/**
 * This function adding two matrices and return a new matrix based on their sum.
 * This function overloading the + operator.
 */
Matrix Matrix::operator+ (Matrix const & matrix)
{
    check_same_size(*this, matrix);
    vector<double> output_vector;
    for (unsigned int i = 0; i < matrix.values.size(); ++i) {
        output_vector.push_back(this->values.at(i)+matrix.values.at(i));
    }
    Matrix output_matrix{output_vector, this->num_of_rows, this->num_of_columns};
    return output_matrix;
}
/**
 * This function adding the right matrix values to the left one.
 * This function overloading the += operator.
 */
Matrix& Matrix::operator+= (const Matrix& matrix)
{
    *this = *this + matrix;
    return *this;
}
/**
 * This function subtract two matrices and return a new matrix based on their subtraction.
 * This function overloading the - operator.
 */
Matrix Matrix::operator- (const Matrix& matrix)
{
    check_same_size(*this, matrix);
    vector<double> output_vector;
    for (unsigned int i = 0; i < matrix.values.size(); ++i) {
        output_vector.push_back(this->values.at(i)-matrix.values.at(i));
    }
    Matrix output_matrix{output_vector, this->num_of_rows, this->num_of_columns};
    return output_matrix;
}
/**
 * This function subtract right matrix from the left one.
 * This function overloading the -= operator.
 */
Matrix& Matrix::operator-= (const Matrix& matrix)
{
    *this = *this - matrix;
    return *this;
}
/**
 * This function returns a deep copy of the matrix.
 * This function overloading the + unary operator.
 */
Matrix Matrix::operator+ () // unari
{
    Matrix matrix = *this;
    return matrix;
}
/**
 * This function returns a deep copy of the (matrix * -1).
 * This function overloading the - unary operator.
 */
Matrix Matrix::operator- ()
{
    Matrix matrix = *this * -1;
    return matrix;
}
/**
 * This function adding 1 to each cell in the matrix and returns the updated matrix.
 * This function overloading the ++ prefix operator.
 */
Matrix& Matrix::operator++ ()
{
    for (unsigned int i = 0; i < this->values.size(); ++i) {
        this->values.at(i)++;
    }
    return *this;
}
/**
 * This function adding 1 to each cell in the matrix and returns the original matrix.
 * This function overloading the ++ postfix operator.
 */
Matrix Matrix::operator++ (int)
{
    Matrix output_matrix{*this};
    ++*this;
    return output_matrix;
}
/**
 * This function subtracting 1 from each cell in the matrix and returns the updated matrix.
 * This function overloading the -- prefix operator.
 */
Matrix& Matrix::operator-- ()
{
    for (unsigned int i = 0; i < this->values.size(); ++i) {
        this->values.at(i)--;
    }
    return *this;
}
/**
 * This function subtracting 1 from each cell in the matrix and returns the original matrix.
 * This function overloading the -- postfix operator.
 */
Matrix Matrix::operator-- (int) // postfix
{
    Matrix output_matrix{*this};
    --*this;
    return output_matrix;
}
/**
 * This function multiplying each cell in the number and returns a new matrix based on that multiplication.
 * This function overloading the num * matrix operator.
 */
Matrix zich::operator* (const double num, Matrix matrix)
{
    return matrix*num;
}
/**
 * This function multiplying each cell in the number and returns a new matrix based on that multiplication.
 * This function overloading the matrix * num operator.
 */
Matrix Matrix::operator* (const double num)
{
    Matrix output_matrix = *this;
    output_matrix *= num;
    return output_matrix;
}
/**
 * This function multiplying each matrix cell in the number and updating the matrix by that multiplication.
 * This function overloading the matrix *= num operator.
 */
Matrix& Matrix::operator*= (const double num)
{
    for (unsigned int i = 0; i < this->getValues().size(); ++i) {
        this->values.at(i) *= num;
    }
    return  *this;
}
/**
 * This function performs a matrix multiplication and returns a new matrix based on that multiplication.
 * This function overloading the matrix * matrix operator.
 */
Matrix Matrix::operator* (const Matrix& matrix)
{
    Matrix output_matrix{*this};
    output_matrix *= matrix;
    return output_matrix;
}
/**
 * This function performs a matrix multiplication and updating the left matrix based on that multiplication.
 * This function overloading the matrix *= matrix operator.
 */
Matrix& Matrix::operator*= (const Matrix& matrix)
{
    if (this->num_of_columns != matrix.num_of_rows)
    {
        throw invalid_argument("the left matrix number of columns must be equal to the right matrix number of rows");
    }
    vector<double> output_vector;
    for (unsigned int i = 0; i < this->num_of_rows; i++) {
        for (unsigned int j = 0; j < matrix.num_of_columns; j++) {
            double value = 0;
            for (size_t k = 0; k < this->num_of_columns ; k++) {
                value+= this->values.at(i*unsigned(this->num_of_columns)+k)*matrix.values.at(k*unsigned(matrix.num_of_columns)+j);
            }
            output_vector.push_back(value);
        }

    }
    this->values = output_vector;
    this->num_of_columns = matrix.num_of_columns;
    return *this;
}
// comparison operations
/**
 * This function check if the values sum of the matrices are equal.
 */
void Matrix::check_sum(const Matrix& matrix1, const Matrix& matrix2, double *sum1, double *sum2)
{
    check_same_size(matrix1, matrix2);
    for (unsigned int i = 0; i < matrix1.values.size(); ++i)
    {
        *sum1 += matrix1.values.at(i);
        *sum2 += matrix2.values.at(i);
    }
}
/**
 * This function check if the left matrix values sum are bigger than the right one.
 * This function overloading the bigger (>) operator.
 */
bool Matrix::operator> (const Matrix& matrix) const
{
    double sum1 = 0;
    double sum2 = 0;
    double *s1 = &sum1;
    double *s2 = &sum2;
    check_sum(*this, matrix, s1, s2);
    sum1 = *s1;
    sum2 = *s2;
    bool ans = sum1 > sum2;
    return ans;
}
/**
 * This function check if the left matrix values sum are bigger than the right one or equal.
 * This function overloading the bigger-equal (>=) operator.
 */
bool Matrix::operator>= (const Matrix& matrix) const
{
    double sum1 = 0;
    double sum2 = 0;
    double *s1 = &sum1;
    double *s2 = &sum2;
    check_sum(*this, matrix, s1, s2);
    sum1 = *s1;
    sum2 = *s2;
    bool ans = sum1 >= sum2;
    return ans;
}
/**
 * This function check if the left matrix values sum are smaller than the right one.
 * This function overloading the smaller (<) operator.
 */
bool Matrix::operator< (const Matrix& matrix) const
{
    double sum1 = 0;
    double sum2 = 0;
    double *s1 = &sum1;
    double *s2 = &sum2;
    check_sum(*this, matrix, s1, s2);
    sum1 = *s1;
    sum2 = *s2;
    bool ans = sum1 < sum2;
    return ans;
}
/**
 * This function check if the left matrix values sum are smaller than the right one or equal.
 * This function overloading the smaller-equal (<=) operator.
 */
bool Matrix::operator<= (const Matrix& matrix) const
{
    double sum1 = 0;
    double sum2 = 0;
    double *s1 = &sum1;
    double *s2 = &sum2;
    check_sum(*this, matrix, s1, s2);
    sum1 = *s1;
    sum2 = *s2;
    bool ans = sum1 <= sum2;
    return ans;
}
/**
 * This function check if the there's a cell that is not equal to the same cell in the other matrix.
 * This function overloading the unequal (==) operator.
 */
bool zich::operator!= (Matrix const & matrix1,Matrix const & matrix2)
{
    Matrix::check_same_size(matrix1, matrix2);
    bool ans = false;
    for (unsigned int i = 0; i < matrix1.values.size(); ++i) {
        if (matrix1.values.at(i) != matrix2.values.at(i))
        {
            ans = true;
        }
    }
    return ans;
}
/**
 * This function checks if each cell is equal to the other matrix cell.
 * This function overloading the equalization (==) operator.
 */
bool zich::operator== (Matrix const & matrix1,Matrix const & matrix2)
{
    return !(matrix1 != matrix2);
}
/**
 * This function overloading the output (<<) operator.
 */
ostream& zich::operator<< (ostream& output, const Matrix& matrix)
{
    for (unsigned int i = 0; i < matrix.num_of_rows; i++)
    {
        output << '[';
        for (unsigned int j = 0; j < matrix.num_of_columns; j++)
        {
            if (j == matrix.num_of_columns - 1)
            {
                output << matrix.values.at(i * unsigned(matrix.num_of_columns) + j);
            }
            else
            {
                output << matrix.values.at(i * unsigned(matrix.num_of_columns) + j) << ' ';
            }
        }
        if (i == matrix.num_of_rows - 1)
        {
            output << ']';
        }
        else
        {
            output << ']' << '\n';
        }
    }
    return output;
}
/**
 * This function overloading the input (>>) operator.
 */
istream& zich::operator >>(istream& in,Matrix &matrix) {
    vector<double> output_vector;
    int row=0;
    int row_len = 1;
    int counter = 1;
    double value = 0;
    bool first = false;
    string str_value;
    char ch = in.get();
    while(ch!='\n'){
        if(ch==' '){
            value= stod(str_value);
            output_vector.push_back(value);
            str_value="";
            counter++;
        }
        if(ch==','){
            row++;
            if(first&&row_len!=counter){
                throw invalid_argument("wrong input for matrix");
            }
            if(!first) {
                row_len = counter;
                first= true;
            }
            counter=0;

        }
        if(ch!='['&&ch!=']') {
            str_value += ch;
        }
        ch = in.get();

    }
    matrix.num_of_columns=row_len;
    matrix.num_of_rows= row;
    matrix.values = output_vector;
    return in;
}