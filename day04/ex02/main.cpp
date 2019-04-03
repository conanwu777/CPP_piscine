#include "ISquad.hpp"
#include "Squad.hpp"
#include "ISpaceMarine.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"

int	main(){
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;
	ISpaceMarine* joe = new AssaultTerminator;

	Squad* vlc = new Squad;
	std::cout << "squd created, adding Bob\n";
	vlc->push(bob);
	std::cout << "Adding Bob again, nothing happens\n";
	vlc->push(bob);
	std::cout << "Make copy of squad\n";
	Squad* vlc2 = new Squad(*vlc);
	std::cout << "Adding Jim\n";
	vlc->push(jim);
	std::cout << "Adding Joe\n";
	vlc->push(joe);
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	std::cout << "Copy of squad stay 2 marines\n";
	for (int i = 0; i < vlc2->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc2->getUnit(i);
		cur->battleCry();
	}
	delete vlc2;
	delete vlc;
	return 0;
}