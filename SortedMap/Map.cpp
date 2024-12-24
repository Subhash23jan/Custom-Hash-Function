template <typename K, typename V>
class Map : public AbstractMap<K, V> {
private:
    Node<K, V>* findKey(Node<K, V>* root, K key) {
        if (!root || root->key == key)
            return root;
        if (key < root->key)
            return findKey(root->left, key);
        return findKey(root->right, key);
    }

    Node<K, V>* insertKey(Node<K, V>* root, K key, V val) {
        if (!root) {
            this->currSize++;
            return new Node<K, V>(key, val);
        }
        if (key < root->key)
            root->left = insertKey(root->left, key, val);
        else if (key > root->key)
            root->right = insertKey(root->right, key, val);
        else
            root->val = val;
        return root;
    }

    void deleteTree(Node<K, V>* root) {
        if (!root)
            return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }

public:
    Map() {}

    V get(K key) override {
        Node<K, V>* node = findKey(this->binaryTreeRoot, key);
        if (node)
            return node->val;
        throw std::runtime_error("Key not found");
    }
    
    bool count(K key) override{
        return findKey(this->binaryTreeRoot, key)!=NULL;
    }

    bool put(K key, V val) override {
        if (this->currSize == this->maxSize) {
            this->maxSize *= 2;
        }
        this->binaryTreeRoot = insertKey(this->binaryTreeRoot, key, val);
        return true;
    }
    
    V& operator[](K key){
        Node<K, V>* node = findKey(this->binaryTreeRoot, key);
        if (node)
            return node->val;
        this->binaryTreeRoot=insertKey(this->binaryTreeRoot,key,V());
        return findKey(this->binaryTreeRoot, key)->val;
    }
    
    int size(){
         return this->currSize;
    }
    
    
    void clear() override {
        deleteTree(this->binaryTreeRoot);
        this->binaryTreeRoot = NULL;
        this->currSize = 0;
    }

    ~Map() {
        clear();
    }
};