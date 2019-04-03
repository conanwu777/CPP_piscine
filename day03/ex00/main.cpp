#include "FragTrap.hpp"

int main(){
	FragTrap a;
	FragTrap l("LiamTrap");
	FragTrap g("GaetanTrap");
	FragTrap d("DanTrap");
	a = g;
	a.meleeAttack("DanTrap");
	d.takeDamage(30);
	l.rangedAttack("DanTrap");
	d.takeDamage(20);
	d.beRepaired(50);
	l.vaulthunter_dot_exe("DanTrap");
	l.vaulthunter_dot_exe("DanTrap");
	l.vaulthunter_dot_exe("DanTrap");
	l.vaulthunter_dot_exe("DanTrap");
	l.vaulthunter_dot_exe("DanTrap");
	return 0;
}
