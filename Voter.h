#ifndef _H_VOTER_
#define _H_VOTER_

#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;

class Voter {
private:
    string first;
    string last;
    int age;
    bool voted;
    unsigned int strength;
    double likelihood;
    double impact;

public:
    // Constructors
    Voter(string firstname, string lastname, int voter_age, bool has_voted, unsigned int support_strength, double vote_likelihood);
    Voter();

    // Getters
    string getFirstName() const;
    string getLastName() const;
    int getAge() const;
    bool hasVoted() const;
    unsigned int getStrength() const;
    double getLikelihood() const;
    double getImpact() const;

    void calculateImpact();
    void vote();
    void addStrength(int n);
    void decLikelihood(double n);

    auto operator<=>(const Voter& other) const = default;
    friend ostream& operator<<(ostream& os, const Voter& voter);
};

#endif
