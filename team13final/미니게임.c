#include <stdio.h>

void main_screen();
void game_list_screen();
void rank_list_screen();
void exit_screen();
void rank_screen1();
void rank_screen2();
void rank_screen3();

void game1();	// ƽ����
void game2();	// ���ھ߱�
int game3();	// ���

void main() {
	main_screen();
}

void main_screen() {
	while (1) {
		int select;	// select: ����� �Է°�
		//����ȭ�� ����
		printf(" $ �̴ϰ��� $ \n");
		printf("-----------------\n");
		printf("| 1. ���� �ϱ�\t|\n");
		printf("| 2. ��ũ ����\t|\n");
		printf("| 3. ����\t|\n");
		printf("-----------------\n");
		printf(">> ");
		scanf_s("%d", &select);
	
		system("cls");
		//����ȭ�� ��� ����
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
		// ���Ӹ�� ȭ�� ����
		printf(" $ ���� ��� $ \n");
		printf("-----------------\n");
		printf("| 1. ƽ����\t|\n");
		printf("| 2. ���ھ߱�\t|\n");
		printf("| 3. ���\t|\n");
		printf("| 4. �ڷΰ���\t|\n");
		printf("-----------------\n");
		printf(">> ");
		scanf_s("%d", &select);

		system("cls");
		//���Ӹ�� ��� ���� (�̱���)
		switch (select) {
		case 1: game1(); break;
		case 2: game2(); break;
		case 3: game3(); break;
		case 4: return;
		default: break;
		}
		system("cls");
	}
}

void rank_list_screen() {
	while (1) {
		int select;
		// ��ũ��� ȭ�� ����
		printf(" $ ��ŷ ��� $ \n\n");
		printf("-------------------------\n");
		printf("| 1. ƽ���� ��ŷ\t|\n");
		printf("| 2. ���ھ߱� ��ŷ\t|\n");
		printf("| 3. ��� ��ŷ\t\t|\n");
		printf("| 4. �ڷΰ���\t\t|\n");
		printf("-------------------------\n");
		printf(">> ");
		scanf_s("%d", &select);

		system("cls");
		//��ũ��� ��� ����
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
		// ����ȭ�� ����
		printf("--------------------------------------------------\n");
		printf("||\t�̴ϰ���.exe�� �����Ͻðڽ��ϱ�?\t||\n");
		printf("--------------------------------------------------\n\n\n");
		printf("----------------------------\n");
		printf("| �� : 1\t�ƴϿ� : 2 |\n");
		printf("----------------------------\n");
		printf(">> ");
		scanf_s("%d", &select);

		system("cls");
		//������ ����
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
		// ��ũȭ�� ���� (����)
		printf(" $ ƽ���� ��ŷ $ \n\n");
		printf("|���\t|�̸�\t|����\t|����\t|\n");
		printf("---------------------------------\n");
		rank1();
		printf("---------------------------------\n");
		printf("1�� �Է��Ͽ� �ڷΰ��� >> ");
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
		// ��ũȭ�� ���� (����)
		printf(" $ ���ھ߱� ��ŷ $ \n\n");
		printf("|���\t|�̸�\t|����\t|�ִ� ��\t|\n");
		printf("---------------------------------\n");
		rank2();
		printf("---------------------------------\n");
		printf("1�� �Է��Ͽ� �ڷΰ��� >> ");
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
		// ��ũȭ�� ���� (����)
		printf(" $ ��� ��ŷ $ \n\n");
		printf("|���\t|�̸�\t|����\t|�ִܱ��\t|\n");
		printf("---------------------------------\n");
		rank3();
		printf("---------------------------------\n");
		printf("1�� �Է��Ͽ� �ڷΰ��� >> ");
		scanf_s("%d", &select);

		system("cls");
		if (select == 1) {
			return;
		}
	}
}