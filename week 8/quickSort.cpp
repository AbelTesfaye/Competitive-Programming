#include <bits/stdc++.h>
using namespace std;


void quickSort(vector <int> &arr) {
	// Complete this function
    if (arr.size() < 2) return;

    vector <int> l, r;

    int pivot = arr[0];

    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] <= pivot) {
            l.push_back(arr[i]);
        }
        else {
            r.push_back(arr[i]);
        }
    }
    quickSort(l);
    quickSort(r);

    int pi = 0;

    for (int i = 0; i < l.size(); ++i) {
        arr[pi++] = l[i];
        cout << l[i] << " ";
    }

    arr[pi++] = pivot;
    cout << pivot << " ";

    for (int i = 0; i < r.size(); ++i) {
        arr[pi++] = r[i];
        cout << r[i] << " ";
    }
    cout << endl;
}


int main()
{
    int n;
    cin >> n;

    vector <int> arr(n);
    for(int i = 0; i < (int)n; ++i) {
        cin >> arr[i];
    }

    quickSort(arr);

    return 0;
}
