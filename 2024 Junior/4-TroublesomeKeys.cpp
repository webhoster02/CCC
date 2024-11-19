#include <iostream>

using namespace std;

int main() {
    string pressed;
    string preview;
    cin >> pressed;
    cin >> preview;
    
    // Find the silly and quiet keys
    char sillyPressed = '-';
    char sillyPreview = '-';
    char silent = '-';
    for (int i = 0; i < pressed.length(); i++) {
        if (pressed[i] != preview[i]) {
            if (pressed[i + 1] == preview[i]) { // Silent key found
                silent = pressed[i];
            } else { // Silly key found
                sillyPressed = pressed[i];
                sillyPreview = preview[i];
            }

            if ('-' != sillyPressed && '-' != sillyPreview && '-' != silent) {
                break;
            }
        }
    }

    cout << sillyPressed << " " << sillyPreview;
    cout << "\n" << silent;
    return 0;
}