#ifndef MININGBARGE_HPP
# define MININGBARGE_HPP
# include "IMiningLaser.hpp"

class MiningBarge
{
		IMiningLaser* lasers[4];
	public:
		MiningBarge();
		MiningBarge(MiningBarge & src);
		~MiningBarge();
		MiningBarge & operator=(MiningBarge const & rhs);

		void equip(IMiningLaser*);
		void mine(IAsteroid*) const;
};

#endif
