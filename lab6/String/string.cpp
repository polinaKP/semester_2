#include <iostream>

struct string {
    char *str;
    size_t size;
    size_t capacity;

    string() //  онструктор пустой строки
    {
        str = NULL;
    }

    string(size_t cnt, char c) // «аполн€ющий конструктор
    {
        size = cnt;
        capacity = 1;
        while (capacity < size)
            capacity = capacity * 2;
        str = new char[capacity + 1];
        for (int i = 0; i < size; i++)
            str[i] = c;
        str[cnt] = '/0';
    }

    string(const string& s) //  опирующий конструктор
    {
        size = s.size;
        capacity = s.capacity;
        str = new char[capacity + 1];
        for (int i = 0; i <= size; i++)
            str[i] = s[i];
    }

    string(char c)  //  онструктор строки из одного символа
    {
        capacity = 1;
        size = 1;
        str = new char[capacity + 1];
        str[0] = c;
        str[1] = '\0';
    }

    string(const char *c_str)  //  онструктор строки из c-style строки (массива символов)
    {
        size = 0;
        while (c_str[size] != '\0')
            size++;
        capacity = 1;
        while (capacity < size)
            capacity = capacity * 2;
        str = new char[capacity + 1];
        for (int i = 1; i <= size; i++)
            str[i] = c_str[i];
    }

    ~string() //очистить всю используемую пам€ть
    {
        delete [] str;
        str = NULL;
        size = 0;
        capacity = 0;
    }

    string& operator= (const string& new_str)
    {
        size = new_str.size;
        size_t new_capacity = 1;
        while (new_capacity < size)
            new_capacity = new_capacity * 2;
        reserve(new_capacity);
        for (int i = 0; i <= size; i++)
             str[i] = new_str[i];
        return *this;
    }

    bool operator== (const string& other)
    {
        bool flag = false;
        if (size == other.size)
        {
            int i = 0;
            while (other[i] == str[i] && other[i] != '\0')
                i++;
            if (i = size)
                flag = true;
        }
        return flag;
    }

    bool operator!= (const string& other)
    {
        bool flag = false;
        if (*this == other)
            flag = true;
        return flag;
    }

    bool operator> (const string& other)
    {
        bool flag = false;
        if (size > other.size)
            flag = true;
        else if (size = other.size)
        {
            int i = 0;
            while (other[i] == str[i] && other[i] != '\0')
                i++;
            if (str[i] > other[i])
                flag = true;
        }
        return flag;
    }

    bool operator< (const string& other)
    {
        bool flag = true;
        if ((*this > other) || (*this == other))
            flag = false;
        return flag;
    }

    string& operator+= (const string& other)
    {
        size_t new_size = size + other.size;
        size_t new_capacity = 1;
        while (new_capacity < new_size)
            new_capacity = new_capacity * 2;
        reserve(new_capacity);
        for (int i = size; i < new_size; i++)
            str[i] = other[i - size];
        str[new_size] = '\0';
        size = new_size;
        return *this;
    }

    char operator[] (unsigned int pos) const
    {
        return str[pos];
    }

    void append(const string other) // дописать в конец данной строки другую
    {
        *this += other;
    }

    void resize(unsigned int new_capacity) // увеличить/уменьшить емкость строки
    {
        if (size >= new_capacity)
        {
            capacity = new_capacity;
            size = new_capacity;
            str[size] = '\0';
        }
        else
            reserve(new_capacity);
    }

    void reserve(unsigned int new_capacity) // зарезервировать пам€ть в нужном объеме
    {
        if (capacity < new_capacity)
        {
            capacity = new_capacity;
            char * new_str = new char[capacity + 1];
            for (int i = 0; i <= size; i++)
                new_str[i] = str[i];
            delete [] str;
            str = new_str;
        }
    }

    void insert(unsigned int pos, string other) {}  // ¬ставка другой строки внутрь данной

    void shrink_to_fit() //очистить неиспользуемую пам€ть
    {
        (*this).resize(size);
    }

    void clear() //очистить содержимое строки, занимаемое место при этом не мен€етс€
    {
        for (int i = 1; i <= size; i++)
            str[i] = '0';
        str[0] = '\0';
        size = 0;
    }

    friend std::ostream& operator<< (std::ostream& ostr, const string& str)
    {
        for (int i = 0; i < str.size; i++)
            ostr << str[i];
        return ostr;
    }

    friend std::istream& operator>> (std::istream& istr, const string& str)
    {
        istr >> str.str;
        return istr;
    }

};


string operator + (const string & str1, const string & str2)
{
    string new_str(str1);
    new_str += str2;
    return new_str;
}

int stoi(const string str, size_t pos = 0, int base = 10 );
// ѕреобразование числа, записанного символами в строке, в int
// base - основание системы счислени€
// „исла могут быть отрицательными
// ќбработка чисел в сс > 10. Ѕольшие и маленькие буквы.

int main()
{
    string empty_str();

    char element;
    std::cout << "Enter element which you want to display: ";
    std::cin >> element;
    string one_element(element);
    std::cout << one_element << '\n';

    std::cout << "Enter number of elements and element: ";
    size_t number;
    std::cin >> number >> element;
    string fill_str(number, element);
    std::cout << "Fill string: ";
    std::cout << fill_str << '\n';

    std::cout << "Copy string: ";
    string copy_str(fill_str);
    std::cout << copy_str << '\n';

    std::cout << "Double string: ";
    fill_str += fill_str;
    std::cout << fill_str << '\n';

    return 0;
}
