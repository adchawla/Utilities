// LineEditor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct wordFormat {
	std::string prefix;
	int index;
	std::string postfix;
};
void SetWordFormat(std::vector<wordFormat>&, std::string&);
int main(int argc, char* argv[])
{
	if (argc < 4) {
		std::cerr<<"Check the arguements\n";
		return 0;
	}
	std::fstream fin, fout;
	fin.open(argv[1], std::ios::in);
	fout.open(argv[2], std::ios::out);
	std::string format(argv[3]);
	std::vector <wordFormat> outputFormat;
	SetWordFormat(outputFormat, format);
	std::vector<std::string>inputWords;
	char temp[500];
	
	
	/* Read line by line from input file and write in the output file */
	while (fin.eof() == false)
	{
		fin.getline(temp, 499);
		std::string inputLine(temp);
		/* break into words */
		std::string::size_type start = 0, end = 0;
		while ( (end = inputLine.find_first_of(' ', start)) != std::string::npos) {
			inputWords.push_back(inputLine.substr(start, end - start));
			start = end + 1;
		}
		inputWords.push_back(inputLine.substr(start));

		/* Write into the file */
		for (int i= 0; i < outputFormat.size(); i++) {
			fout<<outputFormat[i].prefix<<inputWords[outputFormat[i].index-1]<<outputFormat[i].postfix;
		}
		fout<<"\n";
		inputWords.clear();
	}
	fin.close();
	fout.close();
	return 0;
}

void SetWordFormat(std::vector<wordFormat>& wf, std::string& format)
{
	std::string::size_type prefix_start = 0, postfix_end = 0;
	while( (postfix_end = format.find_first_of('$', prefix_start)) != std::string::npos) {
		std::string prefix = format.substr(prefix_start, postfix_end-prefix_start);
		int index = atoi(format.substr(postfix_end+1).c_str());
		prefix_start = postfix_end+2;
		postfix_end = format.find_first_of(' ', prefix_start);
		std::string postfix;
		if (postfix_end != std::string::npos) {
			postfix = format.substr(prefix_start, postfix_end-prefix_start);
			prefix_start = postfix_end + 1;
		} else {
			postfix = format.substr(prefix_start);
			prefix_start = postfix_end;
		}
		
		wordFormat temp; temp.prefix = prefix; temp.index = index; temp.postfix = postfix;
		wf.push_back(temp);
	}

}
