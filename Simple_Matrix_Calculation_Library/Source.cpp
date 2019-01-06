#pragma once
#include "Matrix.h"

int main() {
	auto Z = Ones<int, 2, 2>();
	Z[0][1] = 2;
	Z[1][0] = 2;

	auto C = Zeros<int, 2, 2>();

	C = Z * Z;

	return 0;
}
