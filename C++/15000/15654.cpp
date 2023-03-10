#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool chk[8] = {0, };

void func(vector<int> vec, vector<int> arr, int i, int M) {
    if(i==M) {
        for(int j=0; j<arr.size(); j++) {
            cout << arr[j] << " ";
        }
        cout << "\n";

        return;
    }

    for(int j=0; j<vec.size(); j++) {
        if(chk[j]) continue;

        arr.push_back(vec[j]);
        chk[j] = true;
        
        func(vec, arr, i+1, M);

        arr.pop_back();
        chk[j] = false;
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> vec(N);
    vector<int> arr;

    for(int i=0; i<N; i++) {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

    func(vec, arr, 0, M);
}