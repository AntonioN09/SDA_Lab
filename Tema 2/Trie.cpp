#include <bits/stdc++.h>

using namespace std;
ifstream in("trie.in");
ofstream out("trie.out");

struct Node{
    Node* letters[26];
    int counter;
    int num_letters;

    Node(){
        this->counter = 0;
        this->num_letters = 0;
        for(int i = 0; i < 26; i++){
            this->letters[i] = NULL;
        }
    }
};

Node* trie = new Node();

void Trie_Insert(string word){
    Node* p = trie;
    for(unsigned i = 0; i < word.length(); i++){
        int index = word[i] - 'a';
        if(!p->letters[index]){
            p->letters[index] = new Node();
            p->num_letters++;
        }
        p = p->letters[index];
    }
    p->counter++;
}

bool Trie_Delete(string word, unsigned i, Node* p){
    int index = word[i] - 'a';
    if(i == word.length()){
        p->counter--;
    }
    else if(Trie_Delete(word, i + 1, p->letters[index])){
        p->letters[index] = NULL;
        p->num_letters--;
    }

    if(p != trie && p->counter == 0 && p->num_letters == 0){
        delete p;
        return 1;
    }

    return 0;

}

void Trie_Count(string word){
    Node* p = trie;
    for(unsigned i = 0; i < word.length(); i++){
        int index = word[i] - 'a';
        if(!p->letters[index]){
            out << 0 << '\n';
            return;
        }
        p = p->letters[index];
    }
    out << p->counter << '\n';
}

void Trie_Prefix(string word){
    int len = 0;
    Node* p = trie;
    for(unsigned i = 0; i < word.length(); i++){
        int index = word[i] - 'a';
        if(!p->letters[index]){
            out << len << '\n';
            return;
        }
        p = p->letters[index];
        ++len;
    }
    out << len << '\n';
}

int main()
{
    int op;
    string word;
    while(in >> op >> word){
        Node* p = trie;
        switch(op){
            case 0:
                Trie_Insert(word);
                break;
            case 1:
                Trie_Delete(word, 0, p);
                break;
            case 2:
                Trie_Count(word);
                break;
            case 3:
                Trie_Prefix(word);
                break;
        }
    }

    return 0;
}