//#ifndef TP3_EXO1_H
//#define TP3_EXO1_H


#include <string>
#if !defined (__IOSTREAM_H)
#include <iostream>
#endif
#if !defined (__FSTREAM_H)
#include <fstream>
#endif
#if !defined (__ASSERT_H)
#include <assert.h>
#endif
#if !defined(__CMATH_H)
#include <cmath>
#endif
#if !defined (__VECTOR_H)
#include <vector>
#endif

#if !defined(TP3_EXO1H_H)
#define TP3_EXO1H_H



using namespace std;





/*struct mat_profil {
    vector<int> INDIAG;
    vector<double> ATAB;
};*/








mat_profil matrice_profil(double Apleine[], int n){
    double epsilon=1.e-15;

    mat_profil A;
    A.INDIAG.resize(n);
    A.ATAB.resize(n*n);

    A.INDIAG[0]=0;
    A.ATAB[0]=Apleine[0];
    int k=0, ji;
    for (int i=1; i<n; i++){
        for (int j=0; j<=i; j++){
            if (abs(Apleine[i*n+j])>epsilon){
                ji=j;
                break;}
        }
        for (int j=ji; j<=i; j++){
            k++;
            A.ATAB[k]=Apleine[i*n+j];
        }
        A.INDIAG[i]=k;
    }
    A.ATAB.resize(k+1);
    return A;
}

vector<double> prod_mat_vect_sym(const mat_profil& A, const vector<double>& x) {
    int n = A.INDIAG.size();
    vector<double> y(n, 0.0);


    for (int i = 0; i < n; ++i) {
        int ji = (i == 0) ? 0 : i - A.INDIAG[i] + A.INDIAG[i - 1] + 1;

        for (int j = ji; j <= i; ++j) {
            int k = A.INDIAG[i] - i + j;
            y[i] += A.ATAB[k] * x[j];
        }
    }


    for (int i = 1; i < n; ++i) {
        int ji = i - A.INDIAG[i] + A.INDIAG[i - 1] + 1;

        for (int j = ji; j < i; ++j) {
            int k = A.INDIAG[i] - i + j;
            y[j] += A.ATAB[k] * x[i];
        }
    }

    return y;
}

vector<double> prod_mat_vect_sym2(double Apleine[], const vector<double>& x) {
    int n = x.size();
    vector<double> y(n, 0.0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            y[i] += Apleine[i * n + j] * x[j];
        }
    }

    return y;
}







void factorisation_LDL(mat_profil& A) {
    int n = A.INDIAG.size();

    for (int i = 0; i < n; ++i) {
        int ji = (i == 0) ? 0 : i - (A.INDIAG[i] - A.INDIAG[i - 1] - 1);


        for (int j = ji; j < i; ++j) {
            int jj = (j == 0) ? 0 : j - (A.INDIAG[j] - A.INDIAG[j - 1] - 1);
            int k = std::max(ji, jj);

            for (int s = k; s < j; ++s) {
                int idx_js = A.INDIAG[j] - (j - s);
                int idx_is = A.INDIAG[i] - (i - s);
                A.ATAB[A.INDIAG[i] - (i - j)] -= A.ATAB[idx_js] * A.ATAB[idx_is];
            }
        }


        for (int j = ji; j < i; ++j) {
            int idx_ij = A.INDIAG[i] - (i - j);
            double S = A.ATAB[idx_ij] / A.ATAB[A.INDIAG[j]];
            A.ATAB[idx_ij] = S;
            A.ATAB[A.INDIAG[i]] -= S * A.ATAB[idx_ij];
        }
    }
}


vector<double> resolution_LDL(mat_profil& A, const vector<double>& b) {
    int n = A.INDIAG.size();
    vector<double> x = b;


    for (int i = 1; i < n; ++i) {
        int yi = i - (A.INDIAG[i] - A.INDIAG[i - 1] - 1);
        for (int j = yi; j < i; ++j) {
            int k = A.INDIAG[i] - (i - j);
            x[i] -= A.ATAB[k] * x[j];
        }
    }


    for (int i = 0; i < n; ++i) {
        x[i] /= A.ATAB[A.INDIAG[i]];
    }


    for (int i = n - 1; i >= 1; --i) {
        int yi = i - (A.INDIAG[i] - A.INDIAG[i - 1] - 1);
        for (int j = yi; j < i; ++j) {
            int k = A.INDIAG[i] - (i - j);
            x[j] -= A.ATAB[k] * x[i];
        }
    }

    return x;
}






















#endif // !defined VECTEUR_TEMPLATE_H
