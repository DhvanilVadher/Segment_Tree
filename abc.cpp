#include<bits/stdc++.h>
using namespace std;
vector<int>v(30);
int BUILD(int a[],int start,int end,int count)
{
    int mid = (start + end) / 2;
    if(start>end)return 0 ;
    else if(start < end){
        v[count] = BUILD(a,start,mid,count*2+1) + BUILD(a,mid+1,end,count*2+2);
        return v[count];
    } else {
        v[count] = a[start];
        return v[count];
    }
}
int READ(int a[],int start,int end ,int left ,int right, int count) {
    int mid = (start + end) / 2;
    if (left > end || right < start) {
        return 0;
    } else if (start == left && end == right) {
        return v[count];
    } else if (left > mid) {
        return READ(a, mid + 1, end, left, right, count * 2 + 2);
    } else if (right <= mid) {
        return READ(a, start, mid, left, right, count * 2 + 1);
    } else {
        return READ(a, start, mid, left, mid, count * 2 + 1) + READ(a, mid + 1, end, mid+1, right, count * 2 + 2);
    }
}
int UPDATEELE(int a[],int start,int end,int indx , int val,int count) {
    int mid = (start + end) / 2;
    if (indx > mid) {
        int p = UPDATEELE(a, mid + 1, end, indx, val, count * 2 + 2);
        v[count] = v[count * 2 + 1] + p;
        return v[count];
    } else if (mid == start && mid == end && mid == indx) {
        v[count] = val;
        return v[count];
    } else {
        int p = UPDATEELE(a, start, mid, indx, val, count * 2 + 1);
        v[count] = v[count * 2 + 2] + p;
        return v[count];
    }
}

int main() {
    int a[10] = {0};
    for (int i = 0; i < 10; i++) {
        a[i] = i + 1;
        cout << a[i] << " ";

    }
    cout << endl;
    cout << BUILD(a, 0, 9, 0) << endl;
    for (int i = 0; i < 20; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    cout << READ(a, 0, 9, 0, 5, 0) << endl;
    cout << READ(a, 0, 9, 1, 7, 0) << endl;
    UPDATEELE(a,0,9,4,3,0);
    for (int i = 0; i < 20; i++) {
        cout << v[i] << " ";
    }
    cout << READ(a, 0, 9, 0, 5, 0) << endl;
    cout << READ(a, 0, 9, 1, 7, 0) << endl;

}
