#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

template <typename T>
class Stack {
 public:
    Stack() noexcept;
    explicit Stack(size_t s) noexcept;
    Stack(const Stack& u) noexcept;
    Stack(Stack&& u) noexcept;
    size_t count() const noexcept;
    bool empty() const noexcept;
    void push(T const &) noexcept;
    T& top() const noexcept;
    void pop() noexcept;
    ~Stack() noexcept;

    Stack<T>& operator=(const Stack& u) noexcept;
    Stack<T>& operator=(Stack&& u) noexcept;
    T& operator[](size_t x) const noexcept;

 private:
    T* array_;
    size_t array_size_;
    size_t count_;
};

template <typename T>
Stack<T>::Stack() noexcept : Stack(100) {}

template <typename T>
Stack<T>::Stack(size_t s) noexcept : array_size_(s), array_(new T[s]), count_(0) {}

template <typename T>
Stack<T>::Stack(const Stack& u) noexcept{
 delete[] array_;
 array_size_ = u.array_size_;
 count_ = u.count_;
 array_ = new T[u.array_size_];
    for(size_t i = 0; i < u.count_;++i) {
        array_[i] = u.array_[i];
    }
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& u) noexcept {
    if(this != &u) {
        delete[] array_;
        count_ = u.count_;
        array_size_ = u.array_size_;
        array_ = new T[array_size_];
        for(int i = 0; i < count_; i++) {
            array_[i] = u.array_[i];
        }
    } else {
        throw std::runtime_error("\tIt's the same object...");
    }
    return *this;
}

template <typename T>
Stack<T>::Stack(Stack&& u) noexcept : array_(u.array_), array_size_(u.array_size_), count_(u.count_) {
    u.array_size_ = 0;
    u.count_ = 0;
    u.array_ = nullptr;
}

template <typename T>
Stack<T>& Stack<T>::operator=(Stack&& u) noexcept {
 if(this != &u) {
    count_ = u.count_;
    array_size_ = u.array_size_;
    array_ = u.array_;
    u.count_ = 0;
    u.array_size_ = 0;
    u.array_ = nullptr;
   }
    return *this;
}

template <typename T>
Stack<T>::~Stack() noexcept {
    delete[] array_;
}

template <typename T>
void Stack<T>::push(T const &val) noexcept {
    if (count_ == array_size_) {
        T* array_exp_ = new T[array_size_*2];
        for (int i = 0; i < array_size_; i++) {
            array_exp_[i] = array_[i];
        }
        array_size_ *= 2;
        delete[] array_;
        array_ = array_exp_;
    }
    array_[count_++] = val;
}

template <typename T>
void Stack<T>::pop() noexcept {
    if(count_ == 0) {
      throw std::runtime_error("\tStack empty...");
    }
    --count_;
    
}

template <typename T>
size_t Stack<T>::count() const noexcept {
    return count_;
}

template <typename T>
bool empty() const noexcept {
    if (count_ == 0) return true;
    return false;
}

template <typename T>
T& Stack<T>::top() const noexcept {
    return array_[count_];
}

template <typename T>
T& Stack<T>::operator[](size_t x) const noexcept {
    return array_[x];
}
