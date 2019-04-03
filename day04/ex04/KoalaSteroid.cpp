# include "KoalaSteroid.hpp"
# include "IAsteroid.hpp"
# include <iostream>

KoalaSteroid::KoalaSteroid() {
	this->name = "KoalaSteroid";
}

KoalaSteroid::~KoalaSteroid() {}

KoalaSteroid::KoalaSteroid(KoalaSteroid &) {}

std::string KoalaSteroid::beMined(DeepCoreMiner *) const {
	return ("Krpite");}

std::string KoalaSteroid::beMined(StripMiner *) const {
	return ("Zazium");}

KoalaSteroid & KoalaSteroid::operator=(KoalaSteroid const & src) {
	this->name = src.getName();
	return (*this);
}

std::string KoalaSteroid::getName() const {
	return (this->name);
}
