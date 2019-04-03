#include "AsteroKreog.hpp"
#include "KoalaSteroid.hpp"
#include "IAsteroid.hpp"
#include "StripMiner.hpp"
#include "DeepCoreMiner.hpp"
#include "IMiningLaser.hpp"
#include "MiningBarge.hpp"
#include <iostream>

int main() {
	DeepCoreMiner d;
	StripMiner s;
	MiningBarge b;
	KoalaSteroid k;
	AsteroKreog a;

	d.mine(&a);
	d.mine(&k);
	s.mine(&a);
	s.mine(&k);

	std::cout << "MiningBarge equiped with D,S,D,S\n";
	b.equip(&d);
	b.equip(&s);
	b.equip(&d);
	b.equip(&s);
	b.equip(&d);

	std::cout << "MiningBarge mines AsteroKreog\n";
	b.mine(&a);
	std::cout << "MiningBarge mines KoalaSteroid\n";
	b.mine(&k);

	return 0;
}