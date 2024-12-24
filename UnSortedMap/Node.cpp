template <typename K, typename V>
class ListNode {
public:
    K key;
    V value;
    ListNode(K key, V val) : key(key), value(val), next(nullptr) {}
    ListNode *next;
};