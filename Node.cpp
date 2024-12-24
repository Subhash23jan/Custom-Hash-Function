template <typename K, typename V>
class Node {
public:
    K key;
    V val;
    Node* left;
    Node* right;

    Node(K key, V val) {
        this->key = key;
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }

    Node(K key, V val, Node* left, Node* right) {
        this->key = key;
        this->val = val;
        this->left = left;
        this->right = right;
    }
};