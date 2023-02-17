#ifndef BOARD

#define BOARD 

#include "stdafx.h"

using namespace System;
using namespace System::Collections::Generic ;

// Состояние клетки доски
public enum PlaceState { psEmpty, psBlack, psWhite } ;

// Структура сдвиг
public value struct DeltaPos {
	int dx;
	int dy;
} ;

// Структура позиция
public value struct Position {
	int i;
	int j;
};

// Типы массив мест и список позиций
typedef array<PlaceState>^ ArrayPlaces ;
typedef List<Position>^ ListPosition ;

// Класс доски
public value class Board {
  private:
	  // Набор мест
    array<PlaceState>^ places ;
	// Внутренняя память-метки
	array<bool>^ mem ;
	// Массив сдвигов для вычисления свободных ячеек
	array<DeltaPos>^ dps ;
	// Память ходов
	Stack<ArrayPlaces>^ memstep ;
	// Размер доски
    int FSize ;
	// Сообщение для игрока
	String^ Fmsg ;
	// Обновить доску после хода
	void updateAfterStep(PlaceState stepcolor) ;
	// Существует ли позиция от точки на сдвиг?
	bool existSidePos(int i, int j, DeltaPos dp, Position * sp) ;
	// Имеет ли свободные стороны позиция и связанные с ней
	bool haveFreeSide(int i, int j, PlaceState ps) ;
	// Очистка меток
	void clearMem() ;
	// Установить метку
	void setMem(int i,int j) ;
	// ПРоверить метку
	bool isMem(int i,int j) ;
	// Пометить группу камней
	void markGroup(int i,int j) ;
	// Очистить помеченную группу
	void clearMarkedGroup() ;
	// Записать ход
	void saveStep() ;
	// Есть ли состояние в любой стороне от точки
	bool isStateAtAnySide(int i,int j,PlaceState ps) ;
	// Установить состояние
	void setState(int i,int j, PlaceState ps) ;
	
	bool isSurroundByColor(int i, int j, array<bool> ^ localmem,PlaceState color) ;
  public:
	  // Конструктор
    Board(int ASize) ;
	// Клонирование
	Board^ createClone() ;
	// Размер
    int Size() ;
	// получить состояние
    PlaceState getState(int i,int j) ;
	// Инверсия цвета
    PlaceState reverseColor(PlaceState ps) ;

	// Пустая ли ячейка
	bool isEmpty(int i,int j) ;
	// Существует ли следующий ход для цвета
	bool existNextStepForColor(PlaceState color) ;
	// Можно ли выполнить ход в ячейку
    bool canMakeStep(int i, int j, PlaceState ps) ;
	// Выполнить ход
	void makeStep(int i,int j, PlaceState ps, bool NoHist) ;
	// Получить число ячеек в состонии
	int getStateCount(PlaceState ps) ;
	String^ getMsg() ;

	// Откат хода
	void backStep() ;
	// Создать список допустимых ячеек для хода
	ListPosition createListAvaliableForStep(PlaceState color) ;
	// Получить число свободных ячеек по сторонам
	int getFreeSideCount(PlaceState color) ;
	
	// Получить очки по цвету
	int getScore(PlaceState color) ;

	// Внутренние тесты
	int testCount() ;
	void prepareForTest(int testn) ;
};

#endif