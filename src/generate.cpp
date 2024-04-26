#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <random>
#include <unordered_set>


using namespace std;


void generate(const string &filename, const int &n, const int count) {

    random_device rd;
    mt19937 eng(rd());
    uniform_int_distribution<> distr(0, n);
    unordered_set<int> uniqueNumbers;
    vector<int> numbers;


    while (numbers.size() < count) {

        int number = distr(eng); // Generate random number

        if (uniqueNumbers.insert(number).second) { // Insert into set and check if it's unique

            numbers.push_back(number); // Add to vector if unique

        }
    }

    ofstream file(filename);
    
    if (file.is_open()) {
    
        for (auto num : numbers) {
    
            file << num << "\n";
    
        }
    
        file.close();
        std::cout << "Data written to file: " << filename << endl;
    
    } else {
    
        cerr << "Unable to open file: " << filename << endl;
    
    }

}