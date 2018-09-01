#pragma once
#include <cstddef>

template<typename T>
class dl_list {
public:
    dl_list();
    ~dl_list();

    void push_back(T elem);
    void push_front(T elem);

    T front() const;
    T back() const;

    void pop_back();
    void pop_front();

    size_t size() const;
    bool empty() const;

private:
    struct list_data {
        T  data;
        T* prev = nullptr;
        T* next = nullptr;
    };

    T* begin_;
    T* end_;
    size_t size_;
};

template <typename T>
dl_list<T>::dl_list() : begin_(nullptr), end_(nullptr), size_(0) {
}

template <typename T>
dl_list<T>::~dl_list() {
}

template <typename T>
void dl_list<T>::push_back(T elem) {
    if (begin_ == nullptr && end_ == nullptr) {
        begin_ = new list_data();
        begin_->data = elem;
        end_ = begin_;

        size_++;
        return;
    }

    T* new_next_elem = new list_data();

    new_next_elem->data = elem;
    new_next_elem->prev = end_;

    end_->next = new_next_elem;
    end_ = new_next_elem;

    size_++;
}

template <typename T>
void dl_list<T>::push_front(T elem) {
    if (begin_ == nullptr && end_ == nullptr) {
        begin_ = new list_data();
        begin_->data = elem;
        end_ = begin_;

        size_++;
        return;
    }

    T* new_prev_elem = new list_data();

    new_prev_elem->data = elem;
    new_prev_elem->next = begin_;

    begin_->prev = new_prev_elem;
    begin_ = new_prev_elem;

    size_++;
}

template <typename T>
T dl_list<T>::front() const {
    if (begin_ != nullptr) {
        return *begin_->data;
    }

    return NULL;
}

template <typename T>
T dl_list<T>::back() const {
    if (end_ != nullptr) {
        return *end_->data;
    }

    return NULL;
}

template <typename T>
void dl_list<T>::pop_back() {
    if (begin_ == nullptr && end_ == nullptr) {
        return;
    }


    T* prev_elem = end_->prev;
    if (prev_elem == begin_) {

    }

    prev_elem->next = nullptr;
    delete end_;
    end_ = prev_elem;

    size_--;
}

template <typename T>
void dl_list<T>::pop_front() {
    if (begin_ == nullptr && end_ == nullptr) {
        return;
    }


    size_--;
}

template <typename T>
size_t dl_list<T>::size() const {
    return size_;
}

template <typename T>
bool dl_list<T>::empty() const {
    return begin_ == nullptr && end_ == nullptr ? true : false;
}

