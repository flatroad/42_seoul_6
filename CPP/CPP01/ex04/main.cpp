#include "NameData.hpp"
#include "InputFile.hpp"
// #include "OutputFile.hpp"

int main(int argc, char **argv)
{
	if (argc != 5)
	{
		std::cout << "is not correct argument." << std::endl;
		return (1);
	}
	t_NameData ND = {argv[1], argv[2], argv[3], argv[4]};
	InputFile infile(ND.infile_name, ND.check_str, ND.outfile_name);
	if (infile.check_file())
		return (1);
	infile.set_contents();

	return (0);
}
