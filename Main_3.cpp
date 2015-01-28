//attempt 2
// Meant to shorten orginal with string manipulation


#include<iostream>  //for io
#include<fstream>   //for file reading to find drive
#include<string>    //strings for finding drives
#include<windows.h> //for opening .exes
#include<Shellapi.h>//for opening .exes


using namespace std;    //for io

char drive = 'a';   //saves what drive the USB is on

int whichDrive()    //checks drive of the USB
{
    string found = "n", //string set away from "y"
    directory = "A:\\Projects\\USB Shortcutter\\drive.txt";

    int alternate = 0;  //starts drive reading off

    while (found != "y")  //Found the USB yet?
    {
        alternate++;    //counts up to read the drives

        if (alternate == 1)
            directory[0] = 'D';
        if (alternate == 2)
            directory[0] = 'E';
        if (alternate == 3)
            directory[0] = 'F';
        if (alternate == 4)
            directory[0] = 'G';
        if (alternate == 5)
            directory[0] = 'H';
        if (alternate == 6)
            directory[0] = 'I';
        if (alternate == 7)
            directory[0] = 'J';
        if (alternate == 8)
            directory[0] = 'K';
        if (alternate == 9)
            directory[0] = 'L';

            ifstream driveReader (directory.c_str());
            if (driveReader.is_open())
            {

                while ( getline (driveReader, found))
                driveReader >> found;
                drive = directory[0];
                driveReader.close();
            }

    }//end of the while loop looking for the drives
    return 0;
}//end of searching for drives function

void runProgram (string programToRun)
{
    programToRun[0] = drive;
    ShellExecute(NULL, "open", programToRun.c_str(),"","", SW_SHOW);
}


int main()  //main function
{

    int choice,         //save spot for user choice
    bigLoop = 1;    //creates big loop

    whichDrive();   //calls function of which drive

    while (bigLoop == 1)    // forever big loop
    {

        //asks for what to run
        cout << "On Drive " << drive << ":" << endl
        << "Choose between any of the following programs." << endl
        << "0:  End" << endl
        << "1:  Arduino" << endl
        << "2:  Codeblocks" << endl
        << "3:  Firefox" << endl
        << "4:  Malwarebytes" << endl
        << "5:  OpenOffice" << endl
        << "6:  Spotify" << endl
        << "7:  TrueCrypt" << endl
        << "8:  VLC Player" << endl
        << "9:  7Zip" << endl
        << "10: Minecraft" << endl
        << "11: Dev C++" << endl
        << "12: Sync\'n\'Go";

        int looper = 0;
        do
        {

            if (looper < 5000)
            {
                cout << endl << endl;
                cin >> choice;
            }
            cout << endl;

            if (choice == 0)
            {
                bigLoop = 0;
                looper = 10000;
            }
            if (choice == 1)
            {
                cout << "Opening Arduino";
                runProgram ("A:\\Programs\\Arduino\\arduino.exe");
            }
            else if (choice == 2)
            {
                cout << "Opening Codeblocks";
                runProgram ("A:\\Programs\\Codeblocks\\codeblocks.exe");
            }
            else if (choice == 3)
            {
                cout << "Opening Firefox";
                runProgram ("A:\\Programs\\Firefox\\firefox.exe");
            }
            else if (choice == 4)
            {
                cout << "Opening Malwarebrytes";
                runProgram ("A:\\Programs\\Malwarebytes\\mbam.exe");
            }
            else if (choice == 5)
            {
                cout << "Opening OpenOffice";
                runProgram ("A:\\Programs\\OpenOffice\\program\\soffice.exe");
            }
            else if (choice == 6)
            {
                cout << "Opening Spotify";
                runProgram ("A:\\Programs\\Spotify\\spotify.exe");
            }
            else if (choice == 7)
            {
                cout << "Opening TrueCrypt";
                runProgram("A:\\Programs\\TrueCrypt\\TrueCrypt.exe");
            }
            else if (choice == 8)
            {
                cout << "Opening VLC Player";
                runProgram("A:\\Programs\\VLC\\vlc.exe");
            }
            else if (choice == 9)
            {
                cout << "Opening 7Zip";
                runProgram("D:\\Programs\\7Zip\\7-Zip\\7zFM.exe");
            }
            else if (choice == 10)
            {
                cout << "Opening Minecraft";
                runProgram("A:\\Minecraft.exe");
            }
            else if (choice == 11)
            {
                cout << "Opening Dev C++";
                runProgram("A:\\Programs\\Dev C++\\Dev-Cpp\\devcpp.exe");
            }
            else if (choice == 12)
            {
                cout << "Opening Sync\'n\'Go";
                runProgram("A:\\AllwaySync n Go");
            }
            else
            {
                cout << endl << choice << " is not an option.";
            }


            looper++;

        }while(looper < 6);
        cout << endl << endl << endl;
    } // Big Looper
}//Main function
