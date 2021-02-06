using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace frame
{
    public partial class Form1 : Form
    {
        // private Label lblEcho; 필요없음

        int Game_Check;
         Random r = new Random();  // 랜덤함수
        // int index = r.Next(1, 127); // 랜덤함수
       int index = 1; //임의의 index 값

        public Form1()
        {
            InitializeComponent();
            Zero(); // 가장 초기 화면
        }

        private void Story_Click(object sender, EventArgs e)
        {
            LOL('S'); // stroy box를 clikck하면 LOL('S')를 호출

        //Story.Parent = this;
        //Story.Text = "적을 처치하는 가장 효율적인 방법은 그 옆의 적과 함께 한 칼에 베어버리는 것이다.";
        //Story.Font = new Font(Story.Font.Name, 10);
        //    Story.Location = new Point(30, 50);
        //    Story.AutoSize = true;
        //    lblEcho = new Label();
        //    lblEcho.Parent = this;
        //    lblEcho.Text = "적을 처치하는 가장 효율적인 방법은 \n그 옆의 적과 함께 한 칼에 베어버리는 것이다.";
        //    lblEcho.Location = new Point(30, 50);
        //    lblEcho.AutoSize = true;
        }

        private void Skill_Q_Click(object sender, EventArgs e)
        {
            LOL('Q');  // Skill_Q box를 click하면 LOL('Q')를 호출
        }

        private void Skill_R_Click(object sender, EventArgs e)
        {
            LOL('R'); // SKill_R box를 click하면 LOL('R')를 호출
        }
        
        private void Skill_W_Click(object sender, EventArgs e)
        {
            LOL('W'); // SKill_W box를 click하면 LOL('W')를 호출
        }

        private void Skill_E_Click(object sender, EventArgs e)
        {
            LOL('E'); // SKill_E box를 click하면 LOL('E')를 호출
        }

        private void Submit_Click(object sender, EventArgs e) // 우리가 노가다 뛰어야할 곳 && 확인버튼을 누르면
        {
            if (index == 1 && Answer_Box.Text == "Garen") // 가렌
            {
                MessageBox.Show("Success"); // 입력값과 일치하면 Suceess출력
                Zero(); // 초기화면값 호출
               // index++; // 다음챔프로 넘어가기위해서(랜덤함수쓸땐 필요없음)
            }
            else if (index == 2 && Answer_Box.Text == "Galio") // 이하 동일 // 갈리오
            {
                MessageBox.Show("Success");
                Zero();
                //index += 2;

            }
            else if (index == 3 && Answer_Box.Text == "Gangplank") // 갱플랭크
            {
                MessageBox.Show("Success");
                Zero();
                //index += 3;
            }
            else if (index == 4 && Answer_Box.Text == "Gragas") // 그라가스
            {
                MessageBox.Show("Success");
                Zero();
                //index += 4;
            }
            else if (index == 5 && Answer_Box.Text == "Graves") // 그레이브즈
            {
                MessageBox.Show("Success");
                Zero();
               // index += 5;
            }
            else if (index == 6 && Answer_Box.Text == "Gnar") // 나르
            {
                MessageBox.Show("Success");
                Zero();
               // index += 6;
            }
            else if (index == 7 && Answer_Box.Text == "Nami") // 나미
            {
                MessageBox.Show("Success");
                Zero();
              //  index += 7;
            }
            else if (index == 8 && Answer_Box.Text == "Nasus") // 나서스
            {
                MessageBox.Show("Success");
                Zero();
              //  index += 8;
            }
            else if (index == 9 && Answer_Box.Text == "Nautilus") // 노틸러스
            {
                MessageBox.Show("Success");
                Zero();
               // index += 9;
            }
            else if (index == 10 && Answer_Box.Text == "Nocturne") // 녹턴
            {
                MessageBox.Show("Success");
                Zero();
              //  index += 10;
            }
            else if (index == 11 && Answer_Box.Text == "Nunu") // 누누
            {
                MessageBox.Show("Success");
                Zero();
              //  index += 11;
            }
            else if (index == 12 && Answer_Box.Text == "Nidalee") // 니달리
            {
                MessageBox.Show("Success");
                Zero();
              //  index += 12;
            }
            else if (index == 13 && Answer_Box.Text == "Darius") // 다리우스
            {
                MessageBox.Show("Success");
                Zero();
                // // index += 13;
            }
            else if (index == 14 && Answer_Box.Text == "Diana") // 다이애나
            {
                MessageBox.Show("Success");
                Zero();
                // index += 14;
            }
            else if (index == 15 && Answer_Box.Text == "Draven") // 드레이븐
            {
                MessageBox.Show("Success");
                Zero();
                // index += 15;
            }
            else if (index == 16 && Answer_Box.Text == "Ryze") // 라이즈
            {
                MessageBox.Show("Success");
                Zero();
                // index += 16;
            }
            else if (index == 17 && Answer_Box.Text == "Rammus") // 람머스
            {
                MessageBox.Show("Success");
                Zero();
                // index += 17;
            }
            else if (index == 18 && Answer_Box.Text == "Lux") // 럭스
            {
                MessageBox.Show("Success");
                Zero();
                // index += 18;
            }
            else if (index == 19 && Answer_Box.Text == "Rumble") // 럼블
            {
                MessageBox.Show("Success");
                Zero();
                // index += 19;
            }
            else if (index == 20 && Answer_Box.Text == "Renekton") // 레넥톤
            {
                MessageBox.Show("Success");
                Zero();
                // index += 20;
            }
            else if (index == 21 && Answer_Box.Text == "Leona") // 레오나
            {
                MessageBox.Show("Success");
                Zero();
                // index += 21;
            }
            else if (index == 22 && (Answer_Box.Text == "RekSai" || Answer_Box.Text == "Rek'Sai" || Answer_Box.Text == "Reksai")) // 렉사이
            {
                MessageBox.Show("Success");
                Zero();
                // index += 22;
            }
            else if (index == 23 && Answer_Box.Text == "Rengar") // 렝가
            {
                MessageBox.Show("Success");
                Zero();
                // index += 23;
            }
            else if (index == 24 && Answer_Box.Text == "Lucian") // 루시안
            {
                MessageBox.Show("Success");
                Zero();
                // index += 24;
            }
            else if (index == 25 && Answer_Box.Text == "Lulu") // 룰루
            {
                MessageBox.Show("Success");
                Zero();
                // index += 25;
            }
            else if (index == 26 && (Answer_Box.Text == "LeBlanc" || Answer_Box.Text == "Leblanc")) // 르블랑
            {
                MessageBox.Show("Success");
                Zero();
                // index += 26;
            }
            else if (index == 27 && (Answer_Box.Text == "Lee Sin" || Answer_Box.Text == "LeeSin" || Answer_Box.Text == "Leesin" || Answer_Box.Text == "Lee sin")) // 리신
            {
                MessageBox.Show("Success");
                Zero();
                // index += 27;
            }
            else if (index == 28 && Answer_Box.Text == "Riven") // 리븐
            {
                MessageBox.Show("Success");
                Zero();
                // index += 28;
            }
            else if (index == 29 && Answer_Box.Text == "Lissandra") // 리산드라
            {
                MessageBox.Show("Success");
                Zero();
                // index += 29;
            }
            else if (index == 30 && (Answer_Box.Text == "Master Yi" || Answer_Box.Text == "MasterYi" || Answer_Box.Text == "Masteryi")) // 마스터이 // || Answer_Box.Text == "쿠당탕탕" || Answer_Box.Text == "10 김강산 선배"
            {
                MessageBox.Show("Success");
                Zero();
                // index += 30;
            }
            else if (index == 31 && Answer_Box.Text == "Maokai") // 마오카이
            {
                MessageBox.Show("Success");
                Zero();
                // index += 31;
            }
            else if (index == 32 && Answer_Box.Text == "Malzahar") // 말자하
            {
                MessageBox.Show("Success");
                Zero();
                // index += 32;
            }
            else if (index == 33 && Answer_Box.Text == "Malphite") // 말파이트
            {
                MessageBox.Show("Success");
                Zero();
                // index += 33;
            }
            else if (index == 34 && Answer_Box.Text == "Mordekaiser") // 모데카이저
            {
                MessageBox.Show("Success");
                Zero();
                // index += 34;
            }
            else if (index == 35 && Answer_Box.Text == "Morgana") // 모르가나
            {
                MessageBox.Show("Success");
                Zero();
                // index += 35;
            }
            else if (index == 36 && (Answer_Box.Text == "Dr.Mundo" || Answer_Box.Text == "Dr.mundo")) // 문도 박사
            {
                MessageBox.Show("Success");
                Zero();
                // index += 36;
            }
            else if (index == 37 && (Answer_Box.Text == "Miss Fortune" || Answer_Box.Text == "MissFortune")) // 미스 포츈
            {
                MessageBox.Show("Success");
                Zero();
                // index += 37;
            }
            else if (index == 38 && Answer_Box.Text == "Bard") // 바드
            {
                MessageBox.Show("Success");
                Zero();
                // index += 38;
            }
            else if (index == 39 && Answer_Box.Text == "Varus") // 바루스
            {
                MessageBox.Show("Success");
                Zero();
                // index += 39;
            }
            else if (index == 40 && Answer_Box.Text == "Vi") // 바이
            {
                MessageBox.Show("Success");
                Zero();
                // index += 40;
            }
            else if (index == 41 && Answer_Box.Text == "Veigar") // 베이가
            {
                MessageBox.Show("Success");
                Zero();
                // index += 41;
            }
            else if (index == 42 && Answer_Box.Text == "Vayne") // 베인
            {
                MessageBox.Show("Success");
                Zero();
                // index += 42;
            }
            else if (index == 43 && (Answer_Box.Text == "Vel'Koz" || Answer_Box.Text == "Vel'koz" || Answer_Box.Text == "Vel koz" || Answer_Box.Text == "Vel Koz" || Answer_Box.Text == "VelKoz" || Answer_Box.Text == "Velkoz")) // 벨코즈
            {
                MessageBox.Show("Success");
                Zero();
                // index += 43;
            }
            else if (index == 44 && Answer_Box.Text == "Volibear") // 볼리베어
            {
                MessageBox.Show("Success");
                Zero();
                // index += 44;
            }
            else if (index == 45 && Answer_Box.Text == "Braum") // 브라움
            {
                MessageBox.Show("Success");
                Zero();
                // index += 45;
            }
            else if (index == 46 && Answer_Box.Text == "Brand") // 브랜드
            { 
                MessageBox.Show("Success");
                Zero();
                // index += 46;
            }
            else if (index == 47 && Answer_Box.Text == "Vladimir") // 블라디미르
            {
                MessageBox.Show("Success");
                Zero();
                // index += 47;
            }
            else if (index == 48 && Answer_Box.Text == "Blitzcrank") // 블리츠 크랭크
            {
                MessageBox.Show("Success");
                Zero();
                // index += 48;
            }
            else if (index == 49 && Answer_Box.Text == "Viktor") // 빅토르
            {
                MessageBox.Show("Success");
                Zero();
                // index += 49;
            }
            else if (index == 50 && Answer_Box.Text == "Poppy") // 뽀삐
            {
                MessageBox.Show("Success");
                Zero();
                // index += 50;
            }
            else if (index == 51 && Answer_Box.Text == "Sion") // 사이온
            {
                MessageBox.Show("Success");
                Zero();
                // index += 51;
            }
            else if (index == 52 && Answer_Box.Text == "Shaco") // 샤코
            {
                MessageBox.Show("Success");
                Zero();
                // index += 52;
            }
            else if (index == 53 && Answer_Box.Text == "Sejuani") // 세주아니
            {
                MessageBox.Show("Success");
                Zero();
                // index += 53;
            }
            else if (index == 54 && Answer_Box.Text == "Sona") // 소나
            {
                MessageBox.Show("Success");
                Zero();
                // index += 54;
            }
            else if (index == 55 && Answer_Box.Text == "Soraka") // 소라카
            {
                MessageBox.Show("Success");
                Zero();
            }
            else if (index == 56 && Answer_Box.Text == "Shen") // 쉔
            {
                MessageBox.Show("Success");
                Zero();
            }
            else if (index == 57 && Answer_Box.Text == "Shyvana") // 쉬바나
            {
                MessageBox.Show("Success");
                Zero();
            }
            else if (index == 58 && Answer_Box.Text == "Swain") // 스웨인
            {
                MessageBox.Show("Success");
                Zero();
            }
            else if (index == 59 && Answer_Box.Text == "Skarner") // 스카너
            {
                MessageBox.Show("Success");
                Zero();
            }
            else if (index == 60 && Answer_Box.Text == "Sivir") // 시비르
            {
                MessageBox.Show("Success");
                Zero();
            }
            else {
                MessageBox.Show("Fail"); // 입력값이 틀리면 Fail 출력         
            }
        }

        public void Zero() { // 초기화면
            index = 0; // index = 0
           // Game_Check++;
            if (Game_Check >= 3)
            {
                MessageBox.Show("게임끝 ㅋ");
            }
            else 
            {
                LOL('Q'); // Q 화면 출력
                LOL('W'); // W 화면 출력
                LOL('E'); // E 화면 출력
                LOL('R'); // R 화면 출력
                LOL('S'); // Stroy 화면 출력

                index = r.Next(1, 54); ; // 다음화면으로 넘어가기 위해
        
            }
            Game_Check++;
        }
        
        public void LOL(char check) // 우리가 노가다 뛰어야할곳2
        {


            switch (index)
            {
                case 0: // 초기
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources.Q; // Q스킬의 이미지 출력 방법
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources.W; // W스킬의 이미지 출력 방법
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources.E; // E스킬의 이미지 출력 방법
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources.R; // R스킬의 이미지 출력 방법
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this; // 초기화면 Stroy를 출력하기 위한 방법
                        Story.Text = "Story"; // Stroy라는 글자 출력
                        Story.Font = new Font(Story.Font.Name, 50); // 글자 크기 조절
                    }
                    break;
                case 1: // 이하 동일 // 가렌
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._1_Garen_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._1_Garen_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._1_Garen_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._1_Garen_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "적을 처치하는 가장 효율적인 방법은 그 옆의 적과 함께 한 칼에 베어버리는 것이다.";
                        Story.Font = new Font(Story.Font.Name, 20);
                    }
                    break;
                case 2: // 갈리오
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._2_Galio_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._2_Galio_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._2_Galio_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._2_Galio_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "구원 따위는 존재하지 않아. 속죄만이 가능할 뿐이지.";
                        Story.Font = new Font(Story.Font.Name, 25);
                    }
                    break;
                case 3: // 갱플랭크
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._3_Gangplank_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._3_Gangplank_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._3_Gangplank_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._3_Gangplank_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "다 죽여 버려라! 그리고 이놈들의 배는 흔적도 없이 태워버려라!";
                        Story.Font = new Font(Story.Font.Name, 25);
                    }
                    break;
                case 4: // 그라가스
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._4_Gragas_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._4_Gragas_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._4_Gragas_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._4_Gragas_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "자, 이 술을 마시면 기운이 펄펄 날 걸!";
                        Story.Font = new Font(Story.Font.Name, 25);
                    }
                    break;
                case 5: // 그레이브즈
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._5_Graves_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._5_Graves_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._5_Graves_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._5_Graves_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "교도소 사물함에 써 있는 명언이 있지. 넘치는 게 시간이니 어떻게 놈을 끝장낼 지 실컷 고민해 보자구.";
                        Story.Font = new Font(Story.Font.Name, 20);
                    }
                    break;
                case 6: // 나르
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._6_Gnar_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._6_Gnar_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._6_Gnar_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._6_Gnar_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "냇가로 올라온 고 요들 녀석이 나만 뚫어져라 쳐다보는 것이 아닌가? 녀석은 큰 귀를 쫑긋 세우고, 한 손에는 뼈로 만든 부메랑을 쥐고 있었다. 이윽고 네 다리를 이용해 내 앞으로 달려와서는 뭐라고 자꾸 쫑알대기 시작했다. 뭐라는 건진 모르겠지만 어쨌든 고개를 끄덕여주었다. 잘 있어라, 나는 사냥감을 찾아 떠나야만 한다. 어린 요들에게서 발길을 돌린 나는 장애물처럼 높은 바위를 훌쩍 뛰어넘어 사냥감의 흔적을 계속해서 추적해 나갔다. 놈의 냄새를 포착하는 데 모든 정신을 집중하자. 눈을 감고 킁킁거리고 있는데 갑자기 괴상한 울음소리가 들려왔다. 아, 아쉽게도 범인은 아까 그 요들 녀석.";
                        Story.Font = new Font(Story.Font.Name, 10);
                    }
                    break;
                case 7: // 나미
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._7_Nami_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._7_Nami_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._7_Nami_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._7_Nami_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "내가 바로 해일이야. 되돌아갈 순 없어.";
                        Story.Font = new Font(Story.Font.Name, 20);
                    }
                    break;
                case 8: // 나서스
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._8_Nasus_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._8_Nasus_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._8_Nasus_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._8_Nasus_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "전설에 따르면 챔피언은 죽음과 시간을 지배한다고 한다. 사실 챔피언은 지금으로부터 수천 년 전, 슈리마의 정점에 섰던 존재로서 문명의 관리자이자 보호자였다. 그러나 지금은 메마른 폐허를 떠돌며 동생 레넥톤의 광기를 억누를 방법을 찾고 있다.";
                        Story.Font = new Font(Story.Font.Name, 15);
                    }
                    break;
                case 9: // 노틸러스
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._9_Nautilus_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._9_Nautilus_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._9_Nautilus_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._9_Nautilus_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "완전한 어둠 속에서 소진되어 버린 자라면, 전진하는 수 밖에 다른 길은 없다.";
                        Story.Font = new Font(Story.Font.Name, 20);
                    }
                    break;
                case 10: // 녹턴
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._10_Nocturne_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._10_Nocturne_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._10_Nocturne_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._10_Nocturne_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "어둠이 밀려온다... 이젠 칠흑 같이 어둡다... 그래도 놈이 보여...";
                        Story.Font = new Font(Story.Font.Name, 20);
                    }
                    break;
                case 11: // 누누
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._11_Nunu_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._11_Nunu_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._11_Nunu_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._11_Nunu_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "윌럼프랑 난 이 세상 구석구석을 전부 탐험할 거야. 방해하면... 알지?!";
                        Story.Font = new Font(Story.Font.Name, 20);
                    }
                    break;
                case 12: // 니달리
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._12_Nidalee_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._12_Nidalee_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._12_Nidalee_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._12_Nidalee_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "사나운 정글의 맹수들은 순수함과 소박함을 그대로 간직한 어린 소녀를 적으로 생각하지 않았다. 덕분에 챔피언은 쿠거 가족의 일원이 될 수 있었으며 이빨과 손톱으로 싸우는 법을 배우며 성장했다. 스스럼없이 자연의 순수한 마력을 받아들였고 인간의 육체 속에 야수의 본능을 소유하게 되었다. 그녀는 인간과 짐승을 뛰어넘었다.";
                        Story.Font = new Font(Story.Font.Name, 10);
                    }
                    break;
                case 13: // 다리우스
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._13_Darius_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._13_Darius_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._13_Darius_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._13_Darius_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "하나 된 녹서스는 세계를 제패할 수 있다. 이것이 응당 녹서스에게 허락된 운명이다.";
                        Story.Font = new Font(Story.Font.Name, 20);
                    }
                    break;
                case 14: // 다이애나
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._14_Diana_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._14_Diana_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._14_Diana_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._14_Diana_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "태양은 진실을 비추지 않아. 그저 불태우고 눈 멀게 할 뿐.";
                        Story.Font = new Font(Story.Font.Name, 20);
                    }
                    break;
                case 15: // 드레이븐
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._15_Draven_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._15_Draven_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._15_Draven_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._15_Draven_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "최고의 기준은 바로 내가 정한다.";
                        Story.Font = new Font(Story.Font.Name, 20);
                    }
                    break;
                case 16: // 라이즈
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._16_Ryze_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._16_Ryze_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._16_Ryze_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._16_Ryze_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "챔피언은 더 이상 보통 마법사가 아니다. 이제 마법 그 자체인 생명체가 되어버렸다.";
                        Story.Font = new Font(Story.Font.Name, 20);
                    }
                    break;
                case 17: // 람머스
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._17_Rammus_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._17_Rammus_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._17_Rammus_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._17_Rammus_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "챔피언은 수많은 수수께끼에 둘러싸인 존재다. 사막에서 다른 흔한 동물들처럼 살아가던 녀석이 어떻게 인간처럼 생각하는 능력을 얻게 되었을까? 입고 다니는 그 멋진 갑옷은 어디서 만든 것일까? 온종일 슈리마 사막을 가로지르며 찾고자 하는 것이 무엇인지? 한 가지만은 확실하다. 챔피언의 굳은 의지를 막으려 해봐야 아무 소용 없다는 것이다.";
                        Story.Font = new Font(Story.Font.Name, 10);
                    }
                    break;
                case 18: // 럭스
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._18_Lux_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._18_Lux_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._18_Lux_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._18_Lux_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "챔피언의 본명은 산나, 그녀는 빛이 가득한 곳에서 태어났다. 데마시아 왕궁 근위대 가문의 금쪽같은 딸 산나는 그녀의 높은 신분 때문에 오히려 자유롭지 못한 삶을 살아가는 듯했다.";
                        Story.Font = new Font(Story.Font.Name, 15);
                    }
                    break;
                case 19: // 럼블
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._19_Rumble_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._19_Rumble_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._19_Rumble_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._19_Rumble_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "으, 내 갑옷에서 네 얼굴을 긁어내려면 꽤 오래 걸릴 것 같은데!";
                        Story.Font = new Font(Story.Font.Name, 20);
                    }
                    break;
                case 20: // 레넥톤
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._20_Renekton_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._20_Renekton_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._20_Renekton_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._20_Renekton_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "챔피언은 한때 고대 슈리마의 충직한 수문장이었다. 그러나 번성하던 그의 나라는 무너져버렸고, 그때부터 그는 광기의 노예가 되었다. 분노에 휩싸인 챔피언은 오늘도 형 나서스를 죽이고자 한다. 영혼을 불태우는 이 광기가 나서스 때문이라고 믿기 때문이다.";
                        Story.Font = new Font(Story.Font.Name, 15);
                    }
                    break;
                case 21: // 레오나
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._21_Leona_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._21_Leona_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._21_Leona_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._21_Leona_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "태양은 온 룬테라를 차별 없이 밝혀줍니다. 챔피언 역시 그런 존재가 되어야 합니다.";
                        Story.Font = new Font(Story.Font.Name, 15);
                    }
                    break;
                case 22: // 렉사이
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._22_Rek_Sai_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._22_Rek_Sai_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._22_Rek_Sai_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._22_Rek_Sai_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "자기 종족 중에서도 특히 덩치가 크고 사나운 챔피언은 땅굴을 파고 이동하며, 매복 상태로 먹잇감을 집어삼키는 잔인한 포식자다. 절대 채워지지 않는 허기로 인해 한 때 융성했던 슈리마 제국 전역을 폐허로 몰고간 장본인이기도 하다. 상인과 무역상, 무장한 대상 행렬은 챔피언을 피해 슈리마 사막을 빙 돌아 이동하곤 했지만, 교활한 노상강도들은 이들을 죽음의 길로 몰고가기 일쑤였다. 챔피언에게 한 번 걸리면 운명은 이미 결정지어진 것이나 다름 없다. 모래 속에 도사린 이 사신에게서 피할 방도는 없으니까.";
                        Story.Font = new Font(Story.Font.Name, 10);
                    }
                    break;
                case 23: // 렝가
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._23_Rengar_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._23_Rengar_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._23_Rengar_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._23_Rengar_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "약한 자를 먹이로 삼는 건 생존을 위한 일이지. 하지만 강한 놈을 먹이로 삼을 땐 삶의 희열을 누릴 수 있다.";
                        Story.Font = new Font(Story.Font.Name, 20);
                    }
                    break;
                case 24: // 루시안
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._24_Lucian_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._24_Lucian_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._24_Lucian_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._24_Lucian_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "감사해라.내가 널 파괴하면 너는 영원한 고통에서 벗어날 수 있다.";
                        Story.Font = new Font(Story.Font.Name, 20);
                    }
                    break;
                case 25: // 룰루
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._25_Lulu_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._25_Lulu_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._25_Lulu_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._25_Lulu_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "숲 속 빈터에 아늑하게 자리 잡은 요정의 세계 글레이드는 바깥세상의 법칙이나 힘이 적용되지 않는 환상의 세계였다. 바람만 한 번 스쳐도 모든 사물의 크기나 색깔 등이 시시각각 변화하는 세계에서 챔피언은 마치 고향에 온 것처럼 편안함을 느꼈고, 픽스와 함께 비밀의 세계 곳곳을 돌아다니며 재미나게 놀았다.";
                        Story.Font = new Font(Story.Font.Name, 15);
                    }
                    break;
                case 26: // 르블랑
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._26_LeBlanc_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._26_LeBlanc_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._26_LeBlanc_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._26_LeBlanc_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "눈에 보이는 것밖에 볼 수 없는 이들에겐 세상은 아주 다른 곳일 거야.";
                        Story.Font = new Font(Story.Font.Name, 20);
                    }
                    break;
                case 27: // 리신
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._27_Lee_Sin_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._27_Lee_Sin_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._27_Lee_Sin_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._27_Lee_Sin_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "한 명의 행동으로 세상이 망가질 수도 있지만, 여러 명의 노력으로 이 또한 바로잡을 수 있다.";
                        Story.Font = new Font(Story.Font.Name, 20);
                    }
                    break;
                case 28: // 리븐
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._28_Riven_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._28_Riven_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._28_Riven_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._28_Riven_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "입술을 꼭 다물고 자기 키만큼 길고 무거운 장검을 휘두르며 매일같이 수련에 임하는 용맹한 소녀가 있었다.";
                        Story.Font = new Font(Story.Font.Name, 20);
                    }
                    break;
                case 29: // 리산드라
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._29_Lissandra_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._29_Lissandra_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._29_Lissandra_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._29_Lissandra_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "눈을 꼭 감아라, 짜릿한 냉기를 선사하마.";
                        Story.Font = new Font(Story.Font.Name, 25);
                    }
                    break;
                case 30: // 마스터이
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._30_Master_Yi_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._30_Master_Yi_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._30_Master_Yi_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._30_Master_Yi_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "고대 검술 우주류를 수련하며 심신을 갈고 닦아, 마침내 마음으로 동작을 생각하기만 해도 현실에서 그대로 이루어지는 경지에 이른 무예가다.";
                        Story.Font = new Font(Story.Font.Name, 25);
                    }
                    break;
                case 31: // 마오카이
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._31_Maokai_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._31_Maokai_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._31_Maokai_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._31_Maokai_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "죽음의 땅이 되기 이전 그림자 군도는 자연의 생기와 아름다움이 샘솟는 축복받은 섬이었다. 그중에서도 자연의 아름다움을 고스란히 간직한 성스러운 숲은 수많은 동물과 정령들이 번성하는 지상낙원이었다. 챔피언은 이 울창하게 나무가 우거진 목가적인 숲에서 평화를 사랑하는 정령으로 살아가고 있었다.";
                        Story.Font = new Font(Story.Font.Name, 15);
                    }
                    break;
                case 32: // 말자하
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._32_Malzahar_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._32_Malzahar_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._32_Malzahar_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._32_Malzahar_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "챔피언의 눈앞에 펼쳐지는 미래의 풍경은 오직 하나, 공허의 존재들로 인해 고통에 가득한 발로란의 모습뿐이었다.";
                        Story.Font = new Font(Story.Font.Name, 20);
                    }
                    break;
                case 33: // 말파이트
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._33_Malphite_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._33_Malphite_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._33_Malphite_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._33_Malphite_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "혼돈을 부르는 자들이여, 두려워할 지어다! 이 땅에 거석의 조각이 도착했노라.";
                        Story.Font = new Font(Story.Font.Name, 25);
                    }
                    break;
                case 34: // 모데카이저
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._34_Mordekaiser_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._34_Mordekaiser_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._34_Mordekaiser_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._34_Mordekaiser_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "잔인한 분노의 화신 챔피언은 그림자 군도에 출몰하는 영혼 중에서도 가장 두렵고 흉악한 자다. 고대의 갑옷으로 몸을 감싼 이 금속의 주인은 그림자 군도가 생기기도 전에 이 곳에 존재했던 최초의 언데드라 알려져 있다. 그의 비틀린 영혼은 오로지 고통만을 원하며, 다른 이들에게도 고통을 전염시킨다. 감히 그에게 대적하는 이는 끔찍한 저주에 걸릴 수도 있다. 영혼이 챔피언의 노예로 사로잡혀 파괴의 도구로 이용되는 것이다.";
                        Story.Font = new Font(Story.Font.Name, 10);
                    }
                    break;
                case 35: // 모르가나
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._35_Morgana_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._35_Morgana_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._35_Morgana_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._35_Morgana_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "둘은 피를 나눈 자매가 틀림없었다. 그러나 챔피언이 케일의 대의에 동참하기를 거부하자 케일 쪽에서 먼저 동생과의 연을 끊어버렸다.";
                        Story.Font = new Font(Story.Font.Name, 15);
                    }
                    break;
                case 36: // 문도 박사
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._36_Dr_Mundo_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._36_Dr_Mundo_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._36_Dr_Mundo_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._36_Dr_Mundo_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "오늘날까지도 실험을 멈추지 않는 챔피언은 심지어 스스로를 실험 대상으로 이용하기도 했다. 특이한 외모와 독특한 화법을 보면... 누구든 그 결과를 짐작할 수 있을 것이다.";
                        Story.Font = new Font(Story.Font.Name, 15);
                    }
                    break;
                case 37: // 미스 포츈
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._37_Miss_Fortune_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._37_Miss_Fortune_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._37_Miss_Fortune_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._37_Miss_Fortune_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "빌지워터 출신의 현상금 사냥꾼 챔피언은 16살 생일이 갓 지났을 때부터 엄청난 위업을 이룩하기 시작했다. 이 매력적인 여성의 직업은 해결사! 각각 '충격'과 '공포'라는 이름이 붙은 쌍권총을 능수능란하게 다루는 챔피언에게 해결하기 어렵거나 위험한 사건이란 존재하지 않았다.";
                        Story.Font = new Font(Story.Font.Name, 15);
                    }
                    break;
                case 38: // 바드
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._38_Bard_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._38_Bard_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._38_Bard_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._38_Bard_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "챔피언은 우리 필멸자들이 상상할 수도 없는 저 너머의 여러 세계를 떠돌아다니는 존재입니다. 여러 발로란 최고의 학자들이 챔피언의 신비를 연구하는 데 일생을 바쳤고, 사람들은 역사를 통틀어 이 수수께끼 가득한 정령에 다양한 이름을 붙여왔지만, '우주의 방랑자'나 '위대한 수호자' 같은 호칭도 챔피언의 진정한 존재 이유를 극히 일부밖에 담지 못합니다. 신비로운 우주의 질서가 위협당할 때, 챔피언은 모습을 드러내 모든 존재를 멸망의 길로부터 구해냅니다.";
                        Story.Font = new Font(Story.Font.Name, 10);
                    }
                    break;
                case 39: // 바루스
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._39_Varus_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._39_Varus_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._39_Varus_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._39_Varus_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "화살은 찰나만 살 뿐이지. 나아가야 할 방향과 맞춰야 할 대상에만 집중한 채.";
                        Story.Font = new Font(Story.Font.Name, 20);
                    }
                    break;
                case 40: // 바이
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._40_Vi_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._40_Vi_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._40_Vi_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._40_Vi_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "이거 참 안됐네. 난 주먹이 두 갠데, 넌 얼굴이 하나 밖에 없으니 말야.";
                        Story.Font = new Font(Story.Font.Name, 25);
                    }
                    break;
                case 41: // 베이가
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._41_Veigar_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._41_Veigar_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._41_Veigar_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._41_Veigar_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "발로란에서 가장 강력한 마법사, 흑마법의 대가이자 우주 에너지의 방해꾼...";
                        Story.Font = new Font(Story.Font.Name, 25);
                    }
                    break;
                case 42: // 베인
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._42_Vayne_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._42_Vayne_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._42_Vayne_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._42_Vayne_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "최초의 어둠사냥꾼이 되었고 그녀의 솜씨는 전설이 되었다.";
                        Story.Font = new Font(Story.Font.Name, 25);
                    }
                    break;
                case 43: // 벨코즈
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._43_Vel_Koz_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._43_Vel_Koz_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._43_Vel_Koz_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._43_Vel_Koz_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "촉수를 들어 단번에 내려치자 번개가 곡선을 그리며 첫 번째 놈을 관통한다. 뒤로 나동그라진 그놈을 향해 세 개의 촉수를 모두 뻗는다. 촉수와 촉수 사이에서 불꽃이 인다. 대기가 끓기 시작한다.";
                        Story.Font = new Font(Story.Font.Name, 15);
                    }
                    break;
                case 44: // 볼리베어
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._44_Volibear_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._44_Volibear_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._44_Volibear_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._44_Volibear_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "우리 어사인에게 평화란 전쟁을 통한 것뿐이다.";
                        Story.Font = new Font(Story.Font.Name, 25);
                    }
                    break;
                case 45: // 브라움
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._45_Braum_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._45_Braum_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._45_Braum_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._45_Braum_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "챔피언이 뚫은 터널 때문에 산이 휘청거리기 시작했거든. 모든 게 우르릉 쾅쾅 무너지기 시작했어. 챔피언은 잽싸게 머리를 굴려 마법이 걸린 돌문을 집어 들었고, 떨어지는 돌들을 막아내기 위해 방패처럼 머리 위로 들어 올렸지. 산이 잠잠해진 후 고개를 든 챔피언은 놀랄 수밖에 없었어. 돌문에는 흠집 하나도 나지 않았거든! 대단한 물건인 걸 깨달았지. 그 날 이후로 브라움은 언제나 그 마법의 방패와 함께였단다.";
                        Story.Font = new Font(Story.Font.Name, 10);
                    }
                    break;
                case 46: // 브랜드
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._46_Brand_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._46_Brand_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._46_Brand_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._46_Brand_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "이 세상은 불타 버릴 것이다. 바람의 숨결을 타고 날아오는 불씨 때문이 아니라, 활활 타오르는 내 복수의 손길에 의해서.";
                        Story.Font = new Font(Story.Font.Name, 20);
                    }
                    break;
                case 47: // 블라디미르 
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._47_Vladimir_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._47_Vladimir_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._47_Vladimir_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._47_Vladimir_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "인적이 드문 산기슭에서 피가 완전히 빠져나간 채 말라비틀어진 시체를 목격한다면, 그처럼 기괴한 시신들이 산더미처럼 쌓여있다면, 당신은 아마 엄청난 충격에 사로잡힐 것이다. 그러나 녹서스 출신의 챔피언에게 그 끔찍한 시체들은 감탄과 호기심을 자아낼 뿐이었다.";
                        Story.Font = new Font(Story.Font.Name, 15);
                    }
                    break;
                case 48: // 블리츠 크랭크 
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._48_Blitzcrank_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._48_Blitzcrank_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._48_Blitzcrank_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._48_Blitzcrank_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "온몸이 강철로 만들어진 챔피언은 자신을 가로막는 것은 뭐든 때려 부수지만 마음만은 비단결이다.";
                        Story.Font = new Font(Story.Font.Name, 20);
                    }
                    break;
                case 49: // 빅토르 
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._49_Viktor_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._49_Viktor_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._49_Viktor_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._49_Viktor_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "마법 공학은 사람의 손으로 사용될 때는 도구에 불과하지. 하지만 손 그 자체가 되면 해방을 가져온다.";
                        Story.Font = new Font(Story.Font.Name, 20);
                    }
                    break;
                case 50: // 뽀삐 
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._50_Poppy_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._50_Poppy_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._50_Poppy_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._50_Poppy_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "챔피언의 이름은 대장간의 불꽃이 튀어 오르는 소리를 본떠 지은 것이다. 챔피언 자신이 가장 아끼는 망치 '웜퍼'를 처음으로 손에 든 날. 블롬그런은 기쁨을 주체할 수 없었다.";
                        Story.Font = new Font(Story.Font.Name, 15);
                    }
                    break;
                case 51: // 사이온 
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._51_Sion_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._51_Sion_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._51_Sion_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._51_Sion_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "너는 약해빠졌다,스웨인! 너는 지도자가 아니야!";
                        Story.Font = new Font(Story.Font.Name, 20);
                    }
                    break;
                case 52: // 샤코 
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._52_Shaco_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._52_Shaco_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._52_Shaco_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._52_Shaco_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "유일무이한 발로란의 광대 살인마 챔피언은 지금 이 순간에도 숨이 끊어져 가는 사람 앞에서 장난을 치거나, 농담을 던지고, 배가 아플 때까지 깔깔대며 웃고 있을 것이다.";
                        Story.Font = new Font(Story.Font.Name, 15);
                    }
                    break;
                case 53: // 세주아니 
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._53_Sejuani_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._53_Sejuani_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._53_Sejuani_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._53_Sejuani_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "나는 얼음에서 태어나 폭풍우 속에 빚어져 혹한으로 단련됐다.";
                        Story.Font = new Font(Story.Font.Name, 20);
                    }
                    break;
                case 54: // 소나
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._54_Sona_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._54_Sona_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._54_Sona_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._54_Sona_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "챔피언의 손에 에트왈이 쥐어지면 그것은 도저히 지상의 것이라 여길 수 없을 만큼 신비한 소리를 자아냈고, 그 멜로디는 관객들의 마음을 순식간에 사로잡았다.";
                        Story.Font = new Font(Story.Font.Name, 15);
                    }
                    break;
                case 55: // 소라카
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._55_Soraka_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._55_Soraka_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._55_Soraka_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._55_Soraka_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "단 한 사람의 잔인함으로 인해 많은 이들의 고통을 모른 척하진 않겠어요.";
                        Story.Font = new Font(Story.Font.Name, 20);
                    }
                    break;
                case 56: // 쉔
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._56_Shen_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._56_Shen_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._56_Shen_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._56_Shen_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "훌륭한 판단의 표본이로군";
                        Story.Font = new Font(Story.Font.Name, 30);
                    }
                    break;
                case 57: // 쉬바나
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._57_Shyvana_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._57_Shyvana_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._57_Shyvana_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._57_Shyvana_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "용족에게는 이미 내 위력을 증명했다. 인간은 내게 어떤 도전을 해 올지 궁금하군.";
                        Story.Font = new Font(Story.Font.Name, 20);
                    }
                    break;
                case 58: // 스웨인
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._58_Swain_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._58_Swain_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._58_Swain_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._58_Swain_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "교활한 전략가였던 챔피언은 출전하는 전투마다 훈장을 받았는데, 불편한 다리를 절뚝거리며 최전방을 거닐던 그의 모습은 아직도 많은 병사의 뇌리에 똑똑히 각인되어 있다.";
                        Story.Font = new Font(Story.Font.Name, 20);
                    }
                    break;
                case 59: // 스카너
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._59_Skarner_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._59_Skarner_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._59_Skarner_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._59_Skarner_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "슈리마 유적의 땅 밑 깊숙한 곳엔 비밀의 영역이 있다고 한다. 정확히 확인된 사실은 아니다. 그곳의 입구를 챔피언이 지키고 있기 때문이다. 멋모르고 이곳에 발을 디뎠다가 가까스로 살아남은 사람들은 입을 모아 전한다. 온몸이 수정으로 번쩍이는 그 수호자가 얼마나 무시무시한 지능과 분노, 엄격함을 겸비하고 있는지를! 이 무자비한 문지기가 무엇을 지키고 있는진 물론 아무도 모른다.";
                        Story.Font = new Font(Story.Font.Name, 15);
                    }
                    break;
                case 60: // 시비르
                    if (check == 'Q')
                    {
                        Skill_Q.Image = Properties.Resources._60_Sivir_Q;
                    }
                    else if (check == 'W')
                    {
                        Skill_W.Image = Properties.Resources._60_Sivir_W;
                    }
                    else if (check == 'E')
                    {
                        Skill_E.Image = Properties.Resources._60_Sivir_E;
                    }
                    else if (check == 'R')
                    {
                        Skill_R.Image = Properties.Resources._60_Sivir_R;
                    }
                    else if (check == 'S')
                    {
                        Story.Parent = this;
                        Story.Text = "특유의 무자비함으로 명성을 떨친 챔피언. 모두들 그녀를 전장의 여제라는 호칭으로 부른다. 꺾이지 않는 용기와 끝없는 야망으로 똘똘 뭉친 챔피언은 엄청난 유명세와 부를 모두 거머쥐었다. 이런 그녀의 앞에 조상 대대로 내려온 비밀이 그 정체를 드러냈다. 챔피언은 이제 자신이 택한 길을 걸을 것인지, 숙명을 따를 것인지를 두고 선택의 기로에 서 있다.";
                        Story.Font = new Font(Story.Font.Name, 15);
                    }
                    break;
            }
        }

    }
}
