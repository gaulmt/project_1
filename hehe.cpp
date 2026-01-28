// Source - https://stackoverflow.com/a
// Posted by Stephen Quan, modified by community. See post 'Timeline' for change history
// Retrieved 2026-01-28, License - CC BY-SA 4.0

#include <stdio.h>

const int mazeRows = 9;
const int mazeColumns = 9;
char maze[mazeRows][mazeColumns + 1] = {
    "# #######",
    "#     # #",
    "# ### # #",
    "# #   # #",
    "# # ### #",
    "# #     #",
    "# ##### #",
    "#       #",
    "####### #"
};
const char wall = '#';
const char free = ' ';
const char someDude = '*';

class COORD
{
public:
    int x;
    int y;
    COORD(int _x = 0, int _y = 0) { x = _x, y = _y; }
    COORD(const COORD &coord) { x = coord.x; y = coord.y; }
};
COORD startingPoint(1, 0);
COORD endingPoint(7, 8);

void printDaMaze() {
    for (int Y = 0; Y < mazeRows; Y++) {
        printf("%s\n", maze[Y]);
    }
    printf("\n");
}

char get(int x, int y) {
    if (x < 0 || x >= mazeColumns || y < 0 || y >= mazeRows) return wall;
    return maze[y][x];
}

void set(int x, int y, char ch) {
    if (x < 0 || x >= mazeColumns || y < 0 || y >= mazeRows) return;
    maze[y][x] = ch;
}

bool solve(int x, int y) {
    // Make the move (if it's wrong, we will backtrack later. To illustrate, I have a version of the below in Javascript)
    set(x, y, someDude);

    // If you want progressive update, uncomment these lines...
    //printDaMaze();
    //sleep(50);
    // Check if we have reached our goal.
    if (x == endingPoint.x && y == endingPoint.y) return true;
    // Recursively search for our goal.
    if (get(x - 1, y) == free && solve(x - 1, y)) return true;
    if (get(x + 1, y) == free && solve(x + 1, y)) return true;
    if (get(x, y - 1) == free && solve(x, y - 1)) return true;
    if (get(x, y + 1) == free && solve(x, y + 1)) return true;
    // Otherwise we need to backtrack and find another solution.
    set(x, y, free);
    // If you want progressive update, uncomment these lines...
    //printDaMaze();
    //sleep(50);
    return false;
}

int main(int argc, char* argv[]) {
    if (solve(startingPoint.x, startingPoint.y)) {
        printDaMaze();
        printf("Solved!\n");
    } else {
        printf("Cannot solve. :-(\n");
    }
    return 0;
}
