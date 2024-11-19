#include <iostream>
#include <vector>

using namespace std;

struct Point {
  int row, column;
};

int V = 0;
vector<vector<bool>> explored;

void exploreAndCollect(vector<vector<char>> patch, Point point, int R, int C);

void exploreAndCollect(vector<vector<char>> patch, Point point, int R, int C) {
    if (point.row < 0 || point.row >= R || point.column < 0 || point.column >= C || // In bounds
    patch[point.row][point.column] == '*' || // Don't care if it's a hay bale
    explored[point.row][point.column]) { // Making sure we haven't already explored the point
        return;
    }
    explored[point.row][point.column] = true; // Point is now considered 'explored'

    char tile = patch[point.row][point.column];
    if (tile == 'S') {
        V += 1;
    } else if (tile == 'M') {
        V += 5;
    } else if (tile == 'L') {
        V += 10;
    }
    // Explore in all directions
    exploreAndCollect(patch, Point{point.row - 1, point.column}, R, C);  // Up
    exploreAndCollect(patch, Point{point.row + 1, point.column}, R, C);  // Down
    exploreAndCollect(patch, Point{point.row, point.column - 1}, R, C);  // Left
    exploreAndCollect(patch, Point{point.row, point.column + 1}, R, C);  // Right
}

int main() {
    int R; // Rows in the patch
    int C; // Columns in the patch
    cin >> R;
    cin >> C;
    explored.resize(R, vector<bool>(C));
    vector<vector<char>> patch(R, vector<char>(C));
    for (int i = 0; i < R; i++) {
        char row[C];
        cin >> row;
        for (int j = 0; j < C; j++) {
            patch[i][j] = row[j];
        }
    }
    int farmerStartX;
    int farmerStartY;
    cin >> farmerStartX;
    cin >> farmerStartY;

    exploreAndCollect(patch, Point{farmerStartX, farmerStartY}, R, C);
    cout << V;
    return 0;
}