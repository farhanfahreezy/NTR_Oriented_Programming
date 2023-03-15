#ifndef FILE_HPP
#define FILE_HPP

#include <string>
#include <fstream>
#include <functional>
using namespace std;

class File{
    public:
        /**
         * Provides interface functions for reading from a file.
        */
        class Read{
            private:
                ifstream fs;
            
            public:
                /**
                 * Creates an input file stream from a file.
                 * 
                 * @param path Path to the file.
                */
                Read(string path): fs(path){}

                /**
                 * Closes the file stream.
                */
                ~Read(){
                    fs.close();
                }

                /**
                 * Reads a line from the file stream and stores it into `line`. Returns whether read operation is successful.
                 * 
                 * @param line Out parameter for file line.
                */
                bool readLine(string& line){
                    return (bool)getline(fs, line);
                }

                /**
                 * Reads each line and calls the given function.
                 * 
                 * @param cons Consumer that accepts a string.
                */
                void each(function<void(string&)> cons){
                    string line;
                    while(readLine(line))cons(line);
                }

                /**
                 * Allows usage of the >> operator on a File::Read object to extract a line from the stream.
                 * 
                 * @attention Does not check if read operation is successful.
                */
                Read& operator>>(string& line){
                    readLine(line);
                    return *this;
                }
        };

        /**
         * Provides interface functions for writing to a file.
        */
        class Write{
            private:
                ofstream fs;
            
            public:
                /**
                 * Creates an output file stream from a file.
                 * 
                 * @param path Path to the file.
                */
                Write(string path): fs(path){}

                /**
                 * Closes the file stream.
                */
                ~Write(){
                    fs.close();
                }

                /**
                 * Writes an object into the file stream.
                 * 
                 * @attention Assumes a definition of `ostream& operator<<(T)` exists.
                 * 
                 * @param obj The object to be written.
                */
                template<class T>
                void write(const T& obj){
                    fs << obj;
                }

                /**
                 * Allows usage of the << operator on a File::Write object to write an object into the stream.
                 * 
                 * @attention Assumes a definition of `ostream& operator<<(T)` exists.
                */
                template<class T>
                Write& operator<<(const T& obj){
                    write(obj);
                    return *this;
                }
        };
};

#endif
