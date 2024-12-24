template <typename K, typename V>
class AbstractMap {
protected:
    int maxSize;
    int currSize;
    Node<K, V>* binaryTreeRoot;

public:
    AbstractMap() : maxSize(10), binaryTreeRoot(NULL), currSize(0) {}
    virtual V get(K key) = 0;
    virtual bool put(K key, V val) = 0;
    virtual void clear() = 0;
    virtual bool count(K key)=0;
    virtual int size()=0;
    virtual ~AbstractMap() = default;
};