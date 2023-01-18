#ifndef __EXCEPTION_H_
#define __EXCEPTION_H_

class DeckFileNotFound : std::exception
{
    const char * what() const noexcept override
    {
        return "Deck File Error: File not found";
    }
};

class DeckFileFormatError : std::exception
{
private:
    int m_lineNumber;
    static const int MESSAGE_LENGTH = 64;

public:
    DeckFileFormatError(int lineNumber): m_lineNumber(lineNumber){};

    const char * what() const noexcept override
    {
        char* output = new char[MESSAGE_LENGTH];
        snprintf(output, MESSAGE_LENGTH, "Deck File Error: File format error in line %d",
                 this->m_lineNumber);
        return output;
    }
};

class DeckFileInvalidSize : std::exception
{
    const char * what() const noexcept override
    {
        return "Deck File Error: Deck size is invalid";
    }
};

#endif // __EXCEPTION_H_
