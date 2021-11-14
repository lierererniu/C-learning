#include<iostream>
#include<string>
using namespace std;
#define MAX 1000 //�������

struct Person
{
	string m_name;
	int m_Sex;//1�У�2Ů
	int m_Age;
	string m_Phone;
	string m_Addr;
};
struct Addressbooks
{
	struct Person personArray[MAX];
	int m_size; //ͨѶ¼��Ա����
};


void showmenu()
{	
	
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;
}
void addPerson(Addressbooks * abs)
{
	if (abs->m_size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else
	{
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[abs->m_size].m_name = name;
		cout << "�������Ա�" << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_size].m_Sex = sex;
				break;
			}
			else
			{
				cout << "������������������:"<<endl;
			}
		}
		int age = 0;
		cout << "���������䣺" << endl;
		cin >> age;
		abs->personArray[abs->m_size].m_Age = age;
		
		string phone;
		cout << "������绰��" << endl;
		cin >> phone;
		abs->personArray[abs->m_size].m_Phone = phone;

		string address;
		cout << "�������ͥסַ��" << endl;
		cin >> address;
		abs->personArray[abs->m_size].m_Addr = address;

		//����ͨѶ¼����
		abs->m_size++;
		cout << "��ӳɹ�" << endl;
		system("pause");//�밴���������
		system("cls");
	}
}

void showPerson(Addressbooks * abs)
{
	if (abs->m_size == 0)
	{
		cout << "��ǰ��ͨѶ¼Ϊ�ա�" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++) {
			
			cout << "������" << abs->personArray[i].m_name << "\t";
			cout << "�Ա�" << (abs->personArray[i].m_Sex == 1? "��":"Ů") << "\t";
			cout << "���䣺" << abs->personArray[i].m_Age << "\t";
			cout << "��ַ��" << abs->personArray[i].m_Addr << "\t";
			cout << "�绰��" << abs->personArray[i].m_Phone << endl;
		}
	}
	system("pause");//�밴���������
	system("cls");
}

int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_size; i++) {
		if (abs->personArray[i].m_name == name) {
			return i;
		}
	}
	return -1;
}

void delPerson(Addressbooks * abs)
{
	cout << "��������Ҫɾ������ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//ɾ�����ģ������ĺ��������ǰ�ƶ���������ͨѶ¼�м�¼����Ա����-1.
		for (int i = ret; i < abs->m_size; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
			abs->m_size--;
		}
		cout << "ɾ���ɹ�" << endl;
	}

	else
	{
		cout<<"���޴��ˡ�"<<endl;
	}
	system("pause");//�밴���������
	system("cls");
}

void findPerson(Addressbooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ��:" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "������" << abs->personArray[ret].m_name << "\t";
		cout << "�Ա�" << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << abs->personArray[ret].m_Age << "\t";
		cout << "��ַ��" << abs->personArray[ret].m_Addr << "\t";
		cout << "�绰��" << abs->personArray[ret].m_Phone << endl;
	}
	else
	{
		cout << "���޴���,�����²�ѯ��" << endl;
	}
	system("pause");//�밴���������
	system("cls");
}

void modifyPerson(Addressbooks * abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[ret].m_name = name;
		cout << "�������Ա�" << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			else
			{
				cout << "������������������:" << endl;
			}
		}
		int age = 0;
		cout << "���������䣺" << endl;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		string phone;
		cout << "������绰��" << endl;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		string address;
		cout << "�������ͥסַ��" << endl;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

		cout << "�޸ĳɹ�" << endl;
		system("pause");//�밴���������
		system("cls");
	}
}


void cleanPerson(Addressbooks* abs)
{
	abs->m_size = 0;
	cout << "��ϵ���Ѿ���ա�" << endl;
	system("pause");//�밴���������
	system("cls");
}


int main()
{
	Addressbooks abs;
	//��ʼ��ͨѶ¼�е�ǰ��Ա����
	abs.m_size = 0;
	int select = 0;
	while (true)
	{
		showmenu();
		cin >> select;
		switch (select)
		{
		case 1://�����ϵ��
			addPerson(&abs);

			break;
		case 2://2����ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3://3��ɾ����ϵ��
		{
			delPerson(&abs);
		}
			break;
		case 4://������ϵ��
			findPerson(&abs);
			break;
		case 5://�޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6://�����ϵ��
			cleanPerson(&abs);
			break;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	showmenu();
	system("pause");
	return 0;
}