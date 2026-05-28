class PrefixTree {
public:

    struct trieNode{
        bool endOfWord;

        trieNode* children[26];
    };

    trieNode* getNode(){
        trieNode* newNode = new trieNode();

        newNode->endOfWord = false;

        for(int i=0; i<26; i++){
            newNode->children[i] = NULL;
        }
        return newNode;
    }

    trieNode* root;

    PrefixTree() {
        root = getNode();
    }
    
    void insert(string word) {
        trieNode* crawler = root;

        for(char ch: word){
            int idx = ch-'a';

            if(crawler->children[idx] == NULL){
                crawler->children[idx] = new trieNode();
            }

            crawler = crawler->children[idx];
        }
        crawler->endOfWord = true;
    }
    
    bool search(string word) {
        
        trieNode* crawl = root;
       
        for(auto ch: word){
            int idx = ch-'a';

            if(crawl->children[idx] == NULL) return false;
            crawl = crawl->children[idx];
            
        }

        if(crawl->endOfWord == true) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        trieNode* crawl = root;
        

        for(auto ch: prefix){
            int idx = ch-'a';

            if(crawl->children[idx] == NULL) return false;
            crawl = crawl->children[idx];
            
        }

        return true;
    }
};
