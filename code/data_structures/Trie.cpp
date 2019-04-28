#include<iostream>
#include<array>
#include<vector>

using namespace std;

typedef struct Node{
    Node* nb[26];
    bool isWord;
    Node():isWord(false){
        for(int i=0; i<26; i++)
            nb[i] = NULL;
    }
}Node;

class Trie {
private:
    Node* root;
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(const string& word) {
        Node* temp = root;
        for(int i=0; i<word.length(); i++){
            int index = word[i] - 'a';
            if(temp->nb[index] == NULL){
                temp->nb[index] = new Node();
            }
            temp = temp->nb[index];
        }
        temp->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(const string& word) {
        Node* temp = root;
        for(int i=0; i<word.length(); i++){
            int index = word[i] - 'a';
            if(temp->nb[index] == NULL){
                return false;
            }
            temp = temp->nb[index];
        }
        return temp->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(const string& prefix) {
        Node* temp = root;
        for(int i=0; i<prefix.length(); i++){
            int index = prefix[i] - 'a';
            if(temp->nb[index] == NULL){
                return false;
            }
            temp = temp->nb[index];
        }
        return true;
    }
};


int main()
{
  Trie* obj = new Trie();
  obj->insert("word");
  bool param_2 = obj->search("word");
  bool param_3 = obj->startsWith("prefix");

}