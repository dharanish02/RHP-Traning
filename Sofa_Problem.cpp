#include <bits/stdc++.h>
using namespace std;

struct Sofa {
    int fsr, fsc, ssr, ssc;
    char dir;
    int moves;
    Sofa(int fsr, int fsc, int ssr, int ssc, char dir, int moves)
        : fsr(fsr), fsc(fsc), ssr(ssr), ssc(ssc), dir(dir), moves(moves) {}
};

int R, C;
vector<vector<char>> grid;

const string DELIM = "-";

bool canAdd(int fsr, int fsc, int ssr, int ssc, unordered_set<string>& vis) {
    string key = to_string(fsr) + DELIM + to_string(fsc) + DELIM +
                 to_string(ssr) + DELIM + to_string(ssc);
    if (vis.count(key)) return false;
    vis.insert(key);
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C;
    grid.assign(R, vector<char>(C));

    int fsr = -1, fsc = -1, ssr = -1, ssc = -1, sofacount = 0;
    queue<Sofa> q;
    unordered_set<string> vis;

    for (int row = 0; row < R; row++) {
        for (int col = 0; col < C; col++) {
            char ch;
            cin >> ch;
            grid[row][col] = ch;
            if (ch == 'S') {
                sofacount++;
                if (sofacount == 1) {
                    fsr = row; fsc = col;
                } else {
                    ssr = row; ssc = col;
                    char dir = (fsr == ssr) ? 'H' : 'V';
                    q.push(Sofa(fsr, fsc, ssr, ssc, dir, 0));
                    canAdd(fsr, fsc, ssr, ssc, vis);
                }
            }
        }
    }

    while (!q.empty()) {
        Sofa s = q.front();
        q.pop();

        if (grid[s.fsr][s.fsc] == 's' && grid[s.ssr][s.ssc] == 's') {
            cout << s.moves << "\n";
            return 0;
        }

        if (s.dir == 'H') {
            // Move right
            if (s.ssc < C - 1 && grid[s.ssr][s.ssc + 1] != 'H') {
                if (canAdd(s.ssr, s.ssc, s.ssr, s.ssc + 1, vis)) {
                    q.push(Sofa(s.ssr, s.ssc, s.ssr, s.ssc + 1, 'H', s.moves + 1));
                }
            }
            // Move left
            if (s.fsc > 0 && grid[s.fsr][s.fsc - 1] != 'H') {
                if (canAdd(s.fsr, s.fsc - 1, s.fsr, s.fsc, vis)) {
                    q.push(Sofa(s.fsr, s.fsc - 1, s.fsr, s.fsc, 'H', s.moves + 1));
                }
            }
            // Drag up
            if (s.fsr > 0 && grid[s.fsr - 1][s.fsc] != 'H' && grid[s.ssr - 1][s.ssc] != 'H') {
                if (canAdd(s.fsr - 1, s.fsc, s.ssr - 1, s.ssc, vis)) {
                    q.push(Sofa(s.fsr - 1, s.fsc, s.ssr - 1, s.ssc, 'H', s.moves + 1));
                }
            }
            // Drag down
            if (s.fsr < R - 1 && grid[s.fsr + 1][s.fsc] != 'H' && grid[s.ssr + 1][s.ssc] != 'H') {
                if (canAdd(s.fsr + 1, s.fsc, s.ssr + 1, s.ssc, vis)) {
                    q.push(Sofa(s.fsr + 1, s.fsc, s.ssr + 1, s.ssc, 'H', s.moves + 1));
                }
            }
            // Rotations
            if (s.fsr > 0 && grid[s.fsr - 1][s.fsc] != 'H' && grid[s.ssr - 1][s.ssc] != 'H') {
                if (canAdd(s.fsr - 1, s.fsc, s.fsr, s.fsc, vis)) {
                    q.push(Sofa(s.fsr - 1, s.fsc, s.fsr, s.fsc, 'V', s.moves + 1));
                }
            }
            if (s.fsr < R - 1 && grid[s.fsr + 1][s.fsc] != 'H' && grid[s.ssr + 1][s.ssc] != 'H') {
                if (canAdd(s.fsr, s.fsc, s.fsr + 1, s.fsc, vis)) {
                    q.push(Sofa(s.fsr, s.fsc, s.fsr + 1, s.fsc, 'V', s.moves + 1));
                }
            }
            if (s.ssr > 0 && grid[s.ssr - 1][s.ssc] != 'H' && grid[s.fsr - 1][s.fsc] != 'H') {
                if (canAdd(s.ssr - 1, s.ssc, s.ssr, s.ssc, vis)) {
                    q.push(Sofa(s.ssr - 1, s.ssc, s.ssr, s.ssc, 'V', s.moves + 1));
                }
            }
            if (s.ssr < R - 1 && grid[s.ssr + 1][s.ssc] != 'H' && grid[s.fsr + 1][s.fsc] != 'H') {
                if (canAdd(s.ssr, s.ssc, s.ssr + 1, s.ssc, vis)) {
                    q.push(Sofa(s.ssr, s.ssc, s.ssr + 1, s.ssc, 'V', s.moves + 1));
                }
            }
        } else {
            // Drag up
            if (s.fsr > 0 && grid[s.fsr - 1][s.fsc] != 'H') {
                if (canAdd(s.fsr - 1, s.fsc, s.fsr, s.fsc, vis)) {
                    q.push(Sofa(s.fsr - 1, s.fsc, s.fsr, s.fsc, 'V', s.moves + 1));
                }
            }
            // Drag down
            if (s.ssr < R - 1 && grid[s.ssr + 1][s.ssc] != 'H') {
                if (canAdd(s.ssr, s.ssc, s.ssr + 1, s.ssc, vis)) {
                    q.push(Sofa(s.ssr, s.ssc, s.ssr + 1, s.ssc, 'V', s.moves + 1));
                }
            }
            // Drag left
            if (s.fsc > 0 && grid[s.fsr][s.fsc - 1] != 'H' && grid[s.ssr][s.ssc - 1] != 'H') {
                if (canAdd(s.fsr, s.fsc - 1, s.ssr, s.ssc - 1, vis)) {
                    q.push(Sofa(s.fsr, s.fsc - 1, s.ssr, s.ssc - 1, 'V', s.moves + 1));
                }
            }
            // Drag right
            if (s.fsc < C - 1 && grid[s.fsr][s.fsc + 1] != 'H' && grid[s.ssr][s.ssc + 1] != 'H') {
                if (canAdd(s.fsr, s.fsc + 1, s.ssr, s.ssc + 1, vis)) {
                    q.push(Sofa(s.fsr, s.fsc + 1, s.ssr, s.ssc + 1, 'V', s.moves + 1));
                }
            }
            // Rotations
            if (s.fsc > 0 && grid[s.fsr][s.fsc - 1] != 'H' && grid[s.ssr][s.ssc - 1] != 'H') {
                if (canAdd(s.fsr, s.fsc - 1, s.fsr, s.fsc, vis)) {
                    q.push(Sofa(s.fsr, s.fsc - 1, s.fsr, s.fsc, 'H', s.moves + 1));
                }
            }
                        if (s.fsc < C - 1 && grid[s.fsr][s.fsc + 1] != 'H' && grid[s.ssr][s.ssc + 1] != 'H') {
                if (canAdd(s.fsr, s.fsc, s.fsr, s.fsc + 1, vis)) {
                    q.push(Sofa(s.fsr, s.fsc, s.fsr, s.fsc + 1, 'H', s.moves + 1));
                }
            }
            if (s.ssc > 0 && grid[s.ssr][s.ssc - 1] != 'H' && grid[s.fsr][s.fsc - 1] != 'H') {
                if (canAdd(s.ssr, s.ssc - 1, s.ssr, s.ssc, vis)) {
                    q.push(Sofa(s.ssr, s.ssc - 1, s.ssr, s.ssc, 'H', s.moves + 1));
                }
            }
            if (s.ssc < C - 1 && grid[s.ssr][s.ssc + 1] != 'H' && grid[s.fsr][s.fsc + 1] != 'H') {
                if (canAdd(s.ssr, s.ssc, s.ssr, s.ssc + 1, vis)) {
                    q.push(Sofa(s.ssr, s.ssc, s.ssr, s.ssc + 1, 'H', s.moves + 1));
                }
            }
        }
    }

    cout << "Impossible\n";
    return 0;
}
