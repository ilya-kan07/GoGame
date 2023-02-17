#ifndef PLAYER

#define PLAYER

#include "stdafx.h"
#include "board.h"

using namespace System;

// ������ ���������
public enum PlayerLevel {plDummy, plEasy, plMedium, plHard } ;

// ����� ������ �������������
public value class Player {
private:
	// �������
	PlayerLevel level ;
	// ����
	PlaceState color ;
	// ������� ��������
	int PlayerDepth() ;
	// ��������� ��� (���������)
	bool doDummyStep(Board^ board) ;
	// ������������� ���
	bool doMainStep(Board^ board) ;
	// ���������� ���� ����
	int calcStepWeight(Board^ board, int i, int j) ;
public:
	// ����� �����������
	Player(PlayerLevel Alevel, PlaceState Acolor) ;
	// ������ ���
	bool makeStep(Board^ board) ;
	// ���� ������
	PlaceState getPlayerColor() ;
	// ���������� �������
	void setLevel(PlayerLevel Alevel) ;
} ;

#endif