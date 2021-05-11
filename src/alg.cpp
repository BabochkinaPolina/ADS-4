// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <cassert>
template<typename T>
class TPQueue {
 private:
    T *arr;
    int size;
    int begin,
        end;
    int count;
 public:
    explicit TPQueue(int size = 100);
    ~TPQueue();
    void push(const T &);
    T pop();
    T get() const;
    bool isEmpty() const;
    bool isFull() const;
};
template<typename T>
TPQueue<T>::TPQueue(int sizePQueue) :
size(sizePQueue), begin(0), end(0), count(0) {
    arr = new T[size + 1];
}
template<typename T>
TPQueue<T>::~TPQueue() {
    delete [] arr;
}
template<typename T>
void TPQueue<T>::push(const T & item) {
    assert(count < size);
    if (end != 0) {
      for (int i1 = end - 1; i1 > -1; i1--) {
        if (item.prior > arr[i1].prior) {
           arr[i1+1] = arr[i1];
            if (i1 == 0) arr[i1] = item;
        } else {
          if (item.prior <= arr[i1].prior) {
              arr[i1 + 1] = item;
          }
        }
      }
    }  else {
      arr[end] = item;
    }
    end++;
    count++;
}
template<typename T>
T TPQueue<T>::pop() {
  assert(count > 0);
  T item = arr[begin++];
  count--;

if (begin > size) {
begin -= size + 1;
}
return item;
}

template<typename T>
T TPQueue<T>::get() const {
assert(count > 0);
return arr[begin];
}
template<typename T>
bool TPQueue<T>::isEmpty() const {
  return count == 0;
}
template<typename T>
bool TPQueue<T>::isFull() const {
return count == size;
}
struct SYM {
char ch;
int  prior;
};
#endif // INCLUDE_TPQUEUE_H_
