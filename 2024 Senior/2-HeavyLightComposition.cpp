#include <iostream>
#include <cstdio> // For scanf and printf
#include <vector>

using namespace std;

char scanLine(int N, int C) {
    char output = 'T';
    char line[C + 1];

    // Find the heavy letters
    vector<bool> foundOnce(26);
    vector<bool> heavyLetters(26); // letters we know are heavy
    for (int i = 1; i < C + 1; i++) {
        // Get the character
        char ch;
        scanf(" %c", &ch);
        if (output == 'F') continue; 
        line[i] = ch;
        
        // early break: same character twice = not alternating for sure
        if (line[i] == line[i-1])
            output = 'F';

        // Set the heavyletter of the character
        if (!heavyLetters[ch-97]) {
            if (!foundOnce[ch-97]) { 
                foundOnce[ch-97] = true;
            } else {
                heavyLetters[ch-97] = true;
            }
        }
        
    }

    if (output == 'F') return output;

    bool firstHeavy = heavyLetters[line[1]-97];
    for (int i = 1; i < C + 1; i++) {
        char ch = line[i];
        bool heavy = heavyLetters[ch-97];
        if (heavy != (i % 2 == firstHeavy))
            return 'F';
    }
    return output;
}

int main() {
    int N, C;
    
    // Use scanf to read two integers in a single line
    scanf("%d %d", &N, &C);
    
    char output[N];

    for (int i = 0; i < N; i++) {
        output[i] = scanLine(N, C);
        getchar(); // Removes the newline
    }

    for (int i = 0; i < N; i++) {
        cout << output[i] << "\n";
    }
    
    return 0;
}