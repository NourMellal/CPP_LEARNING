#include <iostream>


namespace my_vec
{
    using namespace std;

    template <typename T>

    class Myvec
    {
    private:
        T* data;
        size_t size;
        size_t capacity;

        void resize()
        {
            size_t new_cap = capacity * 2;
            T* new_data = new T[new_cap];
            for (size_t i = 0; i < size; i++)
                new_data[i] = data[i];
            delete data;
            data = new_data;
            capacity = new_cap;
        }
    public:
        Myvec() : data(nullptr), size(0), capacity(1)
        {
            data = new T[capacity];
        }
        ~Myvec() {
            delete data;
        }

        void push_back(const T& value)
        {
            if (size == capacity)
                resize();
            data[size++] = value;
        }

        size_t get_size() const {
            return size;
        }
        size_t get_capacity() const {
            return capacity;
        }

        void display()
        {
            for (size_t i{} ; i < size ; i++)
            {
                cout << data[i] << " ";
            }
        }
        T& operator[](size_t index)
        {
            try {
                if (index >= size)
                {
                    throw std::out_of_range("index out of range");
                }
            } catch (const std::out_of_range &e) {
                cout << "An exception thrown " << e.what() << endl;
            }
            return data[index];
        }
    };

    int main(void) {
        Myvec<int> vec;
        vec.push_back(10);
        vec.push_back(20);
        vec.push_back(20);
        vec.push_back(20);
        vec.push_back(20);
        vec.push_back(20);
        vec.push_back(20);
        vec.push_back(20);
        vec.push_back(20);
        vec.display();
        cout << "\n";
        cout << vec[3] << endl;
        return 0;
    }
} // namespace my_vec


namespace except
{
    using namespace std;

    class A {};
    class B {};

    void unexpectedHandler()
    {
        cout << "unexpected catched\n";
        throw A();
    } 
    void f() throw(A) {
        throw B();
    }

    int main(void) {
        set_unexpected(unexpectedHandler);
        try {
            
        } catch(A&) {
            cout << "from main\n";
        }
        qreturn 0;
    }
} // namespace except



int main(void) {
    // my_vec::main();
    except::main();
}