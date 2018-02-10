/*
Insertion of N strings in a trie
*/
#include<bits/stdc++.h>
using namespace std;

struct trie {
	char c; //the character stored in this node
	trie * next[26]; //array of trie pointers for next character links
};

string s;
trie * root;

trie * create_new_node(char ch) {
	trie * new_node = (trie *) malloc(sizeof(struct trie));
	new_node -> c = ch;
	for(int i=0;i<26;i++) {
		new_node -> next[i] = NULL;
	}
	return new_node;
}

trie * insert(trie * node, int position) {

	if(position < s.length()) {  //position should be less than length of string (0 indexing)
		if(node -> next[s[position] -'a'] == NULL) {   //if this link is still NULL, create a node
			node -> next[s[position] - 'a'] = create_new_node(s[position]);
		}
		node -> next[s[position] - 'a'] = insert(node -> next[s[position] - 'a'], position+1);  //call insertion for further characters
	}
	return node;
}

int main() {
	int n;
	cin>>n; //number of strings to be stored

	root = (trie *) malloc(sizeof(struct trie)); //create a node as root node
	root -> c = '#'; //say the root contains # as a character

	for(int i=0;i<26;i++) {
		root -> next[i] = NULL;   //all links for next character of root is set NULL
	}

	for(int i=0;i<n;i++) {
		cin>>s; //input string one by one
		root = insert(root, 0);  //insert the string starting from 0th index
	}
}
