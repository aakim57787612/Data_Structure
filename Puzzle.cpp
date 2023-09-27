#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stack>
using namespace std;

struct element {
    char name = '0';
    int row = 0;
    int col = 0;
    int rotation = 0;
    bool end = false;
    vector<vector<int>> puzzle;
};

vector<char> last;
int total = 0;

// 旋轉拼圖元素
void rotate(element& p, int rota) {
    int newRow = p.col;
    int newCol = p.row;
    vector<vector<int>> newPuzzle(newRow, vector<int>(newCol, 0));

    for (int i = 0; i < p.row; i++) {
        for (int j = 0; j < p.col; j++) {
            newPuzzle[j][p.row - 1 - i] = p.puzzle[i][j];
        }
    }
    p.rotation = rota;
    p.row = newRow;
    p.col = newCol;
    p.puzzle = newPuzzle;
}

bool canPlace(const element& main_p, const element& vice_p, int row, int col) {
    for (int i = 0; i < vice_p.row; i++) {
        for (int j = 0; j < vice_p.col; j++) {
            if (vice_p.puzzle[i][j] == 1) {
                int newRow = row + i;
                int newCol = col + j;

                if (newRow < 0 || newRow >= main_p.row || newCol < 0 || newCol >= main_p.col) {
                    return false; // 拼圖超出邊界
                }

                if (main_p.puzzle[newRow][newCol] != 0) {
                    return false; // 此位置已有拼圖
                }
            }
        }
    }

    return true;
}

bool solve(element& main_p, vector<element>& vice_ps, int current_puzzle, vector<element>& errorStack) {
    if (current_puzzle == vice_ps.size()) {
        // 成功放置所有副拼圖
        return true;
    }

    element& vice_p = vice_ps[current_puzzle];

    // 嘗試四個方向的旋轉
    for (int rotation = 0; rotation < 4; rotation++) {
        // 在每個方向之前旋轉副拼圖
        rotate(vice_p , rotation);

        for (int row = 0; row <= main_p.row - vice_p.row; row++) {
            for (int col = 0; col <= main_p.col - vice_p.col; col++) {
                if (canPlace(main_p, vice_p, row, col)) {
                    // Push 目前位置到 error stack
                    errorStack.push_back(vice_p);
                    // 放置副拼圖
                    for (int i = 0; i < vice_p.row; i++) {
                        for (int j = 0; j < vice_p.col; j++) {
                            if (vice_p.puzzle[i][j] == 1) {
                                main_p.puzzle[row + i][col + j] = current_puzzle + 1;
                            }
                        }
                    }

                    if (solve(main_p, vice_ps, current_puzzle + 1, errorStack)) {
                        return true; // 找到解決方案
                    }

                    // 回溯並移除副拼圖
                    for (int i = 0; i < vice_p.row; i++) {
                        for (int j = 0; j < vice_p.col; j++) {
                            if (vice_p.puzzle[i][j] == 1) {
                                main_p.puzzle[row + i][col + j] = 0;
                            }
                        }
                    }
                }
                else {

                    // Push 一個空的puzzle當結束點 
                    element temp;
                    temp.end = true;
                    errorStack.push_back(temp);

                }
            }
        }
    }

    return false; // 找不到解決方案
}


void find_main_p(element* main_p, ifstream& inputFile) {
    // 找題目空拼圖
    string a;
    getline(inputFile, a);
    main_p->col = a.size() / 2 + 1;

    for (int i = 0; i < a.size(); i++) {
        if (a[i] != ' ') {
            main_p->puzzle[0][i / 2] = a[i] - '0';
        }
    }

    main_p->row = 1;

    while (getline(inputFile, a) && a != "x") {
        vector<int> row;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != ' ') {
                row.push_back(a[i] - '0');
            }
        }
        main_p->puzzle.push_back(row);
        main_p->row++;
    }
}

void find_vice_p(vector<element>& vice_ps, ifstream& inputFile) {
    // 找副拼圖
    string a;
    element s;

    while (true) {
        getline(inputFile, a);
        if (a == "0") {
            break;
        }

        vice_ps.push_back(s);
        vice_ps.back().col = a.size() / 2 + 1;

        while (getline(inputFile, a) && a != "x") {
            vector<int> row;
            for (int i = 0; i < a.size(); i++) {
                if (a[i] != ' ') {
                    row.push_back(a[i] - '0');
                    if (a[i] != '0') {
                        vice_ps.back().name = a[i];
                    }
                }
            }
            vice_ps.back().puzzle.push_back(row);
            vice_ps.back().row++;
        }
    }
}

int main() {
    ifstream inputFile("S1-input.txt");
    ofstream outputFile("output.txt");

    element main_p;
    find_main_p(&main_p, inputFile);

    vector<element> vice_ps;
    find_vice_p(vice_ps, inputFile);

    vector<element> errorStack; // 存錯誤的位置紀錄

    if (solve(main_p, vice_ps, 0, errorStack)) {
        // 如果 solve 過了，output 拼好的檔案
        for (int i = 0; i < main_p.row; i++) {
            for (int j = 0; j < main_p.col; j++) {
                cout << main_p.puzzle[i][j] << " ";
                outputFile << main_p.puzzle[i][j] << " ";
            }
            cout << endl;
            outputFile << endl;
        }
    }
    else {
        cout << "沒有解答" << endl;
        outputFile << "沒有解答" << endl;
    }
    inputFile.close(); 
    outputFile.close();  

    return 0;
}
