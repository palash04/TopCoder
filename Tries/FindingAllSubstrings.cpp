#include <bits/stdc++.h>
using namespace std;

#define alpha 26

struct TrieNode{
    TrieNode *children[alpha];
    bool isEndOfWord;
    void insertSuffix(string s);
};

struct TrieNode *getNode(){
    TrieNode *pNode = new TrieNode;
    for (int i=0;i<alpha;i++){
        pNode->children[i] = NULL;
    }
    return pNode;
}

void TrieNode::insertSuffix(string s){
    
    if (s.length() > 0){
        int index = s[0]-'A';
        if (children[index] == NULL){
            children[index] = getNode();
        }
        children[index]->insertSuffix(s.substr(1));
    }
    
}

void insert(TrieNode *root, string s){
    
    for (int i=0;i<s.length();i++){
        root->insertSuffix(s.substr(i));
    }
    
}

bool search(TrieNode *root,string s){
    TrieNode *tNode = root;
    for (int i=0;i<s.size();i++){
        int index = s[i]-'A';
        if (!tNode->children[index]){
            return false;
        }
        tNode = tNode->children[index];
    }
    return (tNode != NULL);
}

set<string> st;

void printTrie(TrieNode *root,string s){
    
    if (!root) return;
    
    for (int i=0;i<alpha;i++){
        if (root->children[i]){
            s += 'A'+i; // 'a' for small letters
            st.insert(s);
            //cout << s << endl;
            printTrie(root->children[i],s);
            s.pop_back();
        }
    }
}

int main(){
    
    TrieNode *root = getNode();
    
    string s = "ABABA";
    insert(root, s);
    printTrie(root,"");
    cout << st.size() << endl;
    
    return 0;
}

