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
    ListNode(K key, V val) : key(key), value(val), next(nullptr) {}
    ListNode *next;
};

template <typename K, typename V>
struct Node {
public:
    ListNode<K, V>* node;
    Node() : node(nullptr) {}
};

template <typename K, typename V>
class MyMap {
private:
    int MAP_SIZE = 10;
    int load_factor = 5;
    int curr_size = 0;
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

        for (int i = 0; i < MAP_SIZE; ++i) {
            ListNode<K, V>* current = arr[i].node;
            while (current != nullptr) {
                int new_index = static_cast<int>(hash<K>{}(current->key) % new_size);
                ListNode<K, V>* next = current->next;
                current->next = new_arr[new_index].node;
                new_arr[new_index].node = current;
                current = next;
            }
        }

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
            bool keyFound = false;
            if (ptr->key == k) {
                ptr->value = v;
                keyFound = true;
            }
            while (ptr->next && !keyFound) {
                ptr = ptr->next;
                if (ptr->key == k) {
                    ptr->value = v;
                    keyFound = true;
                }
            }
            if (!keyFound)
                ptr->next = new ListNode<K, V>(k, v);
        }

        curr_size++;

        if (curr_size > load_factor * MAP_SIZE) {
            resize(MAP_SIZE * 2);
        }
    }

    V get(K k) {
        int bucketIndex = hashFunction(k);
        ListNode<K, V>* head = arr[bucketIndex].node;
        if (!head) {
            return V();
        }
        while (head) {
            if (head->key == k) return head->value;
            head = head->next;
        }
        return V();
    }

    void clear() {
        for (int i = 0; i < MAP_SIZE; ++i) {
            ListNode<K, V>* current = arr[i].node;
            while (current != nullptr) {
                ListNode<K, V>* next = current->next;
                delete current;
                current = next;
            }
            arr[i].node = nullptr;
        }
        curr_size = 0;
    }

    bool contains(K k) {
        int bucketIndex = hashFunction(k);
        ListNode<K, V>* head = arr[bucketIndex].node;
        while (head) {
            if (head->key == k) return true;
            head = head->next;
        }
        return false;
    }
};

int main() {
    MyMap<int, string> mp;

    mp.put(10, "Subhash");
    mp.put(20, "Darshan");
    cout << "Get key 10: " << mp.get(10) << endl;
    cout << "Get key 20: " << mp.get(20) << endl;

    mp.put(10, "Updated Name");
    cout << "Updated key 10: " << mp.get(10) << endl;

    cout << "Contains key 20: " << mp.contains(20) << endl;
    cout << "Contains key 30: " << mp.contains(30) << endl;

    mp.clear();
    cout << "Get key 10 after clear: " << mp.get(10) << endl;

    return 0;
}
