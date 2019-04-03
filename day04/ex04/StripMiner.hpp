#ifndef STRIPMINER_HPP
# define STRIPMINER_HPP
# include "IMiningLaser.hpp"
# include "IAsteroid.hpp"
# include <iostream>

class StripMiner : public IMiningLaser
{
	public:
		StripMiner();
		StripMiner(StripMiner & src);
		~StripMiner();
		StripMiner & operator=(StripMiner const & rhs);
		void mine(IAsteroid*);;
};

#endif
