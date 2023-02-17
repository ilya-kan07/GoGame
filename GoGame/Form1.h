#pragma once

#include "board.h"
#include "player.h"
#include "FormFinish.h"
#include "FormStart.h"

namespace GoGame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� Form1
	///
	/// ��������! ��� ��������� ����� ����� ������ ���������� ����� ��������
	///          �������� ����� ����� �������� ("Resource File Name") ��� �������� ���������� ������������ �������,
	///          ���������� �� ����� ������� � ����������� .resx, �� ������� ������� ������ �����. � ��������� ������,
	///          ������������ �� ������ ��������� �������� � ���������������
	///          ���������, ��������������� ������ �����.
	/// </summary>
	
	
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		// �����
		Board^ board ;
		// ����� ���������
		Player^ player ;
	
		bool gamefinished ; // ���������� ����
		bool showallowed ; // ���������� ����������� ����
	private: System::Windows::Forms::ToolStripMenuItem^  showallowedToolStripMenuItem;
	public: 
		PlaceState humancolor ;
	
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
			showallowed=false;
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  NGame;
	protected: 

	private: System::Windows::Forms::ToolStripMenuItem^  NNewGame;

	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  NClose;
	private: System::Windows::Forms::ToolStripMenuItem^  NLevel;


	private: System::Windows::Forms::ToolStripMenuItem^  NEasy;
	private: System::Windows::Forms::ToolStripMenuItem^  NMedium;
	private: System::Windows::Forms::ToolStripMenuItem^  NHard;














	private: System::Windows::Forms::ToolStripMenuItem^  ������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  test0ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  test1ToolStripMenuItem;

	private:
		/// <summary>
		/// ��������� ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ������������ ����� ��� ��������� ������������ - �� ���������
		/// ���������� ������� ������ ��� ������ ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->NGame = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->NNewGame = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->NClose = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->NLevel = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->NEasy = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->NMedium = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->NHard = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->test0ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->test1ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->showallowedToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->NGame, this->NLevel,
					this->������������ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(592, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// NGame
			// 
			this->NGame->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->NNewGame, this->toolStripMenuItem1,
					this->NClose
			});
			this->NGame->Name = L"NGame";
			this->NGame->Size = System::Drawing::Size(46, 20);
			this->NGame->Text = L"����";
			// 
			// NNewGame
			// 
			this->NNewGame->Name = L"NNewGame";
			this->NNewGame->Size = System::Drawing::Size(180, 22);
			this->NNewGame->Text = L"����� ����";
			this->NNewGame->Click += gcnew System::EventHandler(this, &Form1::NNewGame_Click);
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(177, 6);
			// 
			// NClose
			// 
			this->NClose->Name = L"NClose";
			this->NClose->Size = System::Drawing::Size(180, 22);
			this->NClose->Text = L"�����";
			this->NClose->Click += gcnew System::EventHandler(this, &Form1::NClose_Click);
			// 
			// NLevel
			// 
			this->NLevel->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->NEasy, this->NMedium,
					this->NHard
			});
			this->NLevel->Name = L"NLevel";
			this->NLevel->Size = System::Drawing::Size(81, 20);
			this->NLevel->Text = L"���������";
			// 
			// NEasy
			// 
			this->NEasy->Checked = true;
			this->NEasy->CheckState = System::Windows::Forms::CheckState::Checked;
			this->NEasy->Name = L"NEasy";
			this->NEasy->Size = System::Drawing::Size(180, 22);
			this->NEasy->Text = L"������";
			this->NEasy->Click += gcnew System::EventHandler(this, &Form1::NEasy_Click);
			// 
			// NMedium
			// 
			this->NMedium->Name = L"NMedium";
			this->NMedium->Size = System::Drawing::Size(180, 22);
			this->NMedium->Text = L"�������";
			this->NMedium->Click += gcnew System::EventHandler(this, &Form1::NMedium_Click);
			// 
			// NHard
			// 
			this->NHard->Name = L"NHard";
			this->NHard->Size = System::Drawing::Size(180, 22);
			this->NHard->Text = L"�������";
			this->NHard->Click += gcnew System::EventHandler(this, &Form1::NHard_Click);
			// 

			// 
			// showallowedToolStripMenuItem
			// 
			this->showallowedToolStripMenuItem->Name = L"showallowedToolStripMenuItem";
			this->showallowedToolStripMenuItem->Size = System::Drawing::Size(239, 22);
			this->showallowedToolStripMenuItem->Text = L"�������� ����������� �����";
			this->showallowedToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::showallowedToolStripMenuItem_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(592, 613);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"���� \"��\"";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->Shown += gcnew System::EventHandler(this, &Form1::Form1_Shown);
			this->ResizeEnd += gcnew System::EventHandler(this, &Form1::Form1_ResizeEnd);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyUp);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void NewGame() { // ����� ����
			 tekposx = 0 ;
			 tekposy = 0 ;

			 FormStart^ f = gcnew FormStart() ; // ����� �������
			 if (f->ShowDialog()==System::Windows::Forms::DialogResult::OK) {

			 
			 int currpl = 1 ;
			 board = gcnew Board(f->getSize()) ; // ����� �����
			 humancolor = (currpl==1)?psBlack:psWhite ;
			 player = gcnew Player(plDummy,(currpl==2)?psBlack:psWhite) ; // ����� �����
			 gamefinished = false ;
			 this->Text=L"" ;
			 }
			 
		 }
private: System::Void FinishGame() { // ���������� ����
			gamefinished=true ;
			this->Text = L"���� ��������" ; 
			FormFinish^ f = gcnew FormFinish() ; // ����� ����������
			f->setInfo(board->getScore(humancolor), // ����� ������ ����
				board->getScore(player->getPlayerColor())) ;
			f->ShowDialog() ;
		}
private: System::Void NClose_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close() ;
		 }
private: System::Void NEasy_Click(System::Object^  sender, System::EventArgs^  e) {
			 NEasy->Checked=true ;
			 NMedium->Checked=false ;
			 NHard->Checked=false ;
			 player->setLevel(plEasy) ;
			 //setEasy() ;
		 }
private: System::Void NMedium_Click(System::Object^  sender, System::EventArgs^  e) {
			 NEasy->Checked=false ;
			 NMedium->Checked=true ;
			 NHard->Checked=false ;
			 player->setLevel(plMedium) ;
			 //setMedium() ;
		 }
private: System::Void NHard_Click(System::Object^  sender, System::EventArgs^  e) {
			 NEasy->Checked=false ;
			 NMedium->Checked=false ;
			 NHard->Checked=true ;
			 player->setLevel(plHard) ;
			 //setHard() ;
		 }
private:
			// ��������� � ���������� ���������
			static int LSH = 20 ;
			static int TSH = 80 ;
			int w ;
			int h ;
			int Rp ;
			int Rf ;

// ������� ���������� �����
private: int getPX(int i) {
			 return LSH+i*w+w/2 ;
		 }
private: int getPY(int j) {
			 return TSH+j*h+h/2 ;			 
		 }
private: bool isInPlace(int i,int j, int X, int Y) {
			return ((getPX(i)-X)*(getPX(i)-X)+(getPY(j)-Y)*(getPY(j)-Y)<=Rp*Rp);
		 }
private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {

			// ���������� ����� �����
			int N = board->Size() ;
			w = (this->Width - 2*LSH) / (N) ;
			h = (this->Height - 2*TSH) / (N) ;

			Rp = w/4 ;
			Rf = w/4 ;

			System::Drawing::SolidBrush^ brushblack = 
				gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black);
			System::Drawing::SolidBrush^ brushwhite = 
				gcnew System::Drawing::SolidBrush(System::Drawing::Color::White);
			System::Drawing::SolidBrush^ brushbeige = 
				gcnew System::Drawing::SolidBrush(System::Drawing::Color::Beige);
			System::Drawing::SolidBrush^ brushred = 
				gcnew System::Drawing::SolidBrush(System::Drawing::Color::Red);

			System::Drawing::Font ^ fnt = gcnew System::Drawing::Font("Arial",20) ;

			e->Graphics->Clear(Color::Beige) ;
			
			Pen^ pen = gcnew Pen(Color::Black);
			pen->Width=1 ;
			
			for (int i=0; i<N; i++)
				e->Graphics->DrawLine(pen,getPX(i),TSH-200,getPX(i),TSH+(N)*h+300) ;
			for (int j=0; j<N; j++)
				e->Graphics->DrawLine(pen,LSH-200,getPY(j),LSH+(N)*w+300,getPY(j)) ;
			
			for (int i=0; i<N; i++)
				for (int j=0; j<N; j++) {
					if ((i == tekposx) && (j == tekposy)) {
						System::Drawing::SolidBrush^ brush ;
						brush = brushred;
						e->Graphics->FillEllipse(brush, getPX(i) - Rf - 4, getPY(j) - Rf - 4, 2 * Rf + 8, 2 * Rf + 8);
					}
						

					else if (board->getState(i,j)==psEmpty) {
						System::Drawing::SolidBrush^ brush ;
						
						brush=brushbeige ;
						if (showallowed) 
							if (board->canMakeStep(i,j,psBlack)) brush=brushred ;	

						e->Graphics->FillEllipse(brush,getPX(i)-Rp,getPY(j)-Rp,2*Rp,2*Rp) ;
						e->Graphics->DrawEllipse(pen,getPX(i)-Rp,getPY(j)-Rp,2*Rp,2*Rp) ;
					}
					else {

						System::Drawing::SolidBrush^ brush ;
						if (board->getState(i,j)==psBlack) brush=brushblack ; 
							else brush=brushwhite ;
						e->Graphics->FillEllipse(brush,getPX(i)-Rf,getPY(j)-Rf,2*Rf,2*Rf) ;
						e->Graphics->DrawEllipse(pen,getPX(i)-Rf,getPY(j)-Rf,2*Rf,2*Rf) ;
					}


				}

				e->Graphics->DrawString(String::Format("������: {0}",
					board->getScore(PlaceState::psBlack)),
					fnt,brushblack,10,40) ;
				
				e->Graphics->DrawString(String::Format("�����: {0}", board->getScore(PlaceState::psWhite)), fnt, brushblack, 450, 40);
			

		 }
private: System::Void Form1_ResizeEnd(System::Object^  sender, System::EventArgs^  e) {
			 Refresh() ;
		 }
private: System::Void Form1_Shown(System::Object^  sender, System::EventArgs^  e) {
			 Refresh() ;
		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 NewGame() ;
			 
		 }
private: System::Void Form1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 
			this->Cursor->Current=System::Windows::Forms::Cursors::Arrow ;

			// ��������� �������� ���� ��� ����������� ����� 
			for (int i=0; i<board->Size(); i++)
				for (int j=0; j<board->Size(); j++)
					if (isInPlace(i,j,e->X,e->Y)&&(board->isEmpty(i,j)))  
					  { this->Cursor->Current=System::Windows::Forms::Cursors::Hand ; break ; }
		 }
private: System::Void Form1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 doNextStep(e->X,e->Y,true) ;
		 }

private: void doAIStep() {
							Refresh() ;
							
							// ��� ����������
							if (board->existNextStepForColor(player->getPlayerColor())) {
								this->Text = L"��� ����������" ;
								System::Threading::Thread::CurrentThread->Sleep(1000) ;
								player->makeStep(board) ;
								this->Text = L"��� ���" ;
								Refresh() ;
								
								if (!board->existNextStepForColor(humancolor)) {
									FinishGame() ;
									return ;
								}
							}
							else {
								FinishGame() ;
								return ;
							}
		 }
private: void doNextStep(int x, int y, bool iscoord) {
			 if (gamefinished) return ;

			 // ��������� ����
			 for (int i=0; i<board->Size(); i++)
				for (int j=0; j<board->Size(); j++) {
					bool z = (iscoord?isInPlace(i,j,x,y):((i==x)&&(j==y))) ;
					if (z&&(board->isEmpty(i,j))) {
						
						
						// ��� ��������
						if (board->canMakeStep(i,j,humancolor)) {
							board->makeStep(i,j,humancolor,false) ;
							
							doAIStep() ;
						}
						else
							this->Text = board->getMsg() ;
					}
				}
		 }

private: System::Void NStepBack_Click(System::Object^  sender, System::EventArgs^  e) {
			 board->backStep() ;
			 Refresh() ;
		 }
private: System::Void NNewGame_Click(System::Object^  sender, System::EventArgs^  e) {
			 NewGame() ;
			 Refresh() ;
		 }
private: System::Void Form1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			 			 
		 }

private: int tekposx  ;
private: int tekposy  ;

private: System::Void Form1_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			 if (e->KeyCode==Keys::Left) 
				 if (tekposx>0) tekposx-- ;
			 if (e->KeyCode==Keys::Right) 
				 if (tekposx<board->Size()-1) tekposx++ ;
			 if (e->KeyCode==Keys::Up) 
				 if (tekposy>0) tekposy-- ;
			 if (e->KeyCode==Keys::Down) 
				 if (tekposy<board->Size()-1) tekposy++ ;
			 if ((e->KeyCode==Keys::Space)||(e->KeyCode==Keys::Return))
				 doNextStep(tekposx,tekposy,false) ;
			 
			 this->Refresh() ;
		 }
private: System::Void showallowedToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				showallowed=!showallowed ;
				Refresh() ;
		 }
private: System::Void NStepSkip_Click(System::Object^  sender, System::EventArgs^  e) {
			 doAIStep() ;
		 }
};
}

