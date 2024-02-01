#include <bits/stdc++.h>

template <class TPriority, class TKey>
class UpdatableHeap {
private:
    vector<pair<TPriority, TKey>> heap;
    map<TKey, int> indexMap;

    void hepifyDown(int index){
        
    }

    
public:
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
    
    bool isInserted(const TKey &k) const {
        return keyIndexMap.find(k) != keyIndexMap.end();
    }

    int getSize() const {
        return heap.size();
    }
};