#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<string> sentences;
    string input;

    // 逐行讀取輸入文本
    while (getline(cin, input)) {
        if (input.empty()) {
            // 遇到空行表示一個句子的結尾
            continue;
        }
        sentences.push_back(input);
    }

    int max_length = 0;

    // 找到最長的句子長度
    for (const string& sentence : sentences) {
        max_length = max(max_length, static_cast<int>(sentence.length()));
    }

    int num_sentences = sentences.size();

    // 進行90度旋轉輸出
    for (int i = 0; i < max_length; ++i) {
        for (int j = num_sentences - 1; j >= 0; --j) {
            if (i < sentences[j].length()) {
                cout << sentences[j][i];
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}