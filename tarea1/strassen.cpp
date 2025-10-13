#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> Matrix;

Matrix addMatrix(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

Matrix subMatrix(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

Matrix strassen(const Matrix& A, const Matrix& B) {
    int n = A.size();
    if (n == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    int k = n / 2;
    // Submatrices
    Matrix A11(k, vector<int>(k)), A12(k, vector<int>(k)), A21(k, vector<int>(k)), A22(k, vector<int>(k));
    Matrix B11(k, vector<int>(k)), B12(k, vector<int>(k)), B21(k, vector<int>(k)), B22(k, vector<int>(k));

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }

    // 7 multiplicaciones de Strassen
    Matrix M1 = strassen(addMatrix(A11, A22), addMatrix(B11, B22));
    Matrix M2 = strassen(addMatrix(A21, A22), B11);
    Matrix M3 = strassen(A11, subMatrix(B12, B22));
    Matrix M4 = strassen(A22, subMatrix(B21, B11));
    Matrix M5 = strassen(addMatrix(A11, A12), B22);
    Matrix M6 = strassen(subMatrix(A21, A11), addMatrix(B11, B12));
    Matrix M7 = strassen(subMatrix(A12, A22), addMatrix(B21, B22));

    // Combinar resultados
    Matrix C11 = addMatrix(subMatrix(addMatrix(M1, M4), M5), M7);
    Matrix C12 = addMatrix(M3, M5);
    Matrix C21 = addMatrix(M2, M4);
    Matrix C22 = addMatrix(subMatrix(addMatrix(M1, M3), M2), M6);

    // Reconstruir matriz completa
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[i + k][j] = C21[i][j];
            C[i + k][j + k] = C22[i][j];
        }
    }
    return C;
}


int main() {
    Matrix A = {{1, 2},
                {3, 4}};

    Matrix B = {{5, 6},
                {7, 8}};

    Matrix C2 = strassen(A, B);

    cout << "Naive result:" << endl;

    cout << "Strassen result:" << endl;
    for (auto& row : C2) {
        for (auto& val : row) cout << val << " ";
        cout << endl;
    }

    return 0;
}
