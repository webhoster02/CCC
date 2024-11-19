#include <stdio.h>

int main() {
    int dusa;
    int yobi;
    scanf("%d", &dusa);

    while (scanf("%d", &yobi) == 1) {
        if (yobi >= dusa) { // Too big to eat!
            printf("%d", dusa);
            return 0;
        }
        dusa += yobi;
    }

    return 0;
}