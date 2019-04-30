#include <bits/stdc++.h>
using namespace std;

#define alpha 26
int countDist=0;

struct TrieNode{
    TrieNode *children[alpha];
    bool isEndOfWord;
};

struct TrieNode *getNode(){
    TrieNode *root = new TrieNode;
    for (int i=0;i<alpha;i++){
        root->children[i] = NULL;
    }
    return root;
}

void insertAll(TrieNode *root, string ss){
    TrieNode *tNode = root;
    for (int i=0;i<ss.size();i++){
        int index = ss[i]-'a';
        if (!tNode->children[index]){
            tNode->children[index] = getNode();
        }
        tNode = tNode->children[index];
    }
    tNode->isEndOfWord = true;
}

void insert(TrieNode *root,string s){
    for (int i=0;i<s.size();i++){
        string ss = s.substr(i,s.size()) + s.substr(0,i);
        insertAll(root,ss);
    }
    
}

bool search(TrieNode *root,string s){
    TrieNode *tNode = root;
    for (int i=0;i<s.size();i++){
        int index = s[i]-'a';
        if (!tNode->children[index]){
            return false;
        }
        tNode = tNode->children[index];
    }
    return (tNode!=NULL && tNode->isEndOfWord);
}

class CyclicWords{
public:
    int differentCW(vector<string> words){
        countDist = 0;
        TrieNode *root = getNode();
        for (auto s:words){
            if (!search(root,s)){
                countDist++;
            }
            insert(root, s);
        }
        return countDist;
    }
};
