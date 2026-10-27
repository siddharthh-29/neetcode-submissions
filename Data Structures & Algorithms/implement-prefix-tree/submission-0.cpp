class PrefixTree {
    private:
    struct TrieNode{
        TrieNode*children[26];
        bool isEnd;

        TrieNode(){
            isEnd=false;
            for(int i=0;i<26;i++){
                children[i]=nullptr;
            }
        }
    };
    TrieNode*root;

public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode*curr=root;
        for(auto it:word){
            int idx=it-'a';
            if(curr->children[idx]==nullptr){
                curr->children[idx]=new TrieNode();
            }
            curr=curr->children[idx];
        }
        curr->isEnd=true;
    }
    
    bool search(string word) {
        TrieNode*curr=root;
        for(auto it:word){
            int idx=it-'a';
            if(curr->children[idx]==nullptr)return false;
            curr=curr->children[idx];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode*curr=root;
        for(auto ch:prefix){
            int idx=ch-'a';
            if(curr->children[idx]==nullptr)return false;
            curr=curr->children[idx];
        }
        return true;
    }
};
