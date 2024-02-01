#include <bits/stdc++.h>

template <class TPriority, class TKey>
class UpdatableHeap {
private:
    vector<pair<TPriority, TKey>> heap;
    map<TKey, int> indexMap;


    void heapifyUp(int index){
        while(index > 0) {
            int parent = (index - 1) / 2;
            if(heap[index].priority > heap[parent].priority || (heap[index].priority == heap[parent].priority && heap[index].key > heap[parent].key)){
                swap(heap[index].priority, heap[parent]);
                indexMap[heap[index].key] = index;
                indexMap[heap[parent].key] = index;
                index = parent;
            } else{
                break;
            }
        }
    }

    void heapifyDown(int index){
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if(left < heap.size() && (heap[left].priority > heap[largest].priority || (heap[left].priority == heap[largest].priority && heap[left].key > heap[largest].key))){
            largest = left;
        }

        if(right < heap.size() && (heap[right].priority > heap[largest].priority || (heap[right].priority == heap[largest].priority && heap[right].key > heap[largest].key))){
            largest = right;
        }

        if(largest != index){
            swap(heap[index], heap[largest]);
            indexMap[heap[index].key] = index;
            indexMap[heap[largest].key] = largest;
            heapifyDown(largest);
        }
    }

    
public:

    bool isInserted(const TKey &k) const {
        return keyIndexMap.find(k) != keyIndexMap.end();
    }

    int getSize() const {
        return heap.size();
    }

    bool isEmpty(){
        return heap.empty();
    }

    pair<TPriority, TKey> top() const{
        return heap[0];
    }

    void pop(){
        indexMap.erase(heap[0].second);
        heap[0] = heap.back();
        keyIndexMap[heap[0].second] = 0;
        heap.pop_back();
        heapifyDown(0);
    }
    
    void erase(const TKey &K) {
        if(indexMap.find(k) != indexMap.end()){
            int index = indexMap[k];
            int parent = (index - 1)/2;
            indexMap.erase(k);
            heap[index] = heap.back();
            indexMap[heap[index].key] = index;
            heap.pop_back();
            
        }
    }
};