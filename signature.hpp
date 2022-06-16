#ifndef SIGNATURE_HPP
#define SIGNATURE_HPP

#include <iostream>

class CaesarCipher
{
private:
    std::string message;
    void encodeTheMessage(std::string&,const ushort&);
    void decodeTheMessage(std::string&,const ushort&);

public: 
    CaesarCipher();
    std::string getMessage();
};

std::string codeYourMessage();

#endif