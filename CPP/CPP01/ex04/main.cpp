#include "NameData.hpp"
#include "InputFile.hpp"
#include "TranStr.hpp"
#include "SendStr.hpp"
#include "OutputFile.hpp"

int main(int argc, char **argv)
{
	if (argc != 5)
	{
		std::cout << "is not correct argument." << std::endl;
		return (1);
	}
	t_NameData ND = {argv[1], argv[2], argv[3], argv[4]};
	TranStr tran(ND.tran_str);
	InputFile infile(ND.infile_name, ND.check_str);
	if (infile.check_file())
		return (1);
	infile.set_contents();
	OutputFile outfile(ND.outfile_name);
	if (outfile.check_file())
		return (1);
	while (infile.check_end())
	{
	}

	return (0);
}
