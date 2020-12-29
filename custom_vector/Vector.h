#include <cstddef>
#include <utility>

#ifndef CUSTOM_VECTOR
#define CUSTOM_VECTOR

template<typename Vector>
class VectorIterator{
    private:
        typedef typename Vector::Type Type;
        typedef Type* PType;
        typedef Type& RType; 
    public:
        VectorIterator(PType ptr) : m_ptr(ptr) {}

        VectorIterator operator++(){
            m_ptr++;
            return *this;
        }

        VectorIterator operator++(int){
            VectorIterator temp = *this;
            m_ptr++;
            return temp;
        }

        VectorIterator operator--(int){
            VectorIterator temp = *this;
            m_ptr--;
            return temp;
        }

        VectorIterator operator--(){
            m_ptr--;
            return *this;
        }

        bool operator==(const VectorIterator& iterator){
            return m_ptr == iterator.m_ptr;
        }

        bool operator!=(const VectorIterator& iterator){
            return !(*this == iterator);
        }

        RType operator*(){
            return *m_ptr;
        }

        PType operator->(){
            return m_ptr;
        }
    private:
        PType m_ptr;
};

template<typename T>
class Vector{
    public:
        typedef T Type;
        using Iterator = VectorIterator<Vector<T>>;
    public:
        Vector(){
            ReAlloc(2);
        }

        ~Vector(){
            clear();
            ::operator delete(m_data);
        }

        size_t size() const{
            return m_size;
        }

        void push_back(T& data){
            if( m_size >= m_capacity )
                ReAlloc(m_capacity + m_capacity/2);
            
            m_data[m_size++] = data;
        }

        void push_back(T&& data){
            if( m_size >= m_capacity )
                ReAlloc(m_capacity + m_capacity/2);

            m_data[m_size++] = std::move(data);
        }

        void pop_back(){
            if( m_size > 0 ){
                m_data[--m_size].~T();
            }
        }

        void clear(){
            for(size_t i = 0; i < m_size; i++)
                m_data[i].~T();
            
            m_size = 0;
        }

        template<typename...Args>
        void emplace_back(Args&&...args) noexcept{
            if( m_size >= m_capacity )
                ReAlloc(m_capacity + m_capacity/2);
            
            new(m_data + m_size) T(std::forward<Args>(args)...);
            m_size++;
        }

        T& operator[](int index){
            if( index >= m_size ){
                //assert something
            }

            return m_data[index];
        }

        Iterator begin(){
            return Iterator(m_data);
        }

        Iterator end(){
            return Iterator(m_data + m_size);
        }
    private:
        void ReAlloc(int capacity){
            T* n_data = (T*)::operator new(sizeof(T)*capacity);
            if( capacity < m_size )
                m_size = capacity;
            
            for(size_t i = 0; i < m_size; i++)
                n_data[i] = std::move(m_data[i]);

            for(size_t i = 0; i < m_capacity; i++)
                m_data[i].~T();

            m_capacity = capacity;
            
            ::operator delete(m_data);
            m_data = n_data;
        }

        size_t m_size = 0;
        size_t m_capacity = 0;
        T* m_data = nullptr;
};
#endif