#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string t) :
Form("ShrubberyCreationForm", 145, 137) {
	this->target = t;
}

void ShrubberyCreationForm::action(void) const {
	std::ofstream tree(this->target + "_shrubbery");
	tree << "      .             .             .       \n";
	tree << "   __/ \\__       __/ \\__       __/ \\__    \n";
	tree << "   \\     /       \\     /       \\     /    \n";
	tree << "   /.'o'.\\       /.'o'.\\       /.'o'.\\    \n";
	tree << "    .o.'.         .o.'.         .o.'.     \n";
	tree << "   .'.'o'.       .'.'o'.       .'.'o'.    \n";
	tree << "  o'.o.'.o.     o'.o.'.o.     o'.o.'.o.   \n";
	tree << " .'.o.'.'.o.   .'.o.'.'.o.   .'.o.'.'.o.  \n";
	tree << ".o.'.o.'.o.'. .o.'.o.'.o.'. .o.'.o.'.o.'. \n";
	tree << "   [_____]       [_____]       [_____]    \n";
	tree << "    \\___/         \\___/         \\___/     \n";
	tree.close();
}
