#include <stdio.h>

void main_screen();
void game_list_screen();
void rank_list_screen();
void exit_screen();
void rank_screen1();
void rank_screen2();
void rank_screen3();

void game1();	// 틱택토
void game2();	// 숫자야구
int game3();	// 행맨

void main() {
	main_screen();
}

void main_screen() {
	while (1) {
		int select;	// select: 사용자 입력값
		//메인화면 구성
		printf(" $ 미니게임 $ \n");
		printf("--------------------\n");
		printf("1. 게임 하기\n");
		printf("2. 랭크 보기\n");
		printf("3. 종료\n");
		printf("--------------------\n");
		printf(">> ");
		scanf_s("%d", &select);
	
		system("cls");
		//메인화면 기능 구성
		switch (select)
		{	
		case 1: game_list_screen(); break;
		case 2: rank_list_screen(); break;
		case 3: exit_screen(); break;
		default: break;
		}
	}
}

void game_list_screen() {
	while (1) {
		int select;
		// 게임목록 화면 구성
		printf(" $ 게임 목록 $ \n");
		printf("--------------------\n");
		printf("1. 틱택토\n");
		printf("2. 숫자야구\n");
		printf("3. 행맨\n");
		printf("4. 뒤로가기\n");
		printf("--------------------\n");
		printf(">> ");
		scanf_s("%d", &select);

		system("cls");
		//게임목록 기능 구성 (미구현)
		switch (select) {
		case 1: game1(); break;
		case 2: game2(); break;
		case 3: game3(); break;
		case 4: return;
		default: break;
		}
	}
}

void rank_list_screen() {
	while (1) {
		int select;
		// 랭크목록 화면 구성
		printf(" $ 랭킹 목록 $ \n\n");
		printf("| 틱택토왕 : ' | 야구왕 : ' | 행맨왕: ' |\n");	// 추후 각 랭킹 1등을 여기에 출력
		printf("--------------------\n");
		printf("1. 틱택토 랭킹\n");
		printf("2. 숫자야구 랭킹\n");
		printf("3. 행맨 랭킹\n");
		printf("4. 뒤로가기\n");
		printf("--------------------\n");
		printf(">> ");
		scanf_s("%d", &select);

		system("cls");
		//랭크목록 기능 구성
		switch (select) {
		case 1: rank_screen1(); break;
		case 2: rank_screen2(); break;
		case 3: rank_screen3(); break;
		case 4: return;
		default: break;
		}
	}
}

void exit_screen() {
	while (1) {
		int select;
		// 종료화면 구성
		printf("||\t미니게임.exe를 종료하시겠습니까?\t||\n\n\n");
		printf("네 : 1\t아니오 : 2\n");
		printf("--------------------\n");
		printf(">> ");
		scanf_s("%d", &select);

		system("cls");
		//종료기능 구성
		switch (select) {
		case 1: exit();
		case 2: return;
		default: break;
		}
	}
}

void rank_screen1() {
	while (1) {
		int select;
		// 랭크화면 구성 (예시)
		printf(" $ Tic-Tac-Toe 랭킹 $ \n\n");
		printf("--------------------\n");
		printf("1\t이름\t점수\t추가정보(ex.최다승)\n");
		printf("2\t이름\t점수\t추가정보(ex.최다승)\n");
		printf("--------------------\n");
		printf("1을 입력하여 뒤로가기 >> ");
		scanf_s("%d", &select);
		
		system("cls");
		if (select == 1) {
			return;
		}
	}
}

void rank_screen2() {
	while (1) {
		int select;
		// 랭크화면 구성 (예시)
		printf(" $ 숫자야구 랭킹 $ \n\n");
		printf("--------------------\n");
		printf("1\t이름\t점수\t추가정보(ex.최다승)\n");
		printf("2\t이름\t점수\t추가정보(ex.최다승)\n");
		printf("--------------------\n");
		printf("1을 입력하여 뒤로가기 >> ");
		scanf_s("%d", &select);

		system("cls");
		if (select == 1) {
			return;
		}
	}
}
void rank_screen3() {
	while (1) {
		int select;
		// 랭크화면 구성 (예시)
		printf(" $ 행맨 랭킹 $ \n\n");
		printf("--------------------\n");
		printf("1\t이름\t점수\t추가정보(ex.최다승)\n");
		printf("2\t이름\t점수\t추가정보(ex.최다승)\n");
		printf("--------------------\n");
		printf("1을 입력하여 뒤로가기 >> ");
		scanf_s("%d", &select);

		system("cls");
		if (select == 1) {
			return;
		}
	}
}