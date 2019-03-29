
#include <iostream>
#include <fstream>
#include <string>


void writeStrToFile(const std::string &fileName, const std::string &strToWrite)
{
	std::ofstream fofs(fileName, std::ofstream::app);
	fofs << strToWrite << std::endl;
	fofs.close();
}

int main()
{
	writeStrToFile(std::string("out.txt"), std::string("XXX"));

	return 0;
}
