#include<iostream>
#include<cstring>

class String
{
    private:
        unsigned int m_Size;
        
    public:
        char* m_Buffer;
        String(const char* str)
        {   m_Size = strlen(str);
            m_Buffer = new char[m_Size + 1];
            memcpy(m_Buffer,str,m_Size+1);
        }
        String(const String& other) :m_Size(other.m_Size)
        {
            m_Buffer = new char[m_Size+1];
            std::cout<<"Copy !!";
            memcpy(m_Buffer,other.m_Buffer,m_Size+1);
        }
        ~String()
        {
            delete[] m_Buffer;
        }
        friend std::ostream& operator <<(std::ostream &out,const String& string);
};
std::ostream& operator <<(std::ostream &out,const String& string)
{
    out << string.m_Buffer;
    return out;
}
int main()
{   String string = "Pratham";
    String str = string;
    str.m_Buffer[2] ='i';
    std::cout<< string<<std::endl;
    std::cout<< str<<std::endl;
    std::cin.get();
}