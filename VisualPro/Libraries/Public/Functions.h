//Windows/Linux commands // Author: Edward Patch

#pragma once
#include <iostream>
#include <sstream>
#include <string>

class _declspec(dllexport) Functions 
{
    protected:
        // 0 = Windows, 1 = Linux
        const int operatingSystemConf = 0;
        std::stringstream stream;
        std::string uInput;
        char cInput;
        double nInput;
	
    public:	
        void PauseSystem() 
        { 
			//Windows
			if (operatingSystemConf == 0)
				system("Pause");

            //Instead of system("Pause");
            //Send to my text input and ask the user to press enter :/
            
			//Linux:
			else
				TextInput("Press enter to continue...");
        }

        void ClearSystem()
        {
			//Windows:
			if(operatingSystemConf == 0)
				system("CLS");

			//Linux:
			else
				std::cout << "\033[2J";
        }

        char CharInput(std::string msg)
        {
            std::cout << msg;

            cInput = getchar();

            return cInput;
        }

        void CharsInput(std::string msg, char* aCInput, int size)
        {
            std::cout << msg;

            std::cin.getline(aCInput, size);
        }

        std::string TextInput(std::string msg)
        {
            std::cout << msg;

            getline(std::cin, uInput);

            return uInput;
        }

        double NumberInput(std::string msg)
        {
            std::cout << msg;

            getline(std::cin, uInput);
            stream.str(uInput);
            stream >> nInput;
            stream.clear();

            return nInput; 
        }

        double TextToNumber(std::string input)
        {
            stream.str(input);
            stream >> nInput;
            stream.clear();
            
            return nInput;
        }

        std::string NumberToText(double input)
        { return std::to_string(input); }

        std::string NumberToText(float input)
        { return std::to_string(input); }
	
		std::string NumberToText(int input)
        { return std::to_string(input); }

        char TextToChar(std::string input)
        {
            stream.str(input);
            stream >> cInput;
            stream.clear();

            return cInput;
        }

        bool TextToBool(std::string input, char charTrue)
        {
            if(input[0] == charTrue) return true;
            return false;
        }

        bool TextToBool(std::string input, const char* charsTrue)
        {
            if(input[0] == charsTrue[0] || input[0] == charsTrue[1])
                return true;
            return false;
        }

        // Latest Feature <3 || Should work on Windows
        std::string ColorText(std::string input, int FG, int BG, int opt = 1)
        { return "\033[" + std::to_string(opt) + ";" + std::to_string(BG) + ";" + std::to_string(FG) + "m" + input + "\033[0m"; }
};
