#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
class p_q {
public:
    vector<ll> vec;
public:
    void push(ll a) {
        if (vec.empty()) {
            vec.push_back(a);
        } else {
            vec.push_back(a);
            auto itr = vec.end();
            ll ind = itr - vec.begin();
            while (ind > 0) {
                if (vec[ind / 2] < vec[ind]) {
                    swap(vec[ind / 2], vec[ind]);
                    ind = ind / 2;
                } else {
                    break;
                }
            }
        }
    }

    long long int top() {
        if (vec.empty()) {
            return LONG_LONG_MIN;
        } else {
            return vec[0];
        }
    }

    void pop() {
        long long int i = 0;
        while (vec.size() > 2 * i + 2) {
            if (vec[2 * i + 1] < vec[2 * i + 2]) {
                vec[i] = vec[2 * i + 1];
                i = 2 * i + 1;
            } else {
                vec[i] = vec[2 * i + 2];
                i = 2 * i + 2;
            }
        }

        if (2 * i + 2 == vec.size()) {
            vec[i] = 2 * i + 1;
            i = 2 * i + 1;
        }
        vec.pop_back();
    }
};
int main() {
    p_q mypq;
    for (long long int i = 0; i < 20; i++) {
        mypq.push(i);
    }
    for (int i = 0; i < mypq.vec.size(); i++) {
        cout << mypq.vec[i] << endl;
    }
    for (long long int i = 0; i < 20; i++) {
        cout << mypq.top() << endl;
        mypq.pop();
    }
    cout << "aaaaaaaaaaaaaaaaaaaaaaaaaaa" << endl;
    for (int i = 0; i < mypq.vec.size(); i++) {
        cout << mypq.vec[i] << endl;
    }
}
