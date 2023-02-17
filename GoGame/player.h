#ifndef PLAYER

#define PLAYER

#include "stdafx.h"
#include "board.h"

using namespace System;

// Уровни сложности
public enum PlayerLevel {plDummy, plEasy, plMedium, plHard } ;

// Класс игрока компьютерного
public value class Player {
private:
	// Уровень
	PlayerLevel level ;
	// Цвет
	PlaceState color ;
	// Глубина перебора
	int PlayerDepth() ;
	// Банальный ход (случайный)
	bool doDummyStep(Board^ board) ;
	// Аналитический ход
	bool doMainStep(Board^ board) ;
	// Вычисление веса хода
	int calcStepWeight(Board^ board, int i, int j) ;
public:
	// Игрок конструктор
	Player(PlayerLevel Alevel, PlaceState Acolor) ;
	// Делать шаг
	bool makeStep(Board^ board) ;
	// Цвет игрока
	PlaceState getPlayerColor() ;
	// Установить уровень
	void setLevel(PlayerLevel Alevel) ;
} ;

#endif