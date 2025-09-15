#include <iostream>
#include <string>

std::string s;
bool vis[7][7];
long long ans;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const char dir_char[] = {'D', 'U', 'R', 'L'};

const int GRID_SIZE = 7;
const int TARGET_X = 6;
const int TARGET_Y = 0;
const int MAX_MOVES = 48;

#define IS_VALID(x, y) ((x) >= 0 && (x) < GRID_SIZE && (y) >= 0 && (y) < GRID_SIZE)

void dfs(int move_idx, int x, int y) {
    if (x == TARGET_X && y == TARGET_Y) {
        if (move_idx == MAX_MOVES) {
            ans++;
        }
        return;
    }

    if (move_idx == MAX_MOVES) {
        return;
    }

    bool blocked_up = !IS_VALID(x + 1, y) || vis[x + 1][y];
    bool blocked_down = !IS_VALID(x - 1, y) || vis[x - 1][y];
    bool blocked_left = !IS_VALID(x, y - 1) || vis[x][y - 1];
    bool blocked_right = !IS_VALID(x, y + 1) || vis[x][y + 1];

    if (blocked_up && blocked_down) {
        if (!blocked_left && !blocked_right) {
            return;
        }
    }
    if (blocked_left && blocked_right) {
        if (!blocked_up && !blocked_down) {
            return;
        }
    }

    vis[x][y] = true;

    char current_s_char = s[move_idx];

    for (int k = 0; k < 4; ++k) {
        if (current_s_char != '?' && current_s_char != dir_char[k]) {
            continue;
        }

        int nx = x + dx[k];
        int ny = y + dy[k];

        if (IS_VALID(nx, ny) && !vis[nx][ny]) {
            dfs(move_idx + 1, nx, ny);
        }
    }

    vis[x][y] = false;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> s;

    ans = 0;

    dfs(0, 0, 0);

    std::cout << ans << "\n";

    return 0;
}