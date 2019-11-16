// Copyright 2018 Your Name <your_email>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <cstddef>
#include <atomic>

template <typename T>
class SharedPtr {


public:

    SharedPtr(){
        object= nullptr;
        amount = nullptr;
    } //

    SharedPtr(T* ptr){
        object = ptr;
        amount = new std::atomic_uint{1};
    }// конструктор от сырого укаазателя

    SharedPtr(const SharedPtr& r){
        *this = r;
    } // копирование

    SharedPtr(SharedPtr&& r){
        *this = std::move(r);
    } // перемещение

    ~SharedPtr() { // деструктор
        if (object == nullptr)
        {
            return;
        }
        else {
            if (*amount == 1)
            {
                delete object;
                delete amount;
            }
            else {
                *amount = *amount - 1;
            }
        }

    }
/*    */
    SharedPtr &operator=(const SharedPtr &r) {
        if(&r==this){
            return *this;
        }
        amount  = r.amount;
        object = r.object;
        (*amount)++;

        return *this;

    } // оператор присваивания, который копирует

    SharedPtr &operator=(SharedPtr&& r) {
        if(&r == this){
            return *this;
        }
        else {
            amount  = r.amount;
            object = r.object;
            r.amount = nullptr;
            r.object = nullptr;



            return *this;
        }
    }// оператор присваивания, который перемещает

// проверяет, указывает ли указатель на объект
    operator bool() const{
        if(object == nullptr) {
            return false;
        }
        return true;
    }

    T& operator*() const{
        return *object;
    } // разыменовывание объекта этого типа (sharpet_ptr)

    T* operator->() const{
        return *object;
    } // оператор стрелочка

    auto get() -> T*{
        return object;
    } // получение объекта

    void reset(){ // обнуление
        this->object = nullptr;
        *amount = 0;
    }

    void reset(T* ptr){ // изменение объекта
        object = ptr;
        *amount = 1;
    }

    void swap(SharedPtr& r){
        std::swap(r.object, object);
        std::swap(r.amount, amount);
    }

// возвращает количество объектов SharedPtr, которые ссылаются на тот же управляемый объект
    unsigned int use_count() const {
        if(amount== nullptr)
            return 0;
        return *amount;
    }

private:
    std::atomic_uint *amount;
    T* object;
};

#endif // INCLUDE_HEADER_HPP_