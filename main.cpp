#include "FrequencyCounter.h"
#include "Huffman.h"
#include<bits/stdc++.h>
#include<unistd.h>
#include<windows.h>


using namespace std;

#define RESET   "\033[0m"
#define PURPLE  "\033[35m"
#define GREEN   "\033[32m"


std::ifstream::pos_type filesize(const char* filename);

void loadingBar()
{

   

    char a = 177, b = 219;

    cout << "\n\t\t\t\t\t"
         << "Loading...\n\n";
    cout << "\t\t\t\t\t";

    for (int i = 0; i < 26; i++)
        cout << a;

    cout << "\r";
    cout << "\t\t\t\t\t";

    for (int i = 0; i < 26; i++)
    {
        cout << b;
    
        Sleep(300);
    }
}


int main()
{
    system("color 9");
    printf("\n\n\n\n\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                                           =");
    printf("\n\t\t\t        =                                           =");
    printf("\n\t\t\t        =               FILE ZIPPER                 =");
    printf("\n\t\t\t        =                                           =");
    printf("\n\t\t\t        =                                           =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");

    loadingBar();
    cout<<endl<<endl;


    
    cout<<"\t\t\t"<<GREEN<<"Enter your Choice :"<<endl;
    cout<<"\t\t\t"<<"1. Compress"<<endl;
    cout<<"\t\t\t"<<"2. Decompress"<<endl<<endl;

    FrequencyCounter frequencyCounter ;
    Huffman huffman;
    int workingMode;
    cout<<"\t\t\t"<<"Your Choice : ";
    cin >> workingMode;
    if(workingMode == 1)
    {
        string s;
        cout<<"\t\t\tEnter the name of File to be Compressed :";
        cin>>s;
        clock_t tStart = clock();
        frequencyCounter.readFile("input.txt");
        cout<<endl;
        huffman.huffer(frequencyCounter.getFrequencyMap());
        huffman.compressTofile("input.txt","output.txt");
        cout <<"Time taken: "<<(1.0*(clock() - tStart)/CLOCKS_PER_SEC)<<"sec"<<endl;
        cout << "Input File Size : "<<filesize("input.txt")<<" bytes."<<endl;
        cout<< "Compressed File Size : "<<filesize("output.txt")<<" bytes."<<endl;
        cout<< "Compression Ratio : "<<(1.0*filesize("output.txt")/filesize("input.txt"))<<endl;
    }
    else if(workingMode == 2)
    {
        clock_t tStart = clock();
        string s1;
         cout<<"Enter the File to be Extracted: ";
        cin>>s1;
       
        huffman.deHuffer("output.txt","output2.txt");
        cout<<endl;
        cout <<"Time taken: "<<(1.0*(clock() - tStart)/CLOCKS_PER_SEC)<<"sec"<<endl;
        cout << "Input File (Compressed) Size : "<<filesize("output.txt")<<" bytes."<<endl;
        cout<< "DeCompressed File Size : "<<filesize("output2.txt")<<" bytes."<<endl;
    }


    return 0;
}

std::ifstream::pos_type filesize(const char* filename)
{
    std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
    return in.tellg();
}