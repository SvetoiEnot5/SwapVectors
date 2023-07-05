#include <iostream>
using namespace std;

class MyIntVector
{
public:
    void pushback(int);
    int Length() const;
    int Capacity() const;
    bool IsEmpty() const;
    int& operator[](int n) const;
    MyIntVector& operator=(const MyIntVector&);
    MyIntVector(const MyIntVector&);
    MyIntVector();
    ~MyIntVector() { delete[] this->dataPointer; };
    void clean();
private:
    void UpCapacity(int newCapacity);
    int length;
    int capacity;
    int* dataPointer;
};
int MyIntVector::Length() const
{
    return this->length;
}
int& MyIntVector::operator[](int n) const
{
    return this->dataPointer[n];
}
int MyIntVector::Capacity() const
{
    return this->capacity;
}
bool MyIntVector::IsEmpty() const
{
    if (this->length == 0)
        return true;
    else
        return false;
}
void MyIntVector::UpCapacity(int newCapacity)
{
    int* newDataPointer = new int[newCapacity];
    for (int i = 0; i < this->length; i++)
    {
        newDataPointer[i] = this->dataPointer[i];
    }
    this->dataPointer = newDataPointer;
    this->capacity = newCapacity;
}
void MyIntVector::pushback(int n)
{
    if (this->length < this->capacity)
    {
        this->dataPointer[this->length] = n;
        this->length++;
    }
    else
    {
        this->UpCapacity(this->capacity * 2);
        this->dataPointer[this->length] = n;
        this->length++;
    }
}
void MyIntVector::clean()
{
    this->length = 0;
    this->capacity = 1;
    delete this->dataPointer;
    this->dataPointer = new int[1];
}
void OutputMyIntVector(const MyIntVector& outVector)
{
    for (int i = 0; i < outVector.Length(); i++)
    {
        cout << outVector[i] << ' ';
    }
    cout << endl;
}
void InputMyIntVector(MyIntVector& inVector, int N)
{
    for (int i = 0; i < N; i++)
    {
        int val;
        cin >> val;
        inVector.pushback(val);
    }
}
MyIntVector& MyIntVector::operator=(const MyIntVector& sec)
{
    MyIntVector dop;
    for (int i = 0; i < sec.Length(); i++)
    {
        int a = sec[i];
        dop.pushback(a);
    }
    this->clean();
    for (int i = 0; i < dop.Length(); i++)
    {
        int a = dop[i];
        this->pushback(a);
    }
    return *this;
}
MyIntVector::MyIntVector()
{
    cout << "work";
    this->length = 0;
    this->capacity = 1;
    this->dataPointer = new int[1];
}
MyIntVector::MyIntVector(const MyIntVector& vec)
{
    this->length = 0;
    this->capacity = 1;
    this->dataPointer = new int[1];
    for (int i = 0; i < vec.Length(); i++)
    {
        int a = vec[i];
        this->pushback(a);
    }
}

template<class TypeOfElement>
class MyVector
{
public:
    void pushback(TypeOfElement);
    int Length() const;
    int Capacity() const;
    bool IsEmpty() const;
    TypeOfElement& operator[](int n) const;
    MyVector<TypeOfElement>& operator=(const MyVector<TypeOfElement>&);
    MyVector(const MyVector<TypeOfElement>&);
    MyVector();
    ~MyVector() { delete[] this->dataPointer; };
    void clean();
    MyVector<TypeOfElement> operator+(const MyVector<TypeOfElement>&);
    void MyVector<TypeOfElement>::Swap(MyVector<TypeOfElement> & v1);
private:
    void UpCapacity(int newCapacity);
    int length;
    int capacity;
    TypeOfElement* dataPointer;
};

template<class T>
MyVector<T> MyVector<T>::operator+(const MyVector<T>& vec)
{
    MyVector<T> res = *this;
    for (int i = 0; i < vec.Length(); i++)
    {
        res.pushback(vec[i]);
    }
    return res;
}
template<class T>
int  MyVector<T>::Length() const
{
    return this->length;
}
template<class T>
T& MyVector<T>::operator[](int n) const
{
    return this->dataPointer[n];
}
template<class T>
int MyVector<T>::Capacity() const
{
    return this->capacity;
}
template<class T>
bool MyVector<T>::IsEmpty() const
{
    if (this->length == 0)
        return true;
    else
        return false;
}
template<class T>
void MyVector<T>::UpCapacity(int newCapacity)
{
    T* newDataPointer = new T[newCapacity];
    for (int i = 0; i < this->length; i++)
    {
        newDataPointer[i] = this->dataPointer[i];
    }
    this->dataPointer = newDataPointer;
    this->capacity = newCapacity;
}
template<class T>
void MyVector<T>::pushback(T n)
{
    if (this->length < this->capacity)
    {
        this->dataPointer[this->length] = n;
        this->length++;
    }
    else
    {
        this->UpCapacity(this->capacity * 2);
        this->dataPointer[this->length] = n;
        this->length++;
    }
}
template<class T>
void MyVector<T>::clean()
{
    this->length = 0;
    this->capacity = 1;
    delete this->dataPointer;
    this->dataPointer = new T[1];
}
template<typename T>
void OutputMyVector(const MyVector<T>& outVector)
{
    for (int i = 0; i < outVector.Length(); i++)
    {
        std::cout << outVector[i] << ' ';
    }
    std::cout << std::endl;
}
template<typename T>
void InputMyVector(MyVector<T>& inVector, int N)
{
    for (int i = 0; i < N; i++)
    {
        T val;
        std::cin >> val;
        inVector.pushback(val);
    }
}
template <typename Type>
MyVector<Type> &MyVector<Type>::operator=(const MyVector<Type> &rhs) {
    MyVector<Type> tmp(rhs);
    if (this->capacity != 0)
        delete[] this->dataPointer;
    this->length = tmp.Length();
    this->capacity = tmp.Capacity();
    this->dataPointer = new Type[this->capacity];
    for(int i = 0; i < this->capacity; ++i)
        this->dataPointer[i] = tmp[i];
    return *this;
}
template<class T>
MyVector<T>::MyVector()
{
    this->length = 0;
    this->capacity = 1;
    this->dataPointer = new T[1];
}
template<class T>
MyVector<T>::MyVector(const MyVector<T>& vec)
{
    this->length = 0;
    this->capacity = 1;
    this->dataPointer = new T[1];
    for (int i = 0; i < vec.Length(); i++)
    {
        int a = vec[i];
        this->pushback(a);
    }
}

template<class TypeOfElement>
void MyVector<TypeOfElement>::Swap(MyVector<TypeOfElement> & v1) {
    MyVector<TypeOfElement> tmp(v1);
    v1 = *this;
    if (this->capacity != 0)
        delete[] this->dataPointer;
    this->length = tmp.Length();
    this->capacity = tmp.Capacity();
    this->dataPointer = new TypeOfElement[this->capacity];
    for(int i = 0; i < this->capacity; ++i)
        this->dataPointer[i] = tmp[i];
}

template<class MyType>
void MySwap(MyType& element1, MyType& element2)
{
    MyType element3 = element1;
    element1 = element2;
    element2 = element3;
}

int main()
{

    setlocale(LC_ALL, "Russian");
    MyVector<char> v1, v2;
    int n1, n2;
    cout << "Введите длину первого вектора: ";
    cin >> n1;
    cout << "Введите элементы первого вектора: ";
    InputMyVector(v1, n1);
    cout << "Введите длину второго вектора: ";
    cin >> n2;
    cout << "Введите элементы второго вектора: ";
    InputMyVector(v2, n2);
    v1.Swap(v2);
    cout << "Результат обмена двух векторов: " << endl;
    OutputMyVector(v1);
    OutputMyVector(v2);
}
