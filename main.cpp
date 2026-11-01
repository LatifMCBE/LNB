#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    if (argc < 2) // Checks If We Gave a File
    {
        return 1;
    }
    
    std::string file_name = argv[1];
    std::ifstream file(file_name);
    
    if (!file.is_open())
    {
        std::cout << "ERROR: File Did Not Found\n"
            << "Make Sure File Path And File Name Are Correct!"
        << std::endl; // "Cool" Error Message
        return 1;
    }
    
    std::string line;
    int line_no = 0;
    
    while(std::getline(file, line))
    {
        line_no++;
        
        size_t begin = line.find_first_not_of(" \t\r"); // First Character of THE Line
        if (begin == std::string::npos) // If Only Space(s)
        {
            continue; // skip the line
        }
        size_t end = line.find_last_not_of(" \t\r"); // Last Character of THE Line
        line = line.substr(begin, end - begin + 1); // for substr(begin, length);
        
        const std::string start = "printl(\""; // How Starts
        const std::string finish = "\");"; // How Ends
        
        bool start_is_right = line.compare(0, start.size(), start) == 0;
        bool finish_is_right = line.size() >= start.size() + finish.size() && line.compare(line.size() - finish.size(), finish.size(), finish) == 0;
        
        if (start_is_right && finish_is_right)
        {
            std::string string = line.substr(
                start.size(),
                line.size() - start.size() - finish.size());
            std::cout << string << std::endl; // Finally I CAN PRINT
        }
        
        
        else {
            std::cout << "ERROR: Unknown Command\n"
                << "Line No: " << line_no << "\n"
                << "Line: " << line << "\n"
                << "Just One Question: What You Did Wrong !?\nThere are Just a Few Commands"
            << std::endl; // I'm Serious
            
            return 1;
        }
    }
    
    return 0; // "return 0": I Wanna End It All !!!
} // Don't Ask How am I Still Alive with This Brain 'cause I Don't Even Know