class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord))
            return 0;
        int count = 1;
        queue<string> q;
        q.push(beginWord);
        while (!q.empty()) {
            int n = q.size();

            for (int i = 0; i < n; i++) {
                string word = q.front();
                q.pop();
                if (word == endWord)
                    return count;
                for (int i = 0; i < word.size(); i++) {
                    char original = word[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == original)
                            continue;
                        word[i] = c;
                        if (wordSet.count(word)) {
                            q.push(word);
                            wordSet.erase(word);
                        }
                    }
                    word[i] = original;
                }
            }
            count++;
        }
        return 0;
    }
};