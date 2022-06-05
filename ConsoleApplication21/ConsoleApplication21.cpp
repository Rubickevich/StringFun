#include <iostream>
class Continent
{
	std::string countries[10];
public:
	bool AddCountry(std::string country)
	{
		for (int i = 0; i < 10; i++)
		{
			if(countries[i].empty())
			{
				countries[i] = country;
				return true;
			}
		}
		return false; //returns false if there is no more space for countries
	}
	void FindCountry(std::string country)
	{
		for (int i = 0; i < 10; i++)
		{
			if (countries[i] == country)
			{
				std::cout << "Element " << i + 1 << " of array is: " << countries[i] << std::endl;
				return;
			}
		}
		std::cout << "Couldn't find element with this value" << std::endl;
	}
	bool FindSubCountry(std::string subCountry, int country)
	{
		if (countries[country].find(subCountry) != std::string::npos)
		{
			return true;
		}
		return false;
	}
	void ReplaceCountry(int country, int position, int amount)
	{
		countries[country].replace(position, amount, "qwerty");
	}
	std::string GetSubCountry(int country, int position, int amount)
	{
		if(countries[country].empty())
		{
			std::cout << "Country is empty!" << std::endl;
			return std::string(); //return empty string if country is empty
		}
		return countries[country].substr(position, amount);
	}
	void PrintAll()
	{
		for(int i = 0; i < 10; i++)
		{
			if(!countries[i].empty())
			{
				printf(countries[i].c_str());
				printf("\n");
			}
		}
			
	}
};
int main()
{
	std::cout << "Give country names: " << std::endl;
	Continent continent;
	std::string temp;
	int country, position, amount;
	for(int i=0; i<7; i++)
	{
		std::cout << "Country #" << i + 1 << ": ";
		std::cin >> temp;
		continent.AddCountry(temp);
	}
	std::cout << "Write country to look for: ";
	std::cin >> temp;
	continent.FindCountry(temp);
	std::cout << "Write sub country to look for: ";
	std::cin >> temp;
	std::cout << "Write index of country to check: ";
	std::cin >> position;
	std::cout << (continent.FindSubCountry(temp, position-1)?"Found sub country!" : "Can't find sub country!") << std::endl;
	std::cout << "Write country index to partly replace with qwerty: ";
	std::cin >> country;
	std::cout << "Write from what position to start: ";
	std::cin >> position;
	std::cout << "Write how many to replace: ";
	std::cin >> amount;
	continent.ReplaceCountry(country-1, position-1, amount);
	std::cout << "Write country index to check: ";
	std::cin >> country;
	std::cout << "Write from what position to start: ";
	std::cin >> position;
	std::cout << "Write how many to read: ";
	std::cin >> amount;
	std::cout << continent.GetSubCountry(country-1, position-1, amount) <<std::endl;
	continent.PrintAll();
}
