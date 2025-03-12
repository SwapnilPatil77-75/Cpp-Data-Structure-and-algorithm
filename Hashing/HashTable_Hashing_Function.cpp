#include<iostream>
using namespace std;


class Node{

public:
        string key;
        int val;
        Node* next;


        Node(string key,int val){
            this->key = key;
            this->val = val;
            next = NULL;
    }

        ~Node(){
            if(next != NULL){
                delete next;
            }
        }



};

class HashTable{

        int totalSize;
        int currSize;
        Node** table;

        int hashFunction(string key){
            //cout<<"int hash Function"<<endl;
            int inx = 0;              // HashFunction to calculate index for key 
            for(int i = 0; i<key.size(); i++){
                inx = inx + (key[i] * key[i])%totalSize;
            }
            return inx % totalSize;
        }

        void reHashing(){
            Node** oldTable;
            oldTable = table;
            int oldSize = totalSize;
            totalSize = 2*totalSize;
            //int newSize = 2*oldSize; 
            currSize = 0;
            table = new Node*[totalSize];

            for(int i = 0; i<totalSize; i++){
                table[i] = NULL;
            }
            // copy old values to new table 
            for(int i = 0; i<oldSize; i++){
                Node* temp = oldTable[i];
                while(temp!=NULL){
                    insert(temp->key,temp->val);
                    temp = temp->next; 
                }
                // deleting old values from the old table 
                if(oldTable[i] != NULL){
                    delete oldTable[i];
                }
            }
            // delete all Null values from old table 
            delete[] oldTable;
        }

public:
       
       // HashTable initialised with deafult linked list with null values 
        HashTable(int size = 5){
            
            totalSize = size;
            currSize = 0;
            table = new Node*[totalSize];  // Dynamic array for given size of linked list 
                                // that is of Nodes 

            for(int i = 0; i<size; i++){ // Intiliase all index of array with value NULL
                table[i] = NULL;
            }
        }

        // insert new key-value pair in the hashTable 
        void insert(string key, int val){
            //cout<<"in insert function"<<endl;
            int inx = hashFunction(key);
            Node* newNode = new Node(key,val);
            //Node* head = table[inx];

           newNode->next = table[inx];
           table[inx] = newNode;
           currSize++;


            double lamda = currSize/(double)totalSize;
            if(lamda > 1 ){
                reHashing();
            }

        }

        bool isExist(string key){  // Check if the key is preset or not in the table
            int inx = hashFunction(key);
            Node* temp = table[inx];
            while(temp != NULL){
                if(temp->key == key){
                    return true;
                }
                temp =  temp->next;
            }

            return false;
        }

       int search(string key){
            
            if(!(isExist(key))){
                return false;
            }

            int inx = hashFunction(key);
            Node* temp = table[inx];
            while(temp != NULL){
                if(temp->key == key){
                    return temp->val;
                }
                temp = temp->next;
            }
            return false;

        }

        void deletion(string key){
            int inx = hashFunction(key);

            Node* temp = table[inx];
            Node* prev = temp;
            while(temp != NULL){
                if(temp->key == key){
                    if(temp = prev){
                        table[inx] = temp->next;
                    }else{
                        prev->next = temp->next;
                    }

                }
                
                prev = temp;
                temp = temp->next;
            }

        }

        void print(){
            
            for(int i = 0; i<totalSize; i++){
                Node* temp = table[i];
                while(temp != NULL){
                    cout<<i<<" "<<temp->key<<"->"<<temp->val<<"\n";
                    temp = temp->next;
                }
            }
        }
};





int main(){

    HashTable ht;

    ht.insert("India",150);
    ht.insert("China",150);
    ht.insert("Nivo",64);
    ht.insert("uk",69);
    ht.insert("nepal",60);
    ht.insert("us",60);
    ht.print();
    if(ht.isExist("uk")){
        cout<<"No is  "<<ht.search("uk")<<endl;
    }

    ht.deletion("India");
    ht.print();
}