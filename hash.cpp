#include <iostream>
using namespace std;
#include <list>

class Hash
{
    int hashBucket;
    list<int> *hashTable;

public:
    Hash(int K);

    void insert(int x);

    void remove(int key);

    unsigned long hashFunction(int x){
        unsigned long index = 0;
            for (int i=0; i < 8; i++) {
            index += (x >> (i*8)) & 0xff;
            }
        return index % 16;
    }

    void displayHash();
};

Hash::Hash(int b){
    this ->hashBucket = b;
    hashTable = new list<int>[hashBucket];
}

void Hash::insert(int key){
    int index = hashFunction(key);
    hashTable[index].push_back(key);
}

void Hash::remove(int key){
   int index = hashFunction(key);


   list<int> :: iterator i;
   for (i = hashTable[index].begin();i != hashTable[index].end();i++){
    if(*i == key){
        break;
    }
   }
   if (i != hashTable[index].end())
    hashTable[index].erase(i);
}

void Hash::displayHash() {
  for (int i = 0; i < hashBucket; i++) {
    cout << i;
    for (auto& x : hashTable[i]){
      cout << " --> " << x;}
    cout << endl;
  }
}

int main()
{
  unsigned long a[] = {0x123412341234,0x432143214321,0x12345678910,0x10987654321,0x546843965034,0x594385438645,0x948562947584,0x938475934856,0x948538591231,
  0x958034520347,0x958396541234};

  int n = sizeof(a)/sizeof(a[0]);

  Hash h(25);

  for (int i = 0; i < n; i++)
    h.insert(a[i]); 
 
  h.displayHash();
 
}