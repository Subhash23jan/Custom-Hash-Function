#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
using namespace std;
template <typename K, typename V>
class ListNode {
public:
    K key;
    V value;
    ListNode(K key, V val) : key(key), value(val), next(NULL) {}
    ListNode *next;
};
template <typename K, typename V>
struct Node {
public:
    ListNode<K, V>* node;
    Node() : node(NULL) {}
};
template <typename K, typename V>
class MyMap {
private:
    int MAP_SIZE = 10;
    int load_factor = 5;
    Node<K, V>* arr;
    int hashFunction(K k) {
        return static_cast<int>(hash<K>{}(k) % MAP_SIZE);
    }
    void resize(int new_size) {
        if (new_size <= MAP_SIZE) {
            std::cerr << "New size must be greater than the current size." << endl;
            return;
        }
        Node<K, V>* new_arr = new Node<K, V>[new_size];
        for (int i = 0; i < new_size; ++i) {
            new_arr[i].node = nullptr;
        }
        copy(arr, arr + MAP_SIZE, new_arr);
        delete[] arr;
        arr = new_arr;
        MAP_SIZE = new_size;
    }
public:
    MyMap() {
        arr = new Node<K, V>[MAP_SIZE];
        for (int i = 0; i < MAP_SIZE; ++i) {
            arr[i].node = nullptr;
        }
    }
    ~MyMap() {
        for (int i = 0; i < MAP_SIZE; ++i) {
            ListNode<K, V>* current = arr[i].node;
            while (current != nullptr) {
                ListNode<K, V>* next = current->next;
                delete current;
                current = next;
            }
        }
        delete[] arr;
    }
    void put(K k, V v) {
        int bucketIndex = hashFunction(k);
        ListNode<K, V>* head = arr[bucketIndex].node;
        ListNode<K, V>* ptr = head;
        if (!head) {
            arr[bucketIndex].node = new ListNode<K, V>(k, v);
        } else {
            bool keyFound=false;
            if(ptr->key==k){
                    ptr->value=v;
                    keyFound=true;
            }
            while (ptr->next && !keyFound) {
                ptr = ptr->next;
                if(ptr->key==k){
                    ptr->value=v;
                    break;
                }
                
            }
            if(!keyFound)
               ptr->next = new ListNode<K, V>(k, v);
        }
    }
    V get(K k) {
        int bucketIndex = hashFunction(k);
        ListNode<K, V>* head = arr[bucketIndex].node;
        if (!head) {
            cout << "it's nullptr" << endl;
            return V();
        }
        while (head) {
            if (head->key == k) return head->value;
            head = head->next;
        }
        return V();
    }
};
int main() {
    MyMap<int, string> mp;
    mp.put(10, "Subhash");
     mp.put(10, "Darshan");
    cout << mp.get(10) << endl;
    return 0;
}
