#ifndef ASTEROKREOG_HPP
# define ASTEROKREOG_HPP
# include "IAsteroid.hpp"
# include <iostream>

class AsteroKreog : public IAsteroid
{
		std::string name;
	public:
		AsteroKreog();
		AsteroKreog(AsteroKreog &);
		AsteroKreog & operator=(AsteroKreog const &);
		~AsteroKreog();		
		std::string beMined(DeepCoreMiner *) const;
		std::string beMined(StripMiner *) const;
		std::string getName() const;
};

#endif
