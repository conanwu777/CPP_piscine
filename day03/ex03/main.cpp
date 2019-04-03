#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"
#include "ClapTrap.hpp"

int main(){
	ClapTrap c("DanTrap");
	ScavTrap g("GaetanTrap");
	FragTrap f("ZazTrap");
	NinjaTrap n;

	n.ninjaShoebox(c);
	n.ninjaShoebox(g);
	n.ninjaShoebox(f);
	n.ninjaShoebox(f);
	n.ninjaShoebox(n);
	return 0;
}
