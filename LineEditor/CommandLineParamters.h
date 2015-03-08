#include <string>
#include <vector>

class CommandLineParameters {
private:
	string inputFile;
	string outputFile;
	vector<string> outputFormat;

public:
	void SetInputFile(char* name);
	void SetOutputFile(char* name);
	void SetOutputFormat(
}