#include "stdafx.h"
#include "board.h"
#include "stdio.h"
Board::Board(int ASize) {
	// ����������� �����
	FSize=ASize ;
	places = gcnew array<PlaceState>(FSize*FSize) ;	// ����������� ���� �� �����
	mem = gcnew array<bool>(FSize*FSize) ; // ��������� ������ ��� �����
	for (int i=0; i<FSize*FSize; i++)
		places[i]=psEmpty ; //������� ����
	dps = gcnew array<DeltaPos>(4) ;
	dps[0].dx=-1 ; dps[0].dy=0 ;
	dps[1].dx=1  ; dps[1].dy=0 ;
	dps[2].dx=0  ; dps[2].dy=-1 ;
	dps[3].dx=0  ; dps[3].dy=1 ;
	memstep = gcnew Stack<ArrayPlaces>() ;
}
Board^ Board::createClone() {
	Board^ board = gcnew Board(Size()) ; // ������� ������������ ����� ��� ��
	board->places = (array<PlaceState>^)places->Clone() ;
	return board ;
}
int Board::Size() {
	// ���������� ������ �����
	return FSize ;
}
PlaceState Board::reverseColor(PlaceState ps) {
	if (ps==psWhite) return psBlack ; else // ����������� ���������������� ����� �����
		if (ps==psBlack) return psWhite ; else
			return psEmpty ;
}
PlaceState Board::getState(int i, int j) {
	return places[i*FSize+j] ;
}
void Board::setState(int i,int j, PlaceState ps) {
	places[i*FSize+j]=ps ;
} 
bool Board::isStateAtAnySide(int i,int j,PlaceState ps) {
	for (int dx=-1; dx<=1; dx++)
		for (int dy=-1; dy<=1; dy++)
			if (!((dx==0)&&(dy==0))) { 
				DeltaPos dp ;
				dp.dx=dx ;
				dp.dy=dy ;
				Position sp ;
				if (existSidePos(i,j,dp,&sp))
					if (getState(sp.i,sp.j)==ps) return true ;
			}
	return false ;
}
bool Board::isEmpty(int i,int j) {
	return (getState(i,j)==psEmpty) ; 	// �������� �� ������ ������ 
}
bool Board::existSidePos(int i, int j, DeltaPos dp, Position * sp) {
	int newi = i+dp.dx ;
	int newj = j+dp.dy ;
	bool r = (newi>=0)&&(newj>=0)&&(newi<FSize)&&(newj<FSize) ;
	if (r) { 
		sp->i=newi ;
		sp->j=newj ;
		return true ;
	}
	else
		return false ;
}
void Board::clearMem() {
	for (int i=0; i<FSize*FSize; i++)
		mem[i]=false ; // ������� ����
}
void Board::setMem(int i,int j) {
	mem[i*FSize+j]=true ;
}
bool Board::isMem(int i,int j) {
	return mem[i*FSize+j] ;
}
bool Board::haveFreeSide(int i, int j, PlaceState ps) {
	setMem(i,j) ;
	Position sidepos ;
	for (int k=0; k<4; k++) // �������� ���������� ���� �� �� ���������
		if (existSidePos(i,j,dps[k],&sidepos)) 
			if (isEmpty(sidepos.i,sidepos.j)) return true ;
			else
				if ((getState(sidepos.i,sidepos.j)==ps)&&
				   (!isMem(sidepos.i,sidepos.j))) 
				     if (haveFreeSide(sidepos.i,sidepos.j,ps)) return true ;
	return false ;
}
bool Board::canMakeStep(int i, int j, PlaceState ps) { // �������� ����� �� ������ � ������ ������
	setState(i,j,ps) ;
	clearMem() ;
	array<ArrayPlaces>^ arr = memstep->ToArray() ;
	for (int k=0; k<arr->Length ; k++) {
		array<PlaceState>^ old = (array<PlaceState>^)arr[k]->Clone() ;
		int cnt=0 ; //  ��������� ������ ����� ���� ������ ��� ���� ������
		for (int q=0; q<FSize*FSize; q++) {
			if (places[q]==old[q]) cnt++ ; 
		}
		if (cnt==FSize*FSize) {   //
			setState(i,j,psEmpty) ;
			Fmsg = gcnew String("������ �������� �� ����� ��������!") ;
			return false ;
		}
	}
	bool nofree = !haveFreeSide(i,j,ps) ; // ���������� ������� ���������� ������ �� ��������� ���
	setState(i,j,psEmpty) ;				
	if (nofree) {
		Fmsg = gcnew String("���������������� ��� ��������!") ;
		return false ;
	}
	return true ;
}
bool Board::existNextStepForColor(PlaceState color) {
	for (int i=0; i<FSize;i++) // ��������� ���� 
		for (int j=0; j<FSize;j++)
			if (isEmpty(i,j))  //�������� ���������� �� ��������� ��� ��� ���������� �����
				if (canMakeStep(i,j,color)) {
					return true ;
				}
	return false ;
}
ListPosition Board::createListAvaliableForStep(PlaceState color) 
{
	ListPosition list = gcnew List<Position>();// �������� ������ ��������� ����� 
	for (int i=0; i<Size();i++) // ��������� ����� ���� 
		for (int j=0; j<Size();j++)
			if (isEmpty(i,j))
				if (isStateAtAnySide(i,j,reverseColor(color)))
				// ������� ����� � ������
					if (canMakeStep(i,j,color)) {
						Position pf  ;
						pf.i=i ; pf.j=j ;
						list->Add(pf) ;
					}
	return list ;
}
int Board::getFreeSideCount(PlaceState color) {
	clearMem() ;
	Position sidepos ;
	for (int i=0; i<Size();i++) // ��������� ����, ��������� ��������� ������
		for (int j=0; j<Size();j++)
			if (isEmpty(i,j))
				for (int k=0; k<4; k++) 
					if (existSidePos(i,j,dps[k],&sidepos)) 
						if (getState(sidepos.i,sidepos.j)==color) setMem(i,j) ;

	int cnt = 0; 
	for (int i=0; i<Size();i++) // ������� ��������� �����
		for (int j=0; j<Size();j++)
			if (isMem(i,j)) cnt++ ;
	return cnt ;
}
void Board::saveStep() {
	array<PlaceState>^ arr = gcnew array<PlaceState>(FSize*FSize) ;
	for (int i=0; i<FSize*FSize; i++) {
		arr[i]=places[i] ; // ���������� ���� � ������
	}
	memstep->Push(arr) ;

}
void Board::backStep() {
	if (memstep->Count>=2) {
		array<PlaceState>^ tmp = memstep->Pop() ; // ������� ����
		array<PlaceState>^ arr = memstep->Pop() ;
		for (int i=0; i<FSize*FSize; i++)
			places[i]=arr[i] ;
	}
}
void Board::makeStep(int i,int j, PlaceState ps, bool NoHist) {
	if (!NoHist) saveStep() ; // ���������� ����
	setState(i,j,ps) ;
	updateAfterStep(ps) ;
}
void Board::markGroup(int i,int j) {
	setMem(i,j) ;
	Position sidepos ;
	for (int k=0; k<4; k++) 
		if (existSidePos(i,j,dps[k],&sidepos)) 
			if ((getState(sidepos.i,sidepos.j)==getState(i,j))&&
			   (!isMem(sidepos.i,sidepos.j))) 
			     markGroup(sidepos.i,sidepos.j) ;
}
void Board::clearMarkedGroup() {
    for (int i=0; i<FSize; i++)	
		for (int j=0; j<FSize; j++) 
			if (isMem(i,j)) setState(i,j,psEmpty) ;
}
void Board::updateAfterStep(PlaceState stepcolor) {
    for (int i=0; i<FSize; i++)	// ���� ������� ���������� �� ���� � ��������� ��� ������
		for (int j=0; j<FSize; j++) {
			if (getState(i,j)==reverseColor(stepcolor)) { // ��������� ������ ����������
				clearMem() ;
			
				bool nofree = !haveFreeSide(i,j,getState(i,j)) ;
				if (nofree) {
					clearMem() ;
					markGroup(i,j) ;
					clearMarkedGroup() ;
				}
			}
		}
	for (int i=0; i<FSize; i++)	// ���� ������� ���������� �� ���� � ��������� ��� ������
		for (int j=0; j<FSize; j++) {
			if (getState(i,j)==stepcolor) { // ��������� ������ ������
				clearMem() ;
			
				bool nofree = !haveFreeSide(i,j,getState(i,j)) ;
				if (nofree) {
					clearMem() ;
					markGroup(i,j) ;
					clearMarkedGroup() ;
				}
			}
		}	
}
int Board::getStateCount(PlaceState ps) {
	int r = 0;
    for (int i=0; i<FSize; i++)	// ��������� ���� � ����� �������� ���������� ������� ����� ����������
		for (int j=0; j<FSize; j++) 
			if (getState(i,j)==ps) r++ ;
	return r ;
}
bool Board::isSurroundByColor(int i, int j, array<bool> ^ localmem,PlaceState color) {
	localmem[i*FSize+j]=true ; 
	Position sidepos ;
	for (int k=0; k<4; k++) {   // �������� ���� �� �� ��� ��� ��� ������
		if (!existSidePos(i,j,dps[k],&sidepos)) return false ;
		if (getState(sidepos.i,sidepos.j)==reverseColor(color)) return false ; // �������� �� ��������� ���� �����������
		if (getState(sidepos.i,sidepos.j)==PlaceState::psEmpty) // �������� �� ������ ����
			if (!localmem[FSize*sidepos.i+sidepos.j])
				if (!isSurroundByColor(sidepos.i,sidepos.j,localmem,color)) return false ;
	}
	return true ;			
}
int Board::getScore(PlaceState color) {
	// ��������� ����� ������ � �����
	if ((getStateCount(PlaceState::psBlack)==0)||
		(getStateCount(PlaceState::psWhite)==0)) return getStateCount(color) ; // ������� ������� ������ ������ ������������ �������
	clearMem() ;
	for (int i=0; i<FSize; i++)	//��������� ���� ����
		for (int j=0; j<FSize; j++) 
			if ((getState(i,j)==PlaceState::psEmpty)&&(!isMem(i,j))) {
				array<bool> ^ localmem = gcnew array<bool>(FSize*FSize) ;
				
				if (isSurroundByColor(i,j,localmem,color)) {
					for (int q=0; q<FSize; q++)	// ���������� ����� ������ ������ ������������ �������
						for (int r=0; r<FSize; r++) 
							if (localmem[q*FSize+r])
								setMem(q,r) ;	
				}
			}
	
	int cnt = 0 ;
	for (int i=0; i<FSize; i++)	// ������ �� ���������� ������� �������
		for (int j=0; j<FSize; j++) 
			if (isMem(i,j))	cnt++ ; // ������� ����� ������

	return getStateCount(color)+cnt ;
}
String^ Board::getMsg() {
	return Fmsg ;
}
int Board::testCount() {
	return 2 ; // ������������ ���������
}
void Board::prepareForTest(int testn) {
	for (int i=0; i<FSize*FSize; i++) // ��������� ��������� � �����, ������� ����
		places[i]=psEmpty ;
	if (testn==0) {
		setState(0,1,psBlack) ;
		setState(1,1,psBlack) ;
		setState(2,1,psBlack) ;

		setState(0,3,psBlack) ;
		setState(1,3,psBlack) ;
		setState(2,3,psBlack) ;

		setState(1,2,psWhite) ;
		setState(2,2,psWhite) ;

	}
	if (testn==1) {
		setState(1,0,psWhite) ;
		setState(1,1,psBlack) ;
		setState(1,2,psBlack) ;
		setState(0,2,psWhite) ;
	}

}
