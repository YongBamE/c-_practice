#pragma once
#include<iostream>
#include<string.h>

using namespace std;



class City
{

private:
	int data[11];	//1.�ͳ��� 2.������ 3. �������� 4.������ 5. ��Ÿ���Ϸ� 6. �����γ� 7. ����Ⱦ�ܺ��� 8. �����κα� 9. ö��ǳθ� 10. ��Ÿ 11. �Ҹ�
	string cityName;
	string districtName;
public:
	City();
	City(const char* getname);

	string getCityName();
	string getDistrictName();
	int* getData();
	
	void setCityName(string name);
	void setDistrictName(string name);
	void setData(int i, string data);

};

// ���ú� �ڻ��α�

//���ø����� �� ã�ƺ��� ������ �׶� �ñ��� ���� ���� ������ �Ѵ�

// 1.�ñ��� ����
// 2.����������� or all
// 3.���.��.


//line �����ؼ� ���� data[13]���� �����
//data[0]�� data[1]�� �˻������ ��ġ�°� ������ ��. �����ϳ��� ������ ���.
//������ data���� ���ں��� ������ �Է��ϸ� ���� ������ ��µǵ���.
//���������� ���� line ������ŭ ���ø� �޾Ƽ� ������ �����ϴ� �ν��Ͻ�

//�ٵ� �̰� Ŭ�󽺷� ��� ������;
//1.City �ν��Ͻ��� ���� search�� �̸��� �޴´�.
//1.1 �´� City �̸����� Ȯ�����ִ� �Լ�. ��ġ�ϴ°��� ������ true ��ȯ

//2. City�� �޾Ƽ� ����� �޾��ִ� Ŭ����

//���ÿ� ������ ��ƾ��ұ�?
//�����̸��� �޾Ƽ� �����͸� �̾��ִ� Ŭ������ �ؾ��ұ�?

//�ñ����� �����ؼ� �̸��� ����


//City �ν��Ͻ��� 229�� �������� �ű� ������ �� �־������.
