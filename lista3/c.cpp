#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

// Evaluate a WFF for given variable values
bool evaluate(const string& wff, const vector<bool>& vars) {
    stack<bool> st;
    // p=0, q=1, r=2, s=3, t=4
    for (int i = wff.size() - 1; i >= 0; i--) {
        char c = wff[i];
        if (c == 'p') st.push(vars[0]);
        else if (c == 'q') st.push(vars[1]);
        else if (c == 'r') st.push(vars[2]);
        else if (c == 's') st.push(vars[3]);
        else if (c == 't') st.push(vars[4]);
        else if (c == 'N') {
            bool a = st.top(); st.pop();
            st.push(!a);
        } else {
            bool a = st.top(); st.pop();
            bool b = st.top(); st.pop();
            if (c == 'K') st.push(a && b);
            else if (c == 'A') st.push(a || b);
            else if (c == 'C') st.push(!a || b); // implication
            else if (c == 'E') st.push(a == b);  // biconditional
        }
    }
    return st.top();
}

int main() {
    string wff;
    while (cin >> wff && wff != "0") {
        bool tautology = true;
        // Try all 2^5 = 32 truth assignments for p, q, r, s, t
        for (int mask = 0; mask < 32; mask++) {
            vector<bool> vars(5);
            for (int i = 0; i < 5; i++) {
                vars[i] = (mask >> i) & 1;
            }
            if (!evaluate(wff, vars)) {
                tautology = false;
                break;
            }
        }
        if (tautology) cout << "tautology\n";
        else cout << "not\n";
    }
    return 0;
}