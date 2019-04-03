#ifndef KOALASTEROID_HPP
# define KOALASTEROID_HPP
# include "IAsteroid.hpp"
# include <iostream>

class KoalaSteroid : public IAsteroid
{
		std::string name;
	public:
		KoalaSteroid();
		KoalaSteroid(KoalaSteroid &);
		~KoalaSteroid();
		KoalaSteroid & operator=(KoalaSteroid const &);
		std::string beMined(DeepCoreMiner *) const;
		std::string beMined(StripMiner *) const;
		std::string getName() const;
};

#endif
