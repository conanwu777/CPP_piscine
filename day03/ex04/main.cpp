#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"
#include "ClapTrap.hpp"
#include "SuperTrap.hpp"

int main(){
	ClapTrap c("DanTrap");
	ScavTrap g("GaetanTrap");
	FragTrap f("ZazTrap");
	NinjaTrap n("LiamTrap");
	SuperTrap s("MarketingLadyTrap");

	s.ninjaShoebox(f);
	s.vaulthunter_dot_exe("DanTrap");
	s.rangedAttack("GartanTrap");
	s.meleeAttack("GartanTrap");
	n.meleeAttack("MarketingLadyTrap");
	return 0;
}
