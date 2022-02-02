#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void splitStringComma(std::string str, std::vector<long long int>& fish_cycle) {
	int iter = 0;
	while (iter < str.length()) {
		char fish = str[iter];
		if (fish != ',') {

			fish_cycle[fish - '0']++;
		}
		iter++;
	}
}

std::vector<long long int> cycleLive(std::vector<long long int> fish_cycle) {
	std::vector<long long int> fish_buffer(9, 0);
	for (int i = 1; i < fish_cycle.size(); i++) {
		fish_buffer[i - 1] = fish_cycle[i];
	}
	fish_buffer[6] += fish_cycle[0];
	fish_buffer[8] = fish_cycle[0];
	return fish_buffer;
}

std::string numberOfFish(std::vector<long long int> fish_cycle) {
	long long int sum = 0;
	for (auto value : fish_cycle)
	{
		sum += value;
	}
	return std::to_string(sum);
}

int main()
{
	std::string path("inputSix.txt");
	std::ifstream in(path); 
	std::string line;
	std::vector<long long int> fish_cycle(9, 0);

	if (in.is_open())
	{
		while (getline(in, line))
		{
			splitStringComma(line, fish_cycle);
		}
	}
	else std::cout << "File not found";
	in.close();    
	int i = 0;
	while (i < 256) {
		fish_cycle = cycleLive(fish_cycle);
		i++;
	}

	std::cout << numberOfFish(fish_cycle)<<'\n';

	system("pause");
	return 0;
}