#include <bits/stdc++.h>
using namespace std;

#define newAlpha 20

map<char,int> mp,mp1;
vector<string> v;

void createMap(){
    mp.insert(make_pair('a', 1));
    mp.insert(make_pair('b', 2));
    mp.insert(make_pair('k', 3));
    mp.insert(make_pair('d', 4));
    mp.insert(make_pair('e', 5));
    mp.insert(make_pair('g', 6));
    mp.insert(make_pair('h', 7));
    mp.insert(make_pair('i', 8));
    mp.insert(make_pair('l', 9));
    mp.insert(make_pair('m', 10));
    mp.insert(make_pair('n', 11));
    mp.insert(make_pair('z', 12));
    mp.insert(make_pair('o', 13));
    mp.insert(make_pair('p', 14));
    mp.insert(make_pair('r', 15));
    mp.insert(make_pair('s', 16));
    mp.insert(make_pair('t', 17));
    mp.insert(make_pair('u', 18));
    mp.insert(make_pair('w', 19));
    mp.insert(make_pair('y', 20));
    
    mp1.insert(make_pair(1, 'a'));
    mp1.insert(make_pair(2, 'b'));
    mp1.insert(make_pair(3, 'k'));
    mp1.insert(make_pair(4, 'd'));
    mp1.insert(make_pair(5, 'e'));
    mp1.insert(make_pair(6, 'g'));
    mp1.insert(make_pair(7, 'h'));
    mp1.insert(make_pair(8, 'i'));
    mp1.insert(make_pair(9, 'l'));
    mp1.insert(make_pair(10, 'm'));
    mp1.insert(make_pair(11, 'n'));
    mp1.insert(make_pair(12, 'z'));
    mp1.insert(make_pair(13, 'o'));
    mp1.insert(make_pair(14, 'p'));
    mp1.insert(make_pair(15, 'r'));
    mp1.insert(make_pair(16, 's'));
    mp1.insert(make_pair(17, 't'));
    mp1.insert(make_pair(18, 'u'));
    mp1.insert(make_pair(19, 'w'));
    mp1.insert(make_pair(20, 'y'));

}

struct TrieNode{
    TrieNode *children[newAlpha];
    bool isEndOfWord;
};

struct TrieNode *getNode(){
    TrieNode *tNode = new TrieNode;
    for (int i=0;i<newAlpha;i++){
        tNode->children[i] = NULL;
    }
    return tNode;
}

void insert(TrieNode *root, string s){
    TrieNode *tNode = root;
    for (int i=0;i<s.size();i++){
        int index = mp[s[i]]-mp['a'];
        if (!tNode->children[index]){
            tNode->children[index] = getNode();
        }
        tNode = tNode->children[index];
    }
    tNode->isEndOfWord = true;
}
string rearrange(string s){
    string ss = "";
    for (int i=0;i<s.size();i++){
        if (s[i]=='z'){
            ss += "ng";
        }else{
            ss += s[i];
        }
    }
    return ss;
}

void printTrie(TrieNode *root,string s){
    
    if (root->isEndOfWord){
        s = rearrange(s);
		v.push_back(s);
    }
    
    for (int i=0;i<newAlpha;i++){
        if (root->children[i]){
            s += mp1[i+1];
            printTrie(root->children[i], s);
            s.pop_back();
        }
    }
    
}

string wordC(string s){
    for (int i=0;i<s.size()-1;i++){
        if (s[i]=='n' && s[i+1]=='g'){
            s[i] ='z';
            s.erase(s.begin()+i+1);
        }
    }
    return s;
}

class TagalogDictionary{
public:
    vector<string> sortWords(vector<string> words){
        createMap();
        TrieNode *root = getNode();
        for (auto key:words){
            key = wordC(key);
            insert(root, key);
        }
        
        printTrie(root,"");
        return v;
    }
};
