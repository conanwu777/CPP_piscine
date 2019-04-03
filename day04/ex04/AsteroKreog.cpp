# include "AsteroKreog.hpp"
# include "IAsteroid.hpp"
# include <iostream>

AsteroKreog::AsteroKreog() {
	this->name = "AsteroKreog";}

AsteroKreog::~AsteroKreog() {}

AsteroKreog::AsteroKreog(AsteroKreog &) {}

std::string AsteroKreog::beMined(DeepCoreMiner *) const {
	return ("Thorite");}

std::string AsteroKreog::beMined(StripMiner *) const {
	return ("Flavium");}

AsteroKreog & AsteroKreog::operator=(AsteroKreog const & src) {
	this->name = src.getName();
	return (*this);}

std::string AsteroKreog::getName() const {
	return (this->name);}
