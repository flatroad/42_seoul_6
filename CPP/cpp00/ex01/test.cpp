// #include <iostream>
// #include <string>

// int	main()
// {
// 	std::string str = "12347";

// 	std::cout << str.find_first_not_of("0123456789") << std::endl;
// 	return (0);
// }


// #include <iostream>
// #include <string>
// #include <algorithm>
 
// int main()
// {
//     std::string str;

//     std::cout << "firstName : ";
//     getline(std::cin, str);
//     if (str.empty())
//     {
//         std::cout << "try again!" << std::endl;
//     }
//     for (int i = 0; str[i]; i++)
//     {
//         std::cout << str[i] << std::endl;
        
//         if (!(std::isalpha(str[i])))
//         {
//             std::cout << "is not string.. try again!" << std::endl;
// 			break;
//         }
//     }

//     return 0;
// }