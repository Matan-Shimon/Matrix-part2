#include <iostream>
#include "Matrix.hpp"

using namespace std;
using namespace zich;

int main() {
    Matrix final_matrix;
    bool logistic_ans = false;
    int choice1 = 0;
    while (choice1 != 1 && choice1 != 2)
    {
        cout << "Choose creation:\n";
        cout << "1 : Matrix\n";
        cout << "2 : float number\n" << endl;
        cin >> choice1;
    }
    Matrix matrix1;
    Matrix matrix2;
    double num;
    if (choice1 == 1)
    {
        int num_of_rows = 0;
        while (num_of_rows <= 0)
        {
            cout << "Enter number of rows (must be positive): ";
            cin >> num_of_rows;
        }
        int num_of_columns = 0;
        while (num_of_columns <= 0)
        {
            cout << "Enter number of columns (must be positive): ";
            cin >> num_of_columns;
        }
        vector<double> matrix_vector;
        for (int i = 0; i < num_of_rows*num_of_columns; ++i) {
            double value;
            cout << "Enter value: ";
            cin >> value;
            matrix_vector.push_back(value);
        }
        matrix1.setNumberOfRows(num_of_rows);
        matrix1.setNumberOfColumns(num_of_columns);
        matrix1.setValues(matrix_vector);
    }
    else
    {
        cout << "Enter floating point number: ";
        cin >> num;
    }
    int action = 1;
    if (choice1 == 1)
    {
        action = 0;
        while (action != 1 && action != 2)
        {
            cout << "\nChoose action:\n";
            cout << "1: Arithmetic action\n";
            cout << "2: Comparison action\n";
            cin >> action;
        }
    }
    int arithmetic_action = 0;
    int comparison_action = 0;
    if (action == 1)
    {
        if (choice1 == 1)
        {
            while (arithmetic_action < 1 || arithmetic_action > 8)
            {
                cout << "\nChoose arithmetic action:\n";
                cout << "1: +\n";
                cout << "2: -\n";
                cout << "3: *\n";
                cout << "4: +=\n";
                cout << "5: ++\n";
                cout << "6: -=\n";
                cout << "7: --\n";
                cout << "8: *=\n";
                cin >> arithmetic_action;
            }
        }
    }
    else
    {
        while (comparison_action < 1 || comparison_action > 6)
        {
            cout << "1: >\n";
            cout << "2: >=\n";
            cout << "3: <\n";
            cout << "4: <=\n";
            cout << "5: ==\n";
            cout << "6: !=\n";
            cin >> comparison_action;
        }
    }
    int choice2 = 1;
    if (arithmetic_action != 5 && arithmetic_action != 7)
    {
        if (choice1 == 1 && action == 1 && (arithmetic_action == 3 || arithmetic_action == 8))
        {
            choice2 = 0;
            while (choice2 != 1 && choice2 != 2)
            {
                cout << "Choose creation:\n";
                cout << "1 : Matrix\n";
                cout << "2 : float number\n" << endl;
                cin >> choice2;
            }
        }
        if (choice2 == 1)
        {
            int num_of_rows = 0;
            while (num_of_rows <= 0)
            {
                cout << "Enter number of rows for matrix (must be positive): ";
                cin >> num_of_rows;
            }
            int num_of_columns = 0;
            while (num_of_columns <= 0)
            {
                cout << "Enter number of columns for matrix (must be positive): ";
                cin >> num_of_columns;
            }
            vector<double> matrix_vector;
            for (int i = 0; i < num_of_rows*num_of_columns; ++i) {
                double value;
                cout << "Enter value: ";
                cin >> value;
                matrix_vector.push_back(value);
            }
            matrix2.setNumberOfRows(num_of_rows);
            matrix2.setNumberOfColumns(num_of_columns);
            matrix2.setValues(matrix_vector);
        }
        else
        {
            cout << "Enter floating point number: ";
            cin >> num;
        }
    }
    if (choice1 == 1)
    {
        if (choice2 == 1)
        {
            if (action == 1)
            {
                switch (arithmetic_action) {
                    case 1:
                        final_matrix = matrix1 + matrix2;
                        break;case 2:final_matrix = matrix1 - matrix2;
                        break;case 3:final_matrix = matrix1 * matrix2;
                        break;case 4:matrix1 += matrix2;
                        final_matrix = matrix1;
                        break;case 5:matrix1++;
                        final_matrix = matrix1;
                        break;case 6:matrix1 -= matrix2;
                        final_matrix = matrix1;
                        break;case 7:matrix1--;
                        final_matrix = matrix1;
                        break;case 8:matrix1 *= matrix2;
                        final_matrix = matrix1;
                        break;default:break;
                }
            }
            else
            {
                cout << "1: >\n";
                cout << "2: >=\n";
                cout << "3: <\n";
                cout << "4: <=\n";
                cout << "5: ==\n";
                cout << "6: !=\n";
                switch (comparison_action) {
                    case 1:
                        logistic_ans = matrix1 > matrix2;
                        break;case 2:logistic_ans = matrix1 >= matrix2;
                        break;case 3:logistic_ans = matrix1 < matrix2;
                        break;case 4:logistic_ans = matrix1 <= matrix2;
                        break;case 5:logistic_ans = matrix1 == matrix2;
                        break;case 6:logistic_ans = matrix1 != matrix2;
                        break;default:break;
                }
            }
        }
        else
        {
            if (arithmetic_action == 1)
            {
                final_matrix = matrix1 * num;
            }
            else
            {
                matrix1 *= num;
                final_matrix = matrix1;
            }
        }
    }
    else
    {
        final_matrix = num * matrix2;
    }
    cout << "You action outcome:" << endl;
    if (action == 1)
    {
        if (choice1 == 1)
        {
            cout << "Matrix 1:" << endl;
            cout << matrix1 << endl;
        }
        else
        {
            cout << "number: " << num << endl;
        }
        if (choice2 == 1)
        {
            cout << "Matrix 2:" << endl;
            cout << matrix2 << endl;
        }
        else
        {
            cout << "number: " << num << endl;
        }

        cout << "outcome matrix:" << endl;
        cout << final_matrix << endl;
    }
    else
    {
        cout << "Matrix 1:" << endl;
        cout << matrix1 << endl;
        cout << "Matrix 2:" << endl;
        cout << matrix2 << endl;
        cout << "comparison value: ";
        cout << logistic_ans << endl;
    }
}