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
		printf("--------------------\n");
		printf("1. ���� �ϱ�\n");
		printf("2. ��ũ ����\n");
		printf("3. ����\n");
		printf("--------------------\n");
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
		printf("--------------------\n");
		printf("1. ƽ����\n");
		printf("2. ���ھ߱�\n");
		printf("3. ���\n");
		printf("4. �ڷΰ���\n");
		printf("--------------------\n");
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
	}
}

void rank_list_screen() {
	while (1) {
		int select;
		// ��ũ��� ȭ�� ����
		printf(" $ ��ŷ ��� $ \n\n");
		printf("| ƽ����� : ' | �߱��� : ' | ��ǿ�: ' |\n");	// ���� �� ��ŷ 1���� ���⿡ ���
		printf("--------------------\n");
		printf("1. ƽ���� ��ŷ\n");
		printf("2. ���ھ߱� ��ŷ\n");
		printf("3. ��� ��ŷ\n");
		printf("4. �ڷΰ���\n");
		printf("--------------------\n");
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
		printf("||\t�̴ϰ���.exe�� �����Ͻðڽ��ϱ�?\t||\n\n\n");
		printf("�� : 1\t�ƴϿ� : 2\n");
		printf("--------------------\n");
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
		printf(" $ Tic-Tac-Toe ��ŷ $ \n\n");
		printf("--------------------\n");
		printf("1\t�̸�\t����\t�߰�����(ex.�ִٽ�)\n");
		printf("2\t�̸�\t����\t�߰�����(ex.�ִٽ�)\n");
		printf("--------------------\n");
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
		printf("--------------------\n");
		printf("1\t�̸�\t����\t�߰�����(ex.�ִٽ�)\n");
		printf("2\t�̸�\t����\t�߰�����(ex.�ִٽ�)\n");
		printf("--------------------\n");
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
		printf("--------------------\n");
		printf("1\t�̸�\t����\t�߰�����(ex.�ִٽ�)\n");
		printf("2\t�̸�\t����\t�߰�����(ex.�ִٽ�)\n");
		printf("--------------------\n");
		printf("1�� �Է��Ͽ� �ڷΰ��� >> ");
		scanf_s("%d", &select);

		system("cls");
		if (select == 1) {
			return;
		}
	}
}