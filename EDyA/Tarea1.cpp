#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

template <class TPriority, class TKey>
class UpdatableHeap {
private:
    struct HeapNode {
        TPriority priority;
        TKey key;

        HeapNode(const TPriority &p, const TKey &k) : priority(p), key(k) {}
    };

    vector<HeapNode> heap;
    unordered_map<TKey, unsigned int> keyIndexMap;

    void heapifyUp(unsigned int index) {
        while (index > 0) {
            unsigned int parentIndex = (index - 1) / 2;
            if (heap[index].priority > heap[parentIndex].priority ||
                (heap[index].priority == heap[parentIndex].priority && heap[index].key > heap[parentIndex].key)) {
                swap(heap[index], heap[parentIndex]);
                keyIndexMap[heap[index].key] = index;
                keyIndexMap[heap[parentIndex].key] = parentIndex;
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    void heapifyDown(unsigned int index) {
        unsigned int leftChild = 2 * index + 1;
        unsigned int rightChild = 2 * index + 2;
        unsigned int largest = index;

        if (leftChild < heap.size() &&
            (heap[leftChild].priority > heap[largest].priority ||
             (heap[leftChild].priority == heap[largest].priority && heap[leftChild].key > heap[largest].key))) {
            largest = leftChild;
        }

        if (rightChild < heap.size() &&
            (heap[rightChild].priority > heap[largest].priority ||
             (heap[rightChild].priority == heap[largest].priority && heap[rightChild].key > heap[largest].key))) {
            largest = rightChild;
        }

        if (largest != index) {
            swap(heap[index], heap[largest]);
            keyIndexMap[heap[index].key] = index;
            keyIndexMap[heap[largest].key] = largest;
            heapifyDown(largest);
        }
    }

public:
    UpdatableHeap() {}

    pair<TPriority, TKey> top() const {
        return make_pair(heap[0].priority, heap[0].key);
    }
    
    bool isEmpty(){
       return heap.empty();
    }
    
    void pop() {
        if (!heap.empty()) {
            keyIndexMap.erase(heap[0].key);
            if(heap.size() > 1){
                heap[0] = heap.back();
                keyIndexMap[heap[0].key] = 0;
                heap.pop_back();
                heapifyDown(0);
            } else heap.clear();
            
        }
    }

    void insertOrUpdate(const TPriority &p, const TKey &k) {
        if (keyIndexMap.find(k) != keyIndexMap.end()) {
        
            unsigned int index = keyIndexMap[k];
            heap[index].priority = p;
            heapifyUp(index);
            heapifyDown(index);
        } else {
        
            heap.push_back(HeapNode(p, k));
            keyIndexMap[k] = heap.size() - 1;
            heapifyUp(heap.size() - 1);
        }
    }

    bool isInserted(const TKey &k) const {
        return keyIndexMap.find(k) != keyIndexMap.end();
    }

    int getSize() const {
        return heap.size();
    }

    void erase(const TKey &k) {
        if (keyIndexMap.find(k) != keyIndexMap.end()) {
            int index = keyIndexMap[k];
            keyIndexMap.erase(keyIndexMap.find(k));
            
            if(index == (int)heap.size() - 1) heap.pop_back();
             
            else{
                heap[index] = heap.back();
                keyIndexMap[heap[index].key] = index;
                heap.pop_back();
                heapifyUp(index);
                heapifyDown(index);
            }
        }
    }
};

int main() {
    UpdatableHeap<int, string> myHeap;
    int ops, value;
    cin >> ops;

    string op, food;
    while(ops--){
        cin >> op;
        if(op == "P"){
            if(myHeap.isEmpty()) cout << -1 << endl;
            else cout << myHeap.top().second << " " << myHeap.top().first << endl;
        }
        if(op == "IU"){
            cin >> food >> value;
            myHeap.insertOrUpdate(value, food);
        }
        if(op == "DL"){
            myHeap.pop();
        }
        if(op == "D"){
            cin >> food;
            myHeap.erase(food);
        }
    }

    return 0;
}