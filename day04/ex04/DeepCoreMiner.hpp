#ifndef DEEPCOREMINER_HPP
# define DEEPCOREMINER_HPP
# include "IMiningLaser.hpp"
# include "IAsteroid.hpp"
# include <iostream>

class DeepCoreMiner : public IMiningLaser
{
	public:
		DeepCoreMiner();
		DeepCoreMiner(DeepCoreMiner & src);
		~DeepCoreMiner();
		DeepCoreMiner & operator=(DeepCoreMiner const & rhs);
		void mine(IAsteroid*);
};

#endif
