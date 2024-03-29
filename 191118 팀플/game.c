#include "game.h"

int keyControl()
{
	char temp = getch(); //getch()함수는 엔터안눌러도 키가 눌리면 바로 반환
	//키가 입력되면 바로 temp변수에 임시로 값을 저장하고 if문에서 확인 해당문자 맞으면 값반환

	if (temp == 'w' || temp == 'W' || temp == 72) {
		return UP;
	}
	else if (temp == 's' || temp == 'S' || temp == 80) {
		return DOWN;
	}
	else if (temp == 'a' || temp == 'A' || temp == 75) {
		return LEFT;
	}
	else if (temp == 'd' || temp == 'D' || temp == 77) {
		return RIGHT;
	}
	else if (temp == 13) {
		return SUBMIT;
	}
}

void titleDraw(void)
{
	system("cls");
	int x = 10; //타이틀 표시 x좌표
	int y = 20; //타이틀 표시 y좌표
	setcolor(6,0); gotoxy(x, y + 0); printf("ooo        ooooo        .o.       ooooooooooooo  ooooo   ooooo            .oooooo.          .o.        ooo        ooooo  oooooooooooo"); Sleep(100); //연한노란색
	gotoxy(x, y + 1); printf("`88.       .888'       .888.      8'   888   `8  `888'   `888'           d8P'  `Y8b        .888.       `88.       .888'  `888'     `8"); Sleep(100);
	gotoxy(x, y + 2); printf(" 888b     d'888       .8'888.          888        888     888           888               .8'888.       888b     d'888    888 "); Sleep(100);
	gotoxy(x, y + 3); printf(" 8 Y88. .P  888      .8' `888.         888        888ooooo888           888   ooooo      .8' `888.      8 Y88. .P  888    888ooooo8 "); Sleep(100);
	gotoxy(x, y + 4); printf(" 8 `888'    888    .88oooo8888.        888        888     888           888      88     .88oooo8888.    8  `888'   888    888    "); Sleep(100);
	gotoxy(x, y + 5); printf(" 8   Y      888   .8o'     `888.       888        888     888           `88.    .88'   .8o'     `888.   8    Y     888    888       o "); Sleep(100);
	gotoxy(x, y + 6); printf("o8o        o888o  o88o     o8888o     o888o      o888o   o888o           `Y8bood8P'   o88o     o8888o  o8o        o888o  o888ooooood8 "); Sleep(100);


}

int menuDraw(void)
{
	setcolor(7, 0); gotoxy(110, 30); printf("- Made by. 정길연, 정민우, 정세훈"); //흰색

	int x = 70;
	int y = 32;


	setcolor(7, 0); gotoxy(x - 2, y); printf("> 게임 시작"); //-2하는 이유는 >을 넣어야되서 
	gotoxy(x, y + 1); printf("게임 정보");
	gotoxy(x, y + 2); printf("순위 보기");
	gotoxy(x, y + 3); printf("게임 종료");

	int new_name(int x, int y);

	while (1) //무한반복
	{
		int n = keyControl(); //키보드이벤트를 키값으로 받아오기
		switch (n)
		{
		case UP: {
			if (y > 32) //계속 못올라가게
			{
				gotoxy(x - 2, y); //'>'을 두칸 이전에 출력하려고
				printf(" "); //원래 위치 지우기
				gotoxy(x - 2, --y); //지우고 새로 이동한 위치로 이동
				printf(">"); //'>'삽입
			}
			break; }
		case DOWN: {
			if (y < 35) //계속 못내려가게
			{
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break; }
		case SUBMIT: {
			return y - 32; } //스페이스바 선택경우 시작위치 32이니까 0123 받을 수있음
		}
	}
}

int new_name(int x, int y) //사용자이름 입력
{
	system("cls");

	struct data {
		int number;
		int age;
		char name[10];
	};
	struct data student;

	setcolor(6, 0); gotoxy(x + 10, y +5 ); printf(" [ 캐 릭 터 생 성 ] ");


	setcolor(6, 0); gotoxy(x + 10, y + 8); printf(" [ 학번을 적어주세요 ]");
	setcolor(7, 0); gotoxy(x + 10, y + 9); printf(" 학번 : ");
	scanf("%d", &student.number);

	setcolor(6, 0); gotoxy(x + 10, y + 11); printf(" [ 나이를 적어주세요 ]");
	setcolor(7, 0); gotoxy(x + 10, y + 12); printf(" 나이 : ");
	scanf("%d", &student.age);

	setcolor(6, 0); gotoxy(x + 10, y + 14); printf(" [ 이름을 적어주세요 ]");
	setcolor(7, 0); gotoxy(x + 10, y + 15); printf(" 이름 : ");
	scanf("%s", student.name);

	setcolor(6, 0); gotoxy(x + 10, y + 17); printf("[ 생성되었습니다 ]\n\n");

	system("PAUSE");

	

	FILE* fp;
	fp = fopen("Nickname.txt", "a");
	if (fp != NULL) 
	{
		fprintf(fp, "%d/ %d/ %s/ %s/ %s\n", student.number,student.age, student.name, __DATE__, __TIME__);
	}
	fclose(fp);

	
}

void Help()
{
	system("cls");

	int x = 35;
	int y = 18;

	gotoxy(x, y); printf("    주어진 문제를 푸시오. 단계는 총 7단계입니다.");
	gotoxy(x, y + 5); printf("-> 사용자 이름을 입력하면, 순위에 올라갈 수있습니다.");
	gotoxy(x, y + 6); printf("-> 답이 틀렸을 시, 5초가 경과되고, 기회가 한 번씩 줄어들게 되며, 7번 실패시 자동종료됩니다.");
	gotoxy(x, y + 8); printf("-> 조작은 방향키와 엔터를 이용합니다. ( w(위) a(좌) s(아래) d(우)도 가능합니다. 입력이 안될 시 한/영에서 영어설정 )");
	gotoxy(x, y + 11); printf("   **  엔터를 누르면 메인화면으로 이동합니다. **");

	while (1)
	{
		if (keyControl() == SUBMIT)
			break;
	}
}

int heart(int heartnum)
{
	setcolor(7, 0); gotoxy(0,0); printf("목숨수 :");
	switch (heartnum) 
	{
	case 7:
		setcolor(5, 0); gotoxy(0, 0); printf("♥ ♥ ♥ ♥ ♥ ♥ ♥\n");
		break;
	case 6:
		setcolor(5, 0); gotoxy(0, 0); printf("♥ ♥ ♥ ♥ ♥ ♥ ♡\n");
		break;
	case 5:
		setcolor(5, 0); gotoxy(0, 0); printf("♥ ♥ ♥ ♥ ♥ ♡ ♡\n");
		break;
	case 4:
		setcolor(5, 0); gotoxy(0, 0); printf("♥ ♥ ♥ ♥ ♡ ♡ ♡\n");
		break;
	case 3:
		setcolor(5, 0); gotoxy(0, 0); printf("♥ ♥ ♥ ♡ ♡ ♡ ♡\n");
		break;
	case 2:
		setcolor(5, 0); gotoxy(0, 0); printf("♥ ♥ ♡ ♡ ♡ ♡ ♡\n");
		break;
	case 1:
		setcolor(5, 0); gotoxy(0, 0); printf("♥ ♡ ♡ ♡ ♡ ♡ ♡\n");
		break;
	}
	printf("\n");
}

void skull(int skullnum){
	int skullswitch = skullnum;
	if (skullswitch == 2|| skullswitch == 3|| skullswitch == 4|| skullswitch == 5 || skullswitch == 6 || skullswitch == 7)
	{
		gotoxy(50, 1); printf("                           ,--.\n");
		gotoxy(50, 2); printf("                          {    }\n");
		gotoxy(50, 3); printf("                          K,   }\n");
		gotoxy(50, 4); printf("                         /  `Y`\n");
	}
	if (skullswitch == 3 || skullswitch == 4 || skullswitch == 5 || skullswitch == 6 || skullswitch == 7)
	{
		gotoxy(50, 5); printf("	                  /   /\n");
		gotoxy(50, 6); printf("                   {_'-K.__/\n");
		gotoxy(50, 7); printf("                     `/-.__L._\n");
		gotoxy(50, 8); printf("                     /  ' /`\_}\n");
	}
	if (skullswitch == 4 || skullswitch == 5 || skullswitch == 6 || skullswitch == 7)
	{
		gotoxy(50, 9); printf("                    /  ' /\n");
		gotoxy(50, 10); printf("            ____   /  ' /\n");
		gotoxy(50, 11); printf("     ,-'~~~~    ~~/  ' /_\n");
		gotoxy(50, 12); printf("   ,'             ``~~~%%',\n");
	}
	if (skullswitch == 5 || skullswitch == 6 || skullswitch == 7)
	{	
		gotoxy(50, 13); printf("  (                     %  Y\n");
		gotoxy(50, 14); printf(" {                      %% I\n");
		gotoxy(50, 15); printf("{      -                 %  `.\n");
		gotoxy(50, 16); printf("|       ',                %  )\n");
	}
	if (skullswitch == 6 || skullswitch == 7)
	{
		gotoxy(50, 17); printf("|        |   ,..__      __. Y\n");
		gotoxy(50, 18); printf("|    .,_./  Y ' / ^Y   J   )|\n");
		gotoxy(50, 19); printf("\\           |' /   |   |   ||\n");
		gotoxy(50, 20); printf(" \\          L_/    . _ (_,.'(\n");

	}
	if (skullswitch == 7)
	{
		gotoxy(50, 21); printf("  \\,   ,      ^^""' / |      )\n");
		gotoxy(50, 22); printf("    \\_  \\          /,L]     /\n");
		gotoxy(50, 23); printf("      '-_`-,       ` `   ./`\n");
	}
}
void viewlog()
{
	system("cls");

	char buffer[10000] = {0, }; 
	//파일을 읽을 때 사용할 임시 공간(버퍼)를 선언해야 하는데 
	//fread 함수를 사용할 때는 char 배열을 선언한 뒤 반드시 0으로 초기화해야 한다.
	//(char 포인터에 동적 메모리를 할당한 뒤 0으로 초기화해도 된다)

	FILE* fp = fopen("Nickname.txt", "r");

	//fgets(buffer, sizeof(buffer), fp); 이건 줄바꿈문자있으면 그 전까지만 읽어오기 가능
	fread(buffer, sizeof(buffer), 1, fp);
	printf("%s\n\n", buffer);
	fclose(fp);

	printf("\n\n   **  엔터를 누르면 메인화면으로 이동합니다. **");
	while (1)
	{
		if (keyControl() == SUBMIT)
			break;
	}
}