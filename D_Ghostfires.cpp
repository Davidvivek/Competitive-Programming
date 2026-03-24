#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**
 * Problem D: Ghostfires
 * The constraints (dist 1 and 3) only connect indices of different parity.
 * This makes the underlying constraint graph Bipartite.
 * A greedy approach that prioritizes the most frequent available color
 * is optimal for maximizing the sequence length.
 */

void solve() {
    long long r, g, b;
    if (!(cin >> r >> g >> b)) return;

    // Use an array to make it easy to iterate through colors
    long long counts[3] = {r, g, b};
    char labels[3] = {'R', 'G', 'B'};
    
    string s = "";
    
    while (true) {
        int best_idx = -1;
        long long max_count = -1;

        for (int i = 0; i < 3; ++i) {
            if (counts[i] <= 0) continue;

            char current_color = labels[i];
            int n = s.size();
            
            // Check constraints: s[i] != s[i-1] and s[i] != s[i-3]
            bool possible = true;
            if (n >= 1 && s[n - 1] == current_color) possible = false;
            if (n >= 3 && s[n - 3] == current_color) possible = false;

            if (possible) {
                // Greedy choice: pick the color we have the most of
                if (counts[i] > max_count) {
                    max_count = counts[i];
                    best_idx = i;
                }
            }
        }

        if (best_idx == -1) break; // No more valid colors can be placed

        s += labels[best_idx];
        counts[best_idx]--;
    }

    cout << s << "\n";
}

int main() {
    // Optimize I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}