#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <cctype>

std::vector<std::string> splitString(const std::string& str) {
    std::vector<std::string> words;
    std::string current;
    for (char ch : str) {
        if (isspace(ch) || ch == ',' || ch == '?' || ch == '!' || ch == '.') {
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
    bool operator()(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
        if (a.second != b.second) return a.second < b.second;
        return a.first > b.first;
    }
};

int main() {
    std::ifstream file("textfile.txt");
    std::string phrase;
    getline(file, phrase);
    file.close();

    std::vector<std::string> words = splitString(phrase);
    std::map<std::string, int> counts;
    for (const auto& word : words) counts[word]++;

    std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, Comparator> pq;
    for (const auto& pair : counts) pq.push(pair);

    while (!pq.empty()) {
        auto top = pq.top();
        std::cout << top.first << " => " << top.second << std::endl;
        pq.pop();
    }
}
