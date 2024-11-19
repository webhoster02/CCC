#include <iostream>

using namespace std;

int main() {
    int N; // Number of participants
    cin >> N;
    int scores[N]; // Their scores

    // Finding the third largest number
    int first = 0;
    int second = 0;
    int third = 0;
    for (int i = 0; i < N; i++) {
        cin >> scores[i];
        if (scores[i] == first || scores[i] == second || scores[i] == third) {
            continue;
        }
        else if (scores[i] > first ) {
            third = second;
            second = first;
            first = scores[i];
        }
        else if (scores[i] > second) {
            third = second;
            second = scores[i];
        }
        else if (scores[i] > third) {
            third = scores[i];
        }
    }

    int P = 0;
    // Finding how many times third is in the list
    for (int i = 0; i < N; i++) {
        if (scores[i] == third) P++;
    }

    cout << "" << third << " " << P;

    return 0;
}