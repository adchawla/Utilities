#include <iostream.h>
#include <fstream>
#include <string>
#include <conio.h>
#include "CommandLineParameters.hpp"

using namespace std;

void DisplayUsage();
bool SetCommandLineParameters(int& argc, char* argv[], commandLineParameters& cmdLineParams);

int main( int argc, char *argv[ ], char *envp[ ] )
{
	if (argc < 5)
	{
		DisplayUsage();
		return 0;
	}
	commandLineParameters cmdLineParams;
	bool success = false;
	success = SetCommandLineParameters(argc, argv, cmdLineParams);

	if (success)
	{
		fstream fin, fout;
		fin.open(cmdLineParams.GetSourceFileName().c_str(), ios::in);
		fout.open(cmdLineParams.GetDestinationFileName().c_str(), ios::out);

		if(fin.is_open() == false)
		{
			cout<<"Unable to open input file"<<cmdLineParams.GetSourceFileName().c_str()<<endl;
			getch();
			return 0;
		}
		if (fout.is_open() == false)
		{
			cout<<"Unalbe to open output file"<<cmdLineParams.GetDestinationFileName().c_str()<<endl;
			getch();
			return 0;
		}

		char line_buffer[500];
		string buffer;
		while (fin.eof() == false)
		{
			fin.getline(line_buffer, 499);
			buffer = line_buffer;
			bool lines_to_be_added = true;
			int i = 0;
			for(i = 0; i < cmdLineParams.GetNumOfStringsToBeChecked(); i++)
			{
				lines_to_be_added = false;
				if (buffer.find(cmdLineParams.GetStringToBeChecked(i)) != string::npos)
				{
					lines_to_be_added = true;
					break;
				}
			}

			//if (cmdLineParams.GetInsertOption() == after_line)
				fout<<"mkdir -p re"<<buffer<<"\nrm -rf re"<<buffer<<endl;
			
			if (lines_to_be_added == true)
			{
				for (i = 0; i < cmdLineParams.GetNumOfLinesToBeInserted(); i++)
				{
					fout<<cmdLineParams.GetLineToBeInserted(i)<<" ";
				}
			}
			
			if (cmdLineParams.GetInsertOption() == before_line)
				fout<<buffer<<" ";
			    fout<<"re"<<buffer<<endl;
				fout<<"p4 add re"<<buffer<<endl;
		}
		fout.close();
		fin.close();
		cout<<"File Successfully created"<<endl;
		getch();
		return 0;
	}
	else
	{
		DisplayUsage();
		return 0;
	}
}

void DisplayUsage()
{
   cout<<"Command Line Options:"<<endl;
   cout<<"-i/I \t InputFileName         \t (required)"<<endl;
   cout<<"-o/O \t OutputFileName        \t (required)"<<endl;
   cout<<"-m/M \t Insert Mode           \t (default = 1)"<<endl;
   cout<<"     \t                       \t 0 = insert before line "<<endl;
   cout<<"     \t                       \t 1 = insert after line "<<endl;
   cout<<"-a/A \t Line to be Added      \t (optional: default empty)"<<endl;
   cout<<"-s/S \t String to be searched \t (optional: default empty)"<<endl;
   getch();
}

bool SetCommandLineParameters(int& argc, char* argv[], commandLineParameters& cmdLineParams)
{
	bool inputfileset = false, outputfileset = false;

	for (int i = 1; i < argc; i++)
	{
		char temp = argv[i][0];
		char option = argv[i][1];

		if (temp == '-')
		{
			string str;
			int mode;

			switch (option)
			{
			case 'i':
			case 'I':
				str = argv[++i];
				cmdLineParams.SetSourceFileName(str);
				inputfileset = true;
				break;

			case 'o':
			case 'O':
				str = argv[++i];
				cmdLineParams.SetDestinationFileName(str);
				outputfileset = true;
				break;

			case 'm':
			case'M':
				mode = atoi(argv[++i]);
				if ( (mode == 0) || (mode == 1) )
					cmdLineParams.SetInsertOption((insertOptions)mode);
				else
					return 0;
				break;

			case 'a':
			case 'A':
				str = argv[++i];
				cmdLineParams.AddLinesToBeInserted(str);
				break;

			case 's':
			case 'S':
				str = argv[++i];
				cmdLineParams.AddStringsToBeChecked(str);
				break;

			default:
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	if( (inputfileset == true) && (outputfileset == true) )
		return true;
	else
		return false;
}