/*
Insertion of N strings in a trie
Deletion Of String in a trie.
*/

#include<bits/stdc++.h>
using namespace std;

struct trie {
	int next[26];
	int flag;
	int prev;
}node[100000];

int allocated;


void del(string s){  //  Here is think i have considered a string with 0s and 1s - 2 characters only. 

   int current=0,cur=0;

   for(int i=0;i<s.length();++i){

       current=node[current].next[s[i]-'0'];
       if(i==s.length()-1){

          cur=current;
	  node[cur].flag=0;   // Remove the mark of end of string
          break;
       }

   }
	


   while(cur!=0){

      bool hasChildren=false;
	   
      for(int i=0;i<26;++i){	 
	  
	  if(node[cur].next[i]!=0){
		 
	      hasChildren=true;
	      break;
		 	  
	  }
	      
      }
	      
      if(hasChildren==false && node[cur].flag==0){  // If the node has no children and it does not mark the end of any string- Delete it.

          int prev=node[cur].prev;
	      
	  for(int i=0;i<26;++i){
	
	      if(node[prev].next[i]==cur){
	      	 node[prev].next[i]=0;
		 break;      
	      }  
	  }
	      
          cur=prev;
      }

      else{  //  If the node has a child -  one or two or many -  I can't delete it.

        break;
      }

   }
} 

void insert(string s) {
	int current = 0;  //so root node is node[0]
	for(int i = 0; i < s.length(); i++) {
		if(node[current].next[s[i]-'a'] == 0) { //no link --> so allocate it
			node[current].next[s[i]-'a'] = allocated;
			node[allocated].prev=node[current];  // Make pointer to parent node:- to be used in deletion.
			current = allocated;
			allocated++;
		}
		else current = node[current].next[s[i]-'a'];  //already present --> so just update current

		//setting flag for last character of string
		if(i == s.length()-1) {
			node[current].flag = 1;
		}
	}
}

int main() {
	string s;
	int n;
	cin>>n;  //input number of strings

	allocated = 1; //allocated to be started from 1

	memset(node, 0, sizeof node); //initialize node to 0 (each values in next[] array and flag will be 0 for each node)

	for(int i=0;i<n;i++) {
		cin>>s; //input string one by one
		insert(s); //insert the string in trie and mark the end of this string by setting flag to 1 for last character's node
	}
	return 0;
}
