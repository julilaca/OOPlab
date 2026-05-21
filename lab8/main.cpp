#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <cctype>

using namespace std;

vector<string> splitString(const string& str) {
    vector<string> words;
    string current;
    for (char ch : str) {
        if (ch == ' ' || ch == ',' || ch == '?' || ch == '!' || ch == '.') {
            if (!current.empty()) {
                words.push_back(current);
                current.clear();
            }
        } else {
            current += tolower(ch);
        }
    }
    if (!current.empty()) words.push_back(current);
    return words;
}

struct Comparator {
    bool operator()(const pair<string, int>& a, const pair<string, int>& b) {
        if (a.second != b.second) return a.second > b.second;
        return a.first < b.first;
    }
};

int main() {
    ifstream file("textfile.txt");
    string phrase;
    getline(file, phrase);
    file.close();

    vector<string> words = splitString(phrase);
    map<string, int> counts;
    for (const auto& word : words) counts[word]++;

    priority_queue<pair<string, int>, vector<pair<string, int>>, Comparator> priorityq;
    for (const auto& pair : counts) priorityq.push(pair);

    while (!priorityq.empty()) {
        auto top = priorityq.top();
        cout << top.first << " => " << top.second << endl;
        priorityq.pop();
    }
}