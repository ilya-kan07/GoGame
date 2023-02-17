#include "stdafx.h"
#include "player.h"
#include "string.h"
#include "vector" 
using namespace System::Collections::Generic ;
static FILE * f ;
int Player::PlayerDepth() {
	if (level==plEasy) return 2 ; else
		if (level==plMedium) return 4 ; else
			if (level==plHard) return 6 ; else return 2 ;
}
PlaceState Player::getPlayerColor() {// получение цвета игрока
	return color ;
}
Player::Player(PlayerLevel Alevel, PlaceState Acolor) {// инициализация игрока
	level = Alevel ;
	color = Acolor ;
}
bool Player::doDummyStep(Board^ board) {
	// Ход компьютера на легкой сложности
	List<Position>^ list = board->createListAvaliableForStep(color) ; // компьютер получает возможныее для хода клетки 
	if (list->Count==0) return false ;
	int maxwi = 0 ;
	int maxw = calcStepWeight(board,list[0].i,list[0].j) ; // подсчет веса хода
	for (int i=0; i<list->Count; i++) {
		int w = calcStepWeight(board,list[i].i,list[i].j) ;
		if (w>maxw) {
			maxwi=i ;
			maxw=w ;
		}
	}
	board->makeStep(list[maxwi].i,list[maxwi].j,color,false) ; // компьюбтер делает ход
	return true ;
}
bool Player::doMainStep(Board^ board) {
	// Ход компьютера на обычной и сложной сложности
	List<Position>^ list = board->createListAvaliableForStep(color) ; // компьютер получает возможныее для хода клетки 
	if (list->Count==0) return false ;
	int maxwi = 0 ;
	int maxw = calcStepWeight(board,list[0].i,list[0].j) ;// подсчет веса хода
	for (int i=0; i<list->Count; i++) {
		int w = calcStepWeight(board,list[i].i,list[i].j) ; // компьюбтер делает ход
		if (w>maxw) {
			maxwi=i ;
			maxw=w ;
		}
	}
	board->makeStep(list[maxwi].i,list[maxwi].j,color,false) ;
	return true ;
}
bool Player::makeStep(Board^ board) {
	if (level==plDummy) return doDummyStep(board) ; else
		return doMainStep(board) ;
}
int Player::calcStepWeight(Board^ board, int i, int j) {
	Board^ local = board->createClone() ;
	// Алгоритм Альфа-Бета
	// Вес вычисляется как наименьший положительный при взятии камешков врага
	// или наибольший отрицательный при уменьшии степеней свободы врага
	int enemycount = local->getStateCount(board->reverseColor(color)) ;
	int myfreeside = local->getFreeSideCount(color) ;
	int enemyfreeside = local->getFreeSideCount(board->reverseColor(color)) ;
	local->makeStep(i,j,color,true) ;
	int newenemycount = local->getStateCount(board->reverseColor(color)) ;
	if (newenemycount<enemycount) 
		return enemycount-newenemycount ; // >0
	else
		return - local->getFreeSideCount(board->reverseColor(color)) ;
	 ;
}
void Player::setLevel(PlayerLevel Alevel) {
	level=Alevel ;
}