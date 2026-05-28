class Solution {
public:
    vector<string> ans;
    int m, n;

    struct trieNode{
        bool endOfWord;
        trieNode* children[26];
        string word;
    };

    trieNode* getNode(){
        trieNode* newNode = new trieNode();

        newNode->endOfWord = false;

        for(int i=0; i<26; i++){
            newNode->children[i] = NULL;
        }

        newNode->word = "";
        return newNode;
    }

    void insert(trieNode* root, string &word){
        trieNode* crawl = root;

        for(auto ch: word){
            int idx = ch-'a';
            if(crawl->children[idx] == NULL){
                crawl->children[idx] = getNode();
            }
            crawl = crawl->children[idx];
        }
        crawl->endOfWord = true;
        crawl->word = word;


    }


    void dfs(vector<vector<char>>& board, int i, int j, trieNode* root){
        if(i<0 || i>=m || j<0 || j>=n) return;
        int idx = board[i][j]-'a';
        if((board[i][j] == '#') || root->children[idx]==NULL) return;

        root = root->children[idx];

        if(root->endOfWord){
            ans.push_back(root->word);
            root->endOfWord = false;
        }
        char tmp = board[i][j];
        board[i][j] = '#';


        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        for(int k=0; k<4; k++){
            int ni = i + dx[k];
            int nj = j+ dy[k];

            dfs(board, ni, nj, root);
        }
        board[i][j]= tmp;
    }


    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();

        trieNode* root = getNode();

        for(auto i: words){
            insert(root, i);
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                char ch = board[i][j];
                int idx = ch-'a';

                if(root->children[idx] != NULL){
                    dfs(board, i, j, root);
                }
            }
        }
        return ans;

    }
};
