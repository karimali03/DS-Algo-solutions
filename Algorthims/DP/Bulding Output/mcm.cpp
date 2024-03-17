#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>
#include <cassert>
using namespace std;

const int MAX = 100 + 1;
int memory[MAX][MAX];

vector<int> rows, cols;

int mcm(int start_idx, int end_idx) {	// O(N^3) time
	if (start_idx == end_idx)
		return 0;	// a single matrix: no multiplication

	auto &ret = memory[start_idx][end_idx];
	if (ret != -1)
		return ret;

	ret = INT_MAX;
	for (int k = start_idx; k < end_idx; k++) { // < NOT <=
		int blocks_mult = rows[start_idx] * cols[k] * cols[end_idx];
		int sub1 = mcm(start_idx, k);
		int sub2 = mcm(k + 1, end_idx);
		int total_k = blocks_mult + sub1 + sub2;
		ret = min(ret, total_k);
	}

	return ret;
}

void print_mcm(int start_idx, int end_idx) {	// O(N^3) time
	if (start_idx == end_idx)
		cout<<"{ "<<rows[start_idx]<<", "<<cols[end_idx]<<" }";

	int optimal = mcm(start_idx,end_idx);

	
	for (int k = start_idx; k < end_idx; k++) { // < NOT <=
		int blocks_mult = rows[start_idx] * cols[k] * cols[end_idx];
		int sub1 = mcm(start_idx, k);
		int sub2 = mcm(k + 1, end_idx);
		int total_k = blocks_mult + sub1 + sub2;
		if(total_k == optimal){
            print_mcm(start_idx,k);
            cout<<" X ";
            print_mcm(k+1,end_idx);
            return;
        }
	}

}



int test1(const vector<vector<int>> &data) {
	rows.resize(data.size());
	cols.resize(data.size());

	for (int i = 0; i < (int)data.size(); ++i)
		rows[i] = data[i][0], cols[i] = data[i][1];

	memset(memory, -1, sizeof(memory));
    print_mcm(0,(int) rows.size() - 1);
	return mcm(0, (int) rows.size() - 1);
}

int main() {
	assert(18 == test1({{1, 2}, {2, 3}, {3, 4}}) );
	assert(1615 == test1({{5, 10}, {10, 19}, {19, 7}}) );

	// A common books format is a single array: [5, 10, 19, 7]
	return 0;
}
