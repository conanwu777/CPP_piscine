#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(){
	ScavTrap a;
	ScavTrap l("LiamTrap");
	ScavTrap g("GaetanTrap");
	ScavTrap d("DanTrap");
	FragTrap c;

	a = g;
	c.meleeAttack("GatanTrap");
	a.meleeAttack("DanTrap");
	d.takeDamage(30);
	l.rangedAttack("DanTrap");
	d.takeDamage(20);
	d.beRepaired(50);
	l.challengeNewcomer("DanTrap");
	g.challengeNewcomer("DanTrap");
	l.challengeNewcomer("DanTrap");
	a.challengeNewcomer("DanTrap");
	a.challengeNewcomer("DanTrap");
	return 0;
}
