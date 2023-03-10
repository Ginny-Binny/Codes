#include <iostream>
#include <vector>

using namespace std;

const int N = 40;	// length of vector

/**
 * @brief Sums up N numbers
 *
 * @param accum	The accumulative value
 * @param size	The size of the vector
 * @param data	The vector holding the data elements
 * @return		The sum of all elements in vector
 */
template <typename T>
T const& sum(T& accum, const T size, const vector<int>& data) {
	accum = 0;

	for(int i = 0; i < size; ++i)
		accum += data[i];

	return accum;
}

int main(int argc, char** argv) {
	int accum = 0;

	vector<int> data(N);

	for(int i = 0; i < N; ++i)
		data[i] = i;

	sum(accum, N, data);

	cout << "sum is " << accum << endl;

	return 0;
}