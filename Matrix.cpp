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
    this->num_of_rows = num;
}
void Matrix::setNumberOfColumns(const int num)
{
    this->num_of_columns = num;
}
void Matrix::setValues(const vector<double>& values)
{
    this->values = values;
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
void Matrix::operator+= (const Matrix& matrix)
{
    *this = *this + matrix;
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
void Matrix::operator-= (const Matrix& matrix)
{
    *this = *this - matrix;
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
Matrix Matrix::operator++ ()
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
Matrix Matrix::operator-- ()
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
void Matrix::operator*= (const double num)
{
    for (unsigned int i = 0; i < this->values.size(); ++i) {
        this->values.at(i) *= num;
    }
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
void Matrix::operator*= (const Matrix& matrix)
{
    if (this->num_of_columns != matrix.num_of_rows)
    {
        throw invalid_argument("the left matrix number of columns must be equal to the right matrix number of rows");
    }
    vector<double> output_vector;
    for (unsigned int i = 0; i < this->num_of_rows; ++i) {
        for (unsigned int j = 0; j < this->num_of_rows; ++j) {
            double new_value = 0;
            for (unsigned int k = 0; k < matrix.num_of_rows; ++k) {
                new_value += this->values.at(i*unsigned(this->num_of_columns) + k) * matrix.values.at(k*unsigned(matrix.num_of_columns) + j);
            }
            output_vector.push_back(new_value);
        }
    }
    this->values = output_vector;
    this->num_of_columns = matrix.num_of_columns;
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
bool Matrix::operator!= (const Matrix& matrix)
{
    check_same_size(*this, matrix);
    bool ans = false;
    for (unsigned int i = 0; i < this->values.size(); ++i) {
        if (this->values.at(i) != matrix.values.at(i))
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
bool Matrix::operator== (const Matrix& matrix)
{
    return !(*this != matrix);
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
istream& zich::operator>> (istream& input , Matrix& matrix)
{
    string given_string;
    char ch = 'a';
    while (ch != '\n')
    {
        ch = input.get();
        given_string += ch;
    }
    given_string.pop_back();
    string value_str;
    vector<double> values;
    int num_of_rows = 1;
    int num_of_columns = 1;
    bool first_row = true;
    for (unsigned int i = 0; i < given_string.size(); ++i) {
        ch = given_string.at(i);
        if (ch != ' ')
        {
            if (ch == ',')
            {
                double value = stod(value_str);
                values.push_back(value);
                num_of_rows++;
                if (!first_row)
                {
                    if (num_of_columns != matrix.num_of_columns)
                    {
                        throw invalid_argument("The string you have provided does not have the same number of columns in each row");
                    }
                }
                first_row = false;
                matrix.num_of_columns = num_of_columns;
                num_of_columns = 1;
            }
            else
            {
                value_str += ch;
            }
        }
        else
        {
            num_of_columns++;
            double value = stod(value_str);
            value_str = "";
            values.push_back(value);
            num_of_columns++;
        }
    }
    matrix.num_of_rows = num_of_rows;
    matrix.values = values;
    return input;
}