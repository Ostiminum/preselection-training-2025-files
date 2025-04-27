#include <bits/stdc++.h>
#include <ext/rope>

using namespace std;
using namespace __gnu_cxx;

vector<crope> states(1);

void Init() {}

void TypeLetter(char L) {
    states.push_back(states.back()+L);
    // cout << states.back() << endl;
}

void UndoCommands(int U) {
    states.push_back(states[states.size()-U-1]);
    // cout << states.back() << endl;
}

char GetLetter(int P) {
    return states.back()[P];
}