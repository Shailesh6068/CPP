#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

struct Cutoff {
    string category;
    double value;
};

struct Branch {
    string name;
    vector<Cutoff> cutoffs;
};

struct College {
    string name;
    vector<Branch> branches;
};

int main() {
    ifstream file("file.txt");
    if (!file.is_open()) {
        cout << "Failed to open the file!" << endl;
        return 1;
    }

    string line;
    vector<College> colleges;
    College currentCollege;
    Branch currentBranch;

    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        ss >> token;

        if (token == "College:") {
            currentCollege.name = "";
            ss >> currentCollege.name;
            currentCollege.branches.clear();
            colleges.push_back(currentCollege);
        } else if (token == "Branch:") {
            currentBranch.name = "";
            ss >> currentBranch.name;
            currentBranch.cutoffs.clear();
            colleges.back().branches.push_back(currentBranch);
        } else if (token == "Category:") {
            Cutoff cutoff;
            ss >> cutoff.category >> cutoff.value;
            colleges.back().branches.back().cutoffs.push_back(cutoff);
        }
    }

    // Display the table
    cout << "College\tBranch\tCategory\tCutoff" << endl;
    for (const auto& college : colleges) {
        for (const auto& branch : college.branches) {
            for (const auto& cutoff : branch.cutoffs) {
                cout << college.name << "\t" << branch.name << "\t" << cutoff.category << "\t" << cutoff.value << endl;
            }
        }
    }

    return 0;
}
