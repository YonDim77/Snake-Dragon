#pragma once
#include <stdlib.h>
#include <time.h>
#include "SnakeCoord.h"
#include <list>

namespace SnakeDragon {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace System::Media;
	using namespace System::Text;
	using namespace System::IO;
	using namespace std;

	/// <summary>
	/// Summary for MyForm
	/// </summary>

	enum Direction
	{
		Left,
		Right,
		Up,
		Down
	};

	list<SnakeCoord> Snake;
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			axWindowsMediaPlayer1->Ctlcontrols->stop();
			axWindowsMediaPlayer1->settings->volume = 100;
			SnakeCoord head(500, 300);
			Snake.push_back(head);
			objDirection = (Direction)1;
			currentDirection = objDirection;
			SaveTopScore();
			bobCatX = 0, bobCatY = 600;
			eagleX = pbPlayGround->Size.Width; eagleY = 20;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pbPlayGround;
	private: System::Windows::Forms::Timer^  timer;
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		int xApple = 280, yApple = 140, size, prevX, prevY, fireX, fireY;
		int points = 0, bobCatX, bobCatY, eagleX, eagleY;
		String^ topScore;
		bool blowFire, bricksL = false, bricksR = false, bobCatTrue = true, eagleGetSnake = false;
		int cutSnakeCounter = 0;
		Direction objDirection, currentDirection;
		Image^ imgLeft = Image::FromFile("snakeLeft.jpg");
		Image^ imgRight = Image::FromFile("snake.jpeg");
		Image^ imgUp = Image::FromFile("snakeUp.jpeg");
		Image^ imgDown = Image::FromFile("snakeDown.jpeg");
		Image^ imgNeckH = Image::FromFile("SnakeNeck.jpg");
		int mX, mY;
		bool mClick = false;

	private: AxWMPLib::AxWindowsMediaPlayer^  axWindowsMediaPlayer1;
	private: System::Windows::Forms::Label^  lblScore;
	private: System::Windows::Forms::Button^  btnStart;
	private: System::Windows::Forms::Button^  btnPause;
	private: System::Windows::Forms::Button^  btnNewGame;
	private: System::Windows::Forms::Label^  lblRecord;
	private: System::Windows::Forms::Timer^  timer1;


			 Image^ imgNeckV = Image::FromFile("SnakeNeckV.jpg");

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->pbPlayGround = (gcnew System::Windows::Forms::PictureBox());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->axWindowsMediaPlayer1 = (gcnew AxWMPLib::AxWindowsMediaPlayer());
			this->lblScore = (gcnew System::Windows::Forms::Label());
			this->btnStart = (gcnew System::Windows::Forms::Button());
			this->btnPause = (gcnew System::Windows::Forms::Button());
			this->btnNewGame = (gcnew System::Windows::Forms::Button());
			this->lblRecord = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbPlayGround))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->axWindowsMediaPlayer1))->BeginInit();
			this->SuspendLayout();
			// 
			// pbPlayGround
			// 
			this->pbPlayGround->BackColor = System::Drawing::Color::Black;
			this->pbPlayGround->Location = System::Drawing::Point(0, 0);
			this->pbPlayGround->Name = L"pbPlayGround";
			this->pbPlayGround->Size = System::Drawing::Size(1000, 680);
			this->pbPlayGround->TabIndex = 0;
			this->pbPlayGround->TabStop = false;
			this->pbPlayGround->Click += gcnew System::EventHandler(this, &MyForm::pbPlayGround_Click);
			this->pbPlayGround->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pbPlayGround_Paint);
			// 
			// timer
			// 
			this->timer->Tick += gcnew System::EventHandler(this, &MyForm::timer_Tick);
			// 
			// axWindowsMediaPlayer1
			// 
			this->axWindowsMediaPlayer1->Enabled = true;
			this->axWindowsMediaPlayer1->Location = System::Drawing::Point(1006, 600);
			this->axWindowsMediaPlayer1->Name = L"axWindowsMediaPlayer1";
			this->axWindowsMediaPlayer1->OcxState = (cli::safe_cast<System::Windows::Forms::AxHost::State^>(resources->GetObject(L"axWindowsMediaPlayer1.OcxState")));
			this->axWindowsMediaPlayer1->Size = System::Drawing::Size(279, 47);
			this->axWindowsMediaPlayer1->TabIndex = 1;
			this->axWindowsMediaPlayer1->Visible = false;
			// 
			// lblScore
			// 
			this->lblScore->AutoSize = true;
			this->lblScore->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblScore->ForeColor = System::Drawing::Color::White;
			this->lblScore->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"lblScore.Image")));
			this->lblScore->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->lblScore->Location = System::Drawing::Point(1021, 41);
			this->lblScore->Name = L"lblScore";
			this->lblScore->Size = System::Drawing::Size(121, 20);
			this->lblScore->TabIndex = 2;
			this->lblScore->Text = L"      Резултат: 0";
			// 
			// btnStart
			// 
			this->btnStart->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnStart->Location = System::Drawing::Point(1060, 105);
			this->btnStart->Name = L"btnStart";
			this->btnStart->Size = System::Drawing::Size(102, 30);
			this->btnStart->TabIndex = 3;
			this->btnStart->Text = L"Старт";
			this->btnStart->UseVisualStyleBackColor = true;
			this->btnStart->Click += gcnew System::EventHandler(this, &MyForm::btnStart_Click);
			// 
			// btnPause
			// 
			this->btnPause->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btnPause->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnPause->Location = System::Drawing::Point(1200, 104);
			this->btnPause->Name = L"btnPause";
			this->btnPause->Size = System::Drawing::Size(102, 31);
			this->btnPause->TabIndex = 4;
			this->btnPause->Text = L"Пауза";
			this->btnPause->UseVisualStyleBackColor = true;
			this->btnPause->Click += gcnew System::EventHandler(this, &MyForm::btnPause_Click);
			// 
			// btnNewGame
			// 
			this->btnNewGame->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnNewGame->Location = System::Drawing::Point(1060, 165);
			this->btnNewGame->Name = L"btnNewGame";
			this->btnNewGame->Size = System::Drawing::Size(242, 30);
			this->btnNewGame->TabIndex = 5;
			this->btnNewGame->Text = L"Нова Игра";
			this->btnNewGame->UseVisualStyleBackColor = true;
			this->btnNewGame->Click += gcnew System::EventHandler(this, &MyForm::btnNewGame_Click);
			// 
			// lblRecord
			// 
			this->lblRecord->AutoSize = true;
			this->lblRecord->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblRecord->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"lblRecord.Image")));
			this->lblRecord->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->lblRecord->Location = System::Drawing::Point(1164, 36);
			this->lblRecord->Name = L"lblRecord";
			this->lblRecord->Size = System::Drawing::Size(171, 29);
			this->lblRecord->TabIndex = 6;
			this->lblRecord->Text = L"      Рекорд: 20";
			// 
			// timer1
			// 
			this->timer1->Interval = 70;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->ClientSize = System::Drawing::Size(1284, 681);
			this->Controls->Add(this->lblRecord);
			this->Controls->Add(this->btnNewGame);
			this->Controls->Add(this->btnPause);
			this->Controls->Add(this->btnStart);
			this->Controls->Add(this->lblScore);
			this->Controls->Add(this->axWindowsMediaPlayer1);
			this->Controls->Add(this->pbPlayGround);
			this->ForeColor = System::Drawing::Color::Red;
			this->KeyPreview = true;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Дракона";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbPlayGround))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->axWindowsMediaPlayer1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		
#pragma endregion

		private: System::Void pbPlayGround_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
		{
			Image^ imgApple = Image::FromFile("apple.jpg");
			e->Graphics->DrawImage(imgApple, xApple, yApple, 20, 20);
			

			if (points >= 50)
			{
				Image^ imgBricksL = Image::FromFile("Bricks.jpg");
				e->Graphics->DrawImage(imgBricksL, 280, 140, 20, 400);
				bricksL = true;
			}
			if (points >= 100)
			{
				Image^ imgBricksR = Image::FromFile("Bricks.jpg");
				e->Graphics->DrawImage(imgBricksR, 700, 140, 20, 400);
				bricksR = true;
			}
			if (points >= 150)
			{
				if (bobCatTrue)
				{
					Image^ imgBobCatTrue = Image::FromFile("BcT.jpg");
					e->Graphics->DrawImage(imgBobCatTrue, bobCatX, bobCatY, 60, 60);
					bobCatTrue = false;
				}
				else
				{
					Image^ imgBobCatFalse = Image::FromFile("BcF.jpg");
					e->Graphics->DrawImage(imgBobCatFalse, bobCatX, bobCatY, 60, 60);
					bobCatTrue = true;
				}
			}

			if (points >= 200)
			{
					
					Image^ imgEagle = Image::FromFile("Eagle.png");
					e->Graphics->DrawImage(imgEagle, eagleX, eagleY, 80, 80);
				
			}
			if (eagleGetSnake)
			{
				Image^ imgEagleSnake = Image::FromFile("EGS.jpg");
				e->Graphics->DrawImage(imgEagleSnake, eagleX, eagleY,120, 150);
				MessageBox::Show("Кондора сграбчи Змията Дракон и я погуби!");
			}

			if (!eagleGetSnake)
			{
				for (list<SnakeCoord>::iterator it = Snake.begin(); it != Snake.end(); ++it)
				{
					if (it == Snake.begin())
					{

						switch (objDirection)
						{
						case (Direction)0:
							if (blowFire)
							{
								Image^ imgFire = Image::FromFile("fireL.jpg");
								e->Graphics->DrawImage(imgFire, fireX, fireY, 50, 50);
								blowFire = false;
							}
							e->Graphics->DrawImage(imgLeft, it->X, it->Y, 25, 25);
							break;
						case (Direction)1:
							if (blowFire)
							{
								Image^ imgFire = Image::FromFile("fireR.jpg");
								e->Graphics->DrawImage(imgFire, fireX, fireY, 50, 50);
								blowFire = false;
							}
							e->Graphics->DrawImage(imgRight, it->X, it->Y, 25, 25);
							break;
						case (Direction)2:
							if (blowFire)
							{
								Image^ imgFire = Image::FromFile("fireU.jpg");
								e->Graphics->DrawImage(imgFire, fireX, fireY, 50, 50);
								blowFire = false;
							}
							e->Graphics->DrawImage(imgUp, it->X, it->Y, 25, 25);
							break;
						case (Direction)3:
							if (blowFire)
							{
								Image^ imgFire = Image::FromFile("fireL.jpg");
								e->Graphics->DrawImage(imgFire, fireX, fireY, 50, 50);
								blowFire = false;
							}
							e->Graphics->DrawImage(imgDown, it->X, it->Y, 25, 25);
							break;
						}
					}
					else
					{
						switch (objDirection)
						{
						case (Direction)0:
							e->Graphics->DrawImage(imgNeckH, it->X, it->Y, 20, 20);
							break;
						case (Direction)1:
							e->Graphics->DrawImage(imgNeckH, it->X, it->Y, 20, 20);
							break;
						case (Direction)2:
							e->Graphics->DrawImage(imgNeckV, it->X, it->Y, 20, 20);
							break;
						case (Direction)3:
							e->Graphics->DrawImage(imgNeckV, it->X, it->Y, 20, 20);
							break;
						}
					}

				}
			}
		}

		private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
		{
			if (e->KeyCode == Keys::Left && objDirection != (Direction)1)
			{
				objDirection = (Direction)0;
			}
			else if (e->KeyCode == Keys::Right && objDirection != (Direction)0)
			{
				objDirection = (Direction)1;
			}
			else if (e->KeyCode == Keys::Up && objDirection != (Direction)3)
			{
				objDirection = (Direction)2;
			}
			else if (e->KeyCode == Keys::Down && objDirection != (Direction)2)
			{
				objDirection = (Direction)3;
			}
			else if (e->KeyCode == Keys::Space)
			{
				axWindowsMediaPlayer1->URL = "Roar.mp3";
				axWindowsMediaPlayer1->Ctlcontrols->play();  //SystemSounds::Beep->Play();
				blowFire = true;
				e->SuppressKeyPress = true;
			}
		}
		private: System::Void MyForm_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			if (e->KeyCode == Keys::Space)
			{
				axWindowsMediaPlayer1->Ctlcontrols->stop();
			}
			
			
		}
		void MovePlayer()
		{
			list<SnakeCoord>::iterator it = Snake.begin();
			list<SnakeCoord>::iterator afterHead = Snake.begin();
			afterHead++;
			
			do
			{
				
				if (it == Snake.begin())
				{
					prevX = it->X;
					prevY = it->Y;
					switch (objDirection)
					{
					case (Direction)0:
						if (it->X == 0) it->X = pbPlayGround->Size.Width;
						if (blowFire)
						{
							fireX = it->X - 60;
							fireY = it->Y;
						}
						it->X -= 20;
						break;
					case (Direction)1:
						if (it->X == pbPlayGround->Size.Width) it->X = -40;
						if (blowFire)
						{
							fireX = it->X + 30;
							fireY = it->Y;
						}
						it->X += 20;
						break;
					case (Direction)2:
						if (it->Y == 0) it->Y = pbPlayGround->Size.Height;
						if (blowFire)
						{
							fireX = it->X;
							fireY = it->Y - 60;
						}
						it->Y -= 20;
						break;
					case (Direction)3:
						if (it->Y == pbPlayGround->Size.Height) it->Y =-40 ;
						if (blowFire)
						{
							fireX = it->X - 30;
							fireY = it->Y + 40;
						}
						it->Y += 20;
						break;
					}

					if (it->X == xApple && it->Y == yApple)
					{
						foodCoordinates();
						Body();
						Score();
					}

					for (list<SnakeCoord>::iterator itBody = afterHead; itBody != Snake.end(); itBody++)
					{
						if (it->X == itBody->X && it->Y == itBody->Y)
						{
							timer->Enabled = false;
							SystemSounds::Beep->Play();
							SaveTopScore();
							btnStart->Enabled = false;
							MessageBox::Show("Змията Дракон се захапа и е мъртва!");
						}						

					}
					if (!blowFire && it->X == 280 && (it->Y >=120 && it->Y <= 520 && bricksL) || !blowFire && it->X == 700 && (it->Y >= 120 && it->Y <= 520 && bricksR))
					{
						timer->Enabled = false;
						axWindowsMediaPlayer1->URL = "Roar.mp3";
						axWindowsMediaPlayer1->Ctlcontrols->play();
						SaveTopScore();
						btnStart->Enabled = false;
						MessageBox::Show("Змията Дракон гризна стената и е мъртва!");
					}
					if (fireX == 280 && (fireY >= 120 && fireY <= 520 && bricksL) || fireX == 700 && (fireY >= 120 && fireY <= 520 && bricksR))
						timer->Enabled = true;

					if (points >= 150 && (it->X >= bobCatX && it->X <= bobCatX + 20) && (it->Y >= bobCatY && it->Y <= bobCatY+60))
					{						
						timer->Enabled = false;
						SystemSounds::Beep->Play();
						SaveTopScore();
						btnStart->Enabled = false;
						MessageBox::Show("Змията Дракон загина при епичен сблъсък с Риса!");						
					}
					if (points >= 200 && (it->X >= eagleX && it->X <= eagleX + 20) && (it->Y >= 20 && it->Y <= 100))
					{
						timer->Enabled = false;
						SystemSounds::Beep->Play();
						SaveTopScore();
						btnStart->Enabled = false;
						eagleGetSnake = true;						
					}					
				}
				else
				{
					if (points >= 150 && (it->X >= bobCatX && it->X <= bobCatX + 20) && (it->Y >= 600 && it->Y <= 660))
					{											
						SystemSounds::Beep->Play();
														
						while (Snake.back().X != it->X && Snake.back().Y != it->Y)
						{						
							Snake.pop_back();
							cutSnakeCounter++;							
						}
						
						UpdateScore(cutSnakeCounter);
						cutSnakeCounter = 0;
						
					}
					else
					{
						int x = it->X, y = it->Y;
						it->X = prevX;
						it->Y = prevY;
						prevX = x;
						prevY = y;
					}					
				}
				
				it++;
				
				
			} while (it != Snake.end());

		}
		
		
		private: System::Void timer_Tick(System::Object^  sender, System::EventArgs^  e) {
			MovePlayer();
			if(points >= 150)
				BobCatMove();
			if (points >= 200)
				EagleMove();
			pbPlayGround->Invalidate();
		}

		void Body()
		{
			SnakeCoord neck(Snake.back().X, Snake.back().Y);
			Snake.push_back(neck);
		}
		void foodCoordinates()
		{
			int x1, y1;
			srand(time(NULL));
			xApple = rand() % 960 + 20;
			if (xApple % 20 != 0)
			{
				x1 = 20 - (xApple % 20);
				xApple += x1;
			}
			yApple = rand() % 640 + 20;
			if (yApple % 20 != 0)
			{
				y1 = 20 - (yApple % 20);
				yApple += y1;
			}
			if (xApple == 280 && (yApple >= 120 && yApple <= 520) || xApple == 700 && (yApple >= 120 && yApple <= 520))
			{
				xApple = 100; yApple = 100;
			}
		}
		void Score()
		{
			points += 10;
			lblScore->Text = "      Резултат: " + System::Convert::ToString(points);
		}
		void UpdateScore(int number)
		{
			points -= (number*10);
			lblScore->Text = "      Резултат: " + System::Convert::ToString(points);
			if (points < 50)
				bricksL = false;
			if (points >= 50 && points < 100)
				bricksR = false;
		}
		
	private: System::Void btnStart_Click(System::Object^  sender, System::EventArgs^  e) {
		timer->Enabled = true; 		
	}
	
	private: System::Void btnPause_Click(System::Object^  sender, System::EventArgs^  e) {
		timer->Enabled = false;
	}
	
	protected: virtual bool ProcessDialogKey(System::Windows::Forms::Keys keyData) override
	{
		if (keyData == Keys::Left && objDirection != (Direction)1)
		{
			objDirection = (Direction)0;
			return true;
		}
		if (keyData == Keys::Right && objDirection != (Direction)0)
		{
			objDirection = (Direction)1;
		}
		if (keyData == Keys::Up && objDirection != (Direction)3)
		{
			objDirection = (Direction)2;
		}
		if (keyData == Keys::Down && objDirection != (Direction)2)
		{
			objDirection = (Direction)3;
		}
		return Form::ProcessDialogKey(keyData);
	}
	
	private: System::Void btnNewGame_Click(System::Object^  sender, System::EventArgs^  e) {
		points = 0;
		while (!Snake.empty())
		{
			Snake.pop_front();
		}
		SnakeCoord headNew(500, 300);
		Snake.push_back(headNew);
		bricksL = false;
		bricksR = false;
		lblScore->Text = "      Резултат: 0";
		objDirection = (Direction)1;
		foodCoordinates();
		SaveTopScore();
		btnStart->Enabled = true;
		bobCatX = 0, bobCatY = 600;
		eagleX = pbPlayGround->Size.Width; eagleY = 20;
		eagleGetSnake = false;
		
	}
	
	void SaveTopScore()
	{
		StreamReader^ sr = gcnew StreamReader("Topscore.txt");
		topScore = sr->ReadLine();
		lblRecord->Text = "      Рекорд: " + topScore;
		sr->Close();
		if (points > System::Convert::ToInt32(topScore))
		{
			StreamWriter^ outfile = gcnew StreamWriter("TopScore.txt");
			outfile->Write(System::Convert::ToString(points));
			outfile->Close();
		}
	}
	
	void BobCatMove()
	{
		bobCatX += 20;
		if (bobCatX == pbPlayGround->Size.Width)
			bobCatX = -40;
	}

	void EagleMove()
	{
		eagleX -= 20;
		if (eagleX == -40)
			eagleX = pbPlayGround->Size.Width;
	}
	
	private: System::Void pbPlayGround_Click(System::Object^  sender, System::EventArgs^  e) {
	
		MouseEventArgs^ me = (MouseEventArgs^)e;
		mX = me->X;
		mY = me->Y;
	
		int x1, y1;

		if (mX % 20 != 0)
		{
			x1 = 20 - (mX % 20);
			mX += x1;
		}
	
		if (mY % 20 != 0)
		{
			y1 = 20 - (mY % 20);
			mY += y1;
		}
	}

	};
}
