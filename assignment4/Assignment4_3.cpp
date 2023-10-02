#include <iostream>
using namespace std;
class Matrix
{
private:
    int row;
    int col;
    int **arr = NULL;

public:
    Matrix()
    {
        this->row = 1;
        this->col = 1;
        this->arr = new int *[this->row];
        for (int i = 0; i < this->row; i++)
        {
            arr[i] = new int[this->col];
        }
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->col; j++)
            {
                arr[i][j] = 0;
            }
        }
    }
    Matrix(int row, int col)
    {
        this->row = row;
        this->col = col;
        this->arr = new int *[row];
        for (int i = 0; i < row; i++)
        {
            arr[i] = new int[col];
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                arr[i][j] = 0;
            }
        }
        cout << "matrix is created succefully!" << endl;
    }
    int getRow()
    {
        return this->row;
    }
    int getCol()
    {
        return this->col;
    }
    void setArr(int i, int j, int num)
    {
        this->arr[i][j] = num;
    }
    int getArr(int i, int j)
    {
        return this->arr[i][j];
    }

    void accept()
    {
        cout << "Enter Value in Matrix: " << endl;
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->col; j++)
            {
                cout << "Matrix[" << i << "][" << j << "] : " << endl;
                cin >> this->arr[i][j];
            }
        }
    }
    void print()
    {
        cout << "Matrix: " << endl;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    ~Matrix()
    {
        for (int i = 0; i < this->row; i++) // deallocating  elements
            if (arr[i] != NULL)
            {
                delete[] this->arr[i];
                this->arr[i] = NULL;
            }
        if (arr != NULL)
        {
            delete[] arr; // deallocating array
            this->arr = NULL;
        }
    }
};
Matrix *add(Matrix *mat1, Matrix *mat2)
{
    if ((mat1->getRow() == mat2->getRow()) && (mat1->getCol() == mat2->getCol()))
    {
        int row = mat1->getRow();
        int col = mat1->getCol();
        Matrix *mat3 = new Matrix(row, col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                mat3->setArr(i, j, (mat1->getArr(i, j) + mat2->getArr(i, j)));
            }
        }
        return mat3;
    }
    else
    {
        cout << "Addition not possible because there is different diamention :(" << endl;
        return NULL;
    }
}
Matrix *subtract(Matrix *mat1, Matrix *mat2)
{
    if ((mat1->getRow() == mat2->getRow()) && (mat1->getCol() == mat2->getCol()))
    {
        int row = mat1->getRow();
        int col = mat1->getCol();
        Matrix *mat3 = new Matrix(row, col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                mat3->setArr(i, j, (mat1->getArr(i, j) - mat2->getArr(i, j)));
            }
        }
        return mat3;
    }
    else
    {
        cout << "Substrction not possible because there is different diamention :(" << endl;
        return NULL;
    }
}
Matrix *multiply(Matrix *mat1, Matrix *mat2)
{
    if (mat1->getCol() == mat2->getRow())
    {
        int row = mat1->getRow();
        int col1 = mat1->getCol();
        int col = mat2->getCol();

        Matrix *mat3 = new Matrix(row, col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                int ans = 0;
                for (int k = 0; k < col1; k++)
                {
                    ans += (mat1->getArr(i, k) * mat2->getArr(k, j));
                }
                mat3->setArr(i, j, ans);
            }
        }
        return mat3;
    }
    else
    {
        cout << "Matrix multiplication is not possible on this diamention :(" << endl;
        return NULL;
    }
}
Matrix *transpose(Matrix *mat1)
{
    int row = mat1->getRow();
    int col = mat1->getCol();
    Matrix *mat3 = new Matrix(col, row);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            mat3->setArr(j, i, (mat1->getArr(i, j)));
        }
    }
    return mat3;
}
int menu()
{
    int choice;
    cout << "0. exit\n1. Add/change matrix1 value\n2. Add/change Matrix2 value\n3. ADD Mat1+Mat2" << endl;
    cout << "4. Substract Mat1-MAt2\n5. Multiply Mat1*Mat2\n6. Transpose Mat1" << endl;
    cout << "Enter your choice: " << endl;
    cin >> choice;
    return choice;
}

int main()
{
    Matrix *mat1 = NULL;
    Matrix *mat2 = NULL;
    Matrix *ans = NULL;
    int choice;
    int row;
    int col;
    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
        {

            if (mat1 == NULL)
            {
                cout << "Enter the row: " << endl;
                cin >> row;
                cout << "Enter the col: " << endl;
                cin >> col;
                mat1 = new Matrix(row, col);
                mat1->accept();
            }
            else
            {
                mat1->accept();
            }
            break;
        }
        case 2:
        {
            if (mat2 == NULL)
            {
                cout << "Enter the row: " << endl;
                cin >> row;
                cout << "Enter the col: " << endl;
                cin >> col;
                mat2 = new Matrix(row, col);
                mat2->accept();
            }
            else
            {
                mat2->accept();
            }
            break;
        }
        case 3:
        {
            if (mat1 != NULL && mat2 != NULL)
            {
                ans = add(mat1, mat2);
                ans->print();
                delete ans;
                ans = NULL;
            }
            else
            {
                cout << "Matrix not Found please create Matrix to do this operation: " << endl;
            }
            break;
        }
        case 4:
        {
            if (mat1 != NULL && mat2 == NULL)
            {
                ans = subtract(mat1, mat2);
                ans->print();
                delete ans;
                ans = NULL;
            }
            else
            {
                cout << "Matrix not Found please create Matrix to do this operation: " << endl;
            }
            break;
        }
        case 5:
        {
            if (mat1 != NULL && mat2 != NULL)
            {
                ans = multiply(mat1, mat2);
                ans->print();
                delete ans;
                ans = NULL;
            }
            else
            {
                cout << "Matrix not Found please create Matrix to do this operation: " << endl;
            }
            break;
        }
        case 6:
        {
            if (mat1 != NULL)
            {
                ans = transpose(mat1);
                ans->print();
                delete ans;
                ans = NULL;
            }
            else
            {
                cout << "Matrix not Found please create Matrix" << endl;
            }
            break;
        }
        default:
        {
            cout << "Wrong choice!" << endl;
            break;
        }
        }
        cout << "-----------------------" << endl;
    }
    if (mat1 != NULL)
    {
        delete mat1;
        mat1 = NULL;
    }
    if (mat2 != NULL)
    {
        delete mat2;
        mat2 = NULL;
    }
    if (ans != NULL)
    {
        delete ans;
        ans = NULL;
    }
    return 0;
}