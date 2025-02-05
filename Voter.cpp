#include "Voter.h"

// constructor with parameters
Voter::Voter(string firstname, string lastname, int voter_age, bool has_voted, unsigned int support_strength, double vote_likelihood) {
    first = firstname;
    last = lastname;
    voted = has_voted;
    strength = support_strength;
    likelihood = vote_likelihood;
    impact = 0.0;

    if (voter_age < 18 || voter_age > 118) {
        throw invalid_argument("Age must be between 18 and 118");
    }
    age = voter_age;
    calculateImpact();
}

// constructor
Voter::Voter() {
    first = "";
    last = "";
    age = 18;
    voted = false;
    strength = 0;
    likelihood= 0.0;
    impact = 0.0;
}

// Getters
string Voter::getFirstName() const { 
	return first; 
}
string Voter::getLastName() const { 
	return last; 
}
int Voter::getAge() const { 
	return age; 
}
bool Voter::hasVoted() const { 
	return voted; 
}
unsigned int Voter::getStrength() const { 
	return strength;
}
double Voter::getLikelihood() const { 
	return likelihood; 
}
double Voter::getImpact() const { 
	return impact; 
}

void Voter::calculateImpact() {
    impact = strength/likelihood;
}

void Voter::vote(){
    voted=true;
}

void Voter::addStrength(int addedStrength){
    strength+=addedStrength;
}

void Voter::decLikelihood(double likelihoodDec){
    likelihood=likelihood*((100-likelihoodDec)/100);
}
// Overload << for displaying Voter
ostream& operator<<(ostream& os, const Voter& voter) {
    os << voter.first << " " << voter.last << ", Age: " << voter.age 
       << ", Voted: " << (voter.voted ? "Yes" : "No") 
       << ", Strength: " << voter.strength 
       << ", Likelihood: " << voter.likelihood 
       << ", Impact: " << voter.impact;
    return os;
}
