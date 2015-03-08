#include "CommandLineParameters.hpp"


commandLineParameters::commandLineParameters() :
	insertOption(after_line)
{}

void commandLineParameters::AddLinesToBeInserted(const string& str)
{
	linesToBeInserted.push_back(str);
}

void commandLineParameters::AddStringsToBeChecked(const string& str)
{
	stringsToBeChecked.push_back(str);
}

string commandLineParameters::GetDestinationFileName( ) const
{
	return destinationFile;
}

insertOptions commandLineParameters::GetInsertOption( ) const
{
	return insertOption;
}

string commandLineParameters::GetLineToBeInserted(const int index) const
{
	return linesToBeInserted[index];
}

int commandLineParameters::GetNumOfLinesToBeInserted( ) const
{
	return linesToBeInserted.size();
}

int commandLineParameters::GetNumOfStringsToBeChecked( ) const
{
	return stringsToBeChecked.size();
}

string commandLineParameters::GetSourceFileName( ) const
{
	return sourceFile;
}

string commandLineParameters::GetStringToBeChecked(const int index) const
{
	return stringsToBeChecked.operator [](index);
}

void commandLineParameters::SetDestinationFileName(const string& str)
{
	destinationFile = str;
}

void commandLineParameters::SetInsertOption(const insertOptions opt)
{
	insertOption = opt;
}

void commandLineParameters::SetSourceFileName(const string& str)
{
	sourceFile = str;
}
