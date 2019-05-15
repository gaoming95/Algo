#include<iostream>
#include<vector>
using namespace std;
int main(){

    int n;
	cin >> n;
	vector<vector<int>> a;

    for (int i=0; i<n; ++i){
		a.push_back(vector<int>());
		for (int j = i; j < n; ++j) {
			int v;
			cin >> v;
			a[i].push_back(v);
		}
	}

	int rows = a.size();
	int cols = a[0].size();
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
    return 0;
}