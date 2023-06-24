#include <iostream>
#include <string>

class bad_length : public std::exception 
{
public:
    const char* what() const noexcept 
    {
        return "Вы ввели слово запретной длины!";
    }
};

int function(std::string str, int forbidden_length) 
{
    int length = str.length();
    if (length == forbidden_length) 
    {
        throw bad_length();
    }
    return length;
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    int forbidden_length;
    std::cout << "Введите запретную длину: ";
    std::cin >> forbidden_length;

    std::string str;
    while (true) 
    {
        std::cout << "Введите слово: ";
        std::cin >> str;
        try 
        {
            int length = function(str, forbidden_length);
            std::cout << "Длина слова \"" << str << "\" равна " << length << std::endl;
        }
        catch (const bad_length& e)
        {
            std::cout << e.what() << " До свидания" << std::endl;
            break;
        }
    }
    return 0;
}
