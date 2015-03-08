#include <string.h>
#include <vector>

using namespace std;

enum insertOptions
{
	before_line,
	after_line
};

class commandLineParameters
{
private:
	string sourceFile;
	string destinationFile;
	vector<string> linesToBeInserted;
	vector<string> stringsToBeChecked;
	insertOptions insertOption;
public:
	commandLineParameters();

	void SetSourceFileName(const string& str);
	void SetDestinationFileName(const string& str);
	void AddLinesToBeInserted(const string& str);
	void AddStringsToBeChecked(const string& str);
	void SetInsertOption(const insertOptions opt);

	string GetSourceFileName( ) const;
	string GetDestinationFileName( ) const;
	int GetNumOfLinesToBeInserted( ) const;
	int GetNumOfStringsToBeChecked( ) const;
	string GetLineToBeInserted(int index) const;
	string GetStringToBeChecked(int index) const;
	insertOptions GetInsertOption( ) const;
};