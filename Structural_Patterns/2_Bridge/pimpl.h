#include<memory>

template<typename T> 
class pimple{
    private:
    std::unique_ptr<T> impl;
    public:
    pimple();
    ~pimple();
    template<typename... Args>
    pimple(Args&&... args);
    T* operator->();
    T& operator*();
}