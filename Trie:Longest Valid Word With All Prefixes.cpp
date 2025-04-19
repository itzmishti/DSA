//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

struct Node{
    Node* links[26];
    int flag=false;
    
    bool containsKey(char ch){
        return(links[ch-'a'] !=NULL);
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch, Node* node){
        links[ch-'a']=node;
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
    
};
class Trie{
    private:
    Node * root;
    
    public:
    Trie(){
        root=new Node();
    }
    void insert(string word){
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    bool checkIfPrefixExists(string word){
        Node * node=root;
        for(int i=0;i<word.length();i++){
            if(node->containsKey(word[i])){
                node=node->get(word[i]);
                if(node->isEnd()==false) return false;
            }else{
                return false;
            }
        }
        return true;
    }
};

class Solution {
    public:
    string longestValidWord(vector<string>& words) {
        // code here
        Trie tr;
        for(auto &itr:words){
            tr.insert(itr);
        }
        string longest="";
        for(auto &itr:words){
            if(tr.checkIfPrefixExists(itr)){
                if(itr.length()>longest.length()){
                    longest =itr;
                }else if(itr.length()== longest.length() && itr<longest){
                    longest =itr;
                }
            }
        }
        return longest;
        
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character left by the previous input
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string word;
        while (ss >> word) {
            arr.push_back(word);
        }

        Solution ob;
        string ans = ob.longestValidWord(arr);

        // Handling empty string output by printing an empty line
        cout << ans << endl;
        cout << "~\n";
    }
}

// } Driver Code Ends
