#include<bits/stdc++.h>
using namespace std;

#define MAX 26

struct Node{
    struct Node *child[MAX];
    int countWord;
};

// add a node to the tries

struct Node *newNode(){
    struct Node *node = new Node;
    node->countWord = 0;
    for(int i = 0; i < MAX; i++){
        node->child[i] = NULL;
    }
    return node;

}

void addWord(struct Node *root, string s){
    int ch;
    struct Node *temp = root;
    for(int i = 0; i < s.size(); i++){
        ch = s[i] - 'a';
        if(temp->child[ch] == NULL){
            temp->child[ch] = newNode();
        }
        temp = temp->child[ch];
    }
    temp->countWord++;
}

bool findWord(Node *root, string s){
    int ch;
    struct Node *temp = root;
    for(int i = 0; i < s.size(); i++){
        ch = s[i] - 'a';
        if(temp->child[ch] == NULL){
            return false;
        }
        temp = temp->child[ch];
    }
    return temp->countWord > 0;
}

bool isWord(struct Node *node){
    return (node -> countWord != 0);
}


bool isEmpty(struct Node *node){
    for(int i = 0; i < MAX; i++){
        if(node->child[i] != NULL){
            return false;
        }
    }
    return true;
}

bool removeWord(struct Node *root, string s, int level, int len){
    if(!root) return false;
    if(level == len){
        if(root->countWord > 0){
            root->countWord--;
            return true;
        }
        return false;
    }
    int ch = s[level] - 'a';
    int flag = removeWord(root -> child[ch], s, level + 1, len);
    if(flag && !isWord(root ->child[ch]) && isEmpty(root ->child[ch])){
        delete root -> child[ch];
        root->child[ch] =NULL;
    }
    return flag;
}

void printWord(struct Node * root, string s){
    if(isWord(root)){
        cout << s << '\n';
    }

    for(int i = 0; i < MAX; i++){
        if(root->child[i]){
            printWord(root->child[i], s + (char)('a' + i));
        }
    }
}

void consider(string &answer, string s){
    if(answer.size() < s.size()) answer = s;
    if(answer.size() == s.size()){
        answer = min(answer, s);
    }
}

class Solution {
public:
    void dfs(struct Node *root, string &answer, string res){
    for(int i = 0; i < MAX; i++){
        if(root -> child[i] && isWord(root -> child[i])){
            dfs(root -> child[i], answer, res + (char)(i + 'a'));
            consider(answer, res + (char)(i + 'a'));
        }
    }
}
    string longestWord(vector<string>& words) {
        struct Node *root = newNode();
        for(auto s : words){
            addWord(root, s);
        }
        string answer = "";
        dfs(root, answer, "");
        return answer;

    }
};

int32_t main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(); cout.tie();
    freopen("input.txt", "r", stdin);
    int t; cin >> t;
    while(t--){
        vector<string>words;
        int n; cin >> n;
        for(int i = 0; i < n; i++){
            string s; cin >> s;
            words.push_back(s);
        }
        cout << Solution().longestWord(words) << '\n';
    }
}