#ifndef __EXCEPTION_H_
#define __EXCEPTION_H_

class DeckFileNotFound : public std::exception
{
public:
    const char * what() const noexcept override
    {
        return "Deck File Error: File not found";
    }
};

class DeckFileFormatError : public std::exception
{
private:
    int m_lineNumber;
    static const int MESSAGE_LENGTH = 64;
    char m_message[MESSAGE_LENGTH];

public:
    DeckFileFormatError(int lineNumber): m_lineNumber(lineNumber){};

    const char * what() const noexcept override
    {
        snprintf((char *)(this->m_message), MESSAGE_LENGTH, "Deck File Error: File format error in line %d",
                 this->m_lineNumber);
        return this->m_message;
    }
};

class DeckFileInvalidSize : public std::exception
{
public:
    const char * what() const noexcept override
    {
        return "Deck File Error: Deck size is invalid";
    }
};

#endif // __EXCEPTION_H_
