#include "Contact.hpp"

Contact::Contact() {}
Contact::~Contact() {};

std::string Contact::getFn(void) const {
	return (this->fn);}
std::string Contact::getLn(void) const {
	return (this->ln);}
std::string Contact::getNn(void) const {
	return (this->nn);}
std::string Contact::getLogin(void) const {
	return (this->login);}
std::string Contact::getPa(void) const {
	return (this->pa);}
std::string Contact::getEmail(void) const {
	return (this->email);}
std::string Contact::getNum(void) const {
	return (this->num);}
std::string Contact::getBd(void) const {
	return (this->bd);}
std::string Contact::getMeal(void) const {
	return (this->meal);}
std::string Contact::getUw(void) const {
	return (this->uw);}
std::string Contact::getSec(void) const {
	return (this->sec);}

void Contact::setFn(std::string str) {
	this->fn = str;}
void Contact::setLn(std::string str) {
	this->ln = str;}
void Contact::setNn(std::string str) {
	this->nn = str;}
void Contact::setLogin(std::string str) {
	this->login = str;}
void Contact::setPa(std::string str) {
	this->pa = str;}
void Contact::setEmail(std::string str) {
	this->email = str;}
void Contact::setNum(std::string str) {
	this->num = str;}
void Contact::setBd(std::string str) {
	this->bd = str;}
void Contact::setMeal(std::string str) {
	this->meal = str;}
void Contact::setUw(std::string str) {
	this->uw = str;}
void Contact::setSec(std::string str) {
	this->sec = str;}