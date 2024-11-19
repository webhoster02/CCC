#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int hats[N];
    for (int i = 0; i < N/2; i++) {
        cin >> hats[i];
    }
    int matches = 0;
    for (int i = 0; i < N/2; i++) {
        int hat;
        cin >> hat;
        if (hat == hats[i]) matches += 2;
    }
    
    cout << matches;

    return 0;
}
