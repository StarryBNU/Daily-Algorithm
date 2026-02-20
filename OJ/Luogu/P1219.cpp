#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;

int n;
int total = 0;
vector<vector<int> > answers; 

bool used_col[14] = {false};
bool used_diag1[30] = {false};
bool used_diag2[30] = {false};

vector<int> current;

void dfs(int row) {
    if (row > n) {
        total++;
        if ((int)answers.size() < 3) {
            answers.push_back(current);
        }
        return;
    }

    for (int col = 1; col <= n; col++) {
        int d1 = row - col + n;
        int d2 = row + col;

        if (!used_col[col] && !used_diag1[d1] && !used_diag2[d2]) {
            used_col[col] = used_diag1[d1] = used_diag2[d2] = true;
            current.push_back(col);

            dfs(row + 1);

            current.pop_back();
            used_col[col] = used_diag1[d1] = used_diag2[d2] = false;
        }
    }
}

int main() {
    cin >> n;
    dfs(1);

    for (int i = 0; i < (int)answers.size(); i++) {
        for (int j = 0; j < (int)answers[i].size(); j++) {
            if (j > 0) cout << " ";
            cout << answers[i][j];
        }
        cout << '\n';
    }
    cout << total << endl;
    return 0;
}
