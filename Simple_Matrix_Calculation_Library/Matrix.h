#ifndef MATRIX_H
#define MATRIX_H
#include <array>


template <typename T, std::size_t n, std::size_t m>
using Matrix = std::array<std::array<T, m>, n>;


template <typename T, std::size_t n, std::size_t m>
Matrix<T, n, m> operator+(const Matrix<T, n, m>& A, const Matrix<T, n, m>& B) {
	Matrix<T, n, m> result;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			result[i][j] = A[i][j] + B[i][j];
		}
	}
	return result;
}

template <typename T, std::size_t n, std::size_t m>
Matrix<T, n, m> operator-(const Matrix<T, n, m>& A, const Matrix<T, n, m>& B) {
	Matrix<T, n, m> result;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			result[i][j] = A[i][j] - B[i][j];
		}
	}
	return result;
}

template <typename T1, typename T2, std::size_t n, std::size_t m>
Matrix<T1, n, m> operator*(const T2& c, const Matrix<T1, n, m>& A) {
	Matrix<T1, n, m> result;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			result[i][j] = c * A[i][j];
		}
	}
	return result;
}

template <typename T1, typename T2, std::size_t n, std::size_t m>
Matrix<T1, n, m> operator*(const Matrix<T1, n, m>& A, const T2& c) {
	return c * A;
}

template <typename T, std::size_t n, std::size_t m, std::size_t l>
Matrix<T, n, m> operator*(const Matrix<T, n, l>& A, const Matrix<T, l, m>& B) {
	Matrix<T, n, l> result = { 0 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < l; k++) {
				result[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	return result;
}


template <typename T, std::size_t n, std::size_t m>
Matrix<T, n, m> Zeros() {
	Matrix<T, n, m> result;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			result[i][j] = 0;
		}
	}
	return result;
}

template <typename T, std::size_t n, std::size_t m>
Matrix<T, n, m> Ones() {
	Matrix<T, n, m> result;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			result[i][j] = 1;
		}
	}
	return result;
}

#endif