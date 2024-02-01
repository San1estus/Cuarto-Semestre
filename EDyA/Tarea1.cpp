#include <bits/stdc++.h>
#include <string>

using namespace std;

template <class TPriority, class TKey>
class UpdatableHeap {
private:
    vector<pair<TPriority, TKey>> heap;
    map<TKey, int> indexMap;


    void heapifyUp(int index){
        while(index > 0) {
            int parent = (index - 1) / 2;
            if(heap[index].first > heap[parent].first || (heap[index].first == heap[parent].first && heap[index].second > heap[parent].second)){
                swap(heap[index], heap[parent]);
                indexMap[heap[index].second] = index;
                indexMap[heap[parent].second] = index;
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

        if(left < heap.size() && (heap[left].first > heap[largest].first || (heap[left].first == heap[largest].first && heap[left].second > heap[largest].second))){
            largest = left;
        }

        if(right < heap.size() && (heap[right].first > heap[largest].first || (heap[right].first == heap[largest].first && heap[right].second > heap[largest].second))){
            largest = right;
        }

        if(largest != index){
            swap(heap[index], heap[largest]);
            indexMap[heap[index].second] = index;
            indexMap[heap[largest].second] = largest;
            heapifyDown(largest);
        }
    }

    
public:

    bool isInserted(const TKey &k) const {
        return indexMap.find(k) != indexMap.end();
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
        indexMap[heap[0].second] = 0;
        heap.pop_back();
        heapifyDown(0);
    }
    
    void insertOrUpdate(const TPriority &p, const TKey &k){
        if(indexMap.find(k) != indexMap.end()){
            erase(k);
        }
        heap.push_back({p,k});
        indexMap[k] = (int)heap.size() - 1;
        heapifyUp((int)heap.size() - 1);
    }

    void erase(const TKey &k) {
        if(indexMap.find(k) != indexMap.end()){
            int index = indexMap[k];
            int parent = (index - 1)/2;
            indexMap.erase(k);
            heap[index] = heap.back();
            indexMap[heap[index].second] = index;
            heap.pop_back();

            if(heap[index] > heap[parent]) heapifyUp(index);
            else heapifyDown(index);

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