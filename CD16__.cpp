#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int MAXOfLine(const vector<int>& vec,int  m) {
	stack<int> stk;
	int max = 0;
	int this_res = 0;
	for (int i = 0; i < m; ++i) {
		while (!stk.empty() && vec[stk.top()] >= vec[i]) {
			int j = stk.top();
			stk.pop();
			int k = stk.empty() ? -1 : stk.top();
			this_res = (i - k - 1) * vec[j];
			max = max < this_res ? this_res : max;
		}
		stk.push(i);
	}
	while (!stk.empty()) {
		int j = stk.top();
		stk.pop();
		int len = vec.size();
		int k = stk.empty() ? -1 : stk.top();
		this_res = (len - k - 1) * vec[j];
		max = max < this_res ? this_res : max;
	}
	return max;
}

int MaxRectangle(const vector<vector<bool>>& arr,int n,int  m) {
	vector<int> vec(m, 0);
	int max=0;
	for (int j = 0; j < n; ++j) {
		for (int i = 0; i < m; ++i) {
			vec[i] = arr[j][i] == 0 ? 0: vec[i]+1;
		}	
		int this_res = MAXOfLine(vec, m);
		max = max<this_res? this_res:max;
	}
	return max;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<bool>> arr;
	bool input;
	for (int i = 0; i < n; ++i) {
		vector<bool> vec;
		for (int j = 0; j < m; ++j) {
			cin >> input;
			vec.push_back(input);
		}
		arr.push_back(vec);
	}
	//for (int i = 0; i < n; ++i) {
	//	for (int j = 0; j < m; ++j) {
	//		cout << arr[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	cout << MaxRectangle(arr, n, m);
}