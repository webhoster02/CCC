#include <iostream>
#include <cstdio> // For scanf and printf

using namespace std;

int main() {
    int N, C;
    
    // Use scanf to read two integers in a single line
    scanf("%d %d", &N, &C);
    
    for (int i = 0; i < N; i++) {
        char line[C];
        for (int j = 0; j < C; j++) {
            char ch;
            scanf("%c", &ch);
            line[j] = ch;
        }
    }
    
    cout << N+C;
    return 0;
}
