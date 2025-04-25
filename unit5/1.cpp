#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll MAX = 3 * 1e5, ANS_MAX = 3 * 1e14;

int t, n, k;
ll l, r, curr, ans;
vector<ll> arr(MAX+5);
bool possible;

void calc_size(vector<int>& ans_arr) {
    priority_queue<ll> pq;
    ll curr_sum = 0;

    for (int i = 0; i < n; ++i) {
        pq.push(arr[i]);
        curr_sum += arr[i];

        while (curr_sum > curr) {
            curr_sum -= pq.top();
            pq.pop();
        }

        ans_arr[i+1] = pq.size();
    }
}

int main() {
    cin >> t;

    while (t--) {
        cin >> n >> k;

        for (int i = 0; i < n; ++i) cin >> arr[i];

        l = 1, r = ANS_MAX;

        while (l <= r) {
            curr = (l+r)/2;

            possible = false;

            vector<int> prefix(n+1, 0), suffix(n+1, 0);

            calc_size(prefix);
            reverse(arr.begin(), arr.begin()+n);
            
            calc_size(suffix);
            reverse(arr.begin(), arr.begin()+n);
            reverse(suffix.begin(), suffix.end());

            // for (int i = 0; i <= n; ++i) cout << prefix[i] << " ";
            // cout << endl;

            // for (int i = 0; i <= n; ++i) cout << suffix[i] << " ";
            // cout << endl;
            
            // cout << "Remember, k is " << k << endl;
            for (int i = 0; i <= n; ++i) {
                // cout << prefix[i]+suffix[i] << " ";
                if (prefix[i] + suffix[i] >= k) {
                    possible = true;
                }
            }
            // cout << endl;

            if (possible) {
                // cout << curr << " is possible!\n";
                ans = curr;
                r = curr-1;
            } else {
                // cout << curr << " is not possible!\n";
                l = curr+1;
            }
        }

        cout << ans << endl;
    }
}
